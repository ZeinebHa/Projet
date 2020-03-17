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
