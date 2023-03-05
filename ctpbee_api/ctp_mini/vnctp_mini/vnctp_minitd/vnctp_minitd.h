//ϵͳ
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnctp_mini.h"
#include "pybind11/pybind11.h"
#include "mini/ThostFtdcTraderApi.h"


using namespace pybind11;

//����
#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONHEARTBEATWARNING 2
#define ONRSPAUTHENTICATE 3
#define ONRSPUSERLOGIN 4
#define ONRSPUSERLOGOUT 5
#define ONRSPORDERINSERT 6
#define ONRSPORDERACTION 7
#define ONRSPEXECORDERINSERT 8
#define ONRSPEXECORDERACTION 9
#define ONRSPFORQUOTEINSERT 10
#define ONRSPQUOTEINSERT 11
#define ONRSPQUOTEACTION 12
#define ONRSPBATCHORDERACTION 13
#define ONRSPOPTIONSELFCLOSEINSERT 14
#define ONRSPOPTIONSELFCLOSEACTION 15
#define ONRSPCOMBACTIONINSERT 16
#define ONRSPQRYORDER 17
#define ONRSPQRYTRADE 18
#define ONRSPQRYINVESTORPOSITION 19
#define ONRSPQRYTRADINGACCOUNT 20
#define ONRSPQRYINVESTOR 21
#define ONRSPQRYTRADINGCODE 22
#define ONRSPQRYINSTRUMENTMARGINRATE 23
#define ONRSPQRYINSTRUMENTCOMMISSIONRATE 24
#define ONRSPQRYEXCHANGE 25
#define ONRSPQRYPRODUCT 26
#define ONRSPQRYINSTRUMENT 27
#define ONRSPQRYCOMBINSTRUMENT 28
#define ONRSPQRYCOMBACTION 29
#define ONRSPQRYINVESTORPOSITIONFORCOMB 30
#define ONRSPQRYDEPTHMARKETDATA 31
#define ONRSPQRYINSTRUMENTSTATUS 32
#define ONRSPQRYINVESTORPOSITIONDETAIL 33
#define ONRSPQRYINVESTORPOSITIONCOMBINEDETAIL 34
#define ONRSPQRYEXCHANGEMARGINRATE 35
#define ONRSPQRYEXCHANGEMARGINRATEADJUST 36
#define ONRSPQRYOPTIONINSTRTRADECOST 37
#define ONRSPQRYOPTIONINSTRCOMMRATE 38
#define ONRSPQRYEXECORDER 39
#define ONRSPQRYFORQUOTE 40
#define ONRSPQRYQUOTE 41
#define ONRSPQRYOPTIONSELFCLOSE 42
#define ONRSPERROR 43
#define ONRTNORDER 44
#define ONRTNTRADE 45
#define ONERRRTNORDERINSERT 46
#define ONERRRTNORDERACTION 47
#define ONRTNINSTRUMENTSTATUS 48
#define ONRTNEXECORDER 49
#define ONERRRTNEXECORDERINSERT 50
#define ONERRRTNEXECORDERACTION 51
#define ONERRRTNFORQUOTEINSERT 52
#define ONRTNQUOTE 53
#define ONERRRTNQUOTEINSERT 54
#define ONERRRTNQUOTEACTION 55
#define ONRTNFORQUOTERSP 56
#define ONERRRTNBATCHORDERACTION 57
#define ONRTNOPTIONSELFCLOSE 58
#define ONERRRTNOPTIONSELFCLOSEINSERT 59
#define ONERRRTNOPTIONSELFCLOSEACTION 60
#define ONRTNCOMBACTION 61
#define ONRSPQRYINSTRUMENTORDERCOMMRATE 62


///-------------------------------------------------------------------------------------
///C++ SPI�Ļص���������ʵ��
///-------------------------------------------------------------------------------------

//API�ļ̳�ʵ��
class TdApi : public CThostFtdcTraderSpi
{
private:
    CThostFtdcTraderApi* api;            //API����
    thread task_thread;                    //�����߳�ָ�루��python���������ݣ�
    TaskQueue task_queue;                //�������
    bool active = false;                //����״̬

public:
    TdApi()
    {
    };

    ~TdApi()
    {
        if (this->active)
        {
            this->exit();
        }
    };

    //-------------------------------------------------------------------------------------
    //API�ص�����
    //-------------------------------------------------------------------------------------
    	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected();

	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason);

	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse);

	///�ͻ�����֤��Ӧ
	virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;


	///��¼������Ӧ
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///����¼��������Ӧ
	virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///��������������Ӧ
	virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///ִ������¼��������Ӧ
	virtual void OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///ִ���������������Ӧ
	virtual void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///ѯ��¼��������Ӧ
	virtual void OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///����¼��������Ӧ
	virtual void OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///���۲���������Ӧ
	virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///������������������Ӧ
	virtual void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///��Ȩ�ԶԳ�¼��������Ӧ
	virtual void OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///��Ȩ�ԶԳ����������Ӧ
	virtual void OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�������¼��������Ӧ
	virtual void OnRspCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ������Ӧ
	virtual void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ�ɽ���Ӧ
	virtual void OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯͶ���ֲ߳���Ӧ
	virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ�ʽ��˻���Ӧ
	virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯͶ������Ӧ
	virtual void OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ���ױ�����Ӧ
	virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ��Լ��֤������Ӧ
	virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ��Լ����������Ӧ
	virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ��������Ӧ
	virtual void OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ��Ʒ��Ӧ
	virtual void OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ��Լ��Ӧ
	virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ������Ϻ�Լ��Ӧ
	virtual void OnRspQryCombInstrument(CThostFtdcCombInstrumentField *pCombInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ���������Ӧ
	virtual void OnRspQryCombAction(CThostFtdcCombActionField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ��ϵ��Ȼ��ܱ���Ӧ
	virtual void OnRspQryInvestorPositionForComb(CThostFtdcInvestorPositionForCombField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ������Ӧ
	virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ��Լ״̬��Ӧ
	virtual void OnRspQryInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯͶ���ֲ߳���ϸ��Ӧ
	virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯͶ���ֲ߳���ϸ��Ӧ
	virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ��������֤������Ӧ
	virtual void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ������������֤������Ӧ
	virtual void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ��Ȩ���׳ɱ���Ӧ
	virtual void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ��Ȩ��Լ��������Ӧ
	virtual void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯִ��������Ӧ
	virtual void OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯѯ����Ӧ
	virtual void OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ������Ӧ
	virtual void OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯ��Ȩ�ԶԳ���Ӧ
	virtual void OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///����Ӧ��
	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///����֪ͨ
	virtual void OnRtnOrder(CThostFtdcOrderField *pOrder) ;

	///�ɽ�֪ͨ
	virtual void OnRtnTrade(CThostFtdcTradeField *pTrade) ;

	///����¼�����ر�
	virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) ;

	///������������ر�
	virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo) ;

	///��Լ����״̬֪ͨ
	virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus) ;

	///ִ������֪ͨ
	virtual void OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder) ;

	///ִ������¼�����ر�
	virtual void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo) ;

	///ִ�������������ر�
	virtual void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo) ;

	///ѯ��¼�����ر�
	virtual void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo) ;

	///����֪ͨ
	virtual void OnRtnQuote(CThostFtdcQuoteField *pQuote) ;

	///����¼�����ر�
	virtual void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo) ;

	///���۲�������ر�
	virtual void OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo) ;

	///ѯ��֪ͨ
	virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) ;

	///����������������ر�
	virtual void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo);

	///��Ȩ�ԶԳ�֪ͨ
	virtual void OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose) ;

	///��Ȩ�ԶԳ�¼�����ر�
	virtual void OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo) ;

	///��Ȩ�ԶԳ��������ر�
	virtual void OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField *pOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo) ;

	///�������֪ͨ
	virtual void OnRtnCombAction(CThostFtdcCombActionField *pCombAction) ;

	///�����ѯ�걨����Ӧ
	virtual void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *pInstrumentOrderCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;


    //-------------------------------------------------------------------------------------
    //task������
    //-------------------------------------------------------------------------------------
    void processTask();

    void processFrontConnected(Task *task);

    void processFrontDisconnected(Task *task);

    void processHeartBeatWarning(Task *task);

    void processRspAuthenticate(Task *task);

    void processRspUserLogin(Task *task);

    void processRspUserLogout(Task *task);

    void processRspOrderInsert(Task *task);

    void processRspOrderAction(Task *task);

    void processRspExecOrderInsert(Task *task);

    void processRspExecOrderAction(Task *task);

    void processRspForQuoteInsert(Task *task);

    void processRspQuoteInsert(Task *task);

    void processRspQuoteAction(Task *task);

    void processRspBatchOrderAction(Task *task);

    void processRspOptionSelfCloseInsert(Task *task);

    void processRspOptionSelfCloseAction(Task *task);

    void processRspCombActionInsert(Task *task);

    void processRspQryOrder(Task *task);

    void processRspQryTrade(Task *task);

    void processRspQryInvestorPosition(Task *task);

    void processRspQryTradingAccount(Task *task);

    void processRspQryInvestor(Task *task);

    void processRspQryTradingCode(Task *task);

    void processRspQryInstrumentMarginRate(Task *task);

    void processRspQryInstrumentCommissionRate(Task *task);

    void processRspQryExchange(Task *task);

    void processRspQryProduct(Task *task);

    void processRspQryInstrument(Task *task);

    void processRspQryCombInstrument(Task *task);

    void processRspQryCombAction(Task *task);

    void processRspQryInvestorPositionForComb(Task *task);

    void processRspQryDepthMarketData(Task *task);

    void processRspQryInstrumentStatus(Task *task);

    void processRspQryInvestorPositionDetail(Task *task);

    void processRspQryInvestorPositionCombineDetail(Task *task);

    void processRspQryExchangeMarginRate(Task *task);

    void processRspQryExchangeMarginRateAdjust(Task *task);

    void processRspQryOptionInstrTradeCost(Task *task);

    void processRspQryOptionInstrCommRate(Task *task);

    void processRspQryExecOrder(Task *task);

    void processRspQryForQuote(Task *task);

    void processRspQryQuote(Task *task);

    void processRspQryOptionSelfClose(Task *task);

    void processRspError(Task *task);

    void processRtnOrder(Task *task);

    void processRtnTrade(Task *task);

    void processErrRtnOrderInsert(Task *task);

    void processErrRtnOrderAction(Task *task);

    void processRtnInstrumentStatus(Task *task);

    void processRtnExecOrder(Task *task);

    void processErrRtnExecOrderInsert(Task *task);

    void processErrRtnExecOrderAction(Task *task);

    void processErrRtnForQuoteInsert(Task *task);

    void processRtnQuote(Task *task);

    void processErrRtnQuoteInsert(Task *task);

    void processErrRtnQuoteAction(Task *task);

    void processRtnForQuoteRsp(Task *task);

    void processErrRtnBatchOrderAction(Task *task);

    void processRtnOptionSelfClose(Task *task);

    void processErrRtnOptionSelfCloseInsert(Task *task);

    void processErrRtnOptionSelfCloseAction(Task *task);

    void processRtnCombAction(Task *task);

    void processRspQryInstrumentOrderCommRate(Task *task);


    //-------------------------------------------------------------------------------------
    //data���ص������������ֵ�
    //error���ص������Ĵ����ֵ�
    //id������id
    //last���Ƿ�Ϊ��󷵻�
    //i������
    //-------------------------------------------------------------------------------------

    virtual void onFrontConnected() {};

    virtual void onFrontDisconnected(int reqid) {};

    virtual void onHeartBeatWarning(int reqid) {};

    virtual void onRspAuthenticate(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspUserLogin(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspUserLogout(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspOrderInsert(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspOrderAction(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspExecOrderInsert(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspExecOrderAction(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspForQuoteInsert(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQuoteInsert(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQuoteAction(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspBatchOrderAction(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspOptionSelfCloseInsert(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspOptionSelfCloseAction(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspCombActionInsert(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryOrder(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryTrade(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryInvestorPosition(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryTradingAccount(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryInvestor(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryTradingCode(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryInstrumentMarginRate(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryInstrumentCommissionRate(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryExchange(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryProduct(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryInstrument(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryCombInstrument(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryCombAction(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryInvestorPositionForComb(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryDepthMarketData(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryInstrumentStatus(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryInvestorPositionDetail(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryInvestorPositionCombineDetail(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryExchangeMarginRate(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryExchangeMarginRateAdjust(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryOptionInstrTradeCost(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryOptionInstrCommRate(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryExecOrder(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryForQuote(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryQuote(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspQryOptionSelfClose(const dict &data, const dict &error, int reqid, bool last) {};

    virtual void onRspError(const dict &error, int reqid, bool last) {};

    virtual void onRtnOrder(const dict &data) {};

    virtual void onRtnTrade(const dict &data) {};

    virtual void onErrRtnOrderInsert(const dict &data, const dict &error) {};

    virtual void onErrRtnOrderAction(const dict &data, const dict &error) {};

    virtual void onRtnInstrumentStatus(const dict &data) {};

    virtual void onRtnExecOrder(const dict &data) {};

    virtual void onErrRtnExecOrderInsert(const dict &data, const dict &error) {};

    virtual void onErrRtnExecOrderAction(const dict &data, const dict &error) {};

    virtual void onErrRtnForQuoteInsert(const dict &data, const dict &error) {};

    virtual void onRtnQuote(const dict &data) {};

    virtual void onErrRtnQuoteInsert(const dict &data, const dict &error) {};

    virtual void onErrRtnQuoteAction(const dict &data, const dict &error) {};

    virtual void onRtnForQuoteRsp(const dict &data) {};

    virtual void onErrRtnBatchOrderAction(const dict &data, const dict &error) {};

    virtual void onRtnOptionSelfClose(const dict &data) {};

    virtual void onErrRtnOptionSelfCloseInsert(const dict &data, const dict &error) {};

    virtual void onErrRtnOptionSelfCloseAction(const dict &data, const dict &error) {};

    virtual void onRtnCombAction(const dict &data) {};

    virtual void onRspQryInstrumentOrderCommRate(const dict &data, const dict &error, int reqid, bool last) {};




    //-------------------------------------------------------------------------------------
    //req:���������������ֵ�
    //-------------------------------------------------------------------------------------

    void createFtdcTraderApi(string pszFlowPath = "");

    void release();

    void init();

    int join();

    int exit();

    string getTradingDay();

    void registerFront(string pszFrontAddress);

    void subscribePrivateTopic(int nType);

    void subscribePublicTopic(int nType);

	int reqAuthenticate(const dict &req, int reqid);

    int reqUserLogin(const dict &req, int reqid);

    int reqUserLoginEncrypt(const dict &req, int reqid);

    int reqUserLogout(const dict &req, int reqid);

    int reqOrderInsert(const dict &req, int reqid);

    int reqOrderAction(const dict &req, int reqid);

    int reqExecOrderInsert(const dict &req, int reqid);

    int reqExecOrderAction(const dict &req, int reqid);

    int reqForQuoteInsert(const dict &req, int reqid);

    int reqQuoteInsert(const dict &req, int reqid);

    int reqQuoteAction(const dict &req, int reqid);

    int reqBatchOrderAction(const dict &req, int reqid);

    int reqOptionSelfCloseInsert(const dict &req, int reqid);

    int reqOptionSelfCloseAction(const dict &req, int reqid);

    int reqCombActionInsert(const dict &req, int reqid);

    int reqQryOrder(const dict &req, int reqid);

    int reqQryTrade(const dict &req, int reqid);

    int reqQryInvestorPosition(const dict &req, int reqid);

    int reqQryTradingAccount(const dict &req, int reqid);

    int reqQryInvestor(const dict &req, int reqid);

    int reqQryTradingCode(const dict &req, int reqid);

    int reqQryInstrumentMarginRate(const dict &req, int reqid);

    int reqQryInstrumentCommissionRate(const dict &req, int reqid);

    int reqQryExchange(const dict &req, int reqid);

    int reqQryProduct(const dict &req, int reqid);

    int reqQryInstrument(const dict &req, int reqid);

    int reqQryCombInstrument(const dict &req, int reqid);

    int reqQryInvestorPositionForComb(const dict &req, int reqid);

    int reqQryCombAction(const dict &req, int reqid);

    int reqQryDepthMarketData(const dict &req, int reqid);

    int reqQryOptionSelfClose(const dict &req, int reqid);

    int reqQryInstrumentStatus(const dict &req, int reqid);

    int reqQryInvestorPositionDetail(const dict &req, int reqid);

    int reqQryInvestorPositionCombineDetail(const dict &req, int reqid);

    int reqQryExchangeMarginRate(const dict &req, int reqid);

    int reqQryExchangeMarginRateAdjust(const dict &req, int reqid);

    int reqQryOptionInstrTradeCost(const dict &req, int reqid);

    int reqQryOptionInstrCommRate(const dict &req, int reqid);

    int reqQryExecOrder(const dict &req, int reqid);

    int reqQryForQuote(const dict &req, int reqid);

    int reqQryQuote(const dict &req, int reqid);

    int reqQryInstrumentOrderCommRate(const dict &req, int reqid);
};
