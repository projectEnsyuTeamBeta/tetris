#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"
#include "field.h"
#include <string.h>

#define LEFT_WALL   10  // ミノによって可変必要
#define RIGHT_WALL  17  // ミノによって可変必要
#define GROUND   18  // ミノによって可変&Stageの状態反映

void tmino(void)
{
    int T_mino[4][4] = {
        {0,0,0,0},
        {0,1,0,0},
        {1,1,1,0},
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
	//ミノ描画
        for(time = 0;time < speed;time++){
            for(i = 0; i < 4; i++){
                for(j = 0; j < 4; j++){
                    if(T_mino[i][j] == 1){
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
	
	//移動・回転
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
                        temp[l][k] = T_mino[3 - k][l];
                    }
                }
                memcpy(T_mino, temp, sizeof temp);
                break;
            }
            for(time = 0;time <10;time++);
            break;
        }
	
	
	//設置処理1　途中にミノがあった場合
	if(stage[height+1][x+3]==2 || stage[height+1][x+4]==2 || stage[height+1][x+5]==2){
		stage[height][x+5]=2;
		stage[height][x+4]=2;
		stage[height][x+3]=2;
		stage[height-1][x+4]=2;
		break;
	}
	//設置処理2　一番下まで行く場合
	else if(height==17){
		stage[height+1][x+5]=2;
		stage[height+1][x+4]=2;
		stage[height+1][x+3]=2;
		stage[height][x+4]=2;
		break;
	}
	//落下
        for(time = 0;time < 2;time++){
            for(i = 0; i < 4; i++){
                for(j = 0; j < 4; j++){
                    if(T_mino[i][j] == 1){
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