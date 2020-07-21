from setuptools import Extension, setup
from Cython.Distutils import build_ext
import glob
from sys import platform

if platform == "win32":
    ext_modules = [Extension("zgy2sgz",
                             sources=["zgy2sgz.pyx"],
                             libraries=["zfp", "zgy2sgz", "Slb.Salmon.Zgy"],
                             library_dirs=['build\\convert\\Release', '..\\zfp\\build\\lib\\Release',
                                           'open-zgy\\zgy\\Slb.Salmon.ZgyPublic\\x64_vs140\\Salmon\\Main\\Release'],
                             include_dirs=["open-zgy\\zgy\\Slb.Salmon.ZgyPublic\\include"],
                             language='c++', )]
else:
    ext_modules = [Extension("zgy2sgz",
                             sources=["zgy2sgz.pyx"],
                             libraries=["zgy2sgz"],
                             extra_compile_args=["-I./open-zgy/zgy/Slb.Salmon.ZgyPublic/include/"],
                             extra_link_args=["-L./build/convert"],
                             language='c++',)]

setup(name='zgy2sgz',
      version="0.0.1",
      author="Equinor",
      description="Convert zgy files to sgz files",
      long_description="Convert zgy files to sgz files",
      cmdclass={'build_ext': build_ext},
      extra_compile_args=["-O3", "-Wall"],
      ext_modules=ext_modules)
