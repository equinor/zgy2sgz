ZGY_ROOT=../open-zgy/zgy/Slb.Salmon.ZgyPublic
ZFP_ROOT=../zfp

INC_ZGY=$(ZGY_ROOT)/include
INC_ZFP=$(ZFP_ROOT)/include
LIB_ZGY=$(ZGY_ROOT)/Lin64_gcc485
LIB_ZFP=$(ZFP_ROOT)/build/lib64

CPPFLAGS += -I$(INC_ZGY)
CPPFLAGS += -I$(INC_ZFP)

all: zgy2sgz libzgy2sgz.so

zgy2sgz: libzgy2sgz.so main.o
	$(CXX) -o zgy2sgz main.o -L. -lzgy2sgz -Wl,-rpath,.

libzgy2sgz.so: convert/meta.o convert/convert.o
	$(CXX) -fPIC $(CPPFLAGS) -c convert/meta.cpp -o convert/meta.o -l$(LIB_ZGY)/Slb.Salmon.Zgy.so -l$(LIB_ZFP)/libzfp.so
	$(CXX) -fPIC $(CPPFLAGS) -c convert/convert.cpp -o convert/convert.o -l$(LIB_ZGY)/Slb.Salmon.Zgy.so -l$(LIB_ZFP)/libzfp.so
	$(CXX) -shared $(CPPFLAGS) -Wl,-soname,libzgy2sgz.so -o $@ convert/convert.o convert/meta.o $(LIB_ZGY)/Slb.Salmon.Zgy.so $(LIB_ZFP)/libzfp.so -Wl,-rpath,$(LIB_ZGY) -Wl,-rpath,$(LIB_ZFP)

.PHONY: clean
clean:
	$(RM) zgy2sgz main.o convert/meta.o convert/convert.o libzgy2sgz.so
