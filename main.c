#include <wiringPi.h>

int main (int argc, char *argv[]){
	wiringPiSetup();
	pinMode(0, INPUT);
	pinMode(1, INPUT);
	pinMode(2, INPUT);
	pinMode(3, INPUT);
	pinMode(4, INPUT);
	pinMode(5, INPUT);
	pinMode(6, INPUT);
	pinMode(7, INPUT);
	pinMode(8, INPUT);
	pinMode(9, INPUT);
	pinMode(10, INPUT);
	pinMode(11, INPUT);
	pinMode(12, INPUT);
	pinMode(13, INPUT);
	pinMode(14, INPUT);
	pinMode(15, INPUT);
	pinMode(16, INPUT);
	pinMode(21, INPUT);
	pinMode(22, INPUT);
	pinMode(19, INPUT);
	pinMode(20, INPUT);
	pinMode(21, INPUT);
	pinMode(22, INPUT);
	pinMode(23, INPUT);

	pinMode(24, OUTPUT);

	pinMode(25, INPUT);
	pinMode(26, INPUT);

	pinMode(27, OUTPUT);
	pinMode(28, OUTPUT);

	digitalWrite(24, HIGH);
	digitalWrite(27, HIGH);
	digitalWrite(28, HIGH);

	int i[47];
	while(1) {
		digitalWrite(0, LOW);

		i = digitalRead(2);

		digitalWrite(1, LOW);
		digitalWrite(15, LOW);

		i[0] = digitalRead(0);
		i[1] = digitalRead(1);
		i[2] = digitalRead(2);
		i[3] = digitalRead(3);
		i[4] = digitalRead(4);
		i[5] = digitalRead(5);
		i[6] = digitalRead(6);
		i[7] = digitalRead(7);
		i[8] = digitalRead(8);
		i[9] = digitalRead(9);
		i[10] = digitalRead(10);
		i[11] = digitalRead(11);

		digitalWrite(0, HIGH);

		digitalWrite(15, HIGH);
		digitalWrite(15, LOW);

		i[12] = digitalRead(12);
		i[13] = digitalRead(13);
		i[14] = digitalRead(14);
		i[15] = digitalRead(15);
		i[16] = digitalRead(16);
		i[17] = digitalRead(17);
		i[18] = digitalRead(18);
		i[19] = digitalRead(19);
		i[20] = digitalRead(20);
		i[21] = digitalRead(21);
		i[22] = digitalRead(22);
		i[23] = digitalRead(23);

		digitalWrite(15, HIGH);
		digitalWrite(1, HIGH);
	}

	return 0;
}
