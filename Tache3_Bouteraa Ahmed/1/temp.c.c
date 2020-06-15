#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "temp.h"

void inittemp(temp* t)
{
t->temp[0]=IMG_Load("temp1.png");
t->temp[1]=IMG_Load("temp2.png");
t->temp[2]=IMG_Load("temp3.png");
t->temp[3]=IMG_Load("temp4.png");
t->temp[4]=IMG_Load("temp5.png");
t->temp[5]=IMG_Load("temp6.png");
t->temppos.x=250;
t->temppos.y=0;
}

void affichertemp(temp* t,SDL_Surface* screen,int temp)
{
if(temp<900)
{
SDL_BlitSurface(t->temp[0],NULL,screen,&t->temppos);
}	
if(temp>900)
{
SDL_BlitSurface(t->temp[1],NULL,screen,&t->temppos);
}
if(temp>1800)
{
SDL_BlitSurface(t->temp[2],NULL,screen,&t->temppos);	
}
if(temp>2700)
{
SDL_BlitSurface(t->temp[3],NULL,screen,&t->temppos);	
}
if(temp>3600)
{
SDL_BlitSurface(t->temp[4],NULL,screen,&t->temppos);	
}
if(temp>4500)
{
SDL_BlitSurface(t->temp[5],NULL,screen,&t->temppos);	
}

}
