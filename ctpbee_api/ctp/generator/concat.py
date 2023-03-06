

import os
from const import *

current_dir = os.path.dirname(__file__)
out_base_path = os.path.join(os.path.dirname(current_dir), "vnctp")
filelist = os.listdir(current_dir)

h = [x for x in filelist if x.endswith(".h")]
cpp = [x for x in filelist if x.endswith(".cpp")]
td_h = [x for x in h if "td" in x]
md_h = [x for x in h if "md" in x]
td_cpp = [x for x in cpp if "td" in x]
md_cpp = [x for x in cpp if "md" in x]


def read_file(file_list, name):
    file_name = ""
    for i in file_list:
        if i.split("_")[3].split(".")[0] == name:
            file_name = i
    if len(file_name) == 0:
        print("stop")
        return None
    with open(file_name, "r") as f:
        return "".join(f.readlines())


def generate_md():
    md_h_define = read_file(md_h, "define")
    md_h_on = read_file(md_h, "on")
    md_h_function = read_file(md_h, "function")
    md_h_process = read_file(md_h, "process")

    # 获取行情内容
    md_h_file = MD_H_HEADER + md_h_define + MD_H_API + MD_H_BACK + md_h_process + md_h_on + md_h_function + "};"

    md_c_task = read_file(md_cpp, "task")
    md_c_process = read_file(md_cpp, "process")
    md_c_function = read_file(md_cpp, "function")
    md_c_on = read_file(md_cpp, "on")
    md_c_switch = read_file(md_cpp, "switch")
    md_c_module = read_file(md_cpp, "module")

    md_c_file = MD_C_HEADER \
                + md_c_task + md_c_process + md_c_function + \
                MD_C_PYOBJ + md_c_on + MD_C_PYOBJ_END + \
                MD_C_SWITCH + md_c_switch + MD_C_SWITCH_END + \
                MD_C_MODULE + md_c_module + MD_C_MODULE_END

    return md_h_file, md_c_file


def generate_td():
    td_h_define = read_file(td_h, "define")
    td_h_on = read_file(td_h, "on")
    td_h_process = read_file(td_h, "process")
    td_h_function = read_file(td_h, "function")
    td_h_file = TD_H_HEADER + td_h_define + TD_H_API + td_h_on + td_h_process + td_h_function + TD_H_API_END

    td_c_switch = read_file(td_cpp, "switch")
    td_c_task = read_file(td_cpp, "task")
    td_c_process = read_file(td_cpp, "process")
    td_c_function = read_file(td_cpp, "function")
    td_c_on = read_file(td_cpp, "on")
    td_c_module = read_file(td_cpp, "module")

    td_c_file = TD_C_HEADER + td_c_task + \
                TD_C_SWITCH + td_c_switch + TD_C_SWITCH_END + \
                td_c_process + TD_C_REQ + td_c_function + \
                TD_C_ON + td_c_on + TD_C_ON_END + TD_C_MODULE + td_c_module + TD_C_MODULE_END
    return td_h_file, td_c_file


def write_file(name, h, c):
    h_name = f"{name}.h"
    c_name = f"{name}.cpp"
    base_path = os.path.join(out_base_path, name)
    h_file_path = os.path.join(base_path, h_name)
    with open(h_file_path, "w", encoding="utf8") as f:
        f.write(h)
    c_file_path = os.path.join(base_path, c_name)
    with open(c_file_path, "w", encoding="utf8") as f:
        f.write(c)


if __name__ == "__main__":
    h, c = generate_md()
    write_file("vnctpmd", h, c)
    h, c = generate_td()
    write_file("vnctptd", h, c)

