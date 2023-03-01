def get_interface(interface_name):
    if interface_name == "ctp":
        from ctpbee_api.ctp import MdApi, TdApi
        return MdApi, TdApi

    elif interface_name == "ctp_mini":
        from ctpbee_api.ctp_mini import MiniMdApi, MiniTdApi
        return MiniMdApi, MiniTdApi

    elif interface_name == "ctp_rohon":
        from ctpbee_api.ctp_rohon import RohonMdApi, RohonTdApi
        return RohonMdApi, RohonTdApi
    else:
        raise ValueError("INTERFACE NOT SUPPORTED")
