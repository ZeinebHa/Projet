#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct 
{
	
	SDL_Surface *tab[8]; /*!< Surface. */
	SDL_Rect position; /*!< Rectangle*/
	
}personnage;
typedef struct 
{
     int x;
     int y;
}Vecteur;
void initialiser_personnage(personnage *p);
void afficher_personnage(personnage p,SDL_Surface *screen,int i);
void freesurfaceperso(personnage *perso);
Vecteur InitVecteur(int angle, int distance);
#endif
