/*=======================================================================
Project    :  Tetris
File       :  omino.c
Function   :  Omino Function to Control
Revision   :  1.00 TeamBeta Create
Copyright(c) 2024   Team Beta
=======================================================================*/

#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"
#include "field.h"
#include <string.h>

#define LEFT_WALL   9   /* 左壁のX座標：ミノによって可変必要 */
#define RIGHT_WALL  17  /* 右壁のX座標：ミノによって可変必要 */
#define GROUND   18     /* 床のY座標 */

/*=======================================================================
Func Name     :  omino
Function      :  Display and Control Omino
Param Input   :  None
Param Output  :  None
Return Val    :  None
Input Inf     :  g_stage => Coordinate mapping  
Output Inf    :  g_stage => Coordinate date changed
Note          :  
Revision      :  1.00  2024/07/29  TeamBeta Create
=======================================================================*/

void omino(void)
{
    int O_mino[4][4] = {
        {0,0,0,0},
        {0,1,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };
    int i, j;        /* ミノ描画用 */
    int height = 1;   /* ミノ描画用 */
    int x = 14;     /* ミノ描画用 */
    int time;       /* ウェイト */

    PORT0.PDR.BIT.B0 = 0;
    PORT0.PDR.BIT.B1 = 0;
    PORT0.PDR.BIT.B2 = 0;

    /*-----------------------------------
        ミノの描画
    -----------------------------------*/
    while (height < GROUND) {
        for (time = 0; time < SPEED; time++) {
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {
                    if (O_mino[i][j] == 1) {
                        printFstr(x, height, "#");
                    }
		            else {
                        printFstr(x, height, " ");
                    }
                    x += 1;
                }
                x -= 4;
                height += 1;
            }
            height -= 4;
        }

    /*-----------------------------------
        SW4,5,6による操作
    -----------------------------------*/
        while (1) { 
            if (PORT0.PIDR.BIT.B0 == 1 && x > LEFT_WALL) {            /* SW4 : 左移動 */
                x -= 1;
                break;
            } else if (PORT0.PIDR.BIT.B2 == 1 && x < RIGHT_WALL) {      /* SW6 : 右移動 */
                x += 1;
                break;
            } else if (PORT0.PIDR.BIT.B1 == 1) {       /* SW5 : 回転処理 */
                ;                                   /* 回転させない */
            }
            /* ウェイト */
            for (time = 0; time < 10; time++);
            break;
        }

    /*-----------------------------------
        回転前、回転後のミノの処理
    -----------------------------------*/		
        /* 設置処理1　途中にミノがあった場合 */
        if (g_stage[height + 1][x + 5] == 2 || g_stage[height + 1][x + 4] == 2) {
            g_stage[height][x + 5] = 2;
            g_stage[height - 1][x + 5] = 2;
            g_stage[height][x + 4] = 2;
            g_stage[height - 1][x + 4] = 2;
            height = GROUND;
        }
        /* 設置処理2　一番下まで行く場合 */
        else if (height == 17) {
            g_stage[height + 1][x + 5] = 2;
            g_stage[height][x + 5] = 2;
            g_stage[height + 1][x + 4] = 2;
            g_stage[height][x + 4] = 2;
            height = GROUND;
        }
        /* 落下処理 */
        else{
            for (time = 0; time < (SPEED); time++) {
                for (i = 0; i < 4; i++) {
                    for (j = 0; j < 4; j++) {
                        if (O_mino[i][j] == 1) {
                            printFstr(x, height, "#");
                        } else {
                            printFstr(x, height, " ");
                        }
                        x += 1;
                    }
                    x -= 4 ;
                    height += 1 ;
                }
                height -= 4 ;
            }
            height++;
        }
    }
}