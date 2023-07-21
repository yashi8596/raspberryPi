#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define SW0  4
int ledGpio[4] = {23, 22, 25, 24};

int main (void){
	int i;
	wiringPiSetupGpio();
	for(i = 0;i < 4;i++){
		pinMode(ledGpio[i], OUTPUT);
	}
	
	pinMode(SW0, INPUT);

	
	while(1){
		if(digitalRead(SW0) == HIGH){
			digitalWrite(ledGpio[0], HIGH);
		}
		else{
			digitalWrite(ledGpio[0], LOW);
		}
	}
	
	return EXIT_SUCCESS;
}
	
