#include "lcdlib.h"
#include "i2clib.h"
#include "ad.h"

void gameStart(void)
{
	initBase();
	initI2C();
	initLCD();
	initAD();

    while(1){
	    printFstr(10,5,"TETRIS");
	    printFstr(10,7,"GameStart->SW5");
//	    printFstr(10,7,"�^�񒆂̃{�^���������ƃQ�[���J�n");
//	    printFstr(10,8,"-�������- ��:���ɓ��� �^��:�E��] �E:�E�ɓ���");
    }
}