
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct
{
    SDL_Surface *jouer[2]; // feha jouer wou jouer 1
    SDL_Surface *parametre[2]; //feha  parametre wou parametre 2
   SDL_Surface *quitter[2];
  SDL_Surface *logo;
  SDL_Surface *L[10];
    SDL_Surface *volume[3]; //fih volume wou volume1 wou vol
    SDL_Surface  *resolution[2]; // fih reso wou reso 1;
    SDL_Surface *image; 
    SDL_Surface *personnage;
}Surface;

typedef struct
{
    SDL_Rect positionimage;
    SDL_Rect posjouer ;
    SDL_Rect posparametre;
    SDL_Rect posquitter;
    SDL_Rect positionjoueur;
    SDL_Rect posob;
    SDL_Rect poslogo;
    SDL_Rect posvolume[3];
    SDL_Rect posresolution[2];

}Rect;

typedef struct
{
   int space;
   int enter;
   int up;
   int down;
   int left;
   int right;
   int echap;
}Input;


typedef struct
{
   Input input;
   Rect pos;
   Surface img;


}Menu;


void initialisermenu(Menu *menu);
void getInput(Menu menu);
void affichermenu(Menu menu,SDL_Surface *screen);
void freemenu(Menu *menu);
        

