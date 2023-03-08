import platform
import sys

from setuptools import Extension
from setuptools import setup

if sys.version_info < (3, 6):
    raise RuntimeError('当前ctpbee_api只支持python36以及更高版本/ ctpbee only support python36 and highly only ')
long_description = "ctpbee api support"
system_name = platform.uname().system


class ApiExt:
    def __init__(self, module_name, library_list: list):
        """
        :param api_name: should be vnctp_macmd
        :param module_name: should be `ctp`
        :param library_list: library
        """
        self.module_name = module_name
        self.library_list = library_list

    @property
    def library(self):
        """ 获取基础的ctp API"""
        library_list = self.library_list
        if system_name == "Darwin" and self.module_name == "ctp":
            library_list.extend(["ssl", "crypto", "comunicationkey"])
        return library_list

    @property
    def compiled_flag(self) -> list:
        if system_name == "Windows":
            return ["/MP", "/std:c++17", "/O2", "/Ob2", "/Oi", "/Ot", "/Oy", "/GL", "/wd4819",
                    "/DNOMINMAX"]
        elif system_name == "Darwin":
            return ["-std=c++11", "-mmacosx-version-min=10.12"]
        else:
            return ["-std=c++17", "-O3", "-Wno-delete-incomplete", "-Wno-sign-compare", "-pthread"]

    @property
    def run_time_library(self):
        run_library = []
        if system_name == "Linux":
            run_library.append("$ORIGIN")
        return run_library

    @property
    def extral_link_args(self):
        extra_link_args = []
        if system_name != "Windows":
            extra_link_args.append("-lstdc++")
        if system_name == "Darwin":
            extra_link_args.append("-mmacosx-version-min=10.12")
        return extra_link_args

    @property
    def include(self) -> list:
        dirs = [f"ctpbee_api/{self.module_name}/vn{self.module_name}"]
        if system_name == "Darwin":
            dirs.append(f"ctpbee_api/{self.module_name}/include/mac")
        else:
            dirs.append(f"ctpbee_api/{self.module_name}/include")
        return dirs

    @property
    def library_dir(self) -> library:
        dirs = [f"ctpbee_api/{self.module_name}"]
        if system_name != "Linux":
            dirs.append(f"ctpbee_api/{self.module_name}/libs")
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
        # print(mod, file)
        # print("include", self.include)
        # print("library_dir", self.library_dir)
        # print("compiled_flag", self.compiled_flag)
        # print("run_time_library", self.run_time_library)
        # print("library", self.library)
        # print("extral_link_args", self.extral_link_args)
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

    def as_ext(self):
        return self.as_md_api(), self.as_td_api()


ext_modules = []
pkgs = ["ctpbee_api"]


def build_ctp():
    ctp_md, ctp_td = ApiExt(module_name="ctp", library_list=["thostmduserapi_se", "thosttraderapi_se"]).as_ext()
    ext_modules.append(ctp_md)
    ext_modules.append(ctp_td)
    pkgs.append('ctpbee_api.ctp')


def build_ctp_mini():
    ctp_mini_md, ctp_mini_td = ApiExt(module_name="ctp_mini",
                                      library_list=["thostmduserapi", "thosttraderapi"]).as_ext()
    ext_modules.append(ctp_mini_md)
    ext_modules.append(ctp_mini_td)
    pkgs.append("ctpbee_api.ctp_mini")


def build_rohon():
    ctp_rohon_md, ctp_rohon_td = ApiExt(module_name="rohon",
                                        library_list=["thostmduserapi_se", "thosttraderapi_se"]).as_ext()
    ext_modules.append(ctp_rohon_md)
    ext_modules.append(ctp_rohon_td)
    pkgs.append("ctpbee_api.rohon")


if system_name == "Windows":
    build_ctp()
    build_ctp_mini()
    build_rohon()
elif system_name == "Linux":
    build_ctp()
    build_ctp_mini()
    build_rohon()
elif system_name == "Darwin":
    build_ctp()
else:
    raise ValueError(f"{system_name} not support, only support Linux, Windows, Darwin")

setup(
    name='ctpbee_api',
    version="0.40",
    description="single CTP API support",
    author='somewheve',
    long_description=long_description,
    author_email='somewheve@gmail.com',
    url='https://github.com/ctpbee/ctpbee_api',
    license="MIT",
    packages=pkgs,
    install_requires=[],
    platforms=["Windows", "Linux", "Mac OS-X"],
    include_package_data=True,
    package_dir={'ctpbee_api': 'ctpbee_api'},
    ext_modules=ext_modules,
)
