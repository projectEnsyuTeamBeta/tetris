#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"
//#include "onoff.h"


void gameStart(void)
{
    initBase();
    initI2C();
    initLCD();
// ?intSx5Int();

    while(1){
        printFstr(10,5,"TETRIS");
        printFstr(10,7,"GameStart->SW5");
// ? ? ?printFstr(10,7,"真ん中のボタンを押すとゲーム開始");
// ? ? ?printFstr(10,8,"-操作説明- 左:左に動く 真ん中:右回転 右:右に動く");

        PORT0.PDR.BIT.B1=0;
        if (PORT0.PIDR.BIT.B1 == 1)
        {
            main();
        }
    }

}
