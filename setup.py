import io
import platform
import re
import sys
import warnings

from setuptools import Extension
from setuptools import setup

if sys.version_info < (3, 6):
    raise RuntimeError('当前ctpbee_api只支持python36以及更高版本/ ctpbee only support python36 and highly only ')


runtime_library_dir = []
try:
    import pypandoc

    long_description = pypandoc.convert_file('README.md', 'rst')
except Exception:
    long_description = ""

if platform.uname().system == "Windows":
    compiler_flags = [
        "/MP", "/std:c++17",  # standard
        "/O2", "/Ob2", "/Oi", "/Ot", "/Oy", "/GL",  # Optimization
        "/wd4819"  # 936 code page
    ]
    extra_link_args = []
else:
    compiler_flags = [
        "-std=c++17",  # standard
        "-O3",  # Optimization
        "-Wno-delete-incomplete", "-Wno-sign-compare", "-pthread"
    ]
    extra_link_args = ["-lstdc++"]
    runtime_library_dir = ["$ORIGIN"]

vnctpmd = Extension(
    "ctpbee_api.api.ctp.vnctpmd",
    [
        "ctpbee_api/api/ctp/vnctp/vnctpmd/vnctpmd.cpp",
    ],
    include_dirs=[
        "ctpbee_api/api/ctp/include",
        "ctpbee_api/api/ctp/vnctp",
    ],
    language="cpp",
    define_macros=[],
    undef_macros=[],
    library_dirs=["ctpbee_api/api/ctp/libs", "ctpbee_api/api/ctp"],
    libraries=["thostmduserapi_se", "thosttraderapi_se", ],
    extra_compile_args=compiler_flags,
    extra_link_args=extra_link_args,
    depends=[],
    runtime_library_dirs=runtime_library_dir,
)

vnctptd = Extension(
    "ctpbee_api.api.ctp.vnctptd",
    [
        "ctpbee_api/api/ctp/vnctp/vnctptd/vnctptd.cpp",
    ],
    include_dirs=[
        "ctpbee_api/api/ctp/include",
        "ctpbee_api/api/ctp/vnctp",
    ],
    define_macros=[],
    undef_macros=[],
    library_dirs=["ctpbee_api/api/ctp/libs",
                  "ctpbee_api/api/ctp",
                  ],
    libraries=["thostmduserapi_se", "thosttraderapi_se"],
    extra_compile_args=compiler_flags,
    extra_link_args=extra_link_args,
    runtime_library_dirs=runtime_library_dir,
    depends=[],
    language="cpp",
)

vnctpmd_se = Extension(
    "ctpbee_api.api.ctp.vnctpmd_se",
    [
        "ctpbee_api/api/ctp/vnctp_se/vnctpmd/vnctpmd.cpp",
    ],
    include_dirs=[
        "ctpbee_api/api/ctp/include",
        "ctpbee_api/api/ctp/vnctp_se",
    ],
    language="cpp",
    define_macros=[],
    undef_macros=[],
    library_dirs=["ctpbee_api/api/ctp/libs", "ctpbee_api/api/ctp"],
    libraries=["thosttraderapi_se_app", "thostmduserapi_se_app", ],
    extra_compile_args=compiler_flags,
    extra_link_args=extra_link_args,
    depends=[],
    runtime_library_dirs=runtime_library_dir,
)

vnctptd_se = Extension(
    "ctpbee_api.api.ctp.vnctptd_se",
    [
        "ctpbee_api/api/ctp/vnctp_se/vnctptd/vnctptd.cpp",
    ],
    include_dirs=[
        "ctpbee_api/api/ctp/include",
        "ctpbee_api/api/ctp/vnctp_se",
    ],
    define_macros=[],
    undef_macros=[],
    library_dirs=["ctpbee_api/api/ctp/libs",
                  "ctpbee_api/api/ctp",
                  ],
    libraries=["thosttraderapi_se_app", "thostmduserapi_se_app"],
    extra_compile_args=compiler_flags,
    extra_link_args=extra_link_args,
    runtime_library_dirs=runtime_library_dir,
    depends=[],
    language="cpp",
)

if platform.system() == "Windows":
    ext_modules = [vnctptd, vnctpmd, vnctptd_se, vnctpmd_se]
elif platform.system() == "Darwin":
    warnings.warn("因为官方并没有发布基于mac的api， 所以当前ctpbee并不支持mac下面的ctp接口")
    ext_modules = []
else:
    ext_modules = [vnctptd, vnctpmd, vnctptd_se, vnctpmd_se]

pkgs = ['ctpbee_api.api']

setup(
    name='ctpbee_api',
    version=0.1,
    description="single API support",
    author='somewheve',
    long_description=long_description,
    author_email='somewheve@gmail.com',
    url='https://github.com/ctpbee/ctpbee_api',
    license="MIT",
    packages=pkgs,
    install_requires=[],
    platforms=["Windows", "Linux", "Mac OS-X"],
    package_dir={'ctpbee_api': 'ctpbee_api'},
    # zip_safe=True,
    include_package_data=True,
    package_data={'ctpbee_api': ['api/ctp/*']},
    ext_modules=ext_modules,
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Python :: 3.7',
    ]
)
