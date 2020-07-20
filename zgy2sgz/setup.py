from setuptools import Extension, setup
from Cython.Distutils import build_ext

ext_modules = [Extension("zgy2sgz",
                         sources=["zgy2sgz.pyx"],
                         libraries=["zgy2sgz"],
                         extra_compile_args=["-I../open-zgy/zgy/Slb.Salmon.ZgyPublic/include/"],
                         extra_link_args=["-L./build"],
                         language='c++',)]

setup(name='zgy2sgz', cmdclass={'build_ext': build_ext}, ext_modules=ext_modules)
