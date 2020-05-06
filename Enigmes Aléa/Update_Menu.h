#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"


typedef struct
{
  int click;
	int motion;

}Souris;

typedef struct clavier
{
	
	int Right;
	int Left;
	int Escape;
	int Enter;
	int j; //jump
	int a; // attack
  int x; //click
	
}clavier; 

typedef struct input
{
	clavier c;
	souris s;
	//manette m;
}input;
