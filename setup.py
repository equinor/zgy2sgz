from setuptools import Extension, setup
from Cython.Distutils import build_ext
from sys import platform

# This is for Windows

ext_modules = [Extension("zgy2sgz",
                         sources=["zgy2sgz\zgy2sgz.pyx"],
                         libraries=["zfp", "zgy2sgz", "Slb.Salmon.Zgy"],
                         library_dirs=['zgy2sgz\\build\\convert\\Release', 'zfp\\build\\lib\\Release',
                                       'zgy2sgz\\open-zgy\\zgy\\Slb.Salmon.ZgyPublic\\x64_vs140\\Salmon\\Main\\Release'],
                         include_dirs=["zgy2sgz\\open-zgy\\zgy\\Slb.Salmon.ZgyPublic\\include"],
                         language='c++',)]
                        
setup(name='zgy2sgz',
      version="0.0.2",
      author="Equinor",
      description="Convert zgy files to sgz files",
      long_description="Convert zgy files to sgz files",
      packages=['zgy2sgz'],
      package_data={'zgy2sgz': ['..//zgy2sgz.dll', '..//zfp.dll', '..//Slb.Salmon.Zgy.dll']},
      cmdclass={'build_ext': build_ext},
      ext_modules=ext_modules)