# Makefile for fit
# Author: Ding Xuefeng dingxf@ihep.ac.cn
# History:
#   2013.08.04 ver 1.0
#   2013.08.24 ver 1.1

TARGET:= TimeWatcherTest

HEAD := ./include
HEADFILES := $(wildcard ${HEAD}/*.h)
SRC := ./src
TEST := ./test
SRCFILES := $(wildcard ${SRC}/*.cc)
SRCFILES += $(wildcard ${SRC}/*.C)
TMP := ./tmp
OBJFILES := $(patsubst ${SRC}/%.cc,${TMP}/%.o,$(patsubst ${SRC}/%.C,${TMP}/%.o,${SRCFILES}))

TESTFILES := $(wildcard ${TEST}/*.cc)
TESTFILES += $(wildcard ${TEST}/*.C)
TESTOBJFILES := $(patsubst ${TEST}/%.cc,${TMP}/%.o,$(patsubst ${SRC}/%.C,${TMP}/%.o,${TESTFILES}))

CC := g++
CPPFLAGS := -I$(HEAD) -I$(ROOTSYS)/include -pipe -Wall -O2
LDLIBS := $(shell root-config --glibs --libs)
# for RooFit
LDLIBS += -lRooFitCore -lRooFit -lMinuit

CPPFLAGS += -I/workfs/dyw/dingxf/LegendOfNeutrino/include
LDLIBS += -L/workfs/dyw/dingxf/LegendOfNeutrino/lib

.PHONY: makeFileTut all clean test

all:$(TARGET)

test:Test

clean:
	-@rm $(OBJFILES)
	-@rm $(TARGET) main.o
	-@rm $(HEAD)/*~
	-@rm $(SRC)/*~
	-@rm *~
	@echo "Cleaning done."

makeFileTut:
	echo ${CPPFLAGS}
	echo ${SRCFILES}
	echo ${OBJFILES}

$(TMP)/%.o : $(SRC)/%.cc $(HEADFILES)
	$(CC) -o $@ -c $< $(CPPFLAGS)

$(TMP)/%.o : $(SRC)/%.C $(HEADFILES)
	$(CC) -o $@ -c $< $(CPPFLAGS)

main.o : main.cc $(HEADFILES)
	$(CC) -o $@ -c $< $(CPPFLAGS)

$(TARGET) : main.o $(OBJFILES)
	$(CC) -o $@ $^ $(LDLIBS)

$(TMP)/%.o : $(TEST)/%.cc $(HEADFILES)
	$(CC) -o $@ -c $< $(CPPFLAGS)

$(TMP)/%.o : $(TEST)/%.C $(HEADFILES)
	$(CC) -o $@ -c $< $(CPPFLAGS)

Test : $(TESTOBJFILES) $(OBJFILES)
	$(CC) -o $@ $^ $(LDLIBS)
