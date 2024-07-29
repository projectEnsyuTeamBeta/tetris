#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"
#include <string.h>

#define LEFT_WALL   10  // ミノによって可変必要
#define RIGHT_WALL  19  // ミノによって可変必要
#define GROUND   21  // ミノによって可変&Stageの状態反映

void zmino(void)
{
    int Z_mino[4][4] = {
        {0,0,0,0},
        {1,1,0,0},
        {0,1,1,0},
        {0,0,0,0}
    };
    int i,j; // mino描画用
    int height=1;
    int x = 14;
    int time;
    int temp[4][4];     //回転
    int k,l;

    PORT0.PDR.BIT.B0 = 0;
    PORT0.PDR.BIT.B1 = 0;
    PORT0.PDR.BIT.B2 = 0;

    while(height < GROUND){
        for(time = 0;time < 100;time++){
            for(i = 0; i < 4; i++){
                for(j = 0; j < 4; j++){
                    if(Z_mino[i][j] == 1){
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

        while(1){ 
            if(PORT0.PIDR.BIT.B0 == 1 && x > LEFT_WALL){
                x -= 1;
                break;
            }else if(PORT0.PIDR.BIT.B2 == 1 && x < RIGHT_WALL){
                x += 1;
                break;
            }else if(PORT0.PIDR.BIT.B1 == 1){
                for(k = 0; k < 4; k++){     // 回転
                    for(l = 0; l < 4; l++){
                        temp[l][k] = Z_mino[3 - k][l];
                    }
                }
                memcpy(Z_mino, temp, sizeof temp);
                break;
            }
            for(time = 0;time <10;time++);
            break;
        }
        for(time = 0;time < 2;time++){
            for(i = 0; i < 4; i++){
                for(j = 0; j < 4; j++){
                    if(Z_mino[i][j] == 1){
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
        height++;
    }
}