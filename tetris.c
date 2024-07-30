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

#define X_POS    i + 9      /* �X�e�[�W���W��X�� */
#define Y_POS    j + 1      /* �X�e�[�W���W��Y�� */

volatile g_stage[21][12]= {
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
    int a;      /* �Q�[���I�[�o�[�̔���Ɏg�p�@*/

    initBase();
    initI2C();
    initLCD();

    setFontSize(16, 12);
    setTextColor(CLR_GREY);

	while (1) {
    /*-----------------------------------
        �t�B�[���h�̍��W��LCD�ɕ\��
    -----------------------------------*/
        for (j = 0; j < 21; j++) {                        
            for (i = 0; i < 12; i++) {
                if (g_stage[j][i] == 0) {
                    printFstr(X_POS, Y_POS, "0");     
                } else if (g_stage[j][i] == 1) {
                    printFstr(X_POS, Y_POS, "1");
                } else if(g_stage[j][i] == 2) {
                    if (j == 20) {
                        printFstr(X_POS, Y_POS, "2");
                    }
                    else {
                        printFstr(X_POS, Y_POS, "#");
                    }
                }
            }
        }
    /*-----------------------------------
        �Q�[���I�[�o�[����
    -----------------------------------*/
        for (a = 1; a < 11; a++) {
            if (g_stage[1][a] >= 2) {
                gameOver();
            } else {
                ;
            }
        }
    /*-----------------------------------
        �V�����~�m�̏����J�n
    -----------------------------------*/
        dropMino();
	}
}