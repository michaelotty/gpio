gpio: main.c
	gcc -Wall -O3 -o gpio main.c lib/getPosition.lib -lwiringPi
