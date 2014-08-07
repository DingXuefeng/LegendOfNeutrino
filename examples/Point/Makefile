# Makefile for fit
# Author: Ding Xuefeng dingxf@ihep.ac.cn
# History:
#   2013.08.04 ver 1.0
#   2013.08.24 ver 1.1

TARGET:= Point

HEAD := ./include
HEADFILES := $(wildcard ${HEAD}/*.h)
TMP := ./tmp

CC := g++
CPPFLAGS := -I$(HEAD) -I$(ROOTSYS)/include -pipe -Wall -O2
LDLIBS := $(shell root-config --glibs --libs)
# for RooFit
#LDLIBS += -lRooFitCore -lRooFit -lMinuit

CPPFLAGS += $(shell LegendOfNeutrino-config --cflags)
LDLIBS += $(shell LegendOfNeutrino-config --libs) 

.PHONY: makeFileTut all clean test

all:$(TARGET)

test:Test

clean:
	-@rm tmp/main.o
	-@rm $(TARGET)
	-@rm $(HEAD)/*~
	-@rm $(SRC)/*~
	-@rm *~
	@echo "Cleaning done."

makeFileTut:
	echo ${CPPFLAGS}
	echo ${SRCFILES}
	echo ${OBJFILES}

$(TMP)/main.o : main.cc $(HEADFILES)
	$(CC) -o $@ -c $< $(CPPFLAGS)

$(TARGET) : $(TMP)/main.o
	$(CC) -o $@ $^ $(LDLIBS)
