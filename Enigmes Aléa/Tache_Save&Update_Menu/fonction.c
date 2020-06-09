#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"fonction.h"
#include <SDL/SDL_mixer.h>


void init_back(bg* b)
{
  b->imageback=IMG_Load ("map.png");
	b->posback.x=0;
	b->posback.y=0;
}

void init_perso(perso* p)
{
  p->image=IMG_Load ("image.png");
	
	p->positionimg.x=100;
	p->positionimg.y=350;
	SDL_EnableKeyRepeat(100,100);
	p->frame=0;
	p->nb_enigmes_resolues=0;
	printf("bienvenue:");
}
void init_input(input *inp)
{
  //*****clavier
	inp->c.haut=-1;
	inp->c.bas=-1;
	inp->c.droite=-1;
	inp->c.gauche=-1;
	inp->c.echap=-1;
	inp->c.entrer=-1;
	inp->c.espace=-1;
	inp->c.a=-1;
	inp->c.b=-1;
	inp->c.c=-1;
	inp->c.p=-1;
	inp->c.s=-1;
	inp->c.n=-1;
	inp->c.y=-1;
	inp->c.z=-1;

	//****souris
	inp->s.left=-1;
	inp->s.right=-1;
	inp->s.middle=-1;
	inp->s.posclick.x=-1;
	inp->s.posclick.y=-1;
	inp->s.motion.x=-1;
	inp->s.motion.y=-1;
}

void deplacement_droite(SDL_Rect clip[6])
{
   clip[0].x=0;
	clip[0].y=191.25;
	clip[0].w=113.75;
	clip[0].h=191.2;

	clip[1].x=113.75;
	clip[1].y=191.25;
	clip[1].w=113.75;
	clip[1].h=191.2;

	clip[2].x=227.5;
	clip[2].y=191.25;
	clip[2].w=100;
	clip[2].h=191.2;

	clip[3].x=341.25;
	clip[3].y=191.25;
	clip[3].w=113.75;
	clip[3].h=191.2;

	clip[4].x=455;
	clip[4].y=191.25;
	clip[4].w=113.75;
	clip[4].h=191.2;

	clip[5].x=568.75;
	clip[5].y=191.25;
	clip[5].w=113.75;
	clip[5].h=191.2;

}
void deplacement_gauche(SDL_Rect clip[6])
{
   clip[0].x=0;
	clip[0].y=382.5;
	clip[0].w=113.75;
	clip[0].h=191.2;

	clip[1].x=113.75;
	clip[1].y=382.5;
	clip[1].w=113.75;
	clip[1].h=191.2;

	clip[2].x=227.5;
	clip[2].y=382.5;
	clip[2].w=100;
	clip[2].h=191.2;

	clip[3].x=341.25;
	clip[3].y=382.5;
	clip[3].w=113.75;
	clip[3].h=191.2;

	clip[4].x=455;
	clip[4].y=382.5;
	clip[4].w=113.75;
	clip[4].h=191.2;

	clip[5].x=568.75;
	clip[5].y=382.5;
	clip[5].w=113.75;
	clip[5].h=191.2;
}
void dep2_right(SDL_Rect clip[4])
{
  clip[0].x=0;
	clip[0].y=573.75;
	clip[0].w=113.75;
	clip[0].h=191.2;

	clip[1].x=113.75;
	clip[1].y=573.75;
	clip[1].w=113.75;
	clip[1].h=191.2;

	clip[2].x=227.5;
	clip[2].y=573.75;
	clip[2].w=100;
	clip[2].h=191.2;

	clip[3].x=341.25;
	clip[3].y=573.75;
	clip[3].w=113.75;
	clip[3].h=191.2;
}
void dep2_left(SDL_Rect clip[4])
{
   clip[0].x=0;
	clip[0].y=765;
	clip[0].w=113.75;
	clip[0].h=191.2;

	clip[1].x=113.75;
	clip[1].y=765;
	clip[1].w=113.75;
	clip[1].h=191.2;

	clip[2].x=227.5;
	clip[2].y=765;
	clip[2].w=100;
	clip[2].h=191.2;

	clip[3].x=341.25;
	clip[3].y=765;
	clip[3].w=113.75;
	clip[3].h=191.2;
}
void update_perso(input inp,perso *p)// deplacement
{
     nt tempsPrecedent = 0, tempsActuel = 0;
	char temps[20];
	//int frame=0;
	int running=1;
	if (inp.c.droite==1)
	{
		tempsActuel = SDL_GetTicks();
		if (tempsActuel - tempsPrecedent >10)
		{
                        p->positionimge.x=5+p->positionimge.x;
			dep2_right(p->animepos);
			p->frame++;
			if(acteur->frame==5)
			{
				p->frame=0;
			}	
			tempsPrecedent = tempsActuel;
		}
	}
  if (inp.c.gauche==1)
	{
		tempsActuel = SDL_GetTicks();
		if (tempsActuel - tempsPrecedent >10)
		{
                        acteur->positionimage.x=-5+acteur->positionimage.x;
			setrects_left(acteur->animepos);
			acteur->frame++;
			if(acteur->frame==5)
			{
				acteur->frame=0;
			}
			tempsPrecedent = tempsActuel;
		}
	}
	
	if (inp.c.a==1)
	{
		tempsActuel = SDL_GetTicks();
		if (tempsActuel - tempsPrecedent >10)
		{
                        p->positionimg.x=-5+p->positionimg.x;
			dep2_left(p->animepos);
			p->frame=0;
			p->frame=1;
			p->frame=2;
			p->frame=3;
			tempsPrecedent = tempsActuel;
		}
	}
	
	if (inp.c.z==1)
	{			
		tempsActuel = SDL_GetTicks();
		if (tempsActuel - tempsPrecedent >10)
		{
                        p->positionimg.x=-5+p->positionimg.x;
			dep2_right(p->animepos);
			p->frame=0;
			p->frame=1;
			p->frame=2;
			p->frame=3;
			tempsPrecedent = tempsActuel;
		}
	}
  
  
}
void get_input(input *inp, Mix_Chunk* sound,int *continuer, int *enigme_ouvert) 
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		    	case SDL_QUIT:
				*continuer=0; 
				break; 
							
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						Mix_PlayChannel(-1,sound,0) ;
						inp->c.echap=1;
						break;
					case SDLK_RIGHT:
						inp->c.droite=1;
						break; 
					case SDLK_LEFT:
						inp->c.gauche=1;
						break;
					case SDLK_DOWN:
						inp->c.bas=1;
						break;
					case SDLK_UP:
						inp->c.haut=1;
						break;
					case SDLK_RETURN:
						Mix_PlayChannel(-1,sound,0) ;
						inp->c.entrer=1;
						break;
					case SDLK_a:;
						inp->c.a=1;
						break; 
					case SDLK_b:
						inp->c.b=1;
						break;
					case SDLK_c:
						inp->c.c=1;
						break;
					case SDLK_p:
						inp->c.p=1;
						break;
					case SDLK_s:
						inp->c.s=1;
						break;
					case SDLK_n:
						inp->c.n=1;
						break;
					case SDLK_y:
						inp->c.y=1;
						break;
					case SDLK_z:
						inp->c.z=1;
						break;
					case SDLK_SPACE://espace
						inp->c.espace=1;	
						break;
					case SDLK_w : 
					if ((*enigme_ouvert)==0)
					{
						(*enigme_ouvert)=1 ;
						SDL_Delay(100) ;   
					}
					break ;
				}
				break;
			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						inp->c.echap=-1;
						break;
					case SDLK_RIGHT:
						inp->c.droite=-1;
						break; 
					case SDLK_LEFT:
						inp->c.gauche=-1;
						break;
					case SDLK_DOWN:
						inp->c.bas=-1;
						break;
					case SDLK_UP:
						inp->c.haut=-1;
						break;
					case SDLK_RETURN:
						inp->c.entrer=-1;
						break;
					case SDLK_a:;
						inp->c.a=-1;
						break; 
					case SDLK_b:
						inp->c.b=-1;
						break;
					case SDLK_c:
						inp->c.c=-1;
						break;
					case SDLK_p:
						inp->c.p=-1;
						break;
					case SDLK_s:
						inp->c.s=-1;
						break;
					case SDLK_n:
						inp->c.n=-1;
						break;
					case SDLK_y:
						inp->c.y=-1;
						break;
					case SDLK_z:
						inp->c.z=-1;
						break;
					case SDLK_SPACE://espace
						inp->c.espace=-1;	
						break;
				}
				break;
			case SDL_MOUSEMOTION:
				inp->s.motion.x=event.motion.x;
				inp->s.motion.y=event.motion.y;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button==SDL_BUTTON_LEFT)//click
				{
					Mix_PlayChannel(-1,sound,0);
					inp->s.left=1;
					inp->s.posclick.x=event.button.x;
					inp->s.posclick.y=event.button.y;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if (event.button.button==SDL_BUTTON_LEFT)
				{
					inp->s.left=-1;
					inp->s.posclick.x=-1;
					inp->s.posclick.y=-1;
				}
				break;
		}
	}
}

void afficher_perso(perso p, SDL_Surface *screen)
{
   SDL_BlitSurface(p.image,&p.animepos[p.frame],screen,&(p.positionimg));
}
void afficher_back(bg b, SDL_Surface *screen)
{
   SDL_BlitSurface(b.imageback,NULL,screen,&(b.posback));
}
void liberer_perso(perso *p)
{
    SDL_FreeSurface(p->image);
	printf("liberer perso:\n");
}
void liberer_back(bg *b)
{
    SDL_FreeSurface(b->imageback);
	printf("liberer back:\n");
}
