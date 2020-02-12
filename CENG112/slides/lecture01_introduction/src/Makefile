# filename: Makefile
CXXFLAGS:=-g -Wall

all: hello args fahr2celc

hello: hello.o
	g++ ${CXXFLAGS} $^ -o $@

args: args.o
	g++ ${CXXFLAGS} $^ -o $@

fahr2celc: fahr2celc.o temp_utils.o
	g++ ${CXXFLAGS} $^ -o $@

temp_utils.o: temp_utils.cc temp_utils.h
	g++ -c ${CXXFLAGS} $< -o $@

clean:
	rm *.o *~ -f
