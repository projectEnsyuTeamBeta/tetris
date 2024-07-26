#include "lcdlib.h"
#include "i2clib.h"

#define WALL_HEIGHT     20
#define FLOOR_WIDTH     10 + 2

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