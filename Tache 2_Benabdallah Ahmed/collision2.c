#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"
#include "personnage.h"
#include "background.h"
#include "jump.h"
#include "portal.h"
#include "loading.h"
#include "fireball.h"
#include "score.h"
#include "zombie.h"
#include "pause.h"
#include "vie.h"
#include "collision.h"
#include "attaque.h"





int collide(personnage *p,zombie *z)
 {
    if ((p->persopos.x >= z->zombiepos.x + z->zombiepos.w)
    || (p->persopos.x + p->persopos.w <= z->zombiepos.x)
    || (p->persopos.y >= z->zombiepos.y + z->zombiepos.h)
    || (p->persopos.y + p->persopos.h <= z->zombiepos.y)
    )
        return 0;

    else
        return 1;
}

int collidestar(personnage *p,star *z)
{ 
    if ((p->persopos.x >= z->Starpos.x + z->Starpos.w)
    || (p->persopos.x + p->persopos.w <= z->Starpos.x)
    || (p->persopos.y >= z->Starpos.y + z->Starpos.h)
    || (p->persopos.y + p->persopos.h <= z->Starpos.y)
    )
        return 0;

    else
        return 1;


}

void collideattaque(attaque* a,zombie *z,int attaque)
{
int x;
int y;
x=a->ballpos.x-30;
y=a->ballpos.y-30;
if(z->collisionexplo==0 && attaque==1)
{
int i=0;
    if ((x >= z->zombiepos.x + z->zombiepos.w)
    || (x + a->ballpos.w <= z->zombiepos.x)
    || (y >= z->zombiepos.y + z->zombiepos.h)
    || (y + a->ballpos.h <= z->zombiepos.y)
    )
    z->collisionexplo=0;

    else
    {
    z->collisionexplo=1;
    }
}
if(z->collisionexplo==2)
{
z->zombiepos.x=0;
z->zombiepos.y=0;    
}

}
int collidefireball(personnage *p,fireball *z)
{

    if ((p->persopos.x >= z->firepos.x + z->firepos.w)
    || (p->persopos.x + p->persopos.w <= z->firepos.x)
    || (p->persopos.y >= z->firepos.y + z->firepos.h)
    || (p->persopos.y + p->persopos.h <= z->firepos.y)
    )
        return 0;

    else
        return 1;
}

int collideplatform(personnage *p,background *z)
{
    if ((p->persopos.x >= z->platformpos.x + z->platformpos.w)
    || (p->persopos.x + p->persopos.w <= z->platformpos.x)
    || (p->persopos.y >= z->platformpos.y + z->platformpos.h)
    || (p->persopos.y + p->persopos.h <= z->platformpos.y)
    )
        return 0;

    else
        return 1;


}



