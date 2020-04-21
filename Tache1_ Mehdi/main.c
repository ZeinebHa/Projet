#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "player.h"

int main(int argc, char *argv[])
{
SDL_Surface *ecran = NULL, *perso = NULL, *backmask=NULL,*back=NULL;
SDL_Rect positionPerso,positionmasque,positionback;
SDL_Event event;
personnage p;
int continuer = 1,r,z;
int quit =1;
int i=0,j=5,prev=0;
SDL_Init(SDL_INIT_VIDEO);

ecran = SDL_SetVideoMode(1600,600, 32, SDL_HWSURFACE);
SDL_WM_SetCaption("Game", NULL);



backmask= IMG_Load("back_collision.bmp");
back= IMG_Load("back.bmp");

positionback.x=0;
positionback.y=0;

initialiser_personnage(&p);
SDL_EnableKeyRepeat(10,10); // activation de la touche //

while (continuer)
{

SDL_PollEvent(&event);


switch(event.type)
{
case SDL_QUIT:
continuer = 0;
break;
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
case SDLK_UP: // Flèche haut
p.position.y-=2;
z=2;

break;
case SDLK_DOWN: // Flèche bas
p.position.y +=2;
z=3;

break;
case SDLK_RIGHT: // Flèche droite
p.position.x += 2;
z=0;
i++;



break;
case SDLK_LEFT: // Flèche gauche
p.position.x-=2;
z=1;
j++;



break;
}
break;
}

r=0;
if(i==4)i=0;
if(j==8)j=5;
SDL_BlitSurface(back, NULL, ecran, &positionback);
if(z==0){
SDL_BlitSurface(p.tab[i], NULL, ecran, &p.position);
prev=0;
}
if(z==1){
SDL_BlitSurface(p.tab[j], NULL, ecran, &p.position);
prev=1;
}
if((z==2)&&(prev==0)||(z==3)&&(prev==0))
SDL_BlitSurface(p.tab[i], NULL, ecran, &p.position);
if((z==2)&&(prev==1)||(z==3)&&(prev==1))
SDL_BlitSurface(p.tab[j], NULL, ecran, &p.position);


/* On met à jour l'affichage */
SDL_Flip(ecran);

}


freesurfaceperso(&p);
SDL_FreeSurface(back);
SDL_FreeSurface(backmask);



SDL_Quit();
return EXIT_SUCCESS;
}
