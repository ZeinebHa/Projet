#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enigme.h"
#include "time.h"
void initialiser_enigme(Enigme *E)
{
	E->p.x=0;
	E->p.y=0;	
	E->Img=NULL;
}
void generate_afficher (SDL_Surface *ecran  , char image [],enigme *E,int *RaNd)
{ 
	int test=*RaNd ;
	srand(time(NULL));
 *RaNd = 1+ rand()%3;

 sprintf(image ,"%d.jpg",*RaNd);
E->img = IMG_Load(image);
 SDL_BlitSurface(E->img,NULL,ecran,&(E->p)) ;
  SDL_Flip(screen) ;
}
