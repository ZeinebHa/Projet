#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED

typedef struct Input
{
	int left;
	int up;
	int down;
	int right;
	int enter;
	int pause;
} Input;

typedef struct 
{
 SDL_Surface * Img;
 SDL_Rect 	p;
 char  R_True[10];
 char question[100];
 char re1[10];
 char re2[10];
 int resolu=0;
 int temps ;
 SDL_Surface * Boutons[5];
 SDL_Surface *posBouton[5];
 SDL_Surface *Question,*Reponse1,*Reponse2,*Reponse3;
 SDL_Surface  *image1,*image2,image3;
 
}Enigme;






void initialiser_enigme(Enigme *E);
void generer(SDL_Surface *ecran, char image [],Enigme *E ,int *Rand);
void afficher(enigme *E ,int val);
int solution_enigme(char image [],int *reponse);

void afficher_resultat (SDL_Surface *ecran ,int solution,int res,Enigme *enigme);
void liberer ();
#endif // ENIGME_H_INCLUDED
