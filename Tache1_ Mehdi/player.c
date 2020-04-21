#include "player.h"
void initialiser_personnage(personnage *p)
{
  
  
  
   
    p->tab[0]=IMG_Load("1.png");
    p->tab[1]=IMG_Load("2.png");
    p->tab[2]=IMG_Load("3.png");
    p->tab[3]=IMG_Load("4.png");
    p->tab[4]=IMG_Load("5.png");
    p->tab[5]=IMG_Load("6.png");
    p->tab[6]=IMG_Load("7.png");
    p->tab[7]=IMG_Load("8.png");
    
  p->position.x=40;
  p->position.y=360;
}

void afficher_personnage(personnage p,SDL_Surface *screen,int i)
{
  SDL_BlitSurface(p.tab[i],NULL,screen,&p.position);

}

void freesurfaceperso(personnage *perso)
{
SDL_FreeSurface(perso->tab[0]);
SDL_FreeSurface(perso->tab[1]);
SDL_FreeSurface(perso->tab[2]);
SDL_FreeSurface(perso->tab[3]);
SDL_FreeSurface(perso->tab[4]);
SDL_FreeSurface(perso->tab[5]);
SDL_FreeSurface(perso->tab[6]);
SDL_FreeSurface(perso->tab[7]);
}
