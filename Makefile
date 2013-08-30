# Makefile for fit
# Author: Ding Xuefeng dingxf@ihep.ac.cn
# History:
#   2013.08.04 ver 1.0
#   2013.08.24 ver 1.1

TARGET:= fit

HEAD := ./include
HEADFILES := $(wildcard ${HEAD}/*.h)
SRC := ./src
LIB := ./lib
SRCFILES := $(wildcard ${SRC}/*.cc)
TMP := ./tmp
OBJFILES := $(patsubst ${SRC}/%.cc,$(LIB)/lib%.so,$(SRCFILES))

CC := g++
CPPFLAGS := -I$(HEAD) -I$(ROOTSYS)/include -pipe -Wall -O2
LDLIBS := $(shell root-config --glibs --libs)
# for RooFit
#LDLIBS += -lRooFitCore -lRooFit -lMinuit

.PHONY: makeFileTut all clean test

all: $(OBJFILES)

test:

clean:
	-@rm $(OBJFILES)
	-@rm $(TARGET)
	-@rm $(HEAD)/*~
	-@rm $(SRC)/*~
	-@rm *~
	@echo "Cleaning done."

makeFileTut:
	echo ${CPPFLAGS}
	echo ${SRCFILES}
	echo ${OBJFILES}

$(LIB)/lib%.so : $(SRC)/%.cc $(HEADFILES)
	$(CC) -o $@ $(CPPFLAGS) -fPIC -shared $< 
	chmod a+x $@
