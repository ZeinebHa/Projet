#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "sauvegarde.h"

int main()
{
   sauvegarde Save;
   int cont=1;
   Enigme e;
   SDL_Event event;
  char ch[20];
  SDL_Surface *ecran;

ecran = SDL_SetVideoMode(900,680,32,SDL_HWSURFACE | SDL_DOUBLEBUF);


while (cont)
	{
	    if (SDL_PollEvent(&event))
           	    {
			switch(event.type)
			{
				case SDL_QUIT:
					cont=0;
			}
                           printf(" voulez vous enregistrer votre partie?");
                        if (strcmp(ch,"oui")==0)
                               {
                                  enregistrersauvegarde(Save);
                               }
                        printf ("voulez vous reprendre la partie precendente ?");
                         if (strcmp(ch,"oui")==0)
                             {
                                  recuperersauvegarde(Save);
                             }
                    }
      }



}
