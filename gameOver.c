#include "lcdlib.h"
#include "i2clib.h"
#include "ad.h"


void main(void)
{
	initBase();
	initI2C();
	initLCD();
	initAD();

	while (1) {
		printFstr(5,5,"Game Over!!!!");
	}
}
