import platform
import sys

from setuptools import Extension
from setuptools import setup

version = sys.version_info[0] * 100 + sys.version_info[1]
if version < 306:
    raise RuntimeError('当前ctpbee_api只支持python36以及更高版本/ ctpbee only support python36 and highly only ')
long_description = "ctpbee api support"
system_name = platform.uname().system


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
        if system_name == "Darwin":
            library_list = ["mac_" + x for x in library_list]
        self.library_list = library_list

    @property
    def library(self):
        """ 获取基础的ctp API"""
        library_list = self.library_list
        if self.system_name == "Darwin" and self.module_name == "ctp":
            library_list.extend(["ssl", "crypto", "comunicationkey"])
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
            extra_link_args.append("-mmacosx-version-min=10.12")
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
        dirs = [f"ctpbee_api/{self.module_name}"]
        if self.system_name != "Linux":
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
    ext = ApiExtension(module_name=module_name, library_list=library_list,
                       system=system)
    if ext.init:
        md, td = ext.as_extension()
        ext_modules.append(md)
        ext_modules.append(td)
        pkgs.append(include_module)
    else:
        pass


build("ctp", ["thostmduserapi_se", "thosttraderapi_se"], system_name, include_module='ctpbee_api.ctp')
build("ctp_mini", ["thostmduserapi", "thosttraderapi"], system_name, include_module='ctpbee_api.ctp_mini')
build("rohon", ["thostmduserapi_se", "thosttraderapi_se"], system_name, include_module='ctpbee_api.rohon')

setup(
    name='ctpbee_api',
    version="0.43",
    description="Trading API support for China Future",
    author='somewheve',
    long_description=long_description,
    author_email='somewheve@gmail.com',
    url='https://github.com/ctpbee/ctpbee_api',
    license="MIT",
    packages=pkgs,
    include_package_data=True,
    install_requires=[],
    platforms=["Windows", "Linux", "Mac OS-X"],
    package_dir={'ctpbee_api': 'ctpbee_api'},
    ext_modules=ext_modules,
    package_data={
        'ctpbee_api': ['*'],
    },
)
