/*=======================================================================
Project    :  Tetris
File       :  tetris.c
Function   :  Supervision Function
Revision   :  1.00 TeamBeta Create
Copyright(c) 2024   Team Beta
=======================================================================*/

#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"
#include "field.h"

#define X_POS    i + 9      /* ス�?ージ座標�?�X軸 */
#define Y_POS    j + 1      /* ス�?ージ座標�?�Y軸 */

int g_stage[21][12]= {
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,2,2,2,2,2,2,2,2,2,2,1}
};


void gameClear(void);
void gameOver(void);
void dropMino(void);
void derete(int);

/*=======================================================================
Func Name     :  tetris
Function      :  All date Control
Param Input   :  None
Param Output  :  None
Return Val    :  None
Input Inf     :  Coordinate date mapping
Output Inf    :  Output coord date
Note          :  
Revision      :  1.00  2024/07/29  TeamBeta Create
=======================================================================*/

void tetris(void)
{

    int i, j;
    int a;      /* ゲー�?オーバ�?�の判定に使用　*/

    initBase();
    initI2C();
    initLCD();

    setFontSize(16, 12);
    setTextColor(CLR_GREY);

	while (1) {
    /*-----------------------------------
        フィールド�?�座標をLCDに表示
    -----------------------------------*/
        for (j = 0; j < 21; j++) {                        
            for (i = 0; i < 12; i++) {
                if (g_stage[j][i] == 0) {
                    printFstr(X_POS, Y_POS, " ");     
                } else if (g_stage[j][i] == 1) {
                    printFstr(X_POS, Y_POS, "O");
                } else if(g_stage[j][i] == 2) {
                    if (j == 20) {
                        printFstr(X_POS, Y_POS, "O");
                    }
                    else {
                        printFstr(X_POS, Y_POS, "#");
                    }
                }
            }
        }

    /*-----------------------------------
        ゲー�?オーバ�?�判�?
    -----------------------------------*/
        for (a = 1; a < 11; a++) {
            if (g_stage[1][a] >= 2) {
                gameOver();
            } else {
                ;
            }
        }
    /*-----------------------------------
        新しいミノの処�?開�?
    -----------------------------------*/
        dropMino();    
	}
}