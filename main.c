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
	pinMode(12, OUTPUT);
	pinMode(13, INPUT);
	pinMode(14, OUTPUT);
	pinMode(15, OUTPUT);
	pinMode(16, OUTPUT);

	digitalWrite(14, HIGH);
	digitalWrite(15, HIGH);
	digitalWrite(16, HIGH);

	int i[47];
	while(1) {
		digitalWrite(12, LOW);
		digitalWrite(12, HIGH);

		int j = digitalRead(2);
		digitalWrite(14, LOW);
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
		
		digitalWrite(15, HIGH);
		
		digitalWrite(16, LOW);

		i[12] = digitalRead(0);
		i[13] = digitalRead(1);
		i[14] = digitalRead(2);
		i[15] = digitalRead(3);
		i[16] = digitalRead(4);
		i[17] = digitalRead(5);
		i[18] = digitalRead(6);
		i[19] = digitalRead(7);
		i[20] = digitalRead(8);
		i[21] = digitalRead(9);
		i[22] = digitalRead(10);
		i[23] = digitalRead(11);
		
		digitalWrite(14, HIGH);
		digitalWrite(16, HIGH);
		
		digitalWrite(14, LOW);
		digitalWrite(15, LOW);

		i[24] = digitalRead(28);
		i[25] = digitalRead(25);
		i[26] = digitalRead(26);
		i[27] = digitalRead(27);
		i[28] = digitalRead(28);
		i[29] = digitalRead(29);
		i[30] = digitalRead(30);
		i[31] = digitalRead(19);
		i[32] = digitalRead(20);
		i[33] = digitalRead(21);
		i[34] = digitalRead(22);
		i[35] = digitalRead(23);

		digitalWrite(15, HIGH);

		digitalWrite(16, LOW);

		i[36] = digitalRead(28);
		i[37] = digitalRead(25);
		i[38] = digitalRead(26);
		i[39] = digitalRead(27);
		i[40] = digitalRead(28);
		i[41] = digitalRead(29);
		i[42] = digitalRead(30);
		i[43] = digitalRead(19);
		i[44] = digitalRead(20);
		i[45] = digitalRead(21);
		i[46] = digitalRead(22);
		i[47] = digitalRead(23);

		digitalWrite(16, HIGH);
    digitalWrite(14, HIGH);
	}

	return 0;
}
