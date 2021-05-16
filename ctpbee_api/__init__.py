__version__ = "0.1"


def get_interface(interface_name):
    if interface_name == "ctp":
        from ctpbee_api.ctp import MdApi, TdApi
        return MdApi, TdApi

    elif interface_name == "ctp_se":
        from ctpbee_api.ctp import MdApiApp, TdApiApp
        return MdApiApp, TdApiApp

    elif interface_name == "ctp_mini":
        from ctpbee_api.ctp_mini import MdApi, TdApi
        return MdApi, TdApi
