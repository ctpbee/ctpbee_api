import platform
import sys
import shutil
import os

from setuptools import Extension
from setuptools import setup

version = sys.version_info[0] * 100 + sys.version_info[1]
if version < 306:
    raise RuntimeError('当前ctpbee_api只支持python36以及更高版本/ ctpbee only support python36 and highly only ')
long_description = "ctpbee api support"
system_name = platform.uname().system


def copy_folder_contents(source_folder, destination_folder):
    # 创建目标文件夹（如果不存在）
    if not os.path.exists(destination_folder):
        os.makedirs(destination_folder)
    shutil.copytree(source_folder, destination_folder, dirs_exist_ok=True)


if_copy = False


def get_framework_path():
    """
    获取工作路径
    """
    import os
    home_path = os.path.join(os.environ["HOME"], ".ctpbee")
    if not os.path.exists(home_path):
        os.mkdir(home_path)
    framework_path = os.path.join(home_path, "Frameworks")
    global if_copy
    if not if_copy:
        if not os.path.exists(framework_path):
            os.mkdir(framework_path)
        local_framework_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), "ctpbee_api", "framework")
        copy_folder_contents(local_framework_path, framework_path)
        if_copy = True
    return framework_path


class ApiExtension:
    support_platform = {"ctp": ["Windows", "Linux", "Darwin"],
                        "rohon": ["Windows", "Linux"],
                        "ctp_mini": ["Windows", "Linux"]
                        }

    def __init__(self, module_name, library_list: list, system="Windows"):
        """
        :param api_name: should be vnctp_macmd
        :param module_name: should be `ctp`
        :param library_list: library
        """
        self.module_name = module_name
        self.system_name = system
        if system in self.support_platform.get(module_name, []):
            self.init = True
        else:
            self.init = False
        self.library_list = library_list

    @property
    def library(self):
        """ 获取基础的ctp API"""
        library_list = self.library_list
        if self.system_name == "Darwin":
            """mac 采用framework进行link 此处忽略不计"""
            return []
        else:
            return library_list

    @property
    def compiled_flag(self) -> list:
        if self.system_name == "Windows":
            return ["/MP", "/std:c++17", "/O2", "/Ob2", "/Oi", "/Ot", "/Oy", "/GL", "/wd4819",
                    "/DNOMINMAX"]
        elif self.system_name == "Darwin":
            return ["-std=c++11", "-mmacosx-version-min=10.12"]
        else:
            return ["-std=c++17", "-O3", "-Wno-delete-incomplete", "-Wno-sign-compare", "-pthread"]

    @property
    def run_time_library(self):
        run_library = []
        if self.system_name == "Linux":
            run_library.append("$ORIGIN")
        return run_library

    @property
    def extral_link_args(self):
        extra_link_args = []
        if self.system_name != "Windows":
            extra_link_args.append("-lstdc++")
        if self.system_name == "Darwin":
            """
            mac下需要进行额外的处理
            """
            extra_link_args.append("-mmacosx-version-min=10.12")
            framework_path = get_framework_path()
            extra_link_args.append(f"-Wl,-rpath,{framework_path}")
            extra_link_args.extend(["-F", framework_path])
            extra_link_args.extend(["-framework", "thosttraderapi_se"])
            extra_link_args.extend(["-framework", "thostmduserapi_se"])
        return extra_link_args

    @property
    def include(self) -> list:
        dirs = [f"ctpbee_api/{self.module_name}/vn{self.module_name}"]
        if self.system_name == "Darwin":
            dirs.append(f"ctpbee_api/{self.module_name}/include/mac")
        else:
            if version >= 311:
                dirs.append(f"ctpbee_api/{self.module_name}/include/new")
            else:
                dirs.append(f"ctpbee_api/{self.module_name}/include/previous")
        return dirs

    @property
    def library_dir(self) -> library:
        dirs = []
        if self.system_name != "Linux":
            dirs.append(f"ctpbee_api/{self.module_name}/libs")
        if self.system_name == "Darwin":
            """
            mac从frameworks进行搜索路径下进行搜索
            """
            dirs.append(get_framework_path())
        else:
            dirs.append(f"ctpbee_api/{self.module_name}")
        return dirs

    def td_api_file(self) -> (str, str):
        return f"ctpbee_api.{self.module_name}.vn{self.module_name}td", f"ctpbee_api/{self.module_name}/vn{self.module_name}/vn{self.module_name}td/vn{self.module_name}td.cpp"

    def md_api_file(self) -> (str, str):
        return f"ctpbee_api.{self.module_name}.vn{self.module_name}md", f"ctpbee_api/{self.module_name}/vn{self.module_name}/vn{self.module_name}md/vn{self.module_name}md.cpp"

    def as_td_api(self) -> Extension:
        mod, file = self.td_api_file()
        return Extension(
            mod,
            [
                file
            ],
            include_dirs=self.include,
            language="cpp",
            define_macros=[],
            undef_macros=[],
            library_dirs=self.library_dir,
            libraries=self.library,
            extra_compile_args=self.compiled_flag,
            extra_link_args=self.extral_link_args,
            depends=[],
            runtime_library_dirs=self.run_time_library,
        )

    def as_md_api(self) -> Extension:
        mod, file = self.md_api_file()
        return Extension(
            mod,
            [
                file
            ],
            include_dirs=self.include,
            language="cpp",
            define_macros=[],
            undef_macros=[],
            library_dirs=self.library_dir,
            libraries=self.library,
            extra_compile_args=self.compiled_flag,
            extra_link_args=self.extral_link_args,
            depends=[],
            runtime_library_dirs=self.run_time_library,
        )

    def as_extension(self):
        return self.as_md_api(), self.as_td_api()


ext_modules = []
pkgs = ["ctpbee_api"]


def build(module_name, library_list, system, include_module):
    ext = ApiExtension(module_name=module_name,
                       library_list=library_list,
                       system=system)
    if ext.init:
        md, td = ext.as_extension()
        ext_modules.append(md)
        ext_modules.append(td)
        pkgs.append(include_module)
        if system == "Darwin" and module_name == "ctp":
            """
            mac需要进行额外处理
            """
            pkgs.append("ctpbee_api.framework")
    else:
        del ext


build("ctp", ["thostmduserapi_se", "thosttraderapi_se"], system=system_name, include_module='ctpbee_api.ctp')
build("ctp_mini", ["thostmduserapi", "thosttraderapi"], system=system_name, include_module='ctpbee_api.ctp_mini')
build("rohon", ["thostmduserapi_se", "thosttraderapi_se"], system=system_name, include_module='ctpbee_api.rohon')


def find_data_files(directory):
    data_files = []
    for root, dirs, files in os.walk(directory):
        for file in files:
            data_files.append(os.path.relpath(os.path.join(root, file), directory))
    return data_files


package_data = {}
for pkg in pkgs:
    if "." not in pkg:
        continue
    files = find_data_files(pkg.replace(".", "/"))
    package_data[pkg] = files

setup(
    name='ctpbee_api',
    version="0.45",
    description="Trading API support for China Future",
    author='somewheve',
    long_description=long_description,
    author_email='somewheve@gmail.com',
    url='https://github.com/ctpbee/ctpbee_api',
    license="MIT",
    packages=pkgs,
    platforms=["Windows", "Linux", "Mac OS-X"],
    ext_modules=ext_modules,
    package_data=package_data,
)
