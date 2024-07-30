/*=======================================================================
Project    :  Tetris
File       :  main.c
Function   :  GameStart Function
Revision   :  1.00 TeamBeta Create
Copyright(c) 2024   Team Beta
=======================================================================*/

#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"

void tetris(void);

/*=======================================================================
Func Name     :  main
Function      :  Display on LCD "GameStart"
Param Input   :  None
Param Output  :  None
Return Val    :  None
Input Inf     :  None
Output Inf    :  None
Note          :  
Revision      :  1.00  2024/07/29  TeamBeta Create
=======================================================================*/

void main(void)
{
    initBase();
    initI2C();
    initLCD();

    /*-----------------------------------
        ゲームスタート画面の表示
        SW5を押すとゲームスタート
    -----------------------------------*/
    while (1) {
        printFstr(10, 5, "TETRIS");
        printFstr(10, 7, "GameStart->SW5");

        PORT0.PDR.BIT.B1 = 0;
        if (PORT0.PIDR.BIT.B1 == 1) {
            tetris();
        }
    }
}
