#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"
// #include "tetriMino.h"

void dropMino(void)
{
    int height;
    int x = 14;
    int time;
    
    PORT0.PDR.BIT.B0 = 0;
    PORT0.PDR.BIT.B2 = 0;
    for(height=0; height < 20; height++){
        while(1){
            for(time = 0;time < 10000;time++){
                printFstr(x,height,"A");
                while(x > 10 && x < 20){
                    if(PORT0.PIDR.BIT.B0 == 1){
                        x -= 1;
                    }else if(PORT0.PIDR.BIT.B2 == 1){
                        x += 1;
                    }
                }
            }
        }
    }
}