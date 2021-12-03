case ONFRONTCONNECTED:
{
	this->processFrontConnected(&task);
	break;
}

case ONFRONTDISCONNECTED:
{
	this->processFrontDisconnected(&task);
	break;
}

case ONHEARTBEATWARNING:
{
	this->processHeartBeatWarning(&task);
	break;
}

case ONRSPAUTHENTICATE:
{
	this->processRspAuthenticate(&task);
	break;
}

case ONRSPUSERLOGIN:
{
	this->processRspUserLogin(&task);
	break;
}

case ONRSPUSERLOGOUT:
{
	this->processRspUserLogout(&task);
	break;
}

case ONRSPORDERINSERT:
{
	this->processRspOrderInsert(&task);
	break;
}

case ONRSPORDERACTION:
{
	this->processRspOrderAction(&task);
	break;
}

case ONRSPEXECORDERINSERT:
{
	this->processRspExecOrderInsert(&task);
	break;
}

case ONRSPEXECORDERACTION:
{
	this->processRspExecOrderAction(&task);
	break;
}

case ONRSPFORQUOTEINSERT:
{
	this->processRspForQuoteInsert(&task);
	break;
}

case ONRSPQUOTEINSERT:
{
	this->processRspQuoteInsert(&task);
	break;
}

case ONRSPQUOTEACTION:
{
	this->processRspQuoteAction(&task);
	break;
}

case ONRSPBATCHORDERACTION:
{
	this->processRspBatchOrderAction(&task);
	break;
}

case ONRSPOPTIONSELFCLOSEINSERT:
{
	this->processRspOptionSelfCloseInsert(&task);
	break;
}

case ONRSPOPTIONSELFCLOSEACTION:
{
	this->processRspOptionSelfCloseAction(&task);
	break;
}

case ONRSPCOMBACTIONINSERT:
{
	this->processRspCombActionInsert(&task);
	break;
}

case ONRSPQRYORDER:
{
	this->processRspQryOrder(&task);
	break;
}

case ONRSPQRYTRADE:
{
	this->processRspQryTrade(&task);
	break;
}

case ONRSPQRYINVESTORPOSITION:
{
	this->processRspQryInvestorPosition(&task);
	break;
}

case ONRSPQRYTRADINGACCOUNT:
{
	this->processRspQryTradingAccount(&task);
	break;
}

case ONRSPQRYINVESTOR:
{
	this->processRspQryInvestor(&task);
	break;
}

case ONRSPQRYTRADINGCODE:
{
	this->processRspQryTradingCode(&task);
	break;
}

case ONRSPQRYINSTRUMENTMARGINRATE:
{
	this->processRspQryInstrumentMarginRate(&task);
	break;
}

case ONRSPQRYINSTRUMENTCOMMISSIONRATE:
{
	this->processRspQryInstrumentCommissionRate(&task);
	break;
}

case ONRSPQRYEXCHANGE:
{
	this->processRspQryExchange(&task);
	break;
}

case ONRSPQRYPRODUCT:
{
	this->processRspQryProduct(&task);
	break;
}

case ONRSPQRYINSTRUMENT:
{
	this->processRspQryInstrument(&task);
	break;
}

case ONRSPQRYCOMBINSTRUMENT:
{
	this->processRspQryCombInstrument(&task);
	break;
}

case ONRSPQRYCOMBACTION:
{
	this->processRspQryCombAction(&task);
	break;
}

case ONRSPQRYINVESTORPOSITIONFORCOMB:
{
	this->processRspQryInvestorPositionForComb(&task);
	break;
}

case ONRSPQRYDEPTHMARKETDATA:
{
	this->processRspQryDepthMarketData(&task);
	break;
}

case ONRSPQRYINSTRUMENTSTATUS:
{
	this->processRspQryInstrumentStatus(&task);
	break;
}

case ONRSPQRYINVESTORPOSITIONDETAIL:
{
	this->processRspQryInvestorPositionDetail(&task);
	break;
}

case ONRSPQRYINVESTORPOSITIONCOMBINEDETAIL:
{
	this->processRspQryInvestorPositionCombineDetail(&task);
	break;
}

case ONRSPQRYEXCHANGEMARGINRATE:
{
	this->processRspQryExchangeMarginRate(&task);
	break;
}

case ONRSPQRYEXCHANGEMARGINRATEADJUST:
{
	this->processRspQryExchangeMarginRateAdjust(&task);
	break;
}

case ONRSPQRYOPTIONINSTRTRADECOST:
{
	this->processRspQryOptionInstrTradeCost(&task);
	break;
}

case ONRSPQRYOPTIONINSTRCOMMRATE:
{
	this->processRspQryOptionInstrCommRate(&task);
	break;
}

case ONRSPQRYEXECORDER:
{
	this->processRspQryExecOrder(&task);
	break;
}

case ONRSPQRYFORQUOTE:
{
	this->processRspQryForQuote(&task);
	break;
}

case ONRSPQRYQUOTE:
{
	this->processRspQryQuote(&task);
	break;
}

case ONRSPQRYOPTIONSELFCLOSE:
{
	this->processRspQryOptionSelfClose(&task);
	break;
}

case ONRSPERROR:
{
	this->processRspError(&task);
	break;
}

case ONRTNORDER:
{
	this->processRtnOrder(&task);
	break;
}

case ONRTNTRADE:
{
	this->processRtnTrade(&task);
	break;
}

case ONERRRTNORDERINSERT:
{
	this->processErrRtnOrderInsert(&task);
	break;
}

case ONERRRTNORDERACTION:
{
	this->processErrRtnOrderAction(&task);
	break;
}

case ONRTNINSTRUMENTSTATUS:
{
	this->processRtnInstrumentStatus(&task);
	break;
}

case ONRTNEXECORDER:
{
	this->processRtnExecOrder(&task);
	break;
}

case ONERRRTNEXECORDERINSERT:
{
	this->processErrRtnExecOrderInsert(&task);
	break;
}

case ONERRRTNEXECORDERACTION:
{
	this->processErrRtnExecOrderAction(&task);
	break;
}

case ONERRRTNFORQUOTEINSERT:
{
	this->processErrRtnForQuoteInsert(&task);
	break;
}

case ONRTNQUOTE:
{
	this->processRtnQuote(&task);
	break;
}

case ONERRRTNQUOTEINSERT:
{
	this->processErrRtnQuoteInsert(&task);
	break;
}

case ONERRRTNQUOTEACTION:
{
	this->processErrRtnQuoteAction(&task);
	break;
}

case ONRTNFORQUOTERSP:
{
	this->processRtnForQuoteRsp(&task);
	break;
}

case ONERRRTNBATCHORDERACTION:
{
	this->processErrRtnBatchOrderAction(&task);
	break;
}

case ONRTNOPTIONSELFCLOSE:
{
	this->processRtnOptionSelfClose(&task);
	break;
}

case ONERRRTNOPTIONSELFCLOSEINSERT:
{
	this->processErrRtnOptionSelfCloseInsert(&task);
	break;
}

case ONERRRTNOPTIONSELFCLOSEACTION:
{
	this->processErrRtnOptionSelfCloseAction(&task);
	break;
}

case ONRTNCOMBACTION:
{
	this->processRtnCombAction(&task);
	break;
}

case ONRSPQRYINSTRUMENTORDERCOMMRATE:
{
	this->processRspQryInstrumentOrderCommRate(&task);
	break;
}

