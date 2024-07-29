#include "lcdlib.h"
#include "i2clib.h"

void gameOver(void)
{
	initBase();
	initI2C();
	initLCD();

	while (1) {
		printFstr(5,5,"Game Over!!!!");
	}
}
