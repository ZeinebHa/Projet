#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "vie.h"



void Initvie(vie* v)
{
v->heart[0]=IMG_Load("heart1.png");
v->heart[1]=IMG_Load("heart2.png");
v->heart[2]=IMG_Load("heart3.png");
v->gameover=IMG_Load("gameover.png");
v->heartpos.x=580;
v->heartpos.y=20;
v->i=0;	
}
void Initvie2(vie* v)
{
v->heart[0]=IMG_Load("heart1.png");
v->heart[1]=IMG_Load("heart2.png");
v->heart[2]=IMG_Load("heart3.png");
v->gameover=IMG_Load("gameover.png");
v->heartpos.x=1380;
v->heartpos.y=20;
v->i=0;	
}
void affichezvie(vie* v,SDL_Surface* screen,int *collision,int *collision1,int *collision2)
{
if(*collision==1)
{
v->i++;
*collision=0;
if(v->i>3)
{
v->i=0;	
}
}
if(*collision1==1)
{
v->i++;
*collision1=0;
if(v->i>3)
{
v->i=0;	
}
}
if(*collision2==1)
{
v->i++;
*collision2=0;
if(v->i>3)
{
v->i=0;	
}
}
if(v->i<3)
{
SDL_BlitSurface(v->heart[v->i],NULL,screen,&v->heartpos);
}

}
void affichezgameover(vie* v,SDL_Surface* screen,int *d,int *quit1,int *r,int *deathocc)
{
int r1=0;

if(v->i==3)
{
v->i=0;
*quit1=0;
*r=7;
while(r1!=500)
{	
SDL_BlitSurface(v->gameover,NULL,screen,NULL);
SDL_Flip(screen);
r1++;
}
*deathocc=1;
*d=0;
}
}