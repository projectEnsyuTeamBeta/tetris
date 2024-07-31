#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"
#include "field.h"

#define X_POS    i + 9
#define Y_POS    j + 1

int stage[21][12]= {
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
void derete(int);

void tetris(void)
{
    int i,j;
    int a;      // gameOver����
    int flag[21]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //�Y������y���W�ɂ����āAx���W�����ׂĖ��܂��Ă��邩�𔻒肷��

    initBase();
    initI2C();
    initLCD();

    setFontSize(16,12);
    setTextColor(CLR_GREY);

	while (1) {
        for(j = 0; j < 21; j++){
            for(i = 0; i < 12;i++){
                if(stage[j][i] == 0){
                    printFstr(X_POS,Y_POS,"0");     // A��ύX�i0�F��\��/1�F�~�m�z�u�j
                }else if(stage[j][i] == 1){
                    printFstr(X_POS,Y_POS,"1");
                }else if(stage[j][i]==2){
                    if(j==20){
                        printFstr(X_POS,Y_POS,"2");
                    }
                    else{
                        printFstr(X_POS,Y_POS,"#");
                    }
                }
            }
        }

        //x���W�̒l���w��a������Ă���̂ł����Ȃ�Q�[���I�[�o�[�ɂȂ�̂����H�iX�QPOS���ہj
        for(a = 1; a < 11; a++){
            if(stage[1][a]>=2){
                gameOver();
            }else{
                ;
            }
        }
        dropMino();

        //derete�Ăяo������
        for(j = 1; j < 21; j++){
            for(i = 1; i < 11;i++){
                if(stage[j][i] == 2){
                    flag[j]++;
                }
                else{
                    flag[j]=0;
                    break;
                }
            }
            if(flag[j]==10){
                derete(j);
            }
        }
        
	}
}