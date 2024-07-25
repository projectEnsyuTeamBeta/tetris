

#include "lcdlib.h"
#include "i2clib.h"
#include "ad.h"


void main(void)
{
	int adData1;
	int adData2;

	initBase();
	initI2C();
	initLCD();
	initAD();

	while (1) {
		waitTimeMS(10);
		adData1 = getVR1();
		adData2 = getVR2();
		

		printFstr( 5, 5, "%8d", adData1);
		printFstr(15, 5, "%8d",1024 );
	}
}
