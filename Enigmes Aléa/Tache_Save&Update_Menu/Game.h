#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


/*typedef struct back
{
	SDL_Surface* imageback;
	SDL_Rect posback;
} back;
typedef struct perso
{
	SDL_Surface* imageperso;
	SDL_Rect posperso;
} perso;
typedef struct clavier
{
	int right;
	int left;
	int echap;
	int up;
	int down;
}clavier; 
typedef struct input
{
	clavier c;
}input;
*/

typedef struct 
{

SDL_Surface *image ; 
SDL_Rect position ; 
int Direction;

} object ; 



/*
void init_back (back* b);
void init_perso(perso* p);
void init_input(input *inp);
int update_perso(input inp,perso *p);
void afficher_back (back b, SDL_Surface *screen);
void afficher_perso (perso p, SDL_Surface *screen);
void get_input(input *inp,SDL_Event event);
void liberer_perso (perso *p);
void liberer_back (back *b);*/
void initialiserObj( object *obj ,  int x , int y ) ;

void affichageObj ( object obj , SDL_Surface *screen) ;
object Entity_Deplacer( object obj);
int collisionbb( SDL_Rect posj , SDL_Rect posobj ) ;
void initialiserObj( object *obj ,  int x , int y );
void liberer_object(object *obj); 
#endif // JEU_H_INCLUDED
