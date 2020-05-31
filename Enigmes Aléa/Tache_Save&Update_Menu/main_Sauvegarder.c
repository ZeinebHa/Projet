#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Sauvegarder.h"

int main()
{
   SDL_Surface *ecran ; 
	menu m;
	save s;
	perso p;
	ennemi e;
	input inp;
	int continuer=1;
  char chaine[10];
	SDL_Event event;
  
  ecran = SDL_SetVideoMode(600,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
  
  while (continuer)
	{
		if (SDL_PollEvent(event)
		{
			switch(event.type)
			{
				case SDL_QUIT:
					continuer=0;
			}
		//*******Integration
			//********** Exit game avec sauvegarde 
		if (((m.choix_boutons==0)||(m.choix_boutons==1)||(m.choix_boutons==2))&&(m.choix_options==3))
		{
         printf (" voulez vous sauvegarder votre partie ? ");
			if (strcmp(chaine,"OUI")==0)
			{	
				update_save (&s,p,e,&back);
				enregistrer (s);
			}
      
      //**Jouer**: Continuer la partie precedente
      if (m.choix_boutons== 4)
      {
          printf(" voulez vous reprendre la partie precedente ?");
          if (strcmp(chaine,"OUI")==0)
          {
             recuperer (&s);
          }
        
      }
     continuer=0;
		}

SDL_FreeSurface(ecran);	
SDL_Quit();

}
