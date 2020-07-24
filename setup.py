from setuptools import Extension, setup
from Cython.Distutils import build_ext

from sys import platform


def get_long_description():
    with open('README.md') as f:
        return f.read()

version="0.0.4"

if platform == "win32":
    # This is for Windows
    ext_modules = [Extension("zgy2sgz",
                             sources=["zgy2sgz\\zgy2sgz.pyx"],
                             libraries=["zfp", "zgy2sgz", "Slb.Salmon.Zgy"],
                             library_dirs=['zgy2sgz\\build\\convert\\Release', 'zfp\\build\\lib\\Release',
                                           'zgy2sgz\\open-zgy\\zgy\\Slb.Salmon.ZgyPublic\\x64_vs140\\Salmon\\Main\\Release'],
                             include_dirs=["zgy2sgz\\open-zgy\\zgy\\Slb.Salmon.ZgyPublic\\include"],
                             language='c++',)]

    setup(name='zgy2sgz',
          version=version,
          author="Equinor",
          url='https://github.com/equinor/zgy2sgz',
          description="Convert zgy files to sgz files",
          long_description=get_long_description(),
          long_description_content_type='text/markdown',
          license="Apache License 2.0",
          packages=['zgy2sgz'],
          package_data={'zgy2sgz': ['..//zgy2sgz.dll', '..//zfp.dll', '..//Slb.Salmon.Zgy.dll']},
          cmdclass={'build_ext': build_ext},
          ext_modules=ext_modules)
else:
    # This is for Linux
    ext_modules = [Extension("zgy2sgz",
                             sources=["zgy2sgz/zgy2sgz.pyx"],
                             libraries=["zgy2sgz"],
                             extra_compile_args=["-I./zgy2sgz/open-zgy/zgy/Slb.Salmon.ZgyPublic/include/", "-O3"],
                             extra_link_args=["-L./zgy2sgz/build/convert"],
                             language='c++', )]

    setup(name='zgy2sgz',
          version=version,
          author="Equinor",
          url='https://github.com/equinor/zgy2sgz',
          description="Convert zgy files to sgz files",
          long_description=get_long_description(),
          long_description_content_type='text/markdown',
          license="Apache License 2.0",
          cmdclass={'build_ext': build_ext},
          ext_modules=ext_modules)
