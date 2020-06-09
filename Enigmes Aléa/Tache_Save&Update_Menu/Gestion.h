#pragma once
#include <SDL/SDL_ttf.h>
typedef struct a 
{
	int vie ; 
	int score ; 
}Perso; 
typedef struct backgrounds
{
	SDL_Surface* Coeur;
	SDL_Rect positionCoeur;
	SDL_Surface *Fond ; 
	SDL_Rect positionFond ; 
	SDL_Surface *Victory ;
	SDL_Surface *Defeat ; 


} backgrounds ;

void init_backgrounds (backgrounds *b) ; 
void Gestion_Vie (SDL_Surface *Coeur, SDL_Rect positionCoeur , int vie, SDL_Surface *ecran ) ; ; 
void Gestion_score(SDL_Surface *ecran, int score, TTF_Font *police , TTF_Font *police2) ;
int Gestion_temps(int temps_precedent , int temps_actuel,  SDL_Surface*ecran, TTF_Font *police2) ; 
int fin_jeu_defaite (int vie, int continuer, int temps, SDL_Surface *Defeat, SDL_Surface *ecran,SDL_Rect positionFond,SDL_Surface *Victory, int score  ) ;
void Liberation_Memoire(backgrounds *b);
 
