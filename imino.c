/*=======================================================================
Project    :  Tetris
File       :  imino.c
Function   :  Imino Function to Control
Revision   :  1.00 TeamBeta Create
Copyright(c) 2024   Team Beta
=======================================================================*/

#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"
#include "field.h"
#include <string.h>

#define LEFT_WALL   10  /* ���ǂ�X���W�F�~�m�ɂ���ĉϕK�v */
#define RIGHT_WALL  16  /* �E�ǂ�X���W�F�~�m�ɂ���ĉϕK�v */
#define GROUND   18     /* ����Y���W */


/*=======================================================================
Func Name     :  imino
Function      :  Display and Control Imino
Param Input   :  None
Param Output  :  None
Return Val    :  None
Input Inf     :  g_stage => Coordinate mapping  
Output Inf    :  g_stage => Coordinate date changed
Note          :  
Revision      :  1.00  2024/07/29  TeamBeta Create
=======================================================================*/

void imino(void)
{
    int I_mino[4][4] = {
        {0,0,0,0},
        {1,1,1,1},
        {0,0,0,0},
        {0,0,0,0}
    };
    int i, j;        /* �~�m�`��p */
    int height = 1;   /* �~�m�`��p */
    int x = 14;     /* �~�m�`��p */
    int time;       /* �E�F�C�g */
    int temp[4][4]; /* ��]�����p */
    int k, l;        /* ��]�����p */
    int cnt = 0;      /* SW5�̉����ꂽ��(=����]������)���J�E���g���� */
    
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
                    if (I_mino[i][j] == 1) {
                        printFstr(x, height, "#");
                    } else {
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
            if (PORT0.PIDR.BIT.B0 == 1 && x > LEFT_WALL) {    /* SW4 : ���ړ� */
                for (i = 0; i < 4; i++) {
                    for (j = 0; j < 4; j++) {
                        if (I_mino[i][j] == 1) {
                            printFstr(x, height, " ");
                        }
                        x += 1;
                    }
                    x -= 4;
                    height += 1;
                }
                height -= 4;
                x -= 1;
                break;
            } else if (PORT0.PIDR.BIT.B2 == 1 && x < RIGHT_WALL) {     /* SW6 : �E�ړ� */
                for (i = 0; i < 4; i++) {
                    for (j = 0; j < 4; j++) {
                        if (I_mino[i][j] == 1) {
                            printFstr(x, height, " ");
                        }
                        x += 1;
                    }
                    x -= 4;
                    height += 1;
                }
                height -= 4 ;
                x += 1;
                break;
            } else if (PORT0.PIDR.BIT.B1 == 1) {       /* SW5 : ��]���� */
                for (k = 0; k < 4; k++) {     
                    for (l = 0; l < 4; l++) {
                        temp[l][k] = I_mino[3 - k][l];
                    }
                }
                memcpy(I_mino, temp, sizeof temp);
                cnt++;
                break;
            }
            /* �E�F�C�g */
            for (time = 0; time < 10; time++);
            break;
        }
        
    /*-----------------------------------
        ��]�O�A��]��̃~�m�̏���
    -----------------------------------*/
        switch (cnt % 4) {
            case 0:
                /* �ݒu����1�@�r���Ƀ~�m���������ꍇ */
                if (g_stage[height + 1][x + 6] == 2 || g_stage[height + 1][x + 5] == 2 || g_stage[height + 1][x + 4] == 2 || g_stage[height + 1][x + 3] == 2) {
                    g_stage[height][x + 6] = 2;
                    g_stage[height][x + 5] = 2;
                    g_stage[height][x + 4] = 2;
                    g_stage[height][x + 3] = 2;
                    height = GROUND;
                }
                /* �ݒu����2�@��ԉ��܂ōs���ꍇ */
                else if (height == 17) {
                    g_stage[height + 1][x + 6] = 2;
                    g_stage[height + 1][x + 5] = 2;
                    g_stage[height + 1][x + 4] = 2;
                    g_stage[height + 1][x + 3] = 2;
                    height = GROUND;
                }
                /* �������� */
                else{
                    for (time = 0; time < 2; time++) {
                        for (i = 0; i < 4; i++) {
                            for (j = 0; j < 4; j++) {
                                if (I_mino[i][j] == 1) {
                                    printFstr(x, height, " ");
                            }
                                else{
                                    printFstr(x, height, " ");
                            }
                                x += 1;
                            }
                            x -= 4;
                            height += 1;
                        }
                        height -= 4;
                    }
                    height++;
                }    
            
            case 1:
                /* �ݒu����1�@�r���Ƀ~�m���������ꍇ */
                if (g_stage[height + 1][x + 5] == 2) {
                    g_stage[height][x + 5] = 2;
                    g_stage[height - 1][x + 5] = 2;
                    g_stage[height - 2][x + 5] = 2;
                    g_stage[height - 3][x + 5] = 2;
                    height = GROUND;
                }
                /* �ݒu����2�@��ԉ��܂ōs���ꍇ */
                else if (height == 17) {
                    g_stage[height + 1][x + 5] = 2;
                    g_stage[height][x + 5] = 2;
                    g_stage[height - 1][x + 5] = 2;
                    g_stage[height - 2][x + 5] = 2;
                    height = GROUND;
                }
                else{
                    /* �������� */
                    for (time = 0; time < 2; time++) {
                        for (i = 0; i < 4; i++) {
                            for (j = 0; j < 4; j++) {
                                if (I_mino[i][j] == 1) {
                                    printFstr(x, height, " ");
                            }
                                else{
                                    printFstr(x, height, " ");
                            }
                                x += 1;
                            }
                            x -= 4;
                            height += 1;
                        }
                        height -= 4;
                    }
                    height++;
                }
            
            case 2:
                /* �ݒu����1�@�r���Ƀ~�m���������ꍇ */
                if (g_stage[height + 1][x + 6] == 2 || g_stage[height + 1][x + 5] == 2 || g_stage[height + 1][x + 4] == 2 || g_stage[height + 1][x + 3] == 2) {
                    g_stage[height][x + 6] = 2;
                    g_stage[height][x + 5] = 2;
                    g_stage[height][x + 4] = 2;
                    g_stage[height][x + 3] = 2;
                    height = GROUND;
                }
                /* �ݒu����2�@��ԉ��܂ōs���ꍇ */
                else if (height == 17) {
                    g_stage[height + 1][x + 6] = 2;
                    g_stage[height + 1][x + 5] = 2;
                    g_stage[height + 1][x + 4] = 2;
                    g_stage[height + 1][x + 3] = 2;
                    height = GROUND;
                }
                /* �������� */
                else{
                    for (time = 0; time < 2; time++) {
                        for (i = 0; i < 4; i++) {
                            for (j = 0; j < 4; j++) {
                                if (I_mino[i][j] == 1) {
                                    printFstr(x, height, " ");
                            }
                                else{
                                    printFstr(x, height, " ");
                            }
                                x += 1;
                            }
                            x -= 4;
                            height += 1;
                        }
                        height -= 4;
                    }
                    height++;
                }    
            
            case 3:
                /* �ݒu����1�@�r���Ƀ~�m���������ꍇ */
                if (g_stage[height + 1][x + 4] == 2) {
                    g_stage[height][x + 4] = 2;
                    g_stage[height - 1][x + 4] = 2;
                    g_stage[height - 2][x + 4] = 2;
                    g_stage[height - 3][x + 4] = 2;
                    height = GROUND;
                }
                /* �ݒu����2�@��ԉ��܂ōs���ꍇ */
                else if (height == 17) {
                    g_stage[height + 1][x + 4] = 2;
                    g_stage[height][x + 4] = 2;
                    g_stage[height - 1][x + 4] = 2;
                    g_stage[height - 2][x + 4] = 2;
                    height = GROUND;
                }
                /* �������� */
                else{
                    for (time = 0; time < 2; time++) {
                        for (i = 0; i < 4; i++) {
                            for (j = 0; j < 4; j++) {
                                if (I_mino[i][j] == 1) {
                                    printFstr(x, height, " ");
                                } else{
                                    printFstr(x, height, " ");
                                }
                                x += 1;
                            }
                            x -= 4;
                            height += 1;
                        }
                        height -= 4;
                    }
                    height++;
                }
            default:        /* �G���[���� */
                break;
        }
    }
}
