#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"
#include "field.h"
#include <string.h>

#define LEFT_WALL   9  // ミノによって可変必要
#define RIGHT_WALL  17  // ミノによって可変必要
#define GROUND   18  // ミノによって可変&Stageの状態反映

void omino(void)
{
    int O_mino[4][4] = {
        {0,0,0,0},
        {0,1,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };
    int i,j; // mino描画用
    int height=1; //高さ
    int x = 14; //x座標の初期値
    int time; //疑似タイマー用のカウント
    //int temp[4][4];     //回転に使う
    //int k,l;

    PORT0.PDR.BIT.B0 = 0;
    PORT0.PDR.BIT.B1 = 0;
    PORT0.PDR.BIT.B2 = 0;

    
    while(height < GROUND){
	 //ミノ描画
        /*for(time = 0;time < 100;time++){
            for(i = 0; i < 4; i++){
                for(j = 0; j < 4; j++){
                    if(O_mino[i][j] == 1){
                        printFstr(x,height,"#");
                    }
		    else{
                        printFstr(x,height," ");
                    }
                    x+=1;
                }
                x-=4;
                height+=1;
            }
            height-=4;
        }*/
	
	//移動・回転処理
        while(1){ 
            if(PORT0.PIDR.BIT.B0 == 1 && x > LEFT_WALL){
                x -= 1;
                break;
            }else if(PORT0.PIDR.BIT.B2 == 1 && x < RIGHT_WALL){
                x += 1;
                break;
            }/*else if(PORT0.PIDR.BIT.B1 == 1){
                for(k = 0; k < 4; k++){     // 回転
                    for(l = 0; l < 4; l++){
                        temp[l][k] = O_mino[3 - k][l];
                    }
                }
                memcpy(O_mino, temp, sizeof temp);
                break;
            }*/
            for(time = 0;time <10;time++);
            break;
        }
	
	
	//設置処理1　途中にミノがあった場合
	if(stage[height+1][x+5]==2 || stage[height+1][x+4]==2){
		stage[height][x+5]=2;
		stage[height-1][x+5]=2;
		stage[height][x+4]=2;
		stage[height-1][x+4]=2;
		break;
	}
	//設置処理2　一番下まで行く場合
	else if(height==17){
		stage[height+1][x+5]=2;
		stage[height][x+5]=2;
		stage[height+1][x+4]=2;
		stage[height][x+4]=2;
		break;
	}
	//落下処理
	else{
        for(time = 0;time < speed;time++){
            for(i = 0; i < 4; i++){
                for(j = 0; j < 4; j++){
                    if(O_mino[i][j] == 1){
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
        height++;
	}
	
	
	//座標確認用の表示
	//printFstr(22,10,"%d %d",height,x);
    }
}