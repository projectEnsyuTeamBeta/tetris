#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"
//#include "onoff.h"


void gameStart(void)
{
    initBase();
    initI2C();
    initLCD();
// ?intSx5Int();

    while(1){
        printFstr(10,5,"TETRIS");
        printFstr(10,7,"GameStart->SW5");
// ? ? ?printFstr(10,7,"�^�񒆂̃{�^���������ƃQ�[���J�n");
// ? ? ?printFstr(10,8,"-�������- ��:���ɓ��� �^��:�E��] �E:�E�ɓ���");

        PORT0.PDR.BIT.B1=0;
        if (PORT0.PIDR.BIT.B1 == 1)
        {
            main();
        }
    }

}
