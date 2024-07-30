/*=======================================================================
Project    :  Tetris
File       :  gameOver.c
Function   :  GameOver Function
Revision   :  1.00 TeamBeta Create
Copyright(c) 2024   Team Beta
=======================================================================*/

#include "lcdlib.h"
#include "i2clib.h"

/*=======================================================================
Func Name     :  gameOver
Function      :  Display on LCD "GameOver"
Param Input   :  None
Param Output  :  None
Return Val    :  None
Input Inf     :  None
Output Inf    :  None
Note          :  
Revision      :  1.00  2024/07/29  TeamBeta Create
=======================================================================*/

void gameOver(void)
{
	initBase();
	initI2C();
	initLCD();

    /*-----------------------------------
        ゲームオーバー画面の表示
    -----------------------------------*/
	while (1) {
		printFstr(5, 5, "Game Over!!!!");
	}
}
