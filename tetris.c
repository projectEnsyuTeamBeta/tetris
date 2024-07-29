#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"
#include "field.h"

#define X_POS    i + 9
#define Y_POS    j + 1

void gameClear(void);
void gameOver(void);
void dropMino(void);

void tetris(void)
{
    int i,j;

    initBase();
	initI2C();
	initLCD();

    setFontSize(16,12);
    setTextColor(CLR_GREY);

	while (1) {
        for(j = 0; j < 21; j++){
            for(i = 0; i < 12;i++){
                if(stage[j][i] == 0){
                    printFstr(X_POS,Y_POS,"0");     // Aを変更（0：非表示/1：ミノ配置）
                }else if(stage[j][i] == 1){
                    printFstr(X_POS,Y_POS,"1");
                }
            }
        }

        dropMino();
	}
}