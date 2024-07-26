#include "lcdlib.h"
#include "i2clib.h"
#include "ad.h"

void main(void)
{

    initBase();
	initI2C();
	initLCD();

	while (1) {
        PORT0.PDR.BIT.B4 = 0;
        PORT0.PDR.BIT.B5 = 0;
        PORT0.PDR.BIT.B6 = 0;

        if(PORT0.PIDR.BIT.B4 == 1){
            gameClear();
        }else if(PORT0.PIDR.BIT.B6 == 1){
            gameOver();
        }
	}
    
}