#include "lcdlib.h"
#include "i2clib.h"
#include "iodefine.h"
#include "field.h"
#include <string.h>

#define HIGH_MINO 0
#define UNDER_MINO 20
#define LEFT_MINO 1
#define RIGHT_MINO 10
#define TOTAL_MINO 10
#define EXIST_MINO 0
#define HIGHER_STAGE -1

/*void delete(void)
{
    int a,i,l,x,y,z;
    
    for ( l = HIGH_MINO; l < UNDER_MINO; l++)
    {
        for ( i = LEFT_MINO; i < RIGHT_MINO; i++)
        {
            a+=stage[l][i];
        }
        if (a=TOTAL_MINO)
        {
            for ( x = LEFT_MINO; x < RIGHT_MINO; x++)
            {
                stage[l][x]=EXIST_MINO;
            }
            if (l!=HIGH_MINO)
            {
                for ( y = l; y > HIGH_MINO; y--)
                {
                    for ( z = LEFT_MINO; z < RIGHT_MINO; z++)
                    {
                        if (y!=HIGH_MINO)
                        {
                            stage[y][z]=stage[y+HIGHER_STAGE][z];
                        }
                        if (y=HIGH_MINO)
                        {
                            stage[y][z]=EXIST_MINO;
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    
}*/

void derete(int y){
    int i;
    for(i=1+9; i<11+9; i++){
        stage[y][i]=0;
    }
}
