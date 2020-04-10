#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
typedef struct 
{
 SDL_Surface * Img;
 SDL_Rect 	p;
}Enigme;

void initialiser_enigme(Enigme *E);
void generer_afficherEnigme (SDL_Surface *ecran  , char image [],Enigme *E,int *RaNd);
int solution_enigme(char image []);
void resolution (int *res );
void afficher_resultat (SDL_Surface *ecran ,int solution,int res,Enigme *enigme);
#endif // ENIGME_H_INCLUDED
