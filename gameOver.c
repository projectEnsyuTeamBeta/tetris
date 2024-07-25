#include "lcdlib.h"
#include "i2clib.h"

void gameOver(void)
{

	initBase();
	initI2C();
	initLCD();
	initAD();

	while (1) {
		waitTimeMS(10);
		printFstr( 5, 10, "GAME OVER!!!");
	}
}