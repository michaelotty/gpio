//Define all the pin number names
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

//Libraries
#include <stdio.h>
#include <wiringPi.h>

//Function declaration
int getSample();

//Function definitions
int main(int argc, char *argv[]){
	delay(5000);// 5 seconds

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

	int loops = 8000;
	int data[(4*loops)-1];

	for (int i = 0; i < loops; i++) {
		digitalWrite(CONV, LOW);
		digitalWrite(CONV, HIGH);

		while (digitalRead(BUSY)) {
			printf("ADC is busy...\n");
		}

		digitalWrite(RD, LOW);
		digitalWrite(CS_A, LOW);

		data[4*i] = getSample();

		digitalWrite(CS_A, HIGH);
		digitalWrite(CS_B, LOW);

		data[4*i+1] = getSample();

		digitalWrite(RD, HIGH);
		digitalWrite(CS_B, HIGH);

		digitalWrite(RD, LOW);
		digitalWrite(CS_A, LOW);

		data[4*i+2] = getSample();

		digitalWrite(CS_A, HIGH);
		digitalWrite(CS_B, LOW);

		data[4*i+3] = getSample();

		digitalWrite(CS_B, HIGH);
		digitalWrite(RD, HIGH);
	}

	FILE *f;
        f = fopen("output.txt", "w");
	for (int i = 0; i < (4*loops); i++) {
		fprintf(f, "%d\n", data[i]);
	}
	fclose(f);

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

	int sample = 0x000 | a | b | c | d | e | f | g | h | i | j | k | l;

	sample = (sample >> 11) == 0 ? sample : (-1 ^ 0xFFF) | sample;

	return sample;
}
