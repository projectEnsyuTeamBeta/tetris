#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"
#include "field.h"
#include <string.h>

#define LEFT_WALL   9  // �~�m�ɂ���ĉϕK�v
#define RIGHT_WALL  17  // �~�m�ɂ���ĉϕK�v
#define GROUND   18  // �~�m�ɂ���ĉ�&Stage�̏�Ԕ��f

void omino(void)
{
    int O_mino[4][4] = {
        {0,0,0,0},
        {0,1,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };
    int i,j; // mino�`��p
    int height=1; //����
    int x = 14; //x���W�̏����l
    int time; //�^���^�C�}�[�p�̃J�E���g
    //int temp[4][4];     //��]�Ɏg��
    //int k,l;

    PORT0.PDR.BIT.B0 = 0;
    PORT0.PDR.BIT.B1 = 0;
    PORT0.PDR.BIT.B2 = 0;

    
    while(height < GROUND){
	 //�~�m�`��
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
	
	//�ړ��E��]����
        while(1){ 
            if(PORT0.PIDR.BIT.B0 == 1 && x > LEFT_WALL){
                x -= 1;
                break;
            }else if(PORT0.PIDR.BIT.B2 == 1 && x < RIGHT_WALL){
                x += 1;
                break;
            }/*else if(PORT0.PIDR.BIT.B1 == 1){
                for(k = 0; k < 4; k++){     // ��]
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
	
	
	//�ݒu����1�@�r���Ƀ~�m���������ꍇ
	if(stage[height+1][x+5]==2 || stage[height+1][x+4]==2){
		stage[height][x+5]=2;
		stage[height-1][x+5]=2;
		stage[height][x+4]=2;
		stage[height-1][x+4]=2;
		break;
	}
	//�ݒu����2�@��ԉ��܂ōs���ꍇ
	else if(height==17){
		stage[height+1][x+5]=2;
		stage[height][x+5]=2;
		stage[height+1][x+4]=2;
		stage[height][x+4]=2;
		break;
	}
	//��������
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
	
	
	//���W�m�F�p�̕\��
	//printFstr(22,10,"%d %d",height,x);
    }
}