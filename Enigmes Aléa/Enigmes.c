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
E->Img = IMG_Load(image);
 SDL_BlitSurface(E->Img,NULL,ecran,&(E->p)) ;
  SDL_Flip(screen) ;
}

int solution_enigme(char image [])
{
   	int solution =0 ;
 	
 	if(strcmp(image,"1.jpg")==0)
 	{
     solution =1 ;
 	}
 	else  	if(strcmp(image,"2.jpg")==0)
 	{
 		solution =2;

 	}
 	else 	if(strcmp(image,"3.jpg")==0)
 	{
 		solution =3;	
 	}
 	return solution;
}
void resolution (int *res )
{
    	SDL_Event event ;
  	int continuer=1;
	
	while(continuer)
	{
		SDL_WaitEvent(&event);
	            switch(event.type)
	{
		  case SDL_QUIT:
		     continuer=0;
		 reak ;

                  case SDL_KEYDOWN : 
                         switch( event.key.keysym.sym )
                          {
			  case  SDLK_a: 
					 
			  *res= 1;
				continuer=0;
			   break ;
					 
			   case  SDLK_b:
					 
			   *res= 2;
			     continuer=0;
			   break;
					 
			   case SDLK_e: 
					 
			   *res=3 ;
			continuer=0;
			  break;
					 
			    }
       break ;

}
