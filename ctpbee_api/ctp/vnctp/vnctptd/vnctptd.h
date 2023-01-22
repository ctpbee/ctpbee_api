
//系统
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnctp.h"
#include "pybind11/pybind11.h"
#include "ctp/ThostFtdcTraderApi.h"
using namespace pybind11;

#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONHEARTBEATWARNING 2
#define ONRSPAUTHENTICATE 3
#define ONRSPUSERLOGIN 4
#define ONRSPUSERLOGOUT 5
#define ONRSPUSERPASSWORDUPDATE 6
#define ONRSPTRADINGACCOUNTPASSWORDUPDATE 7
#define ONRSPUSERAUTHMETHOD 8
#define ONRSPGENUSERCAPTCHA 9
#define ONRSPGENUSERTEXT 10
#define ONRSPORDERINSERT 11
#define ONRSPPARKEDORDERINSERT 12
#define ONRSPPARKEDORDERACTION 13
#define ONRSPORDERACTION 14
#define ONRSPQRYMAXORDERVOLUME 15
#define ONRSPSETTLEMENTINFOCONFIRM 16
#define ONRSPREMOVEPARKEDORDER 17
#define ONRSPREMOVEPARKEDORDERACTION 18
#define ONRSPEXECORDERINSERT 19
#define ONRSPEXECORDERACTION 20
#define ONRSPFORQUOTEINSERT 21
#define ONRSPQUOTEINSERT 22
#define ONRSPQUOTEACTION 23
#define ONRSPBATCHORDERACTION 24
#define ONRSPOPTIONSELFCLOSEINSERT 25
#define ONRSPOPTIONSELFCLOSEACTION 26
#define ONRSPCOMBACTIONINSERT 27
#define ONRSPQRYORDER 28
#define ONRSPQRYTRADE 29
#define ONRSPQRYINVESTORPOSITION 30
#define ONRSPQRYTRADINGACCOUNT 31
#define ONRSPQRYINVESTOR 32
#define ONRSPQRYTRADINGCODE 33
#define ONRSPQRYINSTRUMENTMARGINRATE 34
#define ONRSPQRYINSTRUMENTCOMMISSIONRATE 35
#define ONRSPQRYEXCHANGE 36
#define ONRSPQRYPRODUCT 37
#define ONRSPQRYINSTRUMENT 38
#define ONRSPQRYDEPTHMARKETDATA 39
#define ONRSPQRYTRADEROFFER 40
#define ONRSPQRYSETTLEMENTINFO 41
#define ONRSPQRYTRANSFERBANK 42
#define ONRSPQRYINVESTORPOSITIONDETAIL 43
#define ONRSPQRYNOTICE 44
#define ONRSPQRYSETTLEMENTINFOCONFIRM 45
#define ONRSPQRYINVESTORPOSITIONCOMBINEDETAIL 46
#define ONRSPQRYCFMMCTRADINGACCOUNTKEY 47
#define ONRSPQRYEWARRANTOFFSET 48
#define ONRSPQRYINVESTORPRODUCTGROUPMARGIN 49
#define ONRSPQRYEXCHANGEMARGINRATE 50
#define ONRSPQRYEXCHANGEMARGINRATEADJUST 51
#define ONRSPQRYEXCHANGERATE 52
#define ONRSPQRYSECAGENTACIDMAP 53
#define ONRSPQRYPRODUCTEXCHRATE 54
#define ONRSPQRYPRODUCTGROUP 55
#define ONRSPQRYMMINSTRUMENTCOMMISSIONRATE 56
#define ONRSPQRYMMOPTIONINSTRCOMMRATE 57
#define ONRSPQRYINSTRUMENTORDERCOMMRATE 58
#define ONRSPQRYSECAGENTTRADINGACCOUNT 59
#define ONRSPQRYSECAGENTCHECKMODE 60
#define ONRSPQRYSECAGENTTRADEINFO 61
#define ONRSPQRYOPTIONINSTRTRADECOST 62
#define ONRSPQRYOPTIONINSTRCOMMRATE 63
#define ONRSPQRYEXECORDER 64
#define ONRSPQRYFORQUOTE 65
#define ONRSPQRYQUOTE 66
#define ONRSPQRYOPTIONSELFCLOSE 67
#define ONRSPQRYINVESTUNIT 68
#define ONRSPQRYCOMBINSTRUMENTGUARD 69
#define ONRSPQRYCOMBACTION 70
#define ONRSPQRYTRANSFERSERIAL 71
#define ONRSPQRYACCOUNTREGISTER 72
#define ONRSPERROR 73
#define ONRTNORDER 74
#define ONRTNTRADE 75
#define ONERRRTNORDERINSERT 76
#define ONERRRTNORDERACTION 77
#define ONRTNINSTRUMENTSTATUS 78
#define ONRTNBULLETIN 79
#define ONRTNTRADINGNOTICE 80
#define ONRTNERRORCONDITIONALORDER 81
#define ONRTNEXECORDER 82
#define ONERRRTNEXECORDERINSERT 83
#define ONERRRTNEXECORDERACTION 84
#define ONERRRTNFORQUOTEINSERT 85
#define ONRTNQUOTE 86
#define ONERRRTNQUOTEINSERT 87
#define ONERRRTNQUOTEACTION 88
#define ONRTNFORQUOTERSP 89
#define ONRTNCFMMCTRADINGACCOUNTTOKEN 90
#define ONERRRTNBATCHORDERACTION 91
#define ONRTNOPTIONSELFCLOSE 92
#define ONERRRTNOPTIONSELFCLOSEINSERT 93
#define ONERRRTNOPTIONSELFCLOSEACTION 94
#define ONRTNCOMBACTION 95
#define ONERRRTNCOMBACTIONINSERT 96
#define ONRSPQRYCONTRACTBANK 97
#define ONRSPQRYPARKEDORDER 98
#define ONRSPQRYPARKEDORDERACTION 99
#define ONRSPQRYTRADINGNOTICE 100
#define ONRSPQRYBROKERTRADINGPARAMS 101
#define ONRSPQRYBROKERTRADINGALGOS 102
#define ONRSPQUERYCFMMCTRADINGACCOUNTTOKEN 103
#define ONRTNFROMBANKTOFUTUREBYBANK 104
#define ONRTNFROMFUTURETOBANKBYBANK 105
#define ONRTNREPEALFROMBANKTOFUTUREBYBANK 106
#define ONRTNREPEALFROMFUTURETOBANKBYBANK 107
#define ONRTNFROMBANKTOFUTUREBYFUTURE 108
#define ONRTNFROMFUTURETOBANKBYFUTURE 109
#define ONRTNREPEALFROMBANKTOFUTUREBYFUTUREMANUAL 110
#define ONRTNREPEALFROMFUTURETOBANKBYFUTUREMANUAL 111
#define ONRTNQUERYBANKBALANCEBYFUTURE 112
#define ONERRRTNBANKTOFUTUREBYFUTURE 113
#define ONERRRTNFUTURETOBANKBYFUTURE 114
#define ONERRRTNREPEALBANKTOFUTUREBYFUTUREMANUAL 115
#define ONERRRTNREPEALFUTURETOBANKBYFUTUREMANUAL 116
#define ONERRRTNQUERYBANKBALANCEBYFUTURE 117
#define ONRTNREPEALFROMBANKTOFUTUREBYFUTURE 118
#define ONRTNREPEALFROMFUTURETOBANKBYFUTURE 119
#define ONRSPFROMBANKTOFUTUREBYFUTURE 120
#define ONRSPFROMFUTURETOBANKBYFUTURE 121
#define ONRSPQUERYBANKACCOUNTMONEYBYFUTURE 122
#define ONRTNOPENACCOUNTBYBANK 123
#define ONRTNCANCELACCOUNTBYBANK 124
#define ONRTNCHANGEACCOUNTBYBANK 125
#define ONRSPQRYCLASSIFIEDINSTRUMENT 126
#define ONRSPQRYCOMBPROMOTIONPARAM 127
#define ONRSPQRYRISKSETTLEINVSTPOSITION 128
#define ONRSPQRYRISKSETTLEPRODUCTSTATUS 129
#define ONRSPQRYSPBMFUTUREPARAMETER 130
#define ONRSPQRYSPBMOPTIONPARAMETER 131
#define ONRSPQRYSPBMINTRAPARAMETER 132
#define ONRSPQRYSPBMINTERPARAMETER 133
#define ONRSPQRYSPBMPORTFDEFINITION 134
#define ONRSPQRYSPBMINVESTORPORTFDEF 135
#define ONRSPQRYINVESTORPORTFMARGINRATIO 136
#define ONRSPQRYINVESTORPRODSPBMDETAIL 137

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
    
     void processTask();
    
    void createFtdcTraderApi(string pszFlowPath = "");

    void release();

    void init();

    int join();

    int exit();

    string getTradingDay();

    void registerFront(string pszFrontAddress);

    void subscribePrivateTopic(int nType);

    void subscribePublicTopic(int nType);


virtual void  OnFrontConnected();
virtual void onFrontConnected() {};


virtual void   OnFrontDisconnected(int nReaso);
virtual void onFrontDisconnected(int reqid) {};


virtual void   OnHeartBeatWarning(int nTimeLaps);
virtual void onHeartBeatWarning(int reqid) {};


virtual void   OnRspAuthenticate(CThostFtdcRspAuthenticateField * pRspAuthenticateField,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspAuthenticate(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspUserLogin(CThostFtdcRspUserLoginField * pRspUserLogin,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspUserLogin(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspUserLogout(CThostFtdcUserLogoutField * pUserLogout,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspUserLogout(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField * pUserPasswordUpdate,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspUserPasswordUpdate(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField * pTradingAccountPasswordUpdate,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspTradingAccountPasswordUpdate(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField * pRspUserAuthMethod,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspUserAuthMethod(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField * pRspGenUserCaptcha,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspGenUserCaptcha(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspGenUserText(CThostFtdcRspGenUserTextField * pRspGenUserText,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspGenUserText(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspOrderInsert(CThostFtdcInputOrderField * pInputOrder,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspOrderInsert(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspParkedOrderInsert(CThostFtdcParkedOrderField * pParkedOrder,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspParkedOrderInsert(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspParkedOrderAction(CThostFtdcParkedOrderActionField * pParkedOrderAction,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspParkedOrderAction(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspOrderAction(CThostFtdcInputOrderActionField * pInputOrderAction,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspOrderAction(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField * pQryMaxOrderVolume,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryMaxOrderVolume(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField * pSettlementInfoConfirm,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspSettlementInfoConfirm(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField * pRemoveParkedOrder,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspRemoveParkedOrder(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField * pRemoveParkedOrderAction,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspRemoveParkedOrderAction(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspExecOrderInsert(CThostFtdcInputExecOrderField * pInputExecOrder,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspExecOrderInsert(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspExecOrderAction(CThostFtdcInputExecOrderActionField * pInputExecOrderAction,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspExecOrderAction(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspForQuoteInsert(CThostFtdcInputForQuoteField * pInputForQuote,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspForQuoteInsert(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQuoteInsert(CThostFtdcInputQuoteField * pInputQuote,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQuoteInsert(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQuoteAction(CThostFtdcInputQuoteActionField * pInputQuoteAction,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQuoteAction(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField * pInputBatchOrderAction,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspBatchOrderAction(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField * pInputOptionSelfClose,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspOptionSelfCloseInsert(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField * pInputOptionSelfCloseAction,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspOptionSelfCloseAction(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspCombActionInsert(CThostFtdcInputCombActionField * pInputCombAction,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspCombActionInsert(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryOrder(CThostFtdcOrderField * pOrder,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryOrder(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryTrade(CThostFtdcTradeField * pTrade,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryTrade(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryInvestorPosition(CThostFtdcInvestorPositionField * pInvestorPosition,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryInvestorPosition(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryTradingAccount(CThostFtdcTradingAccountField * pTradingAccount,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryTradingAccount(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryInvestor(CThostFtdcInvestorField * pInvestor,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryInvestor(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryTradingCode(CThostFtdcTradingCodeField * pTradingCode,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryTradingCode(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField * pInstrumentMarginRate,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryInstrumentMarginRate(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField * pInstrumentCommissionRate,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryInstrumentCommissionRate(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryExchange(CThostFtdcExchangeField * pExchange,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryExchange(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryProduct(CThostFtdcProductField * pProduct,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryProduct(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryInstrument(CThostFtdcInstrumentField * pInstrument,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryInstrument(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField * pDepthMarketData,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryDepthMarketData(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryTraderOffer(CThostFtdcTraderOfferField * pTraderOffer,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryTraderOffer(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQrySettlementInfo(CThostFtdcSettlementInfoField * pSettlementInfo,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQrySettlementInfo(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryTransferBank(CThostFtdcTransferBankField * pTransferBank,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryTransferBank(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField * pInvestorPositionDetail,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryInvestorPositionDetail(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryNotice(CThostFtdcNoticeField * pNotice,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryNotice(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField * pSettlementInfoConfirm,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQrySettlementInfoConfirm(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField * pInvestorPositionCombineDetail,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryInvestorPositionCombineDetail(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField * pCFMMCTradingAccountKey,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryCFMMCTradingAccountKey(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField * pEWarrantOffset,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryEWarrantOffset(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField * pInvestorProductGroupMargin,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryInvestorProductGroupMargin(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField * pExchangeMarginRate,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryExchangeMarginRate(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField * pExchangeMarginRateAdjust,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryExchangeMarginRateAdjust(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryExchangeRate(CThostFtdcExchangeRateField * pExchangeRate,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryExchangeRate(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField * pSecAgentACIDMap,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQrySecAgentACIDMap(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryProductExchRate(CThostFtdcProductExchRateField * pProductExchRate,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryProductExchRate(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryProductGroup(CThostFtdcProductGroupField * pProductGroup,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryProductGroup(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField * pMMInstrumentCommissionRate,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryMMInstrumentCommissionRate(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField * pMMOptionInstrCommRate,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryMMOptionInstrCommRate(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField * pInstrumentOrderCommRate,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryInstrumentOrderCommRate(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField * pTradingAccount,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQrySecAgentTradingAccount(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField * pSecAgentCheckMode,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQrySecAgentCheckMode(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField * pSecAgentTradeInfo,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQrySecAgentTradeInfo(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField * pOptionInstrTradeCost,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryOptionInstrTradeCost(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField * pOptionInstrCommRate,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryOptionInstrCommRate(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryExecOrder(CThostFtdcExecOrderField * pExecOrder,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryExecOrder(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryForQuote(CThostFtdcForQuoteField * pForQuote,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryForQuote(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryQuote(CThostFtdcQuoteField * pQuote,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryQuote(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField * pOptionSelfClose,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryOptionSelfClose(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryInvestUnit(CThostFtdcInvestUnitField * pInvestUnit,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryInvestUnit(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField * pCombInstrumentGuard,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryCombInstrumentGuard(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryCombAction(CThostFtdcCombActionField * pCombAction,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryCombAction(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryTransferSerial(CThostFtdcTransferSerialField * pTransferSerial,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryTransferSerial(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryAccountregister(CThostFtdcAccountregisterField * pAccountregister,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryAccountregister(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspError(CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspError(const dict &error, int reqid, bool last) {};


virtual void   OnRtnOrder(CThostFtdcOrderField * pOrde);
virtual void onRtnOrder(const dict &data) {};


virtual void   OnRtnTrade(CThostFtdcTradeField * pTrad);
virtual void onRtnTrade(const dict &data) {};


virtual void   OnErrRtnOrderInsert(CThostFtdcInputOrderField * pInputOrder,CThostFtdcRspInfoField * pRspInf);
virtual void onErrRtnOrderInsert(const dict &data, const dict &error) {};


virtual void   OnErrRtnOrderAction(CThostFtdcOrderActionField * pOrderAction,CThostFtdcRspInfoField * pRspInf);
virtual void onErrRtnOrderAction(const dict &data, const dict &error) {};


virtual void   OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField * pInstrumentStatu);
virtual void onRtnInstrumentStatus(const dict &data) {};


virtual void   OnRtnBulletin(CThostFtdcBulletinField * pBulleti);
virtual void onRtnBulletin(const dict &data) {};


virtual void   OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField * pTradingNoticeInf);
virtual void onRtnTradingNotice(const dict &data) {};


virtual void   OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField * pErrorConditionalOrde);
virtual void onRtnErrorConditionalOrder(const dict &data) {};


virtual void   OnRtnExecOrder(CThostFtdcExecOrderField * pExecOrde);
virtual void onRtnExecOrder(const dict &data) {};


virtual void   OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField * pInputExecOrder,CThostFtdcRspInfoField * pRspInf);
virtual void onErrRtnExecOrderInsert(const dict &data, const dict &error) {};


virtual void   OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField * pExecOrderAction,CThostFtdcRspInfoField * pRspInf);
virtual void onErrRtnExecOrderAction(const dict &data, const dict &error) {};


virtual void   OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField * pInputForQuote,CThostFtdcRspInfoField * pRspInf);
virtual void onErrRtnForQuoteInsert(const dict &data, const dict &error) {};


virtual void   OnRtnQuote(CThostFtdcQuoteField * pQuot);
virtual void onRtnQuote(const dict &data) {};


virtual void   OnErrRtnQuoteInsert(CThostFtdcInputQuoteField * pInputQuote,CThostFtdcRspInfoField * pRspInf);
virtual void onErrRtnQuoteInsert(const dict &data, const dict &error) {};


virtual void   OnErrRtnQuoteAction(CThostFtdcQuoteActionField * pQuoteAction,CThostFtdcRspInfoField * pRspInf);
virtual void onErrRtnQuoteAction(const dict &data, const dict &error) {};


virtual void   OnRtnForQuoteRsp(CThostFtdcForQuoteRspField * pForQuoteRs);
virtual void onRtnForQuoteRsp(const dict &data) {};


virtual void   OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField * pCFMMCTradingAccountToke);
virtual void onRtnCFMMCTradingAccountToken(const dict &data) {};


virtual void   OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField * pBatchOrderAction,CThostFtdcRspInfoField * pRspInf);
virtual void onErrRtnBatchOrderAction(const dict &data, const dict &error) {};


virtual void   OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField * pOptionSelfClos);
virtual void onRtnOptionSelfClose(const dict &data) {};


virtual void   OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField * pInputOptionSelfClose,CThostFtdcRspInfoField * pRspInf);
virtual void onErrRtnOptionSelfCloseInsert(const dict &data, const dict &error) {};


virtual void   OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField * pOptionSelfCloseAction,CThostFtdcRspInfoField * pRspInf);
virtual void onErrRtnOptionSelfCloseAction(const dict &data, const dict &error) {};


virtual void   OnRtnCombAction(CThostFtdcCombActionField * pCombActio);
virtual void onRtnCombAction(const dict &data) {};


virtual void   OnErrRtnCombActionInsert(CThostFtdcInputCombActionField * pInputCombAction,CThostFtdcRspInfoField * pRspInf);
virtual void onErrRtnCombActionInsert(const dict &data, const dict &error) {};


virtual void   OnRspQryContractBank(CThostFtdcContractBankField * pContractBank,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryContractBank(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryParkedOrder(CThostFtdcParkedOrderField * pParkedOrder,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryParkedOrder(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField * pParkedOrderAction,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryParkedOrderAction(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryTradingNotice(CThostFtdcTradingNoticeField * pTradingNotice,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryTradingNotice(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField * pBrokerTradingParams,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryBrokerTradingParams(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField * pBrokerTradingAlgos,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryBrokerTradingAlgos(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField * pQueryCFMMCTradingAccountToken,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQueryCFMMCTradingAccountToken(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField * pRspTransfe);
virtual void onRtnFromBankToFutureByBank(const dict &data) {};


virtual void   OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField * pRspTransfe);
virtual void onRtnFromFutureToBankByBank(const dict &data) {};


virtual void   OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField * pRspRepea);
virtual void onRtnRepealFromBankToFutureByBank(const dict &data) {};


virtual void   OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField * pRspRepea);
virtual void onRtnRepealFromFutureToBankByBank(const dict &data) {};


virtual void   OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField * pRspTransfe);
virtual void onRtnFromBankToFutureByFuture(const dict &data) {};


virtual void   OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField * pRspTransfe);
virtual void onRtnFromFutureToBankByFuture(const dict &data) {};


virtual void   OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField * pRspRepea);
virtual void onRtnRepealFromBankToFutureByFutureManual(const dict &data) {};


virtual void   OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField * pRspRepea);
virtual void onRtnRepealFromFutureToBankByFutureManual(const dict &data) {};


virtual void   OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField * pNotifyQueryAccoun);
virtual void onRtnQueryBankBalanceByFuture(const dict &data) {};


virtual void   OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField * pReqTransfer,CThostFtdcRspInfoField * pRspInf);
virtual void onErrRtnBankToFutureByFuture(const dict &data, const dict &error) {};


virtual void   OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField * pReqTransfer,CThostFtdcRspInfoField * pRspInf);
virtual void onErrRtnFutureToBankByFuture(const dict &data, const dict &error) {};


virtual void   OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField * pReqRepeal,CThostFtdcRspInfoField * pRspInf);
virtual void onErrRtnRepealBankToFutureByFutureManual(const dict &data, const dict &error) {};


virtual void   OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField * pReqRepeal,CThostFtdcRspInfoField * pRspInf);
virtual void onErrRtnRepealFutureToBankByFutureManual(const dict &data, const dict &error) {};


virtual void   OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField * pReqQueryAccount,CThostFtdcRspInfoField * pRspInf);
virtual void onErrRtnQueryBankBalanceByFuture(const dict &data, const dict &error) {};


virtual void   OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField * pRspRepea);
virtual void onRtnRepealFromBankToFutureByFuture(const dict &data) {};


virtual void   OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField * pRspRepea);
virtual void onRtnRepealFromFutureToBankByFuture(const dict &data) {};


virtual void   OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField * pReqTransfer,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspFromBankToFutureByFuture(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField * pReqTransfer,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspFromFutureToBankByFuture(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField * pReqQueryAccount,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQueryBankAccountMoneyByFuture(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRtnOpenAccountByBank(CThostFtdcOpenAccountField * pOpenAccoun);
virtual void onRtnOpenAccountByBank(const dict &data) {};


virtual void   OnRtnCancelAccountByBank(CThostFtdcCancelAccountField * pCancelAccoun);
virtual void onRtnCancelAccountByBank(const dict &data) {};


virtual void   OnRtnChangeAccountByBank(CThostFtdcChangeAccountField * pChangeAccoun);
virtual void onRtnChangeAccountByBank(const dict &data) {};


virtual void   OnRspQryClassifiedInstrument(CThostFtdcInstrumentField * pInstrument,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryClassifiedInstrument(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryCombPromotionParam(CThostFtdcCombPromotionParamField * pCombPromotionParam,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryCombPromotionParam(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryRiskSettleInvstPosition(CThostFtdcRiskSettleInvstPositionField * pRiskSettleInvstPosition,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryRiskSettleInvstPosition(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryRiskSettleProductStatus(CThostFtdcRiskSettleProductStatusField * pRiskSettleProductStatus,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryRiskSettleProductStatus(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQrySPBMFutureParameter(CThostFtdcSPBMFutureParameterField * pSPBMFutureParameter,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQrySPBMFutureParameter(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQrySPBMOptionParameter(CThostFtdcSPBMOptionParameterField * pSPBMOptionParameter,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQrySPBMOptionParameter(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQrySPBMIntraParameter(CThostFtdcSPBMIntraParameterField * pSPBMIntraParameter,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQrySPBMIntraParameter(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQrySPBMInterParameter(CThostFtdcSPBMInterParameterField * pSPBMInterParameter,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQrySPBMInterParameter(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQrySPBMPortfDefinition(CThostFtdcSPBMPortfDefinitionField * pSPBMPortfDefinition,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQrySPBMPortfDefinition(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQrySPBMInvestorPortfDef(CThostFtdcSPBMInvestorPortfDefField * pSPBMInvestorPortfDef,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQrySPBMInvestorPortfDef(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryInvestorPortfMarginRatio(CThostFtdcInvestorPortfMarginRatioField * pInvestorPortfMarginRatio,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryInvestorPortfMarginRatio(const dict &data, const dict &error, int reqid, bool last) {};


virtual void   OnRspQryInvestorProdSPBMDetail(CThostFtdcInvestorProdSPBMDetailField * pInvestorProdSPBMDetail,CThostFtdcRspInfoField * pRspInfo,int nRequestID,bool bIsLas);
virtual void onRspQryInvestorProdSPBMDetail(const dict &data, const dict &error, int reqid, bool last) {};

void processFrontConnected(Task *task);

void processFrontDisconnected(Task *task);

void processHeartBeatWarning(Task *task);

void processRspAuthenticate(Task *task);

void processRspUserLogin(Task *task);

void processRspUserLogout(Task *task);

void processRspUserPasswordUpdate(Task *task);

void processRspTradingAccountPasswordUpdate(Task *task);

void processRspUserAuthMethod(Task *task);

void processRspGenUserCaptcha(Task *task);

void processRspGenUserText(Task *task);

void processRspOrderInsert(Task *task);

void processRspParkedOrderInsert(Task *task);

void processRspParkedOrderAction(Task *task);

void processRspOrderAction(Task *task);

void processRspQryMaxOrderVolume(Task *task);

void processRspSettlementInfoConfirm(Task *task);

void processRspRemoveParkedOrder(Task *task);

void processRspRemoveParkedOrderAction(Task *task);

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

void processRspQryDepthMarketData(Task *task);

void processRspQryTraderOffer(Task *task);

void processRspQrySettlementInfo(Task *task);

void processRspQryTransferBank(Task *task);

void processRspQryInvestorPositionDetail(Task *task);

void processRspQryNotice(Task *task);

void processRspQrySettlementInfoConfirm(Task *task);

void processRspQryInvestorPositionCombineDetail(Task *task);

void processRspQryCFMMCTradingAccountKey(Task *task);

void processRspQryEWarrantOffset(Task *task);

void processRspQryInvestorProductGroupMargin(Task *task);

void processRspQryExchangeMarginRate(Task *task);

void processRspQryExchangeMarginRateAdjust(Task *task);

void processRspQryExchangeRate(Task *task);

void processRspQrySecAgentACIDMap(Task *task);

void processRspQryProductExchRate(Task *task);

void processRspQryProductGroup(Task *task);

void processRspQryMMInstrumentCommissionRate(Task *task);

void processRspQryMMOptionInstrCommRate(Task *task);

void processRspQryInstrumentOrderCommRate(Task *task);

void processRspQrySecAgentTradingAccount(Task *task);

void processRspQrySecAgentCheckMode(Task *task);

void processRspQrySecAgentTradeInfo(Task *task);

void processRspQryOptionInstrTradeCost(Task *task);

void processRspQryOptionInstrCommRate(Task *task);

void processRspQryExecOrder(Task *task);

void processRspQryForQuote(Task *task);

void processRspQryQuote(Task *task);

void processRspQryOptionSelfClose(Task *task);

void processRspQryInvestUnit(Task *task);

void processRspQryCombInstrumentGuard(Task *task);

void processRspQryCombAction(Task *task);

void processRspQryTransferSerial(Task *task);

void processRspQryAccountregister(Task *task);

void processRspError(Task *task);

void processRtnOrder(Task *task);

void processRtnTrade(Task *task);

void processErrRtnOrderInsert(Task *task);

void processErrRtnOrderAction(Task *task);

void processRtnInstrumentStatus(Task *task);

void processRtnBulletin(Task *task);

void processRtnTradingNotice(Task *task);

void processRtnErrorConditionalOrder(Task *task);

void processRtnExecOrder(Task *task);

void processErrRtnExecOrderInsert(Task *task);

void processErrRtnExecOrderAction(Task *task);

void processErrRtnForQuoteInsert(Task *task);

void processRtnQuote(Task *task);

void processErrRtnQuoteInsert(Task *task);

void processErrRtnQuoteAction(Task *task);

void processRtnForQuoteRsp(Task *task);

void processRtnCFMMCTradingAccountToken(Task *task);

void processErrRtnBatchOrderAction(Task *task);

void processRtnOptionSelfClose(Task *task);

void processErrRtnOptionSelfCloseInsert(Task *task);

void processErrRtnOptionSelfCloseAction(Task *task);

void processRtnCombAction(Task *task);

void processErrRtnCombActionInsert(Task *task);

void processRspQryContractBank(Task *task);

void processRspQryParkedOrder(Task *task);

void processRspQryParkedOrderAction(Task *task);

void processRspQryTradingNotice(Task *task);

void processRspQryBrokerTradingParams(Task *task);

void processRspQryBrokerTradingAlgos(Task *task);

void processRspQueryCFMMCTradingAccountToken(Task *task);

void processRtnFromBankToFutureByBank(Task *task);

void processRtnFromFutureToBankByBank(Task *task);

void processRtnRepealFromBankToFutureByBank(Task *task);

void processRtnRepealFromFutureToBankByBank(Task *task);

void processRtnFromBankToFutureByFuture(Task *task);

void processRtnFromFutureToBankByFuture(Task *task);

void processRtnRepealFromBankToFutureByFutureManual(Task *task);

void processRtnRepealFromFutureToBankByFutureManual(Task *task);

void processRtnQueryBankBalanceByFuture(Task *task);

void processErrRtnBankToFutureByFuture(Task *task);

void processErrRtnFutureToBankByFuture(Task *task);

void processErrRtnRepealBankToFutureByFutureManual(Task *task);

void processErrRtnRepealFutureToBankByFutureManual(Task *task);

void processErrRtnQueryBankBalanceByFuture(Task *task);

void processRtnRepealFromBankToFutureByFuture(Task *task);

void processRtnRepealFromFutureToBankByFuture(Task *task);

void processRspFromBankToFutureByFuture(Task *task);

void processRspFromFutureToBankByFuture(Task *task);

void processRspQueryBankAccountMoneyByFuture(Task *task);

void processRtnOpenAccountByBank(Task *task);

void processRtnCancelAccountByBank(Task *task);

void processRtnChangeAccountByBank(Task *task);

void processRspQryClassifiedInstrument(Task *task);

void processRspQryCombPromotionParam(Task *task);

void processRspQryRiskSettleInvstPosition(Task *task);

void processRspQryRiskSettleProductStatus(Task *task);

void processRspQrySPBMFutureParameter(Task *task);

void processRspQrySPBMOptionParameter(Task *task);

void processRspQrySPBMIntraParameter(Task *task);

void processRspQrySPBMInterParameter(Task *task);

void processRspQrySPBMPortfDefinition(Task *task);

void processRspQrySPBMInvestorPortfDef(Task *task);

void processRspQryInvestorPortfMarginRatio(Task *task);

void processRspQryInvestorProdSPBMDetail(Task *task);

int reqAuthenticate(const dict &req, int reqid);

int reqUserLogin(const dict &req, int reqid);

int reqUserLogout(const dict &req, int reqid);

int reqUserPasswordUpdate(const dict &req, int reqid);

int reqTradingAccountPasswordUpdate(const dict &req, int reqid);

int reqUserAuthMethod(const dict &req, int reqid);

int reqGenUserCaptcha(const dict &req, int reqid);

int reqGenUserText(const dict &req, int reqid);

int reqUserLoginWithCaptcha(const dict &req, int reqid);

int reqUserLoginWithText(const dict &req, int reqid);

int reqUserLoginWithOTP(const dict &req, int reqid);

int reqOrderInsert(const dict &req, int reqid);

int reqParkedOrderInsert(const dict &req, int reqid);

int reqParkedOrderAction(const dict &req, int reqid);

int reqOrderAction(const dict &req, int reqid);

int reqQryMaxOrderVolume(const dict &req, int reqid);

int reqSettlementInfoConfirm(const dict &req, int reqid);

int reqRemoveParkedOrder(const dict &req, int reqid);

int reqRemoveParkedOrderAction(const dict &req, int reqid);

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

int reqQryDepthMarketData(const dict &req, int reqid);

int reqQryTraderOffer(const dict &req, int reqid);

int reqQrySettlementInfo(const dict &req, int reqid);

int reqQryTransferBank(const dict &req, int reqid);

int reqQryInvestorPositionDetail(const dict &req, int reqid);

int reqQryNotice(const dict &req, int reqid);

int reqQrySettlementInfoConfirm(const dict &req, int reqid);

int reqQryInvestorPositionCombineDetail(const dict &req, int reqid);

int reqQryCFMMCTradingAccountKey(const dict &req, int reqid);

int reqQryEWarrantOffset(const dict &req, int reqid);

int reqQryInvestorProductGroupMargin(const dict &req, int reqid);

int reqQryExchangeMarginRate(const dict &req, int reqid);

int reqQryExchangeMarginRateAdjust(const dict &req, int reqid);

int reqQryExchangeRate(const dict &req, int reqid);

int reqQrySecAgentACIDMap(const dict &req, int reqid);

int reqQryProductExchRate(const dict &req, int reqid);

int reqQryProductGroup(const dict &req, int reqid);

int reqQryMMInstrumentCommissionRate(const dict &req, int reqid);

int reqQryMMOptionInstrCommRate(const dict &req, int reqid);

int reqQryInstrumentOrderCommRate(const dict &req, int reqid);

int reqQrySecAgentTradingAccount(const dict &req, int reqid);

int reqQrySecAgentCheckMode(const dict &req, int reqid);

int reqQrySecAgentTradeInfo(const dict &req, int reqid);

int reqQryOptionInstrTradeCost(const dict &req, int reqid);

int reqQryOptionInstrCommRate(const dict &req, int reqid);

int reqQryExecOrder(const dict &req, int reqid);

int reqQryForQuote(const dict &req, int reqid);

int reqQryQuote(const dict &req, int reqid);

int reqQryOptionSelfClose(const dict &req, int reqid);

int reqQryInvestUnit(const dict &req, int reqid);

int reqQryCombInstrumentGuard(const dict &req, int reqid);

int reqQryCombAction(const dict &req, int reqid);

int reqQryTransferSerial(const dict &req, int reqid);

int reqQryAccountregister(const dict &req, int reqid);

int reqQryContractBank(const dict &req, int reqid);

int reqQryParkedOrder(const dict &req, int reqid);

int reqQryParkedOrderAction(const dict &req, int reqid);

int reqQryTradingNotice(const dict &req, int reqid);

int reqQryBrokerTradingParams(const dict &req, int reqid);

int reqQryBrokerTradingAlgos(const dict &req, int reqid);

int reqQueryCFMMCTradingAccountToken(const dict &req, int reqid);

int reqFromBankToFutureByFuture(const dict &req, int reqid);

int reqFromFutureToBankByFuture(const dict &req, int reqid);

int reqQueryBankAccountMoneyByFuture(const dict &req, int reqid);

int reqQryClassifiedInstrument(const dict &req, int reqid);

int reqQryCombPromotionParam(const dict &req, int reqid);

int reqQryRiskSettleInvstPosition(const dict &req, int reqid);

int reqQryRiskSettleProductStatus(const dict &req, int reqid);

int reqQrySPBMFutureParameter(const dict &req, int reqid);

int reqQrySPBMOptionParameter(const dict &req, int reqid);

int reqQrySPBMIntraParameter(const dict &req, int reqid);

int reqQrySPBMInterParameter(const dict &req, int reqid);

int reqQrySPBMPortfDefinition(const dict &req, int reqid);

int reqQrySPBMInvestorPortfDef(const dict &req, int reqid);

int reqQryInvestorPortfMarginRatio(const dict &req, int reqid);

int reqQryInvestorProdSPBMDetail(const dict &req, int reqid);


};