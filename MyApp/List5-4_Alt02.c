#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define LED0  23
#define SW0  4

int main(void){
	int i = 0;
	int alt0 = LOW;
	int s0Now = LOW;
	int s0Old = LOW;
	
	wiringPiSetupGpio();
	pinMode(LED0, OUTPUT);
	pinMode(SW0, INPUT);
	pullUpDnControl(SW0, PUD_DOWN);
	
	while(1){
		s0Now = digitalRead(SW0);
		if(s0Now == HIGH && s0Old == LOW){
			delay(20);
			if(digitalRead(SW0) == HIGH){
				alt0 = !alt0;
				digitalWrite(LED0, alt0);
				s0Old = HIGH;
				
				printf("%d\n", ++i);
			}else{
				s0Old = LOW;
			}
		}
		else if(s0Now == HIGH && s0Old == HIGH){
			s0Old = HIGH;
		}
		else{
			s0Old = LOW;
		}
		
		if(i > 10){
			break;
		}
	}
	
	return EXIT_SUCCESS;

}
