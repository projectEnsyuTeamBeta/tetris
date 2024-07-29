#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"

void tetris(void);
void main(void)
{
    initBase();
    initI2C();
    initLCD();

    while(1){
        printFstr(10,5,"TETRIS");
        printFstr(10,7,"GameStart->SW5");

        PORT0.PDR.BIT.B1=0;
        if (PORT0.PIDR.BIT.B1 == 1)
        {
            tetris();
        }
    }

}
