#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#include "attaque.h"

int collide(personnage *p,zombie *z);
int collidestar(personnage *p,star *s);
void collideattaque(attaque* a,zombie *z,int attaque);
int collideplatform(personnage *p,background *z);


#endif 
