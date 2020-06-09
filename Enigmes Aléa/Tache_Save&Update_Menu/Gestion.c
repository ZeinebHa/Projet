#include <stdlib.h>
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "Gestion.h"
void init_backgrounds (backgrounds *bg)
{
	
	bg->Coeur=IMG_Load ("heart.png");
	bg->positionCoeur.x=540;
	bg->positionCoeur.y=30;
	bg->Fond=IMG_Load ("map.png");
	bg->positionFond.x=0;
	bg->positionFond.y=0;
	bg->Victory=IMG_Load ("victory.png");
	bg->Defeat=IMG_Load ("defeat.png");
		
}


void Gestion_Vie (SDL_Surface *Coeur, SDL_Rect position_Coeur , int vie, SDL_Surface *ecran ) 
{
	for (int i=0 ; i<vie ; i++) 
	{
	   SDL_BlitSurface(Coeur, NULL, ecran, &position_Coeur);
	   positionCoeur.x=positionCoeur.x+80 ; 
	}

}

void Gestion_score(SDL_Surface *ecran, int score, TTF_Font *police , TTF_Font *police2) 
{
char sc[100] ; 
SDL_Surface *texte ;
SDL_Surface *scoreValeur = NULL ;
SDL_Rect position;
SDL_Rect pos_scoreValeur;
position.x=50 ; 
position.y=50 ;
pos_scoreValeur.x=175 ; 
pos_scoreValeur.y=40 ;
SDL_Color couleurNoire = {0, 0, 0};

texte = TTF_RenderText_Blended(police, "SCORE : ", couleurNoire);
SDL_BlitSurface(texte, NULL, ecran, &position);
	sprintf(sc,"%d",score);
	scoreValeur= TTF_RenderText_Blended(police2, sc, couleurNoire);
	SDL_BlitSurface(scoreValeur, NULL, ecran, &pos_scoreValeur);

} 

int Gestion_temps(int temps_precedent , int temps_actuel,  SDL_Surface*ecran, TTF_Font *police)
{
	char time[100] ; 
	temps_actuel = SDL_GetTicks() ; 
	int temps1= (temps_actuel-temps_precedent)/1000 ;
	int temps=60-temps1 ; 

	SDL_Rect position;
	SDL_Surface *texte = NULL ; 
	position.x=450 ; 
	position.y=20 ;
	

	SDL_Color couleurNoire = {0, 0, 0};
	
	sprintf(time,"%d",temps);
	texte = TTF_RenderText_Blended(police, time , couleurNoire);
	SDL_BlitSurface(texte, NULL, ecran, &position);
	return temps ; 
}


int fin_jeu_defaite (int vie, int continuer, int temps, SDL_Surface *Defeat, SDL_Surface *ecran,SDL_Rect positionFond,SDL_Surface *Victory, int score ) // continuer = fin_jeu
{
	if ((vie==0)||(temps==0))	// ======== CONDITION DEFAITE ================
	{
		
		SDL_BlitSurface(Defeat, NULL, ecran, &positionFond);
		SDL_Flip(ecran) ;
		SDL_Delay(5000) ; 
		return 0 ; 
		
	} else 	if (score>=100)  // ======== CONDITION VITOIRE ================
	{
		
		SDL_BlitSurface(Victory, NULL, ecran, &positionFond);
		SDL_Flip(ecran) ;
		SDL_Delay(5000) ; 
		return 0 ;
		
	} else 
	{
		return 1 ; 
	}


}


void Liberation_Memoire(backgrounds *bg)
{
SDL_FreeSurface(bg->Coeur);
SDL_FreeSurface(bg->Fond) ;
SDL_FreeSurface(bg->Defeat) ;
SDL_FreeSurface(bg->Victory) ;

}
