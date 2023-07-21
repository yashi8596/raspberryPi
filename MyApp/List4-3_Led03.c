#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

//LEDを0, 1, 2, 3, 0, 1, 2, 3, 0...の順に点灯させるプログラム

int LED[4] = {23, 22, 25, 24};

int main(void){
	if(wiringPiSetupGpio() == -1){
		return EXIT_FAILURE;
	}
	
	int i = 0, j = 0, k, l;
	for(; i < 4; i++){
		pinMode(LED[i], OUTPUT);
	}
	
	for(i = 0; i < 20; i++){
		j = i % 4;
		
		digitalWrite(LED[(j + 3) % 4], 0);
		digitalWrite(LED[j], 1);
		delay(100);
		
		if(i != 19){
			digitalWrite(LED[j], 0);
			digitalWrite(LED[(j + 1) % 4], 1);
			delay(100);
		}
	
	}
	
	for(k = 0; k < 8; k++){
				
		for(l = 0; l < 4; l++){
			digitalWrite(LED[l], 1);
		}
		delay(250);
				
		for(l = 0; l < 4; l++){
			digitalWrite(LED[l], 0);
		}
		delay(250);
	}

	
	return EXIT_SUCCESS;
}
