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
 FILE *fichier;
 int temps ;
 SDL_Surface * Boutons[5];
 SDL_Surface *posBouton[5];
 SDL_Surface *Question,*Reponse1,*Reponse2,*Reponse3;
 SDL_Surface  *image1,*image2,image3;
 
}Enigme;






void Initialiser_Enigme(Enigme *E);
void generer_Question(SDL_Surface *ecran, char nomFich[],Enigme E );
int generer_Reponse(char Reponse1[],char Reponse2[], char Reponse3[]);
void afficher_Question(Enigme E, SDL_Surface *ecran,char nomFich[]);
void afficher_Reponses(char Reponse1[],char Reponse2[], char Reponse3[]);
int solution_enigme(Enigme E);
void afficher_resultat_Enigme(SDL_Surface *ecran ,Enigme enigme);
void liberer ();
#endif // ENIGME_H_INCLUDED
