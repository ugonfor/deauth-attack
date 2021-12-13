LDLIBS = -lpcap
CC = g++

all: deauth-attack

deauth-attack: deauth-attack.o main.o

deauth-attack.o: deauth-attack.cpp deauth-attack.h

main.o: main.cpp deauth-attack.h

clean:
	rm -f *.o deauth-attack