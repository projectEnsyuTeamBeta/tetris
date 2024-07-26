#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"

#define WALL_HEIGHT     20
#define FLOOR_WIDTH     10 + 2

void gameClear(void);
void gameOver(void);
void main(void)
{
    int i;
    int j;

    initBase();
	initI2C();
	initLCD();


	while (1) {
        for(i = 5; i < FLOOR_WIDTH; i++){
            drawString(i,0,"?");
        }
        for(j = 0; j < WALL_HEIGHT; j++){
            drawString(5,j,"?");
            drawString(17,j,"?");
        }
        
        PORT0.PDR.BIT.B0 = 0;
        PORT0.PDR.BIT.B1 = 0;
        PORT0.PDR.BIT.B2 = 0;

        if(PORT0.PIDR.BIT.B0 == 1){
            gameClear();
        }else if(PORT0.PIDR.BIT.B2 == 1){
            gameOver();
        }
	}
}