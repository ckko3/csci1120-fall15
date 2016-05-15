CC=g++
CFLAGS=-Wall
EXE=tour

all: ${EXE}
${EXE}: *.o
	g++ -Wall *.o -o ${EXE}
*.o: *.cpp
	g++ -Wall -c *.cpp

clean:
	/bin/rm -f *.o ${EXE}
