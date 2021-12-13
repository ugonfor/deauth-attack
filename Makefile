LDLIBS = -lpcap -lpthread
CC = g++

all: deauth-attack

deauth-attack: deauth-attack.o main.o Gheader/mac.o

deauth-attack.o: deauth-attack.cpp deauth-attack.h Gheader/mac.h

main.o: main.cpp deauth-attack.h Gheader/mac.h

clean:
	rm -f *.o deauth-attack Gheader/*.o