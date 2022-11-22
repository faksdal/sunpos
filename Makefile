#
#
#	Makefile
#
CC=g++
CFLAGS=-I. -I./src
OBJ = obj/main.o obj/jdn.o obj/parseOptarg.o obj/jdnParseDate.o obj/jdnCalculateJdnMeeus1998.o obj/jdnCalculateJdn.o obj/sunpos.o obj/spPrintOutput.o

all: $(OBJ)
	$(CC) $(OBJ) -o jdn

obj/main.o: main.cpp
	$(CC) $(CFLAGS) -c -o obj/main.o main.cpp

obj/jdn.o : src/jdn.h src/jdn.cpp
	$(CC) $(CFLAGS) -c -o obj/jdn.o src/jdn.cpp

obj/parseOptarg.o : src/parseOptarg.h src/parseOptarg.cpp
	$(CC) $(CFLAGS) -c -o obj/parseOptarg.o src/parseOptarg.cpp

obj/jdnParseDate.o : src/jdnParseDate.cpp
	$(CC) $(CFLAGS) -c -o obj/jdnParseDate.o src/jdnParseDate.cpp

obj/jdnCalculateJdnMeeus1998.o : src/jdnCalculateJdnMeeus1998.cpp
	$(CC) $(CFLAGS) -c -o obj/jdnCalculateJdnMeeus1998.o src/jdnCalculateJdnMeeus1998.cpp

obj/jdnCalculateJdn.o : src/jdnCalculateJdn.cpp
	$(CC) $(CFLAGS) -c -o obj/jdnCalculateJdn.o src/jdnCalculateJdn.cpp

obj/sunpos.o : src/sunpos.cpp
	$(CC) $(CFLAGS) -c -o obj/sunpos.o src/sunpos.cpp	

obj/spPrintOutput.o : src/spPrintOutput.cpp
	$(CC) $(CFLAGS) -c -o obj/spPrintOutput.o src/spPrintOutput.cpp

clean:
	rm -rf obj/*.o jdn

