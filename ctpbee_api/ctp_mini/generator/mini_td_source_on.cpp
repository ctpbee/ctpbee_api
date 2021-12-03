void onFrontConnected() override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onFrontConnected);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onFrontDisconnected(int reqid) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onFrontDisconnected, reqid);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onHeartBeatWarning(int reqid) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onHeartBeatWarning, reqid);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspAuthenticate(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspAuthenticate, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUserLogin(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspUserLogin, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUserLogout(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspUserLogout, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOrderInsert(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspOrderInsert, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOrderAction(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspOrderAction, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspExecOrderInsert(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspExecOrderInsert, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspExecOrderAction(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspExecOrderAction, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspForQuoteInsert(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspForQuoteInsert, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQuoteInsert(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQuoteInsert, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQuoteAction(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQuoteAction, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspBatchOrderAction(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspBatchOrderAction, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOptionSelfCloseInsert(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspOptionSelfCloseInsert, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOptionSelfCloseAction(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspOptionSelfCloseAction, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspCombActionInsert(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspCombActionInsert, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryOrder(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryOrder, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryTrade(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryTrade, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryInvestorPosition(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryInvestorPosition, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryTradingAccount(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryTradingAccount, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryInvestor(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryInvestor, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryTradingCode(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryTradingCode, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryInstrumentMarginRate(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryInstrumentMarginRate, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryInstrumentCommissionRate(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryInstrumentCommissionRate, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryExchange(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryExchange, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryProduct(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryProduct, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryInstrument(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryInstrument, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryCombInstrument(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryCombInstrument, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryCombAction(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryCombAction, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryInvestorPositionForComb(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryInvestorPositionForComb, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryDepthMarketData(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryDepthMarketData, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryInstrumentStatus(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryInstrumentStatus, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryInvestorPositionDetail(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryInvestorPositionDetail, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryInvestorPositionCombineDetail(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryInvestorPositionCombineDetail, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryExchangeMarginRate(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryExchangeMarginRate, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryExchangeMarginRateAdjust(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryExchangeMarginRateAdjust, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryOptionInstrTradeCost(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryOptionInstrTradeCost, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryOptionInstrCommRate(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryOptionInstrCommRate, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryExecOrder(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryExecOrder, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryForQuote(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryForQuote, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryQuote(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryQuote, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryOptionSelfClose(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryOptionSelfClose, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspError(const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspError, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnOrder(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnOrder, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnTrade(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnTrade, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnOrderInsert(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onErrRtnOrderInsert, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnOrderAction(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onErrRtnOrderAction, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnInstrumentStatus(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnInstrumentStatus, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnExecOrder(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnExecOrder, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnExecOrderInsert(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onErrRtnExecOrderInsert, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnExecOrderAction(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onErrRtnExecOrderAction, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnForQuoteInsert(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onErrRtnForQuoteInsert, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnQuote(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnQuote, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnQuoteInsert(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onErrRtnQuoteInsert, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnQuoteAction(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onErrRtnQuoteAction, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnForQuoteRsp(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnForQuoteRsp, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnBatchOrderAction(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onErrRtnBatchOrderAction, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnOptionSelfClose(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnOptionSelfClose, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnOptionSelfCloseInsert(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onErrRtnOptionSelfCloseInsert, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onErrRtnOptionSelfCloseAction(const dict &data, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onErrRtnOptionSelfCloseAction, data, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnCombAction(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnCombAction, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryInstrumentOrderCommRate(const dict &data, const dict &error, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryInstrumentOrderCommRate, data, error, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

