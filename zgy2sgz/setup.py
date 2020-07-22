from setuptools import Extension, setup
from Cython.Distutils import build_ext
import glob

# This is for Linux

ext_modules = [Extension("zgy2sgz",
                         sources=["zgy2sgz.pyx"],
                         libraries=["zgy2sgz"],
                         extra_compile_args=["-I./open-zgy/zgy/Slb.Salmon.ZgyPublic/include/"],
                         extra_link_args=["-L./build/convert"],
                         language='c++',)]

setup(name='zgy2sgz',
      version="0.0.2",
      author="Equinor",
      description="Convert zgy files to sgz files",
      long_description="Convert zgy files to sgz files",
      cmdclass={'build_ext': build_ext},
      extra_compile_args=["-O3", "-Wall"],
      ext_modules=ext_modules)
