


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "collision.h"





SDL_Color GetPixel(SDL_Surface* pSurface,int x,int y)
{
SDL_Color color;
Uint32 col=0;
//Determine position
char* pPosition=(char* ) pSurface->pixels;
pPosition+= (pSurface->pitch * y);
pPosition+= (pSurface->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
//convertir color
SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);

return (color);

}


int collision_parfaite(SDL_Surface* Backmasque ,SDL_Surface* perso, SDL_Rect p, int z) 
{


int i=0,test,x;
SDL_Color couleurobst;
SDL_Rect position[8];


position[0].x=p.x;
position[0].y=p.y;

position[1].x=p.x+(perso->w/2);//haut
position[1].y=p.y;//haut

position[2].x=p.x+(perso->w);
position[2].y=perso->w;

position[3].x=p.x;// gauche
position[3].y=p.y+(perso->h/2);//gauche

position[4].x=p.x;
position[4].y=p.y+(perso->h);

position[5].x=p.x+(perso->w/2);//bas
position[5].y=p.y+(perso->h);//bas

position[6].x=p.x+(perso->w);
position[6].y=p.y+(perso->h);

position[7].x=p.x+(perso->w);//droit
position[7].y=p.y+(perso->h/2);//droit


if(z==0)
{
	couleurobst=GetPixel(Backmasque,p.x+(perso->w),p.y+(perso->h/2));
}
else
if(z==1)
{
	couleurobst=GetPixel(Backmasque,p.x,p.y+(perso->h/2));
}
else
if(z==2)
{
	couleurobst=GetPixel(Backmasque,p.x+(perso->w/2),p.y);
}
else
if(z==3)
{
	couleurobst=GetPixel(Backmasque,p.x+(perso->w/2),p.y+(perso->h));
}

	if(couleurobst.r == 255 && couleurobst.g == 255 && couleurobst.b == 255)		
		{
		 return 1;
		}
	else return 0;	
	 	 
}












