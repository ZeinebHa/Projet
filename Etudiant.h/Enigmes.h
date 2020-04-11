#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
typedef struct 
{
 SDL_Surface * Img;
 SDL_Rect 	p;
}Enigme;

typedef struct
{
	char  R_True[10];
	char quest[100];
	char A1[10];
	char A2[10];
}Question;

typedef struct 
{
	Question e_q[30];
	int reponse;
}Answer;


void initialiser_enigme(Enigme *E);
void generer(SDL_Surface *ecran, char image [],Enigme *E ,int *Rand);
void afficher(enigme *E ,int val);
int solution_enigme(char image [],int *reponse);

void afficher_resultat (SDL_Surface *ecran ,int solution,int res,Enigme *enigme);
void liberer ();
