#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>


int main(int argc, char *argv[])
{
SDL_Surface *ecran = NULL, *perso = NULL,*perso2=NULL, *backmask=NULL,*back=NULL,*back2=NULL;
SDL_Rect positionPerso,positionPerso2,positionmasque,positionback,positionback2;
SDL_Event event;
int continuer = 1,r,r2,z,z2;
int quit =1;

SDL_Init(SDL_INIT_VIDEO);

ecran = SDL_SetVideoMode(1600,1200, 32, SDL_HWSURFACE);
SDL_WM_SetCaption("Collision avec le background", NULL);

/* Chargement de Zozor */
perso = IMG_Load("perso.png");
perso2=IMG_Load("perso.png");
backmask= IMG_Load("back_collision.bmp");
back= IMG_Load("back.bmp");
back2=IMG_Load("back.bmp");

positionback.x=0;
positionback.y=0;
positionback2.x=0;
positionback2.y=600;
/* On centre Zozor à l'écran */
positionPerso.x = 50;
positionPerso.y = 400;

positionPerso2.x = 50;
positionPerso2.y = 800;
SDL_EnableKeyRepeat(10,10); // activation de la touche //

while (continuer)
{

SDL_PollEvent(&event);

r= collision_parfaite(backmask,perso,positionPerso,z);
r2= collision_parfaite(backmask,perso2,positionPerso2,z);
switch(event.type)
{
case SDL_QUIT:
continuer = 0;
break;
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
case SDLK_UP: // Flèche haut
positionPerso.y-=2;
z=2;
if(r==1)
	{positionPerso.y += 2;}
break;
case 'z':
positionPerso2.y-=2;
z2=2;
if(r==1)
	{positionPerso2.y += 2;}
break;

case SDLK_DOWN: // Flèche bas
positionPerso.y +=2;
z=3;
if(r==1)
	{positionPerso.y -= 2;}
break;

case 's':
positionPerso2.y +=2;
z2=3;
if(r==1)
	{positionPerso2.y -= 2;}
break;

case SDLK_RIGHT: // Flèche droite
positionPerso.x += 2;
z=0;
positionback.x= scrolling(z,positionback.x,positionPerso.x);
if(r==1)
	{positionPerso.x -= 2;}
break;

case 'd':
positionPerso2.x += 2;
z2=0;
positionback2.x= scrolling(z2,positionback2.x,positionPerso2.x);
if(r==1)
	{positionPerso2.x -= 2;}
break;
case SDLK_LEFT: // Flèche gauche
positionPerso.x-=2;
z=1;
positionback.x= scrolling(z,positionback.x,positionPerso.x);
if(r==1)
	{positionPerso.x += 2;}
break;

case 'q':
positionPerso2.x-=2;
z2=1;
positionback2.x= scrolling(z2,positionback2.x,positionPerso2.x);
if(r==1)
	{positionPerso2.x += 2;}
break;
}
break;
}

r=0;

if(positionPerso.x<=800)
{
SDL_BlitSurface(back, NULL, ecran, &positionback);
//SDL_BlitSurface(backmask, NULL, ecran, &positionback);
SDL_BlitSurface(perso, NULL, ecran, &positionPerso);


}
else{
SDL_BlitSurface(back,&positionback , ecran, NULL);
//SDL_BlitSurface(backmask, NULL, ecran, &positionback);
SDL_BlitSurface(perso, NULL, ecran, &positionPerso);
}

if(positionPerso2.x<=800)
{
SDL_BlitSurface(back2, NULL, ecran, &positionback2);
//SDL_BlitSurface(backmask, NULL, ecran, &positionback);
SDL_BlitSurface(perso2, NULL, ecran, &positionPerso2);


}
else{
SDL_BlitSurface(back2,&positionback2 , ecran, NULL);
//SDL_BlitSurface(backmask, NULL, ecran, &positionback);
SDL_BlitSurface(perso2,&positionPerso2 , ecran, NULL);
}


/* On met à jour l'affichage */
SDL_Flip(ecran);

}

SDL_FreeSurface(perso);
SDL_FreeSurface(back);
SDL_FreeSurface(perso2);
SDL_FreeSurface(back2);
SDL_FreeSurface(backmask);



SDL_Quit();
return EXIT_SUCCESS;
}
