#define D0 0
#define D1 1
#define D2 2
#define D3 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define D8 8
#define D9 9
#define D10 10
#define D11 11
#define CONV 12
#define BUSY 13
#define RD 14
#define CS_A 15
#define CS_B 16

#include <stdio.h>
#include <time.h>
#include <wiringPi.h>

int getSample();

int main(int argc, char *argv[]){
	wiringPiSetup();
	pinMode(D0, INPUT);
	pinMode(D1, INPUT);
	pinMode(D2, INPUT);
	pinMode(D3, INPUT);
	pinMode(D4, INPUT);
	pinMode(D5, INPUT);
	pinMode(D6, INPUT);
	pinMode(D7, INPUT);
	pinMode(D8, INPUT);
	pinMode(D9, INPUT);
	pinMode(D10, INPUT);
	pinMode(D11, INPUT);
	pinMode(CONV, OUTPUT);
	pinMode(BUSY, INPUT);
	pinMode(RD, OUTPUT);
	pinMode(CS_A, OUTPUT);
	pinMode(CS_B, OUTPUT);

	digitalWrite(CS_A, HIGH);
	digitalWrite(CS_B, HIGH);
	digitalWrite(RD, HIGH);

	int data[4];
  
	clock_t start, end;
  	double cpu_time;

  	start = clock();
	for(int j = 0; j<100; j++) {
		digitalWrite(CONV, LOW);
		digitalWrite(CONV, HIGH);

		while(digitalRead(BUSY)){
			printf("loop\n");
		}// Wait until BUSY is 0

		digitalWrite(RD, LOW);
		digitalWrite(CS_A, LOW);

		data[0] = getSample();

		digitalWrite(CS_A, HIGH);

		digitalWrite(CS_B, LOW);

		data[1] = getSample();

		digitalWrite(RD, HIGH);
		digitalWrite(CS_B, HIGH);

		digitalWrite(RD, LOW);
		digitalWrite(CS_A, LOW);

		data[2] = getSample();

		digitalWrite(CS_A, HIGH);

		digitalWrite(CS_B, LOW);

		data[3] = getSample();

		digitalWrite(CS_B, HIGH);
		digitalWrite(RD, HIGH);
		printf("\n"); 
	}

	end = clock();
	cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("time: %f\n", cpu_time);
	return 0;
}

int getSample() {
	int a, b, c, d, e, f, g, h, i, j, k, l;
	a = digitalRead(D11);
	a = a << 11;
	b = digitalRead(D10);
	b = b << 10;
	c = digitalRead(D9);
	c = c << 9;
	d = digitalRead(D8);
	d = d << 8;
	e = digitalRead(D7);
	e = e << 7;
	f = digitalRead(D6);
	f = f << 6;
	g = digitalRead(D5);
	g = g << 5;
	h = digitalRead(D4);
	h = h << 4;
	i = digitalRead(D3);
	i = i << 3;
	j = digitalRead(D2);
	j = j << 2;
 	k = digitalRead(D1);
	k = k << 1;
 	l = digitalRead(D0);
	
	int sample = 0x000 | b | c | d | e | f | g | h | i | j | k | l;

  	if (a) {
    		sample = sample & 0xFFF;
	}

  	printf("%d\t", sample);
//  printf("%d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j, k, l); 

	return sample;
}

