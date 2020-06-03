#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
/* On inclut les libs supplémentaires */
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

/*************************Define.h**************/

/* Taille de la fenêtre / résolution en plein écran */
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

/* Valeur RGB pour la transparence (canal alpha) */
#define TRANS_R 255
#define TRANS_G 0
#define TRANS_B 255

/* Taille maxi de la map : on voit large : 400 x 300 tiles */
#define MAX_MAP_X 400
#define MAX_MAP_Y 300

/* Taille d'une tile (32 x 32 pixels) */
#define TILE_SIZE 32

/* Taille du sprite de notre héros (largeur = width et hauteur = heigth) */
#define PLAYER_WIDTH 40
#define PLAYER_HEIGTH 80

/* Constantes pour l'animation */
#define TIME_BETWEEN_2_FRAMES 8

//Vitesse de déplacement en pixels du sprite
#define PLAYER_SPEED 4

//Valeurs attribuées aux états/directions
#define WALK_RIGHT 1
#define WALK_LEFT 2
#define IDLE 3
#define JUMP_RIGHT 4
#define JUMP_LEFT 5
#define RIGHT 1
#define LEFT 2

// Constante définissant le seuil entre les tiles traversables (blank) et les tiles solides
#define BLANK_TILE 5

//Constantes définissant la gravité et la vitesse max de chute
#define GRAVITY_SPEED 0.6
#define MAX_FALL_SPEED 10
#define JUMP_HEIGHT 13

//Nombre max de monstres à l'écran
#define MONSTRES_MAX 50

//Nombre max de levels
#define LEVEL_MAX 2

enum
{
	BUMPER,
	DESTROY,
	JUMP,
    STAR
};

enum
{
	START,
	PAUSE
};

/****************struct.h***********************/

/* Structures qui seront utilisées pour gérer le jeu */

/* Structure pour gérer l'input (clavier puis joystick) */

typedef struct Input
{
	int left, right, up, down, jump, attack, enter, erase, pause;
} Input;

/* Structure pour gérer le niveau (à compléter plus tard) */

typedef struct Gestion
{
    SDL_Surface *screen;
    int nombreMonstres;
    int level;

    //HUD
	SDL_Surface *HUD_vie, *HUD_etoiles;
    int vies, etoiles;

    //Sons
    Mix_Music  *musique;

    //Sounds Fx
    Mix_Chunk  *bumper_sound, *destroy_sound, *jump_sound, *star_sound;

    //Gestion des menus
    int onMenu, menuType, choice;

} Gestion;

/* Structure pour gérer la map à afficher (à compléter plus tard) */

typedef struct Map
{
	SDL_Surface *background, *tileSet;
	SDL_Surface *tileSetB;

	/* Coordonnées de début, lorsqu'on doit dessiner la map */
	int startX, startY;

	/* Coordonnées max de fin de la map */
	int maxX, maxY;

	/* Tableau à double dimension représentant la map de tiles */
	int tile[MAX_MAP_Y][MAX_MAP_X];

	/* Timer et numéro du tileset à afficher pour animer la map */
	int mapTimer, tileSetNumber;

} Map;

/* Structure pour gérer notre héros */

typedef struct GameObject
{
    //Sprite du héros (pas d'animation pour l'instant)
	SDL_Surface *sprite;

	/* Coordonnées du héros */
	int x, y;
	/* Largeur, hauteur du sprite */
	int h, w;

	/* Variables utiles pour l'animation */
	int frameNumber, frameTimer;
	int etat, direction;

	/* Variables utiles pour la gestion des collisions */
	int onGround, timerMort;
	float dirX, dirY;
	int saveX, saveY;

	//Variable pour le double saut
	int jump;

} GameObject;



/****************l'animation du perso**************/
 Gestion jeu;
GameObject player;
 Map map;
SDL_Surface *loadImage(char *name);

/*************** draw map******************/

/* Prototypes des fonctions utilisées */
void drawMap(void);
void drawAnimatedEntity(GameObject *entity);
void drawHud(void);
void drawString(char *text, int x, int y, TTF_Font *font);

/* Structures globales */

Gestion jeu;
Map map;
GameObject player;
GameObject monster[];
TTF_Font *font;
Input input;

/*************load map*************/

SDL_Surface *loadImage(char *name);
void loadMap(char *name);
void closeFont(TTF_Font *font);
TTF_Font *loadFont(char *, int);
void loadSong( char filename[200] );
void loadSound(void);
void freeSound(void);
void changeLevel(void);


Gestion jeu;
Map map;
TTF_Font *font;
GameObject player;
GameObject monster[MONSTRES_MAX];

/****************map.h*****************/

/* Prototypes des fonctions utilisées */
void drawImage(SDL_Surface *, int, int);
void drawTile(SDL_Surface *image, int destx, int desty, int srcx, int srcy);
void initializeMonster(int x, int y);
void getItem(void);
void playSoundFx(int type);
SDL_Surface *loadImage(char *name);
void changeLevel(void);
void initializePlayer(void);

/**************zombie.h**************/

typedef struct
{
SDL_Surface * zombie[11];
SDL_Rect zombiepos;
int i;
int mov;

}zombie;
typedef struct 
{
SDL_Surface* bat[8];
SDL_Rect batpos;
int i;
}bat;
typedef struct
{
SDL_Surface* ghost[6];
SDL_Rect ghostpos;
int i;	
}ghost;

void initzombie(zombie* z);
void updatezombie(zombie* z);
void animerzombie ();
void deplacerzombie();
void bondingbox();
void display(zombie* z,SDL_Surface* screen);
void libererzombie();

/**************Collision ppixel ****************/
typedef struct 
{
SDL_Surface *fond;
SDL_Rect positionFond;
}objet;

SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);
int collision_parfaite(SDL_Surface* Backmasque ,SDL_Surface* perso, SDL_Rect p,int z);

/****************player.h*****************/
typedef struct 
{
	
	SDL_Surface *tab[8]; /*!< Surface. */
	SDL_Rect position; /*!< Rectangle*/
	
}personnage;

void initialiser_personnage(personnage *p);
void afficher_personnage(personnage p,SDL_Surface *screen,int i);
void freesurfaceperso(personnage *perso);

/******************enigmeStatique.h*****************/

typedef struct
{
    SDL_Surface *fenetre_enigme;
    SDL_Surface *image;
    SDL_Surface *texte;
    TTF_Font *police;
    SDL_Rect posim,post;
}enigme;

void init_enigme(enigme *enig);
void remplir_fichier(char fichier_question[]);
void afficher_enigme(enigme *enig,int *ancienne,char fichier_question[]);
int solution(int q);
int resolution(int *affiche);
void afficher_resultat(enigme *enig,int solution,int resolution);
void ffree(enigme *enig);

/*********************enigmeAleatoire.h*******************/

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
 SDL_Rect *Questions[3];
 SDL_Rect *Reponse0T,*Reponse01,*Reponse02;
 
 
}Enigme;


void Initialiser_Enigme(Enigme *E);
void generer_Question(SDL_Surface *ecran, char nomFich[],Enigme E );
char generer_Reponse(char *reponse1, *reponse2,*reponse3);
void afficher_Question(Enigme E, SDL_Surface *ecran,char nomFich[]);
void afficher_Reponses(Enigme E);
int solution_enigme(Enigme E);
void EventBoutons_Enigme(SDL_Event event,Enigme E,input *inp);
void liberer (Enigme *E);

/*****************Sauvegarder.h*******************/

typedef struct save//toutes les structures+collision?
{
	personnage p; 
	zombie z;
  SDL_Surface *background;
	FILE *fichier;
}save; 

void update_save (save *s, personnage p,zombie z,SDL_Surface back);
void enregistrer (save s);
void recuperer (save *s);


#endif // STRUCTURES_H_INCLUDED
