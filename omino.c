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

#define LEFT_WALL   9   /* ���ǂ�X���W�F�~�m�ɂ���ĉϕK�v */
#define RIGHT_WALL  17  /* �E�ǂ�X���W�F�~�m�ɂ���ĉϕK�v */
#define GROUND   18     /* ����Y���W */

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
    int i, j;        /* �~�m�`��p */
    int height = 1;   /* �~�m�`��p */
    int x = 14;     /* �~�m�`��p */
    int time;       /* �E�F�C�g */

    PORT0.PDR.BIT.B0 = 0;
    PORT0.PDR.BIT.B1 = 0;
    PORT0.PDR.BIT.B2 = 0;

    /*-----------------------------------
        �~�m�̕`��
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
        SW4,5,6�ɂ�鑀��
    -----------------------------------*/
        while (1) { 
            if (PORT0.PIDR.BIT.B0 == 1 && x > LEFT_WALL) {            /* SW4 : ���ړ� */
                x -= 1;
                break;
            } else if (PORT0.PIDR.BIT.B2 == 1 && x < RIGHT_WALL) {      /* SW6 : �E�ړ� */
                x += 1;
                break;
            } else if (PORT0.PIDR.BIT.B1 == 1) {       /* SW5 : ��]���� */
                ;                                   /* ��]�����Ȃ� */
            }
            /* �E�F�C�g */
            for (time = 0; time < 10; time++);
            break;
        }

    /*-----------------------------------
        ��]�O�A��]��̃~�m�̏���
    -----------------------------------*/		
        /* �ݒu����1�@�r���Ƀ~�m���������ꍇ */
        if (g_stage[height + 1][x + 5] == 2 || g_stage[height + 1][x + 4] == 2) {
            g_stage[height][x + 5] = 2;
            g_stage[height - 1][x + 5] = 2;
            g_stage[height][x + 4] = 2;
            g_stage[height - 1][x + 4] = 2;
            height = GROUND;
        }
        /* �ݒu����2�@��ԉ��܂ōs���ꍇ */
        else if (height == 17) {
            g_stage[height + 1][x + 5] = 2;
            g_stage[height][x + 5] = 2;
            g_stage[height + 1][x + 4] = 2;
            g_stage[height][x + 4] = 2;
            height = GROUND;
        }
        /* �������� */
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