#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"

#define WALL_HEIGHT     20
#define FLOOR_WIDTH     10 + 2
#define HAICHI      9

void gameClear(void);
void gameOver(void);
void dropMino(void);
void main(void)
{
    int i, j;
    int k, l;
    int stage = 0; //stage関数で0or1

    initBase();
	initI2C();
	initLCD();

    setFontSize(16,12);
    setTextColor(CLR_GREY);
	while (1) {
        for(i = HAICHI; i < (FLOOR_WIDTH + HAICHI); i++){
            printFstr(i,21,"#");
        }
        for(j = 1; j < (WALL_HEIGHT + 1); j++){
            printFstr(HAICHI,j,"?");
            printFstr(HAICHI + 11,j,"?");
        }
        for(k = (HAICHI+1); k < (HAICHI+11);k++){
            for(l = 1; l < (WALL_HEIGHT + 1); l++){
                if(stage == 0){
                    printFstr(k,l," ");     // Aを変更（0：非表示/1：ミノ配置）
                }else if(stage == 1){
                    printFstr(k,l,"A");
                }
            }
        }
        
        /* PORT0.PDR.BIT.B0 = 0;
        PORT0.PDR.BIT.B1 = 0;
        PORT0.PDR.BIT.B2 = 0;

        if(PORT0.PIDR.BIT.B0 == 1){
            gameClear();
        }else if(PORT0.PIDR.BIT.B2 == 1){
            gameOver();
        } */

        dropMino();
	}
}