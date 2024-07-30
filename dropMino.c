/*=======================================================================
Project    :  Tetris
File       :  dropMino.c
Function   :  Select Mino Function
Revision   :  1.00 TeamBeta Create
Copyright(c) 2024   Team Beta
=======================================================================*/

#include <stdlib.h>

void imino(void);
void tmino(void);
void zmino(void);
void smino(void);
void lmino(void);
void jmino(void);
void omino(void);

/*=======================================================================
Func Name     :  dropMino
Function      :  Select mino
Param Input   :  None
Param Output  :  None
Return Val    :  None
Input Inf     :  None
Output Inf    :  None
Note          :  
Revision      :  1.00  2024/07/29  TeamBeta Create
=======================================================================*/

void dropMino(void)
{
    /*-----------------------------------
        乱数によるミノの選出
    -----------------------------------*/
    int max = 6;    /* 乱数の最大値 */
    int min = 0;    /* 乱数の最小値 */
    int makeMino = min + (int)(rand() * (max - min + 1) / ( 1 + RAND_MAX));      
    
    /*-----------------------------------
        選出されたミノの関数へ遷移
    -----------------------------------*/
    switch (makeMino) {
        case 0:
            imino();
            break;
        case 1:
            tmino();
            break;
        case 2:
            zmino();
            break;
        case 3:
            smino();
            break;
        case 4:
            lmino();
            break;
        case 5:
            jmino();
            break;
        case 6:
            omino();
            break;
        
        default:        /* エラー処理 */
            break;
    }
}
