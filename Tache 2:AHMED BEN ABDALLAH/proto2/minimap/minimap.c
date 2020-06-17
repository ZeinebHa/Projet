#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>// librairies qui contient les fonctions
#include <SDL/SDL_ttf.h>
#include "ennemi.h"
#include <SDL/SDL_mixer.h>
/**
* @file minimap.c
* @author ahmed ben abdallah
*/

/**
* @return minimap
*/
minimap initialisation_minimap (minimap m) 
{
	
m.s=IMG_Load("mini_map.png");	
	m.position.x=0 ;
	m.position.y=0 ;
return m ;
}
/**
* @return curseur
*/
curseur initialisation_curseur(curseur c)
{
c.cu=IMG_Load("curseur.png");
	c.position.x=0;
	c.position.y=5;
return c ;
}
/**
* @return nothing
*/ 
void afficher_minimap(minimap m,curseur c,SDL_Surface *ecran)
{
SDL_BlitSurface(m.s,NULL,ecran,&m.position);
 
SDL_BlitSurface(c.cu,NULL,ecran,&c.position);
SDL_FreeSurface(&m.position);
SDL_FreeSurface(&c.position);
}
/**
* @return nothing
*/ 
void mini_map(curseur * c ,ennemi *e)
{
	c->position.x=(float)0.32*(e->positionennemi.x);
	c->position.y=(float)0.32*(e->positionennemi.y);

}


 





