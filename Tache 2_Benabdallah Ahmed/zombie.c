#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "zombie.h"
#include "personnage.h"
void initzombie(zombie* z)
{
z->zombie[0]=IMG_Load("zombie1.png");
z->zombie[1]=IMG_Load("zombie2.png");
z->zombie[2]=IMG_Load("zombie3.png");
z->zombie[3]=IMG_Load("zombie4.png");
z->zombie[4]=IMG_Load("zombie5.png");
z->zombie[5]=IMG_Load("zombie6.png");
z->zombie[6]=IMG_Load("zombie7.png");
z->zombie[7]=IMG_Load("zombie8.png");
z->zombie[8]=IMG_Load("zombie9.png");
z->zombie[9]=IMG_Load("zombie10.png");
z->zombiepos.x=200;
z->zombiepos.y=370;
z->i=0;
z->collisionexplo=0;
z->mov=10;							
}
void initzombie2(zombie* z)
{
z->zombie[0]=IMG_Load("zombie1.png");
z->zombie[1]=IMG_Load("zombie2.png");
z->zombie[2]=IMG_Load("zombie3.png");
z->zombie[3]=IMG_Load("zombie4.png");
z->zombie[4]=IMG_Load("zombie5.png");
z->zombie[5]=IMG_Load("zombie6.png");
z->zombie[6]=IMG_Load("zombie7.png");
z->zombie[7]=IMG_Load("zombie8.png");
z->zombie[8]=IMG_Load("zombie9.png");
z->zombie[9]=IMG_Load("zombie10.png");
z->zombiepos.x=1000;
z->zombiepos.y=370;
z->i=0;
z->mov=10;							
}
void changeposzombie(zombie* z)
{
z->zombiepos.x=730;
z->zombiepos.y=300;	
z->collisionexplo=0;
}
void movezombie(zombie* z,SDL_Surface* screen)
{
if(z->collisionexplo==0)
{	
z->zombiepos.x=z->zombiepos.x+z->mov;	
SDL_BlitSurface(z->zombie[z->i],NULL,screen,&z->zombiepos);
z->i++;
if(z->i>9)
{
z->i=0;	
}
if(z->zombiepos.x>=330)
{
z->zombiepos.x=330;
z->mov=-10;	
}
if(z->zombiepos.x<200)
{
z->zombiepos.x=200;
z->mov=10;
}
}
}

void movezombie2(zombie* z,SDL_Surface* screen)
{
if(z->collisionexplo==0)
{	
z->zombiepos.x=z->zombiepos.x+z->mov;	
SDL_BlitSurface(z->zombie[z->i],NULL,screen,&z->zombiepos);
z->i++;
if(z->i>9)
{
z->i=0;	
}
if(z->zombiepos.x>=730)
{
z->zombiepos.x=730;
z->mov=-3;	
}
if(z->zombiepos.x<400)
{
z->zombiepos.x=400;
z->mov=3;
}
}
}	
void initbat(bat* b)
{
b->bat[0]=IMG_Load("bat1.png");
b->bat[1]=IMG_Load("bat2.png");
b->bat[2]=IMG_Load("bat3.png");
b->bat[3]=IMG_Load("bat4.png");
b->bat[4]=IMG_Load("bat5.png");
b->bat[5]=IMG_Load("bat6.png");
b->bat[6]=IMG_Load("bat7.png");
b->bat[7]=IMG_Load("bat8.png");
b->batpos.x=0;
b->batpos.y=0;
b->i=0;
}
void affichezbat(bat* b,SDL_Surface *screen)
{
SDL_BlitSurface(b->bat[b->i],NULL,screen,&b->batpos);
b->i++;
if(b->i > 7)
{
b->i=0;	
} 	
}

void initghost(ghost* g)
{
g->ghost[0]=IMG_Load("ghost1.png");
g->ghost[1]=IMG_Load("ghost2.png");
g->ghost[2]=IMG_Load("ghost3.png");
g->ghost[3]=IMG_Load("ghost4.png");
g->ghostpos.x=700;
g->ghostpos.y=0;
g->i=0;
}
void initghost2(ghost* g)
{
g->ghost[0]=IMG_Load("ghost1.png");
g->ghost[1]=IMG_Load("ghost2.png");
g->ghost[2]=IMG_Load("ghost3.png");
g->ghost[3]=IMG_Load("ghost4.png");
g->ghostpos.x=1500;
g->ghostpos.y=0;
g->i=0;
}
void affichezghost(ghost* g,SDL_Surface* screen,int vision,personnage *p)
{
if(p->persopos.x > g->ghostpos.x)
{
g->i=2;
}
if(p->persopos.x < g->ghostpos.x)
{
g->i=0;
}
if(vision==0)
{if(700 > g->ghostpos.x)
{
g->ghostpos.x++;	
} 
if(700 < g->ghostpos.x)
{
g->ghostpos.x--;	
}
if(0 > g->ghostpos.y)
{
g->ghostpos.y++;	
}
if(0 < g->ghostpos.y)
{
g->ghostpos.y--;	
}
SDL_BlitSurface(g->ghost[g->i],NULL,screen,&g->ghostpos);
}
if(vision==1)
{
if(p->persopos.x > g->ghostpos.x)
{
g->ghostpos.x++;
g->i=3;	
} 
if(p->persopos.x < g->ghostpos.x)
{
g->ghostpos.x--;
g->i=1;	
}
if(p->persopos.y > g->ghostpos.y)
{
g->ghostpos.y++;	
}
if(p->persopos.y < g->ghostpos.y)
{
g->ghostpos.y--;	
}

SDL_BlitSurface(g->ghost[g->i],NULL,screen,&g->ghostpos);
	
}

}




