
__version__ = "0.1"
from ctpbee_api.ctp import vnctpmd, vnctpmd_se, vnctptd, vnctptd_se


def get_interface(interface_name):
    if interface_name == "ctp":
        return (vnctpmd, vnctptd)
    
    if interface_name == "ctp_se":
        return (vnctpmd_se, vnctptd_se)

        