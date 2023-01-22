//系统
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnctp.h"
#include "pybind11/pybind11.h"
#include "ctp/ThostFtdcMdApi.h"
#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONHEARTBEATWARNING 2
#define ONRSPUSERLOGIN 3
#define ONRSPUSERLOGOUT 4
#define ONRSPQRYMULTICASTINSTRUMENT 5
#define ONRSPERROR 6
#define ONRSPSUBMARKETDATA 7
#define ONRSPUNSUBMARKETDATA 8
#define ONRSPSUBFORQUOTERSP 9
#define ONRSPUNSUBFORQUOTERSP 10
#define ONRTNDEPTHMARKETDATA 11
#define ONRTNFORQUOTERSP 12

class MdApi : public CThostFtdcMdSpi
{
private:
	CThostFtdcMdApi* api;				//API对象
	thread task_thread;					//工作线程指针（向python中推送数据）
	TaskQueue task_queue;			    //任务队列
	bool active = false;				//工作状态

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
	
	void processTask();

	//req:主动函数的请求字典
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
void processFrontConnected(Task *task);

void processFrontDisconnected(Task *task);

void processHeartBeatWarning(Task *task);

void processRspUserLogin(Task *task);

void processRspUserLogout(Task *task);

void processRspQryMulticastInstrument(Task *task);

void processRspError(Task *task);

void processRspSubMarketData(Task *task);

void processRspUnSubMarketData(Task *task);

void processRspSubForQuoteRsp(Task *task);

void processRspUnSubForQuoteRsp(Task *task);

void processRtnDepthMarketData(Task *task);

void processRtnForQuoteRsp(Task *task);


virtual void  OnFrontConnected();
virtual void onFrontConnected() {};


virtual void   OnFrontDisconnected(int nReaso);
virtual void onFrontDisconnected(int reqid) {};


virtual void   OnHeartBeatWarning(int nTimeLaps);
virtual void onHeartBeatWarning(int reqid) {};


virtual void   OnRspUserLogin(CThostFtdcRspUserLoginField * pRspUserLogin,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspUserLogin(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspUserLogout(CThostFtdcUserLogoutField * pUserLogout,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspUserLogout(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryMulticastInstrument(CThostFtdcMulticastInstrumentField * pMulticastInstrument,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryMulticastInstrument(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspError(CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspError(const dict &error, int reqid, bool last) {};


virtual void   OnRspSubMarketData(CThostFtdcSpecificInstrumentField * pSpecificInstrument,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspSubMarketData(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField * pSpecificInstrument,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspUnSubMarketData(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField * pSpecificInstrument,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspSubForQuoteRsp(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField * pSpecificInstrument,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspUnSubForQuoteRsp(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRtnDepthMarketData(CThostFtdcDepthMarketDataField * pDepthMarketDat);
virtual void onRtnDepthMarketData(const dict &data) {};


virtual void   OnRtnForQuoteRsp(CThostFtdcForQuoteRspField * pForQuoteRs);
virtual void onRtnForQuoteRsp(const dict &data) {};

int reqUserLogin(const dict &req, int reqid);

int reqUserLogout(const dict &req, int reqid);

int reqQryMulticastInstrument(const dict &req, int reqid);

};