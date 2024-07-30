#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"
#include "field.h"
#include <string.h>

#define LEFT_WALL   10  // �~�m�ɂ���ĉϕK�v
#define RIGHT_WALL  19  // �~�m�ɂ���ĉϕK�v
#define GROUND   21  // �~�m�ɂ���ĉ�&Stage�̏�Ԕ��f

void imino(void)
{
    int I_mino[4][4] = {
        {0,0,0,0},
        {1,1,1,1},
        {0,0,0,0},
        {0,0,0,0}
    };
    int i,j; // mino�`��p
    int height=1;
    int x = 14;
    int time;
    int temp[4][4];     //��]
    int k,l;

    // setTextColor(CLR_GREEN);

    PORT0.PDR.BIT.B0 = 0;
    PORT0.PDR.BIT.B1 = 0;
    PORT0.PDR.BIT.B2 = 0;

    while(height < GROUND){
        for(time = 0;time < 100;time++){
            for(i = 0; i < 4; i++){
                for(j = 0; j < 4; j++){
                    if(I_mino[i][j] == 1){
                        printFstr(x,height,"#");
                    }else{
                        printFstr(x,height," ");
                    }
                    x+=1;
                }
                x-=4;
                height+=1;
            }
            height-=4;
        }

        while(1){       // SW4,5,6����
            if(PORT0.PIDR.BIT.B0 == 1 && x > LEFT_WALL){    // SW4���ړ�
                x -= 1;
                break;
            }else if(PORT0.PIDR.BIT.B2 == 1 && x < RIGHT_WALL){     // SW6�E�ړ�
                x += 1;
                break;
            }else if(PORT0.PIDR.BIT.B1 == 1){       // SW5��]
                for(k = 0; k < 4; k++){     
                    for(l = 0; l < 4; l++){
                        temp[l][k] = I_mino[3 - k][l];
                    }
                }
                memcpy(I_mino, temp, sizeof temp);
                break;
            }
            for(time = 0;time <10;time++);
            break;
        }
        for(time = 0;time < 2;time++){
            for(i = 0; i < 4; i++){
                for(j = 0; j < 4; j++){
                    if(I_mino[i][j] == 1){
                        printFstr(x,height," ");
                    }else{
                        printFstr(x,height," ");
                    }
                    x+=1;
                }
                x-=4;
                height+=1;
            }
            height-=4;
        }
        if(stage[height][x] == 0){
            height++;
        }else{
            stage[height][x] = 1;
        }
        
    }
}