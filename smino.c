#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"
#include "field.h"
#include <string.h>

#define LEFT_WALL   10  // �~�m�ɂ���ĉϕK�v
#define RIGHT_WALL  17  // �~�m�ɂ���ĉϕK�v
#define GROUND   18  // �~�m�ɂ���ĉ�&Stage�̏�Ԕ��f

void smino(void)
{
    int S_mino[4][4] = {
        {0,0,0,0},
        {0,1,1,0},
        {1,1,0,0},
        {0,0,0,0}
    };
    int i,j; // mino�`��p
    int height=1;
    int x = 14;
    int time;
    int temp[4][4];     //��]
    int k,l;
    int cnt=0;

    PORT0.PDR.BIT.B0 = 0;
    PORT0.PDR.BIT.B1 = 0;
    PORT0.PDR.BIT.B2 = 0;

    while(height < GROUND){
	//�~�m�`��
        for(time = 0;time < speed;time++){
            for(i = 0; i < 4; i++){
                for(j = 0; j < 4; j++){
                    if(S_mino[i][j] == 1){
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
	
	//�ړ��E��]
        while(1){ 
            if(PORT0.PIDR.BIT.B0 == 1 && x > LEFT_WALL){
                for(i = 0; i < 4; i++){
                    for(j = 0; j < 4; j++){
                        if(S_mino[i][j] == 1){
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
                x -= 1;
                break;
            }else if(PORT0.PIDR.BIT.B2 == 1 && x < RIGHT_WALL){
                for(i = 0; i < 4; i++){
                    for(j = 0; j < 4; j++){
                        if(S_mino[i][j] == 1){
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
                x += 1;
                break;
            }else if(PORT0.PIDR.BIT.B1 == 1){
                cnt++;
                for(k = 0; k < 4; k++){     // ��]
                    for(l = 0; l < 4; l++){
                        temp[l][k] = S_mino[3 - k][l];
                    }
                }
                memcpy(S_mino, temp, sizeof temp);
                break;
            }
            for(time = 0;time <10;time++);
            break;
        }
	
        switch(cnt % 4)
        {
        case 0:
            //�ݒu����1�@�r���Ƀ~�m���������ꍇ
            if(stage[height+1][x+3]==2 || stage[height+1][x+4]==2 || stage[height][x+5]==2){
                stage[height-1][x+5]=2;
                stage[height-1][x+4]=2;
                stage[height][x+4]=2;
                stage[height][x+3]=2;
                height = GROUND;
            }
            //�ݒu����2�@��ԉ��܂ōs���ꍇ
            else if(height==17){
                stage[height][x+5]=2;
                stage[height][x+4]=2;
                stage[height+1][x+4]=2;
                stage[height+1][x+3]=2;
                height = GROUND;
            }
            //����
            else{
                for(time = 0;time < 2;time++){
                    for(i = 0; i < 4; i++){
                        for(j = 0; j < 4; j++){
                            if(S_mino[i][j] == 1){
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
            break;

        case 1:
            //�ݒu����1�@�r���Ƀ~�m���������ꍇ
            if(stage[height][x+4]==2 || stage[height+1][x+5]==2){
                stage[height-2][x+4]=2;
                stage[height-1][x+4]=2;
                stage[height-1][x+5]=2;
                stage[height][x+5]=2;
                height = GROUND;
            }
            //�ݒu����2�@��ԉ��܂ōs���ꍇ
            else if(height==17){
                stage[height-1][x+4]=2;
                stage[height][x+4]=2;
                stage[height][x+5]=2;
                stage[height+1][x+5]=2;
                height = GROUND;
            }
            //����
            else{
                for(time = 0;time < 2;time++){
                    for(i = 0; i < 4; i++){
                        for(j = 0; j < 4; j++){
                            if(S_mino[i][j] == 1){
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
            break;

        case 2:
            //�ݒu����1�@�r���Ƀ~�m���������ꍇ
            if(stage[height+1][x+4]==2 || stage[height+1][x+5]==2 || stage[height][x+6]==2){
                stage[height-1][x+6]=2;
                stage[height-1][x+5]=2;
                stage[height][x+5]=2;
                stage[height][x+4]=2;
                height = GROUND;
            }
            //�ݒu����2�@��ԉ��܂ōs���ꍇ
            else if(height==17){
                stage[height][x+6]=2;
                stage[height][x+5]=2;
                stage[height+1][x+5]=2;
                stage[height+1][x+4]=2;
                height = GROUND;
            }
            //����
            else{
                for(time = 0;time < 2;time++){
                    for(i = 0; i < 4; i++){
                        for(j = 0; j < 4; j++){
                            if(S_mino[i][j] == 1){
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
            break;
        
        case 3:
            //�ݒu����1�@�r���Ƀ~�m���������ꍇ
            if(stage[height+2][x+4]==2 || stage[height+2][x+5]==2){
                stage[height-1][x+4]=2;
                stage[height][x+4]=2;
                stage[height][x+5]=2;
                stage[height+1][x+5]=2;
                height = GROUND;
            }
            //�ݒu����2�@��ԉ��܂ōs���ꍇ
            else if(height==17){
                stage[height][x+4]=2;
                stage[height+1][x+4]=2;
                stage[height+1][x+5]=2;
                stage[height+2][x+5]=2;
                height = GROUND;
            }
            //����
            else{
                for(time = 0;time < 2;time++){
                    for(i = 0; i < 4; i++){
                        for(j = 0; j < 4; j++){
                            if(S_mino[i][j] == 1){
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
            break;
        
        default:
            break;
        }
    }
}