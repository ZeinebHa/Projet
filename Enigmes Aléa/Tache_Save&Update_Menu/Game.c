#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Game.h"

/*
void init_back (back* b)
{
	b->imageback=IMG_Load ("map.png");
	b->posback.x=0;
	b->posback.y=0;
}
void init_perso(perso* p)
{
	p->imageperso=IMG_Load ("rajel.png");
	p->posperso.x=20;
	p->posperso.y=360;
}
void init_input(input *inp)
{
	
	inp->c.right=-1;
	inp->c.left=-1;
	inp->c.echap=-1;
	inp->c.up=-1;
	inp->c.down=-1;
	
}*/

void initialiserObj( object *obj ,  int x , int y ) 
{

	obj->image = IMG_Load("virus.png"); 
     	obj->position.x  =  x ; 
     	obj->position.y  =  y ; 
     	obj->position.h  =  obj->image->h ;
	obj->position.w = obj->image->w ;
	
}

/*
int update_perso(input inp,perso *p)
{
	
		if (inp.c.right==1)
		{ 
			p->posperso.x+=10;
		}
                else if (inp.c.left==1)
		{
			p->posperso.x-=10;
		}
		else if (inp.c.down==1)
		{
			p->posperso.y += 10;
		}
		 else if (inp.c.up==1)
		 {
		 	p->posperso.y -= 10;
		}
	return p->posperso.x ; 
          
}
void afficher_back (back b, SDL_Surface *screen)
{
	SDL_BlitSurface(b.imageback,NULL,screen,&(b.posback));
}
void afficher_perso (perso p, SDL_Surface *screen)
{
	SDL_BlitSurface(p.imageperso,NULL,screen,&(p.posperso));
}
void affichageObj ( object obj , SDL_Surface *screen) 
{
SDL_BlitSurface(obj.image, NULL, screen, &(obj.position));
SDL_Flip(screen);
}
void get_input(input *inp,SDL_Event event)
{
	switch (event.type)
	{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						inp->c.echap=1;
						break;
					case SDLK_RIGHT:
						inp->c.right=1;
						break; 
					case SDLK_LEFT:
						inp->c.left=1;
						break;
					case SDLK_UP:
						inp->c.up=1;
						break;
			    		case SDLK_DOWN:
						inp->c.down=1;
						break;
				}break;
			                case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						inp->c.echap=0;
						break;
					case SDLK_RIGHT:
						inp->c.right=0;
						break; 
					case SDLK_LEFT:
						inp->c.left=0;
						break;
					case SDLK_UP:
						inp->c.up=0;
						break;
			    		case SDLK_DOWN:
						inp->c.down=0;
						break;
				}break;
		}
	
}*/ 
void affichageObj ( object obj , SDL_Surface *screen) 
{
SDL_BlitSurface(obj.image, NULL, screen, &(obj.position));

}

object Entity_Deplacer( object obj)
{


	if (obj.position.y<50)
		{
			obj.Direction=1;
			
			
		}
    
       if (obj.position.y> 300)
		{
			obj.Direction=0;
			
			
		}
  
	if (obj.Direction=1) 
		{
			obj.position.y+=5 ;
			
		}
	       
	
	else if (obj.Direction=0)
		
		{
			 obj.position.y-=5;
			
		}
		 return obj ; 
}




int collisionbb( SDL_Rect posj , SDL_Rect posobj )
{
int x ; 
if ( (posj.x+posj.w>=posobj.x)&&(posj.x<=posobj.x+posobj.w)&&(posj.y+posj.h>=posobj.y)&&(posj.y<=posobj.y+posobj.h) )
{
	x=1 ; 
}

else x=0 ; 
return x ;
}




/*
void liberer_perso (perso *p)
{
	SDL_FreeSurface(p->imageperso);
}
void liberer_back (back *b)
{
	SDL_FreeSurface(b->imageback);
}*/

void liberer_object(object *obj)
{
SDL_FreeSurface(obj->image);
}
