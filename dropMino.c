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
    int max = 6; // —”Å‘å
    int min = 0; // —”Å¬
    int makeMino = min+(int)(rand()*(max-min+1)/(1+RAND_MAX)); //@—””­¶
    
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
