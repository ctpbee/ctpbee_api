int TdApi::reqAuthenticate(const dict &req, int reqid)
{
	CThostFtdcReqAuthenticateField myreq = CThostFtdcReqAuthenticateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "UserProductInfo", myreq.UserProductInfo);
	getString(req, "AuthCode", myreq.AuthCode);
	getString(req, "AppID", myreq.AppID);
	int i = this->api->ReqAuthenticate(&myreq, reqid);
	return i;
};

int TdApi::reqUserLogin(const dict &req, int reqid)
{
	CThostFtdcReqUserLoginField myreq = CThostFtdcReqUserLoginField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TradingDay", myreq.TradingDay);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "Password", myreq.Password);
	getString(req, "UserProductInfo", myreq.UserProductInfo);
	getString(req, "InterfaceProductInfo", myreq.InterfaceProductInfo);
	getString(req, "ProtocolInfo", myreq.ProtocolInfo);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "OneTimePassword", myreq.OneTimePassword);
	getString(req, "ClientIPAddress", myreq.ClientIPAddress);
	getString(req, "LoginRemark", myreq.LoginRemark);
	int i = this->api->ReqUserLogin(&myreq, reqid);
	return i;
};

int TdApi::reqUserLoginEncrypt(const dict &req, int reqid)
{
	CThostFtdcReqUserLoginField myreq = CThostFtdcReqUserLoginField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TradingDay", myreq.TradingDay);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "Password", myreq.Password);
	getString(req, "UserProductInfo", myreq.UserProductInfo);
	getString(req, "InterfaceProductInfo", myreq.InterfaceProductInfo);
	getString(req, "ProtocolInfo", myreq.ProtocolInfo);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "OneTimePassword", myreq.OneTimePassword);
	getString(req, "ClientIPAddress", myreq.ClientIPAddress);
	getString(req, "LoginRemark", myreq.LoginRemark);
	int i = this->api->ReqUserLoginEncrypt(&myreq, reqid);
	return i;
};

int TdApi::reqUserLogout(const dict &req, int reqid)
{
	CThostFtdcUserLogoutField myreq = CThostFtdcUserLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "UserID", myreq.UserID);
	int i = this->api->ReqUserLogout(&myreq, reqid);
	return i;
};

int TdApi::reqOrderInsert(const dict &req, int reqid)
{
	CThostFtdcInputOrderField myreq = CThostFtdcInputOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "OrderRef", myreq.OrderRef);
	getString(req, "UserID", myreq.UserID);
	getChar(req, "OrderPriceType", &myreq.OrderPriceType);
	getChar(req, "Direction", &myreq.Direction);
	getString(req, "CombOffsetFlag", myreq.CombOffsetFlag);
	getString(req, "CombHedgeFlag", myreq.CombHedgeFlag);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	getInt(req, "VolumeTotalOriginal", &myreq.VolumeTotalOriginal);
	getChar(req, "TimeCondition", &myreq.TimeCondition);
	getString(req, "GTDDate", myreq.GTDDate);
	getChar(req, "VolumeCondition", &myreq.VolumeCondition);
	getInt(req, "MinVolume", &myreq.MinVolume);
	getChar(req, "ContingentCondition", &myreq.ContingentCondition);
	getDouble(req, "StopPrice", &myreq.StopPrice);
	getChar(req, "ForceCloseReason", &myreq.ForceCloseReason);
	getInt(req, "IsAutoSuspend", &myreq.IsAutoSuspend);
	getString(req, "BusinessUnit", myreq.BusinessUnit);
	getInt(req, "RequestID", &myreq.RequestID);
	getInt(req, "UserForceClose", &myreq.UserForceClose);
	getInt(req, "IsSwapOrder", &myreq.IsSwapOrder);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	getString(req, "ClientID", myreq.ClientID);
	getString(req, "IPAddress", myreq.IPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	int i = this->api->ReqOrderInsert(&myreq, reqid);
	return i;
};

int TdApi::reqOrderAction(const dict &req, int reqid)
{
	CThostFtdcInputOrderActionField myreq = CThostFtdcInputOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getInt(req, "OrderActionRef", &myreq.OrderActionRef);
	getString(req, "OrderRef", myreq.OrderRef);
	getInt(req, "RequestID", &myreq.RequestID);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getChar(req, "ActionFlag", &myreq.ActionFlag);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	getInt(req, "VolumeChange", &myreq.VolumeChange);
	getString(req, "UserID", myreq.UserID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "IPAddress", myreq.IPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	int i = this->api->ReqOrderAction(&myreq, reqid);
	return i;
};

int TdApi::reqExecOrderInsert(const dict &req, int reqid)
{
	CThostFtdcInputExecOrderField myreq = CThostFtdcInputExecOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "ExecOrderRef", myreq.ExecOrderRef);
	getString(req, "UserID", myreq.UserID);
	getInt(req, "Volume", &myreq.Volume);
	getInt(req, "RequestID", &myreq.RequestID);
	getString(req, "BusinessUnit", myreq.BusinessUnit);
	getChar(req, "OffsetFlag", &myreq.OffsetFlag);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getChar(req, "ActionType", &myreq.ActionType);
	getChar(req, "PosiDirection", &myreq.PosiDirection);
	getChar(req, "ReservePositionFlag", &myreq.ReservePositionFlag);
	getChar(req, "CloseFlag", &myreq.CloseFlag);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	getString(req, "ClientID", myreq.ClientID);
	getString(req, "IPAddress", myreq.IPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	int i = this->api->ReqExecOrderInsert(&myreq, reqid);
	return i;
};

int TdApi::reqExecOrderAction(const dict &req, int reqid)
{
	CThostFtdcInputExecOrderActionField myreq = CThostFtdcInputExecOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getInt(req, "ExecOrderActionRef", &myreq.ExecOrderActionRef);
	getString(req, "ExecOrderRef", myreq.ExecOrderRef);
	getInt(req, "RequestID", &myreq.RequestID);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ExecOrderSysID", myreq.ExecOrderSysID);
	getChar(req, "ActionFlag", &myreq.ActionFlag);
	getString(req, "UserID", myreq.UserID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "IPAddress", myreq.IPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	int i = this->api->ReqExecOrderAction(&myreq, reqid);
	return i;
};

int TdApi::reqForQuoteInsert(const dict &req, int reqid)
{
	CThostFtdcInputForQuoteField myreq = CThostFtdcInputForQuoteField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "ForQuoteRef", myreq.ForQuoteRef);
	getString(req, "UserID", myreq.UserID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "IPAddress", myreq.IPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "BusinessUnit", myreq.BusinessUnit);
	int i = this->api->ReqForQuoteInsert(&myreq, reqid);
	return i;
};

int TdApi::reqQuoteInsert(const dict &req, int reqid)
{
	CThostFtdcInputQuoteField myreq = CThostFtdcInputQuoteField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "QuoteRef", myreq.QuoteRef);
	getString(req, "UserID", myreq.UserID);
	getDouble(req, "AskPrice", &myreq.AskPrice);
	getDouble(req, "BidPrice", &myreq.BidPrice);
	getInt(req, "AskVolume", &myreq.AskVolume);
	getInt(req, "BidVolume", &myreq.BidVolume);
	getInt(req, "RequestID", &myreq.RequestID);
	getString(req, "BusinessUnit", myreq.BusinessUnit);
	getChar(req, "AskOffsetFlag", &myreq.AskOffsetFlag);
	getChar(req, "BidOffsetFlag", &myreq.BidOffsetFlag);
	getChar(req, "AskHedgeFlag", &myreq.AskHedgeFlag);
	getChar(req, "BidHedgeFlag", &myreq.BidHedgeFlag);
	getString(req, "AskOrderRef", myreq.AskOrderRef);
	getString(req, "BidOrderRef", myreq.BidOrderRef);
	getString(req, "ForQuoteSysID", myreq.ForQuoteSysID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "ClientID", myreq.ClientID);
	getString(req, "IPAddress", myreq.IPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "ReplaceSysID", myreq.ReplaceSysID);
	int i = this->api->ReqQuoteInsert(&myreq, reqid);
	return i;
};

int TdApi::reqQuoteAction(const dict &req, int reqid)
{
	CThostFtdcInputQuoteActionField myreq = CThostFtdcInputQuoteActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getInt(req, "QuoteActionRef", &myreq.QuoteActionRef);
	getString(req, "QuoteRef", myreq.QuoteRef);
	getInt(req, "RequestID", &myreq.RequestID);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "QuoteSysID", myreq.QuoteSysID);
	getChar(req, "ActionFlag", &myreq.ActionFlag);
	getString(req, "UserID", myreq.UserID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "ClientID", myreq.ClientID);
	getString(req, "IPAddress", myreq.IPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	int i = this->api->ReqQuoteAction(&myreq, reqid);
	return i;
};

int TdApi::reqBatchOrderAction(const dict &req, int reqid)
{
	CThostFtdcInputBatchOrderActionField myreq = CThostFtdcInputBatchOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getInt(req, "OrderActionRef", &myreq.OrderActionRef);
	getInt(req, "RequestID", &myreq.RequestID);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "IPAddress", myreq.IPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	int i = this->api->ReqBatchOrderAction(&myreq, reqid);
	return i;
};

int TdApi::reqOptionSelfCloseInsert(const dict &req, int reqid)
{
	CThostFtdcInputOptionSelfCloseField myreq = CThostFtdcInputOptionSelfCloseField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "OptionSelfCloseRef", myreq.OptionSelfCloseRef);
	getString(req, "UserID", myreq.UserID);
	getInt(req, "Volume", &myreq.Volume);
	getInt(req, "RequestID", &myreq.RequestID);
	getString(req, "BusinessUnit", myreq.BusinessUnit);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getChar(req, "OptSelfCloseFlag", &myreq.OptSelfCloseFlag);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	getString(req, "ClientID", myreq.ClientID);
	getString(req, "IPAddress", myreq.IPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	int i = this->api->ReqOptionSelfCloseInsert(&myreq, reqid);
	return i;
};

int TdApi::reqOptionSelfCloseAction(const dict &req, int reqid)
{
	CThostFtdcInputOptionSelfCloseActionField myreq = CThostFtdcInputOptionSelfCloseActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getInt(req, "OptionSelfCloseActionRef", &myreq.OptionSelfCloseActionRef);
	getString(req, "OptionSelfCloseRef", myreq.OptionSelfCloseRef);
	getInt(req, "RequestID", &myreq.RequestID);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "OptionSelfCloseSysID", myreq.OptionSelfCloseSysID);
	getChar(req, "ActionFlag", &myreq.ActionFlag);
	getString(req, "UserID", myreq.UserID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "IPAddress", myreq.IPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	int i = this->api->ReqOptionSelfCloseAction(&myreq, reqid);
	return i;
};

int TdApi::reqCombActionInsert(const dict &req, int reqid)
{
	CThostFtdcInputCombActionField myreq = CThostFtdcInputCombActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "CombActionRef", myreq.CombActionRef);
	getString(req, "UserID", myreq.UserID);
	getChar(req, "Direction", &myreq.Direction);
	getInt(req, "Volume", &myreq.Volume);
	getChar(req, "CombDirection", &myreq.CombDirection);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getString(req, "BusinessUnit", myreq.BusinessUnit);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "IPAddress", myreq.IPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	int i = this->api->ReqCombActionInsert(&myreq, reqid);
	return i;
};

int TdApi::reqQryOrder(const dict &req, int reqid)
{
	CThostFtdcQryOrderField myreq = CThostFtdcQryOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	int i = this->api->ReqQryOrder(&myreq, reqid);
	return i;
};

int TdApi::reqQryTrade(const dict &req, int reqid)
{
	CThostFtdcQryTradeField myreq = CThostFtdcQryTradeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "TradeID", myreq.TradeID);
	getString(req, "TradeTimeStart", myreq.TradeTimeStart);
	getString(req, "TradeTimeEnd", myreq.TradeTimeEnd);
	int i = this->api->ReqQryTrade(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestorPosition(const dict &req, int reqid)
{
	CThostFtdcQryInvestorPositionField myreq = CThostFtdcQryInvestorPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryInvestorPosition(&myreq, reqid);
	return i;
};

int TdApi::reqQryTradingAccount(const dict &req, int reqid)
{
	CThostFtdcQryTradingAccountField myreq = CThostFtdcQryTradingAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	int i = this->api->ReqQryTradingAccount(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestor(const dict &req, int reqid)
{
	CThostFtdcQryInvestorField myreq = CThostFtdcQryInvestorField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryInvestor(&myreq, reqid);
	return i;
};

int TdApi::reqQryTradingCode(const dict &req, int reqid)
{
	CThostFtdcQryTradingCodeField myreq = CThostFtdcQryTradingCodeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ClientID", myreq.ClientID);
	getChar(req, "ClientIDType", &myreq.ClientIDType);
	int i = this->api->ReqQryTradingCode(&myreq, reqid);
	return i;
};

int TdApi::reqQryInstrumentMarginRate(const dict &req, int reqid)
{
	CThostFtdcQryInstrumentMarginRateField myreq = CThostFtdcQryInstrumentMarginRateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	int i = this->api->ReqQryInstrumentMarginRate(&myreq, reqid);
	return i;
};

int TdApi::reqQryInstrumentCommissionRate(const dict &req, int reqid)
{
	CThostFtdcQryInstrumentCommissionRateField myreq = CThostFtdcQryInstrumentCommissionRateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryInstrumentCommissionRate(&myreq, reqid);
	return i;
};

int TdApi::reqQryExchange(const dict &req, int reqid)
{
	CThostFtdcQryExchangeField myreq = CThostFtdcQryExchangeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	int i = this->api->ReqQryExchange(&myreq, reqid);
	return i;
};

int TdApi::reqQryProduct(const dict &req, int reqid)
{
	CThostFtdcQryProductField myreq = CThostFtdcQryProductField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ProductID", myreq.ProductID);
	getChar(req, "ProductClass", &myreq.ProductClass);
	int i = this->api->ReqQryProduct(&myreq, reqid);
	return i;
};

int TdApi::reqQryInstrument(const dict &req, int reqid)
{
	CThostFtdcQryInstrumentField myreq = CThostFtdcQryInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ExchangeInstID", myreq.ExchangeInstID);
	getString(req, "ProductID", myreq.ProductID);
	int i = this->api->ReqQryInstrument(&myreq, reqid);
	return i;
};

int TdApi::reqQryCombInstrument(const dict &req, int reqid)
{
	CThostFtdcQryCombInstrumentField myreq = CThostFtdcQryCombInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ProductID", myreq.ProductID);
	int i = this->api->ReqQryCombInstrument(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestorPositionForComb(const dict &req, int reqid)
{
	CThostFtdcQryInvestorPositionForCombField myreq = CThostFtdcQryInvestorPositionForCombField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "LegInstrumentID", myreq.LegInstrumentID);
	int i = this->api->ReqQryInvestorPositionForComb(&myreq, reqid);
	return i;
};

int TdApi::reqQryCombAction(const dict &req, int reqid)
{
	CThostFtdcQryCombActionField myreq = CThostFtdcQryCombActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	int i = this->api->ReqQryCombAction(&myreq, reqid);
	return i;
};

int TdApi::reqQryDepthMarketData(const dict &req, int reqid)
{
	CThostFtdcQryDepthMarketDataField myreq = CThostFtdcQryDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryDepthMarketData(&myreq, reqid);
	return i;
};

int TdApi::reqQryOptionSelfClose(const dict &req, int reqid)
{
	CThostFtdcQryOptionSelfCloseField myreq = CThostFtdcQryOptionSelfCloseField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "OptionSelfCloseSysID", myreq.OptionSelfCloseSysID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	int i = this->api->ReqQryOptionSelfClose(&myreq, reqid);
	return i;
};

int TdApi::reqQryInstrumentStatus(const dict &req, int reqid)
{
	CThostFtdcQryInstrumentStatusField myreq = CThostFtdcQryInstrumentStatusField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ExchangeInstID", myreq.ExchangeInstID);
	int i = this->api->ReqQryInstrumentStatus(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestorPositionDetail(const dict &req, int reqid)
{
	CThostFtdcQryInvestorPositionDetailField myreq = CThostFtdcQryInvestorPositionDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryInvestorPositionDetail(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestorPositionCombineDetail(const dict &req, int reqid)
{
	CThostFtdcQryInvestorPositionCombineDetailField myreq = CThostFtdcQryInvestorPositionCombineDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "CombInstrumentID", myreq.CombInstrumentID);
	int i = this->api->ReqQryInvestorPositionCombineDetail(&myreq, reqid);
	return i;
};

int TdApi::reqQryExchangeMarginRate(const dict &req, int reqid)
{
	CThostFtdcQryExchangeMarginRateField myreq = CThostFtdcQryExchangeMarginRateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	int i = this->api->ReqQryExchangeMarginRate(&myreq, reqid);
	return i;
};

int TdApi::reqQryExchangeMarginRateAdjust(const dict &req, int reqid)
{
	CThostFtdcQryExchangeMarginRateAdjustField myreq = CThostFtdcQryExchangeMarginRateAdjustField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	int i = this->api->ReqQryExchangeMarginRateAdjust(&myreq, reqid);
	return i;
};

int TdApi::reqQryOptionInstrTradeCost(const dict &req, int reqid)
{
	CThostFtdcQryOptionInstrTradeCostField myreq = CThostFtdcQryOptionInstrTradeCostField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getDouble(req, "InputPrice", &myreq.InputPrice);
	getDouble(req, "UnderlyingPrice", &myreq.UnderlyingPrice);
	int i = this->api->ReqQryOptionInstrTradeCost(&myreq, reqid);
	return i;
};

int TdApi::reqQryOptionInstrCommRate(const dict &req, int reqid)
{
	CThostFtdcQryOptionInstrCommRateField myreq = CThostFtdcQryOptionInstrCommRateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryOptionInstrCommRate(&myreq, reqid);
	return i;
};

int TdApi::reqQryExecOrder(const dict &req, int reqid)
{
	CThostFtdcQryExecOrderField myreq = CThostFtdcQryExecOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ExecOrderSysID", myreq.ExecOrderSysID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	int i = this->api->ReqQryExecOrder(&myreq, reqid);
	return i;
};

int TdApi::reqQryForQuote(const dict &req, int reqid)
{
	CThostFtdcQryForQuoteField myreq = CThostFtdcQryForQuoteField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	int i = this->api->ReqQryForQuote(&myreq, reqid);
	return i;
};

int TdApi::reqQryQuote(const dict &req, int reqid)
{
	CThostFtdcQryQuoteField myreq = CThostFtdcQryQuoteField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "QuoteSysID", myreq.QuoteSysID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	int i = this->api->ReqQryQuote(&myreq, reqid);
	return i;
};

int TdApi::reqQryInstrumentOrderCommRate(const dict &req, int reqid)
{
	CThostFtdcQryInstrumentOrderCommRateField myreq = CThostFtdcQryInstrumentOrderCommRateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	int i = this->api->ReqQryInstrumentOrderCommRate(&myreq, reqid);
	return i;
};

