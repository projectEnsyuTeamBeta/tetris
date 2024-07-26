#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"
// #include "tetriMino.h"

void dropMino(void)
{
    int height = 1;
    int x = 14;
    int time;
    
    PORT0.PDR.BIT.B0 = 0;
    PORT0.PDR.BIT.B2 = 0;
    while(height < 21){
        while(x > 10 && x < 19){ 
            if(PORT0.PIDR.BIT.B0 == 1){
                x -= 1;
                break;
            }else if(PORT0.PIDR.BIT.B2 == 1){
                x += 1;
                break;
            }
            for(time = 0;time <10;time++);
            break;
        }
        for(time = 0;time < 2500;time++){
            printFstr(x,height,"A");
        }
        height++;
    }
}