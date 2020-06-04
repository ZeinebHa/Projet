#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Rotozoom.h"
#define TEMPS       30 // Le temps qu'il y a entre chaque augmentation de l'angle.
 
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *image = NULL, *rotation = NULL;
    SDL_Rect rect;
    SDL_Event event;
    double angle = 0;
 
    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
 
    SDL_Init(SDL_INIT_VIDEO);
 
    ecran = SDL_SetVideoMode(1000, 700, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Ghada", NULL);
 
    image = IMG_Load("smil.png");
 
    rect.x =  150;
    rect.y =  150;
 
    while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
 
        zoom(&tempsActuel,&tempsPrecedent,ecran,&angle,image,rotation,rect,TEMPS);
    }
 
    SDL_FreeSurface(ecran);
    SDL_FreeSurface(image);
    SDL_Quit();
 
    return EXIT_SUCCESS;
}
