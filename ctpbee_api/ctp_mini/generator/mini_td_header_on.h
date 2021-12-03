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

