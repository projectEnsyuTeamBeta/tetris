#include <stdlib.h>

void imino(void);
void tmino(void);
void zmino(void);
void smino(void);
void lmino(void);
void jmino(void);
void omino(void);

void dropMino(void)
{
    int max = 6; // 乱数最大
    int min = 0; // 乱数最小
    int makeMino = min+(int)(rand()*(max-min+1)/(1+RAND_MAX)); //　乱数発生
    
    switch (makeMino)
    {
    case 0:
        imino();
        break;
    case 1:
        tmino();
        break;
    case 2:
        zmino();
        break;
    case 3:
        smino();
        break;
    case 4:
        lmino();
        break;
    case 5:
        jmino();
        break;
    case 6:
        omino();
        break;
    
    default:
        break;
    }
}
