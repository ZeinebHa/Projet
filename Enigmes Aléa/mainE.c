#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h> 
#include "Enigmes.h"

int main ()
{

     //initialiser
     SDL_Rect Reponse0T,Reponse01,Reponse02,nouv;
     char  TabRep_vrai[3];
     char *reponse1, *reponse2,*reponse3;
     Enigme E;
     int SolutionE=0;
     char nomFich[30];
     int scorevie=0;
     int continuer=0;
     SDL_Init(SDL_INIT_VIDEO);
     SDL_Surface *ecran;
     SDL_Event event;
     TTF_Font* Font=NULL;
     char Tab[4];
     char chaineR[40];
     input I;
     
	 if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("unable to initialize SDL: %s\n",SDL_GetError());
        return 1;
    }
 ecran=SDL_SetVideoMode(800,640,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(ecran==NULL)
    {
        printf("unable to set video mode:%s\n",SDL_GetError());
        return 1;
    }
    
    SDL_WM_SetCaption("Enigme_Al", NULL);
    TTF_Init();
    
    //rect
     nouv.w=0;
     nouv.h=0;
     
     Reponse0T.x = 0;
     Reponse0T.y = 0;
     
     Reponse01.x = 0;
     Reponse01.y = 0;
      
     Reponse02.x = 0;
     Reponse02.y = 0;
        
Initialiser_Enigme(&E);

 while (continue=1)
	{ 
	generer_Question(ecran,nomFich,E);
        generer_Reponse(&reponse1,&reponse2,&reponse3);
  afficher_Question(E,&ecran,nomFich);
  afficher_Reponses(&E);
 SolutionE= solution_enigme(E);
 EventBoutons_Enigme(event,E,&I);
 SDL_Flip(ecran);

  



	if (continuer==0)
	{
            liberer (&E);
	    SDL_Quit();
	}
return 0;
}
 }
