gpio: main.o
	gcc -Wall -O3 main.o -lwiringPi -L. -lgetPosition -o gpio
main.o: main.c
	gcc -Wall -O3 -o main.o -c main.c

.PHONY: clean

clean:
	rm -f *.o gpio
