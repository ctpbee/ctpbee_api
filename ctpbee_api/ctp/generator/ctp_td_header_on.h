
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

