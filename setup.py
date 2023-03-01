import platform
import sys

from setuptools import Extension
from setuptools import setup

if sys.version_info < (3, 6):
    raise RuntimeError('当前ctpbee_api只支持python36以及更高版本/ ctpbee only support python36 and highly only ')

runtime_library_dir = []
long_description = "ctp api support"
extra_link_args = []

systemctl = platform.uname().system

if systemctl == "Windows":
    compiler_flags = [
        "/MP", "/std:c++17",  # standard
        "/O2",
        "/Ob2",
        "/Oi",
        "/Ot",
        "/Oy",
        "/GL",  # Optimization
        "/wd4819",  # 936 code page,
        "/DNOMINMAX"
    ]
elif systemctl == "Darwin":
    compiler_flags = [
        "-std=c++17",  # standard
        "-O3",  # Optimization
        "-Wno-delete-incomplete",
        "-Wno-sign-compare",
        "-pthread",
    ]
    extra_link_args = ["-lstdc++"]
else:
    compiler_flags = [
        "-std=c++17",  # standard
        "-O3",  # Optimization
        "-Wno-delete-incomplete",
        "-Wno-sign-compare",
        "-pthread",
    ]
    extra_link_args = ["-lstdc++"]
    runtime_library_dir = ["$ORIGIN"]


def get_library(system_name):
    if system_name == "Darwin":
        lib = ["macmdapi", "mactdapi", "ssl", "crypto", "comunicationkeylib"]
    else:
        lib = ["thostmduserapi_se", "thosttraderapi_se"]
    return lib


vnctpmd = Extension(
    "ctpbee_api.ctp.vnctpmd",
    [
        "ctpbee_api/ctp/vnctp/vnctpmd/vnctpmd.cpp",
    ],
    include_dirs=[
        "ctpbee_api/ctp/include",
        "ctpbee_api/ctp/vnctp",
    ],
    language="cpp",
    define_macros=[],
    undef_macros=[],
    library_dirs=["ctpbee_api/ctp/libs", "ctpbee_api/ctp"],
    libraries=get_library(systemctl),
    extra_compile_args=compiler_flags,
    extra_link_args=extra_link_args,
    depends=[],
    runtime_library_dirs=runtime_library_dir,
)

vnctptd = Extension(
    "ctpbee_api.ctp.vnctptd",
    [
        "ctpbee_api/ctp/vnctp/vnctptd/vnctptd.cpp",
    ],
    include_dirs=[
        "ctpbee_api/ctp/include",
        "ctpbee_api/ctp/vnctp",
    ],
    define_macros=[],
    undef_macros=[],
    library_dirs=["ctpbee_api/ctp/libs",
                  "ctpbee_api/ctp",
                  ],
    libraries=get_library(systemctl),
    extra_compile_args=compiler_flags,
    extra_link_args=extra_link_args,
    runtime_library_dirs=runtime_library_dir,
    depends=[],
    language="cpp",
)

mini_td = Extension(
    "ctpbee_api.ctp_mini.CTdApi",
    [
        "ctpbee_api/ctp_mini/vnmini/vnminitd/vnminitd.cpp",
    ],
    include_dirs=[
        "ctpbee_api/ctp_mini/include",
        "ctpbee_api/ctp_mini/vnmini",
    ],
    define_macros=[],
    undef_macros=[],
    library_dirs=["ctpbee_api/ctp_mini/libs",
                  "ctpbee_api/ctp_mini",
                  ],
    libraries=["thostmduserapi", "thosttraderapi"],
    extra_compile_args=compiler_flags,
    extra_link_args=extra_link_args,
    runtime_library_dirs=runtime_library_dir,
    depends=[],
    language="cpp",
)

mini_md = Extension(
    "ctpbee_api.ctp_mini.CMdApi",
    [
        "ctpbee_api/ctp_mini/vnmini/vnminimd/vnminimd.cpp",
    ],
    include_dirs=[
        "ctpbee_api/ctp_mini/include",
        "ctpbee_api/ctp_mini/vnmini",
    ],
    define_macros=[],
    undef_macros=[],
    library_dirs=["ctpbee_api/ctp_mini/libs",
                  "ctpbee_api/ctp_mini",
                  ],
    libraries=["thostmduserapi", "thosttraderapi"],
    extra_compile_args=compiler_flags,
    extra_link_args=extra_link_args,
    runtime_library_dirs=runtime_library_dir,
    depends=[],
    language="cpp",
)

rohon_td = Extension(
    "ctpbee_api.ctp_rohon.vnrohontd",
    [
        "ctpbee_api/ctp_rohon/vnrohon/vnrohontd/vnrohontd.cpp",
    ],
    include_dirs=[
        "ctpbee_api/ctp_rohon/include",
        "ctpbee_api/ctp_rohon/vnrohon",
    ],
    define_macros=[],
    undef_macros=[],
    library_dirs=["ctpbee_api/ctp_rohon/libs",
                  "ctpbee_api/ctp_rohon",
                  ],
    libraries=["thostmduserapi_se", "thosttraderapi_se"],
    extra_compile_args=compiler_flags,
    extra_link_args=extra_link_args,
    runtime_library_dirs=runtime_library_dir,
    depends=[],
    language="cpp",
)

rohon_md = Extension(
    "ctpbee_api.ctp_rohon.vnrohonmd",
    [
        "ctpbee_api/ctp_rohon/vnrohon/vnrohonmd/vnrohonmd.cpp",
    ],
    include_dirs=[
        "ctpbee_api/ctp_rohon/include",
        "ctpbee_api/ctp_rohon/vnrohon",
    ],
    define_macros=[],
    undef_macros=[],
    library_dirs=["ctpbee_api/ctp_rohon/libs",
                  "ctpbee_api/ctp_rohon",
                  ],
    libraries=["thostmduserapi_se", "thosttraderapi_se"],
    extra_compile_args=compiler_flags,
    extra_link_args=extra_link_args,
    runtime_library_dirs=runtime_library_dir,
    depends=[],
    language="cpp",
)

if platform.system() == "Windows":
    ext_modules = [vnctptd, vnctpmd, mini_td, mini_md, rohon_td, rohon_md]
else:
    ext_modules = [vnctptd, vnctpmd]

pkgs = ["ctpbee_api", 'ctpbee_api.ctp', "ctpbee_api.ctp_mini", "ctpbee_api.ctp_rohon"]

setup(
    name='ctpbee_api',
    version="0.34",
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
