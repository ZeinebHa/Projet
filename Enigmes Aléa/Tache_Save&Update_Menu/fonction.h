#ifndef FONCTION_H_
#define FONCTION_H_
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
typedef struct 
{
	SDL_Surface* imageback;
	SDL_Rect posback;
	SDL_Surface* calque;
	SDL_Rect camera;
	//int move;
}bg;


typedef struct perso
{
	SDL_Surface *image;
	SDL_Rect positionimg;
	SDL_Rect pospoint[8];// contour du personnage 5edmet rania
	int frame;
	SDL_Rect animepos [6];
	SDL_Rect clip[6];
	int score;
	int vie;
	int nb_enigmes_resolues;
}perso

typedef struct clavier
{
	int haut;
	int bas;
	int droite;
	int gauche;
	int echap;
	int entrer;
	int espace;
	int a;
	int b;
	int c;
	int p; 
	int s;
	int y; 
	int n;
	int z; 
}clavier; 

typedef struct souris 
{
	int left; 
	int right; 
	int middle;
	SDL_Rect motion;
	SDL_Rect posclick;
}souris;

/*typedef struct manette  
{
}manette;*/
typedef struct input
{
	clavier c;
	souris s;
	//manette m;
}input;




void init_backYasmine (back* b);
void init_persoYasmine (acteur* acteur);


void init_input(input *inp) ; 

void deplacement_droite(SDL_Rect clip[6]);
void deplacement_gauche(SDL_Rect clip[6]);
void dep2_right(SDL_Rect clip[4]);
void dep2_left(SDL_Rect clip[4]);
void update_perso(input inp,perso *p);// deplacement


void get_input(input *inp, Mix_Chunk* sound,int *continuer, int *enigme_ouvert) ;


void afficher_persoYasmine (perso p, SDL_Surface *screen);
void afficher_backYasmine(bg b, SDL_Surface *screen);
void liberer_persoYasmine (perso *p);
void liberer_backYasmine (bg *b);
#endif // FONCTION_H_INCLUDED

