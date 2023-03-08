//??
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnctp_mini.h"
#include "pybind11/pybind11.h"
#include "mini/ThostFtdcMdApi.h"


using namespace pybind11;

//????
#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONHEARTBEATWARNING 2
#define ONRSPUSERLOGIN 3
#define ONRSPUSERLOGOUT 4
#define ONRSPERROR 5
#define ONRSPSUBMARKETDATA 6
#define ONRSPUNSUBMARKETDATA 7
#define ONRSPSUBFORQUOTERSP 8
#define ONRSPUNSUBFORQUOTERSP 9
#define ONRTNDEPTHMARKETDATA 10
#define ONRTNMBLMARKETDATA 11
#define ONRTNFORQUOTERSP 12



///-------------------------------------------------------------------------------------
///C++ SPI???????????????
///-------------------------------------------------------------------------------------

//API???????
class MdApi : public CThostFtdcMdSpi
{
private:
	CThostFtdcMdApi* api;				//API????
	thread task_thread;					//????????????python???????????
	TaskQueue task_queue;			    //???????
	bool active = false;				//??????

public:
	MdApi()
	{
	};

	~MdApi()
	{
		if (this->active)
		{
			this->exit();
		}
	};

	//-------------------------------------------------------------------------------------
	//API???????
	//-------------------------------------------------------------------------------------

	virtual void OnFrontConnected();

	///??????????????????????????÷????????á???????????????API???????????????????????????
	///@param nReason ???????
	///        0x1001 ????????
	///        0x1002 ????д???
	///        0x2001 ???????????
	///        0x2002 ???????????
	///        0x2003 ?????????
	virtual void OnFrontDisconnected(int nReason);

	///??????????档???????δ???????????÷????????á?
	///@param nTimeLapse ??????ν??????????
	virtual void OnHeartBeatWarning(int nTimeLapse);

	///??????????
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///??????????
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///???????
	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///???????????
	virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///??????????????
	virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///??????????
	virtual void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///?????????????
	virtual void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///?????????
	virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData) ;

	///??????
	virtual void OnRtnMBLMarketData(CThostFtdcMBLMarketDataField *pMBLMarketData) ;

	///?????
	virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp);

	//-------------------------------------------------------------------------------------
	//task??????
	//-------------------------------------------------------------------------------------

	void processTask();

	void processFrontConnected(Task *task);

    void processFrontDisconnected(Task *task);

    void processHeartBeatWarning(Task *task);

    void processRspUserLogin(Task *task);

    void processRspUserLogout(Task *task);

    void processRspError(Task *task);

    void processRspSubMarketData(Task *task);

    void processRspUnSubMarketData(Task *task);

    void processRspSubForQuoteRsp(Task *task);

    void processRspUnSubForQuoteRsp(Task *task);

    void processRtnDepthMarketData(Task *task);

    void processRtnMBLMarketData(Task *task);

    void processRtnForQuoteRsp(Task *task);



	//-------------------------------------------------------------------------------------
	//data??????????????????
	//error?????????????????
	//id??????id
	//last??????????
	//i??????
	//-------------------------------------------------------------------------------------

	virtual void onFrontConnected() {};

    virtual void onFrontDisconnected(int reqid) {};

    virtual void onHeartBeatWarning(int reqid) {};

    virtual void onRspUserLogin(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspUserLogout(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspError(const dict &error, int reqid, bool last) {};

    virtual void onRspSubMarketData(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspUnSubMarketData(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspSubForQuoteRsp(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspUnSubForQuoteRsp(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRtnDepthMarketData(const dict &data) {};

    virtual void onRtnMBLMarketData(const dict &data) {};

    virtual void onRtnForQuoteRsp(const dict &data) {};

	//-------------------------------------------------------------------------------------
	//req:?????????????????
	//-------------------------------------------------------------------------------------

	void createFtdcMdApi(string pszFlowPath = "");

	void release();

	void init();

	int join();

	int exit();

	string getTradingDay();

	void registerFront(string pszFrontAddress);

	int subscribeMarketData(string instrumentID);

	int unSubscribeMarketData(string instrumentID);

	int subscribeForQuoteRsp(string instrumentID);

	int unSubscribeForQuoteRsp(string instrumentID);

    int reqUserLogin(const dict &req, int reqid);

    int reqUserLogout(const dict &req, int reqid);

};
