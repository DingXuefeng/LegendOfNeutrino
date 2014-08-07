# Makefile for fit
# Author: Ding Xuefeng dingxf@ihep.ac.cn
# History:
#   2013.08.04 ver 1.0
#   2013.08.24 ver 1.1

TARGET:= fit

HEAD := ./include
HEADFILES := $(wildcard ${HEAD}/*.h)
SRC := ./src
BIN := ./bin
LIBSRC := ./libsrc
LIB := ./lib
LIBSRCFILES := $(wildcard ${LIBSRC}/*.cc)
LIBOBJFILES := $(patsubst ${LIBSRC}/%.cc,$(LIB)/lib%.so,$(LIBSRCFILES))
SRCFILES := $(wildcard ${SRC}/*.cc)
OBJFILES := $(patsubst ${SRC}/%.cc,$(BIN)/%,$(SRCFILES))
TMP := ./tmp

CC := g++
CPPFLAGS := -I$(HEAD) -I$(ROOTSYS)/include -pipe -Wall -O2
LDLIBS := $(shell root-config --glibs)
# for RooFit
#LDLIBS += -lRooFitCore -lRooFit -lMinuit

.PHONY: makeFileTut all clean test

all: $(OBJFILES) $(LIBOBJFILES)

test:

clean:
	-@rm $(OBJFILES)
	-@rm $(LIBOBJFILES)
	-@rm $(TARGET)
	-@rm $(HEAD)/*~
	-@rm $(LIBSRC)/*~
	-@rm *~
	@echo "Cleaning done."

makeFileTut:
	echo ${CPPFLAGS}
	echo ${LIBSRCFILES}
	echo ${OBJFILES}

$(LIB)/lib%.so : $(LIBSRC)/%.cc $(HEADFILES)
	$(CC) -o $@ $(CPPFLAGS) $(LDLIBS) -fPIC -shared $< 
	chmod a+x $@

lib/libOptionFileManager.so:libsrc/OptionFileManager.cc $(HEADFILES) lib/libConverter.so
	$(CC) -o $@ $(CPPFLAGS) $(LDLIBS) -Llib -lConverter -fPIC -shared $< 
	chmod a+x $@

$(BIN)/% : $(SRC)/%.cc $(HEADFILES) lib/libOptionFileManager.so lib/libDybStyle.so
	$(CC) -o $@ $(CPPFLAGS) $(LDLIBS) -Llib -lOptionFileManager -lDybStyle -lConverter $< 
	chmod a+x $@
