#ifndef ZOMBIE_H_INCLUDED
#define ZOMBIE_H_INCLUDED
typedef struct
{
SDL_Surface * zombie[11];
SDL_Rect zombiepos;
int i;
int mov;
int collisionexplo;
}zombie;
typedef struct 
{
SDL_Surface* bat[8];
SDL_Rect batpos;
int i;
}bat;
typedef struct
{
SDL_Surface* ghost[6];
SDL_Rect ghostpos;
int i;	
}ghost;

void initzombie(zombie* z);
void initbat(bat* b);
void movezombie(zombie* z,SDL_Surface* screen);
void changeposzombie(zombie* z);
void movezombie2(zombie* z,SDL_Surface* screen);
void affichezbat(bat* b,SDL_Surface *screen);


#endif 
