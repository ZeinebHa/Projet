#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <time.h>

typedef struct clavier
{
	
	int droite;
	int gauche;
	int echap;
	int entrer;
	int a;
	int b;
	
}clavier; 

typedef struct souris 
{
	int click;
	int motion;
	//int up;
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
typedef struct 
{
 
 char  R_True[10];
 char question[20];
 char re1[10];
 char re2[10];
 int resolu=0;
 FILE *fichierQ;
 FILE *fichierRep;
 int temps;
 SDL_Surface *Boutons[6];
 SDL_Rect posbouton[6];
 SDL_Surface *Question,*Reponse1,*Reponse2,*Reponse3;
 
 
}Enigme;






void Initialiser_Enigme(Enigme *E);
void generer_Question(SDL_Surface *ecran, char nomFich[],Enigme E );
char generer_Reponse(char *reponse1, *reponse2,*reponse3);
void afficher_Question(Enigme E, SDL_Surface *ecran,char nomFich[]);
void afficher_Reponses(Enigme E);
int solution_enigme(Enigme E);
void EventBoutons_Enigme(SDL_Event event,Enigme E,input *inp);
void liberer (Enigme *E);
#endif // ENIGME_H_INCLUDED
