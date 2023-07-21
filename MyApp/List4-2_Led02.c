#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#define LED0 23
#define LED1 22
#define LED2 25
#define LED3 24

int main(void){
	if(wiringPiSetupGpio() == -1){
		return EXIT_FAILURE;
	}
	pinMode(LED0, OUTPUT);
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);
	for(int i = 0; i < 10; i++){
		digitalWrite(LED0, 1);
		digitalWrite(LED1, 1);
		digitalWrite(LED2, 1);
		digitalWrite(LED3, 1);
		delay(500);
		digitalWrite(LED0, 0);
		digitalWrite(LED1, 0);
		digitalWrite(LED2, 0);
		digitalWrite(LED3, 0);
		delay(500);
	}
	
	return EXIT_SUCCESS;
}
