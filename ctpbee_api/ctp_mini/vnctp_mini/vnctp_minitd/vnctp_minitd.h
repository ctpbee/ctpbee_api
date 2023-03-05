//系统
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnctp_mini.h"
#include "pybind11/pybind11.h"
#include "mini/ThostFtdcTraderApi.h"


using namespace pybind11;

//常量
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
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现
class TdApi : public CThostFtdcTraderSpi
{
private:
    CThostFtdcTraderApi* api;            //API对象
    thread task_thread;                    //工作线程指针（向python中推送数据）
    TaskQueue task_queue;                //任务队列
    bool active = false;                //工作状态

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
    //API回调函数
    //-------------------------------------------------------------------------------------
    	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	virtual void OnFrontConnected();

	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	virtual void OnFrontDisconnected(int nReason);

	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	virtual void OnHeartBeatWarning(int nTimeLapse);

	///客户端认证响应
	virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;


	///登录请求响应
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///登出请求响应
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///报单录入请求响应
	virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///报单操作请求响应
	virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///执行宣告录入请求响应
	virtual void OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///执行宣告操作请求响应
	virtual void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///询价录入请求响应
	virtual void OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///报价录入请求响应
	virtual void OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///报价操作请求响应
	virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///批量报单操作请求响应
	virtual void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///期权自对冲录入请求响应
	virtual void OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///期权自对冲操作请求响应
	virtual void OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///申请组合录入请求响应
	virtual void OnRspCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询报单响应
	virtual void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询成交响应
	virtual void OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询投资者持仓响应
	virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询资金账户响应
	virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询投资者响应
	virtual void OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询交易编码响应
	virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询合约保证金率响应
	virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询合约手续费率响应
	virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询交易所响应
	virtual void OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询产品响应
	virtual void OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询合约响应
	virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询申请组合合约响应
	virtual void OnRspQryCombInstrument(CThostFtdcCombInstrumentField *pCombInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询申请组合响应
	virtual void OnRspQryCombAction(CThostFtdcCombActionField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询组合单腿汇总表响应
	virtual void OnRspQryInvestorPositionForComb(CThostFtdcInvestorPositionForCombField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询行情响应
	virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询合约状态响应
	virtual void OnRspQryInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询投资者持仓明细响应
	virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询投资者持仓明细响应
	virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询交易所保证金率响应
	virtual void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询交易所调整保证金率响应
	virtual void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询期权交易成本响应
	virtual void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询期权合约手续费响应
	virtual void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询执行宣告响应
	virtual void OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询询价响应
	virtual void OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询报价响应
	virtual void OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///请求查询期权自对冲响应
	virtual void OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///错误应答
	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///报单通知
	virtual void OnRtnOrder(CThostFtdcOrderField *pOrder) ;

	///成交通知
	virtual void OnRtnTrade(CThostFtdcTradeField *pTrade) ;

	///报单录入错误回报
	virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) ;

	///报单操作错误回报
	virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo) ;

	///合约交易状态通知
	virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus) ;

	///执行宣告通知
	virtual void OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder) ;

	///执行宣告录入错误回报
	virtual void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo) ;

	///执行宣告操作错误回报
	virtual void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo) ;

	///询价录入错误回报
	virtual void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo) ;

	///报价通知
	virtual void OnRtnQuote(CThostFtdcQuoteField *pQuote) ;

	///报价录入错误回报
	virtual void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo) ;

	///报价操作错误回报
	virtual void OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo) ;

	///询价通知
	virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) ;

	///批量报单操作错误回报
	virtual void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo);

	///期权自对冲通知
	virtual void OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose) ;

	///期权自对冲录入错误回报
	virtual void OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo) ;

	///期权自对冲操作错误回报
	virtual void OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField *pOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo) ;

	///申请组合通知
	virtual void OnRtnCombAction(CThostFtdcCombActionField *pCombAction) ;

	///请求查询申报费响应
	virtual void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *pInstrumentOrderCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;


    //-------------------------------------------------------------------------------------
    //task：任务
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
    //data：回调函数的数据字典
    //error：回调函数的错误字典
    //id：请求id
    //last：是否为最后返回
    //i：整数
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
    //req:主动函数的请求字典
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
