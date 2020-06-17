#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include "fonction.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

/**
* @file Main.c
* @brief proto1 
* @author ahmed ben abdallah
* @version 1.0
* @date June ,13 2020
*
* entite secondaire
*/

int main (void)

{

    int continuee=1;

    SDL_Surface *ecran =NULL;

    SDL_Surface *image=NULL;
	
    SDL_Rect posimage,poshero;

	SDL_Event event ; 
    SDL_Init(SDL_INIT_VIDEO);

    ennemi e ;
    


    ecran = SDL_SetVideoMode(700,490,32, SDL_HWSURFACE | SDL_DOUBLEBUF);




    image=IMG_Load("m.jpeg");
    posimage.x=0;
    posimage.y=0;


	

    if (ecran==NULL)

    {

        printf("error: %s ",SDL_GetError());

        exit(EXIT_FAILURE);

    }




	e=initialisation_ennemi(e);
	
	

    while (continuee)
    {
      SDL_PollEvent(&event) ; 
 switch  ( event.type )  
	{ 
             case  SDL_QUIT : 
                 continuee  =  0 ; 
break;
	}
        SDL_BlitSurface(image, NULL, ecran, &posimage);
	
	
        afficher(e,ecran);
	
        maj_ennemi (&e) ;
	
        SDL_Flip(ecran);




    }










    SDL_FreeSurface(ecran);
	
    SDL_Quit();

    return EXIT_SUCCESS;

}

