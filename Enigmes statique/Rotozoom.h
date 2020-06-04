#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void zoom(int *tempsActuel,int *tempsPrecedent,SDL_Surface *ecran,double *angle,SDL_Surface *image,SDL_Surface *rotation,SDL_Rect rect,int TEMPS);
