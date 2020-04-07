OBJS=CompRJ.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libCompRJ.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libCompRJ_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libCompRJ.a: FORCE
	$(MAKE) lib TARGET=libCompRJ.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libCompRJ_debug.a: FORCE
	$(MAKE) lib TARGET=libCompRJ_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

