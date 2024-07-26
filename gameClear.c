
#include "lcdlib.h"
#include "i2clib.h"
#include "ad.h"

void gameClear(void);

void gameClear(void)
{
	initBase();
	initI2C();
	initLCD();
	initAD();

	while (1) {
		printFstr(5,5,"Game Clear!!");
	}
}
