#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED
#include "structs.h"

extern GameObject monster[];
extern Gestion jeu;
extern GameObject player;
extern Map map;

/* Prototypes des fonctions utilisées */
extern SDL_Surface *loadImage(char *name);
extern void mapCollision(GameObject *entity);
extern int collidebox(GameObject *player, GameObject *monster);
extern int checkFall(GameObject monster);
extern void changeAnimation(GameObject *entity, char *name);
extern void playSoundFx(int type);
extern void monsterCollisionToMap(GameObject *entity);




#endif // MONSTER_H_INCLUDED
