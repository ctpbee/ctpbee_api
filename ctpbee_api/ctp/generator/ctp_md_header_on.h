
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

