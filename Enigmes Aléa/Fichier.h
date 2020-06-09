#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED
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


typedef struct background
{ SDL_Surface* bg;
SDL_Surface* maskbg; //pour la collision pixel parfait
SDL_Rect positionbg;
SDL_Rect positionmask;
int sens;
int speed;
int stage;
SDL_Surface* fenetre;
SDL_Rect camera;
SDL_Surface *map;
SDL_Rect posmap;
}background;

typedef struct  persoprincipal
{SDL_Surface* pp; //une seule image pour le moment. NB:changer en tableau d'images pour l'animation
SDL_Rect positionpp;
int time;
int vie;
int score;
SDL_Surface *nokta;
SDL_Rect posnokta;

}persoprincipal;

//**animation oiseau youssef
typedef struct 
{
	SDL_Surface *img[4];
	SDL_Rect pos;
	int direction; 

}Perso;

typedef struct entitesecondaire
{SDL_Surface* ennemi;
SDL_Rect positionennemi;
SDL_Surface* objet[3];
SDL_Rect positionobj1;
SDL_Rect positionobj2;
SDL_Rect positionobj3;
SDL_Surface* vie[4];
SDL_Rect positionvie;
}entitesecondaire;

typedef struct vie
{SDL_Surface vie[4];
SDL_Rect posvie;
int nb;
}vie;

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
 SDL_Rect *Questions[3];
 SDL_Rect *Reponse0T,*Reponse01,*Reponse02;
 }Enigme;

typedef struct enigmes
{
int nbenigmes;
Enigme E[30];
}enigmes;

typedef struct score
{
SDL_Surface *texte;
SDL_Rect posscore;
int sc;
}score;

typedef struct chrono
{
SDL_Surface *texte;
SDL_Rect poschrono;
}chrono;



//***************************enigme*******************
void Initialiser_Enigme(Enigme *E);
void generer_Question(SDL_Surface *ecran, char nomFich[],Enigme E );
char generer_Reponse(char *reponse1, *reponse2,*reponse3);
void afficher_Question(Enigme E, SDL_Surface *ecran,char nomFich[]);
void afficher_Reponses(Enigme E);
int solution_enigme(Enigme E);
void EventBoutons_Enigme(SDL_Event event,Enigme E,input *inp);
void liberer (Enigme *E);


//P.c
int move();

//*******************background******************
void init_background(background* b);
void afficher_background(background *b, SDL_Surface *fenetre);
void affichermap (persoprincipal *p, background *b, SDL_Surface *screen);

//******************personnage principal**********
void init_persoP(persoprincipal *p);
void afficher_personnageinit(persoprincipal *p, SDL_Surface *ecran);
int deplacement_clavier(persoprincipal *p, SDL_Surface *ecran);
void afficher_personnage(persoprincipal *p, SDL_Surface *screen);

//******************afficher objet***************
 void init_objet(entitesecondaire *obj);
void afficher_objet1(entitesecondaire *obj, SDL_Surface *ecran);
void afficher_objet22(entitesecondaire *obj, SDL_Surface *ecran);
void afficher_objet3(entitesecondaire *obj, SDL_Surface *ecran);
void maj_objet(entitesecondaire *obj, int x);

//**************collision BOUNDINGBOX personnage avec objet*******
int boundingbox (SDL_Rect positionpp, entitesecondaire *obj);//1ers cartons pour score
int boundingbox2 (SDL_Rect positionpp, entitesecondaire *obj); //2eme cartons pour enigme
int boundingbox3 (SDL_Rect positionpp, entitesecondaire *obj);

//***************chrono****************
void initialiser_chrono(chrono *c);
void afficher_chrono(chrono *c,SDL_Surface *screen, int done, background bg);
//***************vie***************
 void init_vie(entitesecondaire *vie);
void afficher_vie3(entitesecondaire *vie, SDL_Surface *ecran);
void afficher_vie2(entitesecondaire *vie, SDL_Surface *ecran);
void afficher_vie1(entitesecondaire *vie, SDL_Surface *ecran);
void freevie(entitesecondaire *vie);

//************deplacement objet*********/
void deplacer_objet (Perso * objet, int min, int max);
void afficher_objet2 (Perso *objet, SDL_Surface *ecran);

//********************score********
void initialiser_score(score *s);
void afficher_score(score *s, SDL_Surface *screen);

//****************ennemi*******
void init_ennemi(entitesecondaire *e);
void afficher_ennemi(entitesecondaire *e, SDL_Surface *ecran);

#endif
