#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"
// #include "tetriMino.h"

void dropMino(void)
{
<<<<<<< HEAD
    //int height;
    int height=1;
=======
    int height = 1;
>>>>>>> main
    int x = 14;
    int time;
    
    PORT0.PDR.BIT.B0 = 0;
    PORT0.PDR.BIT.B2 = 0;
<<<<<<< HEAD
	 /*   for(height=1; height < 21; height++){
	            for(time = 0; time < 10000; time++){
		
			    printFstr(x,height,"A");
	                while(x > 10 && x < 20){
	                    if(PORT0.PIDR.BIT.B0 == 1){
				
	                        x -= 1;
				
	                    }
			else if(PORT0.PIDR.BIT.B2 == 1){
				
	                        x += 1;
				
	                    }
	                }
	            }
	    }*/
	    
	    
	    //—Ž‚¿‚é
	  /*   while(height<20){
	    printFstr(x,height,"A");
	   for(time=0; time<100000000; time++){
		   ;
	   }
	   printFstr(x,height," ");
	   height++;
	    }*/
	    
	    //‰¡‚É“®‚­
	    while(1){
	    printFstr(x,height,"A");
	    if(PORT0.PIDR.BIT.B0 == 1 && x>10){
	                        x -= 1;
				printFstr(x,height,"A");
	                    }
			else if(PORT0.PIDR.BIT.B2 == 1 && x<19){
	                        x += 1;
				printFstr(x,height,"A");
	    }
	     
	    }
	  
=======
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
>>>>>>> main
}