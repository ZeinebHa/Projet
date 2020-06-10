#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include "Rotozoom.h"

void zoom(int *tempsActuel,int *tempsPrecedent,SDL_Surface *ecran,double *angle,SDL_Surface *image,SDL_Surface *rotation,SDL_Rect rect,int TEMPS){
*tempsActuel = SDL_GetTicks();
        if ((*tempsActuel) - (*tempsPrecedent) > TEMPS)
        {
            *angle += 3; //On augmente l'angle pour que l'image tourne sur elle-même.
 
            *tempsPrecedent = *tempsActuel;
        }
        else
        {
            SDL_Delay(TEMPS - ((*tempsActuel) - (*tempsPrecedent)));
        }
 
 
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
 
        rotation = rotozoomSurface(image, (*angle), 0.5, 1); //transformation la surface image.
 
        SDL_BlitSurface(rotation , NULL, ecran, &rect); 
        SDL_FreeSurface(rotation); 
        SDL_Flip(ecran);
        }
