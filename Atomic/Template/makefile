OBJS=TemplateSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libTemplateSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libTemplateSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libTemplateSAN.a: FORCE
	$(MAKE) lib TARGET=libTemplateSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libTemplateSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libTemplateSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

