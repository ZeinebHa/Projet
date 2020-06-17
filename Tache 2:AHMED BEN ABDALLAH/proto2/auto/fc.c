#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include "fc.h"

/**
* @file fc.c
*/
/**
*
* @return enemyy
*/
enemy deplacement_aleatoire(enemy enemyy)
{ 
 if (enemyy.direction % 2 ==1){  if (enemyy.posen.x<enemyy.position_initiale + enemyy.distance ) {enemyy.posen.x+=5;   }
         else  { enemyy.direction++; } }
        else if (enemyy.direction % 2 ==0)
              {  if (enemyy.posen.x>enemyy.position_initiale ) {enemyy.posen.x-=5;   }
         else  { enemyy.direction++; } }  
   return (enemyy) ;   
}

/**
*
* @return enemyy
*/
enemy intialisation_enemy(enemy enemyy)
{
enemyy.posen.x=880;enemyy.posen.y=637; //638.5
enemyy.distance=200;
enemyy.position_initiale=880;
enemyy.direction = 1;
enemyy.en=IMG_Load("en1.png");
 return (enemyy) ; 
}

/**
*
* @return perso
*/
personnage initialisation_perso(personnage perso)
{
perso.posperso.x=400;perso.posperso.y=637; //638.5
perso.perso=IMG_Load("pers.png");
perso.h=61;
perso.w=64;
 return (perso) ; 
}
/**
*
* @return nar
*/
enemy initialisation_box(enemy nar)
{
nar.posen.x=200;nar.posen.y=600; //638.5

nar.en=IMG_Load("feu.png");
 return (nar) ; 
}



void afficher (enemy enemy1,SDL_Surface *ecran)
{SDL_BlitSurface( enemy1.en,NULL,ecran,&enemy1.posen);}

void afficher_nar (enemy nar,SDL_Surface *ecran)
{
  SDL_BlitSurface( nar.en,NULL,ecran,&nar.posen);
}
/**
*
* @param d affichage perso 
* @return perso
*/
void afficher_perso (personnage perso ,enemy nar,SDL_Surface *ecran,int *d)
{
  if ((nar.posen.x==perso.posperso.x))
    *d=2;
 if (*d!=2){SDL_BlitSurface( perso.perso,NULL,ecran,&perso.posperso);}
}

enemy automatisation (SDL_Rect pos, enemy en4,SDL_Rect *posfire,int *firee,int *direct)
{ int dis=300,dis2=150;
  
  if (pos.x<en4.posen.x)
        en4.direction=1;
  else if (pos.x+100>en4.posen.x)
        en4.direction=2;
  if (en4.direction==1)
 {if (((pos.x+dis)>en4.posen.x)&& ((en4.posen.x-pos.x)>100))
   {   *firee=1;
       //*alea=2;
      en4.posen.x-=3;
    if ((en4.posen.x-pos.x)<dis2)
   {
   posfire->x=en4.posen.x-70;
  posfire->y=en4.posen.y+10;
    *firee=2;
    

   }
    }}
  else if (en4.direction==2)
 {if (((pos.x-en4.posen.x)<dis)&&((pos.x-en4.posen.x)<100))
   {   *firee=1;
      en4.posen.x+=3;
    if ((pos.x-en4.posen.x)<dis2)
   {
   posfire->x=en4.posen.x+55;
  posfire->y=en4.posen.y+12;
    *firee=2;
    

   }
    }}
*direct=en4.direction;
  
return en4;
}


int callenemy(personnage per, enemy en)
{

    if ((per.posperso.x +per.perso->w > en.posen.x) && (per.posperso.x < en.posen.x ) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}






