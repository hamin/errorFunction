# Makefile for cs2 directory 

# start by clearing the suffixes
.SUFFIXES:
# set default rules for .cpp, and .o
.SUFFIXES: .cpp .o

# default for creating object file
.cpp.o:; g++ -c -o $@ $*.cpp

# dependencies
# make settest ============================
errorFunction:  errorFunction.o  myMath.o
	g++ -o $@ errorFunction.o myMath.o

errorFunction.o: errorFunction.cpp myMath.h

myMath.o: myMath.cpp myMath.h

# ==========================================

clean:
	/bin/rm -f *.o core

