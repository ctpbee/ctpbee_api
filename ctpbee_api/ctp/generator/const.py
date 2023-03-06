MD_H_BACK = """
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
"""

MD_H_HEADER = """//系统
#ifdef WIN32
#include "stdafx.h"
#endif
#include "vnctp.h"
#include "pybind11/pybind11.h"
#include "ctp/ThostFtdcMdApi.h"
"""

MD_H_API = """
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
"""

MD_C_HEADER = """
#include "vnctpmd.h"
void MdApi::createFtdcMdApi(string pszFlowPath)
{
	this->api = CThostFtdcMdApi::CreateFtdcMdApi(pszFlowPath.c_str());
	this->api->RegisterSpi(this);
};
void MdApi::release()
{
	this->api->Release();
};
void MdApi::init()
{
	this->active = true;
	this->task_thread = thread(&MdApi::processTask, this);
	this->api->Init();
};
int MdApi::join()
{
	int i = this->api->Join();
	return i;
};
int MdApi::exit()
{
	this->active = false;
    this->task_queue.terminate();
    this->task_thread.join();
	this->api->RegisterSpi(NULL);
	this->api->Release();
	this->api = NULL;
	return 1;
};
string MdApi::getTradingDay()
{
	string day = this->api->GetTradingDay();
	return day;
};
void MdApi::registerFront(string pszFrontAddress)
{
	this->api->RegisterFront((char*)pszFrontAddress.c_str());
};
int MdApi::subscribeMarketData(string instrumentID)
{
	char* buffer = (char*) instrumentID.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->SubscribeMarketData(myreq, 1);
	return i;
};
int MdApi::unSubscribeMarketData(string instrumentID)
{
	char* buffer = (char*)instrumentID.c_str();
	char* myreq[1] = { buffer };;
	int i = this->api->UnSubscribeMarketData(myreq, 1);
	return i;
};
int MdApi::subscribeForQuoteRsp(string instrumentID)
{
	char* buffer = (char*)instrumentID.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->SubscribeForQuoteRsp(myreq, 1);
	return i;
};
int MdApi::unSubscribeForQuoteRsp(string instrumentID)
{
	char* buffer = (char*)instrumentID.c_str();
	char* myreq[1] = { buffer };;
	int i = this->api->UnSubscribeForQuoteRsp(myreq, 1);
	return i;
};
"""

MD_C_SWITCH = """
void MdApi::processTask()
{
    try
    {
        while (this->active)
        {
            Task task = this->task_queue.pop();

            switch (task.task_name)
            {
"""
MD_C_SWITCH_END = """
     };
        }
    }
    catch (const TerminatedError&)
    {
    }
};
"""

MD_C_PYOBJ = """
class PyMdApi: public MdApi
{
public:
	using MdApi::MdApi;
"""

MD_C_PYOBJ_END = """
};
"""

MD_C_MODULE = """
PYBIND11_MODULE(vnctpmd, m)
{
	class_<MdApi, PyMdApi> mdapi(m, "MdApi");
	mdapi
		.def(init<>())
		.def("createFtdcMdApi", &MdApi::createFtdcMdApi)
		.def("release", &MdApi::release)
		.def("init", &MdApi::init)
		.def("join", &MdApi::join)
		.def("exit", &MdApi::exit)
		.def("getTradingDay", &MdApi::getTradingDay)
		.def("registerFront", &MdApi::registerFront)
		.def("subscribeMarketData", &MdApi::subscribeMarketData)
		.def("unSubscribeMarketData", &MdApi::unSubscribeMarketData)
		.def("subscribeForQuoteRsp", &MdApi::subscribeForQuoteRsp)
		.def("unSubscribeForQuoteRsp", &MdApi::unSubscribeForQuoteRsp)"""

MD_C_MODULE_END = """
}"""

TD_H_HEADER = """
//系统
#ifdef WIN32
#include "stdafx.h"
#endif
#include "vnctp.h"
#include "pybind11/pybind11.h"
#include "ctp/ThostFtdcTraderApi.h"
using namespace pybind11;
"""
TD_H_API = """
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
"""

TD_H_API_END = """
};"""

TD_C_HEADER = """
#include "vnctptd.h"
"""

TD_C_SWITCH = """
void TdApi::processTask()
{
    try
    {
        while (this->active)
        {
            Task task = this->task_queue.pop();
            switch (task.task_name)
            {
"""

TD_C_SWITCH_END = """
            };
        }
    }
    catch (const TerminatedError&)
    {
    }
};
"""

TD_C_REQ = """
void TdApi::createFtdcTraderApi(string pszFlowPath)
{
    this->api = CThostFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath.c_str());
    this->api->RegisterSpi(this);
};
void TdApi::release()
{
    this->api->Release();
};
void TdApi::init()
{
    this->active = true;
    this->task_thread = thread(&TdApi::processTask, this);
    this->api->Init();
};
int TdApi::join()
{
    int i = this->api->Join();
    return i;
};
int TdApi::exit()
{
    this->active = false;
    this->task_queue.terminate();
    this->task_thread.join();
    this->api->RegisterSpi(NULL);
    this->api->Release();
    this->api = NULL;
    return 1;
};
string TdApi::getTradingDay()
{
    string day = this->api->GetTradingDay();
    return day;
};
void TdApi::registerFront(string pszFrontAddress)
{
    this->api->RegisterFront((char*)pszFrontAddress.c_str());
};
void TdApi::subscribePrivateTopic(int nType)
{
    this->api->SubscribePrivateTopic((THOST_TE_RESUME_TYPE) nType);
};
void TdApi::subscribePublicTopic(int nType)
{
    this->api->SubscribePublicTopic((THOST_TE_RESUME_TYPE)nType);
};
"""

TD_C_ON = """
class PyTdApi : public TdApi
{
public:
    using TdApi::TdApi;"""

TD_C_ON_END = """
};
"""
TD_C_MODULE = """
PYBIND11_MODULE(vnctptd, m)
{
    class_<TdApi, PyTdApi> TdApi(m, "TdApi");
    TdApi
        .def(init<>())
        .def("createFtdcTraderApi", &TdApi::createFtdcTraderApi)
        .def("release", &TdApi::release)
        .def("init", &TdApi::init)
        .def("join", &TdApi::join)
        .def("exit", &TdApi::exit)
        .def("getTradingDay", &TdApi::getTradingDay)
        .def("registerFront", &TdApi::registerFront)
        .def("subscribePublicTopic", &TdApi::subscribePublicTopic)
        .def("subscribePrivateTopic", &TdApi::subscribePrivateTopic)"""

TD_C_MODULE_END = """
}"""