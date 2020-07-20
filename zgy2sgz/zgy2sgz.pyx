#cython: language_level=3

cdef extern from "convert/convert.h":
    cpdef void convertFile(const char* infile, const char* outfile, int bits_per_voxel)
