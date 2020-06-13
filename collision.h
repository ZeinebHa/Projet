
#ifndef _objet_H
#define _objet_H

#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>	
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h> 

typedef struct 
{
SDL_Surface *fond;
SDL_Rect positionFond;
}objet;



SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);
int collision_parfaite(SDL_Surface* Backmasque ,SDL_Surface* perso, SDL_Rect p,int z);

#endif 
