#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "score.h"





void initcoin(coin *co)
{
co->coin[0]=IMG_Load("star coin rotate 1.png");
co->coin[1]=IMG_Load("star coin rotate 2.png");
co->coin[2]=IMG_Load("star coin rotate 3.png");
co->coin[3]=IMG_Load("star coin rotate 4.png");
co->coin[4]=IMG_Load("star coin rotate 5.png");
co->coin[5]=IMG_Load("star coin rotate 6.png");
co->cross=IMG_Load("cross.png");
co->crosspos.x=100;
co->crosspos.y=20;
co->coinpos.x=30;
co->coinpos.y=20;
co->i=0;
}
void initcoin2(coin *co)
{
co->coin[0]=IMG_Load("star coin rotate 1.png");
co->coin[1]=IMG_Load("star coin rotate 2.png");
co->coin[2]=IMG_Load("star coin rotate 3.png");
co->coin[3]=IMG_Load("star coin rotate 4.png");
co->coin[4]=IMG_Load("star coin rotate 5.png");
co->coin[5]=IMG_Load("star coin rotate 6.png");
co->cross=IMG_Load("cross.png");
co->crosspos.x=900;
co->crosspos.y=20;
co->coinpos.x=830;
co->coinpos.y=20;
co->i=0;
}

void initscoreboard(coin *co)
{
co->scoreboard[0]=IMG_Load("0.png");
co->scoreboard[1]=IMG_Load("1.png");
co->scoreboard[2]=IMG_Load("2.png");
co->scoreboard[3]=IMG_Load("3.png");
co->scoreboard[4]=IMG_Load("4.png");
co->scoreboard[5]=IMG_Load("5.png");
co->scoreboard[6]=IMG_Load("6.png");
co->scoreboard[7]=IMG_Load("7.png");
co->scoreboard[8]=IMG_Load("8.png");
co->scoreboard[9]=IMG_Load("9.png");
co->scoreboardpos.x=160;
co->scoreboardpos.y=20;
}
void initscoreboard2(coin *co)
{
co->scoreboard[0]=IMG_Load("0.png");
co->scoreboard[1]=IMG_Load("1.png");
co->scoreboard[2]=IMG_Load("2.png");
co->scoreboard[3]=IMG_Load("3.png");
co->scoreboard[4]=IMG_Load("4.png");
co->scoreboard[5]=IMG_Load("5.png");
co->scoreboard[6]=IMG_Load("6.png");
co->scoreboard[7]=IMG_Load("7.png");
co->scoreboard[8]=IMG_Load("8.png");
co->scoreboard[9]=IMG_Load("9.png");
co->scoreboardpos.x=960;
co->scoreboardpos.y=20;
}

void  Initstar1stage1_1(star *s)
{
s->Star[0]=IMG_Load("starcoin1.png");
s->Star[1]=IMG_Load("starcoin2.png");
s->Star[2]=IMG_Load("starcoin3.png");
s->Star[3]=IMG_Load("starcoin4.png");
s->Star[4]=IMG_Load("starcoin5.png");
s->Star[5]=IMG_Load("starcoin6.png");
s->Starpos.x=310;
s->Starpos.y=330;
s->i=0; 
}
void  Initstar1stage1_12(star *s)
{
s->Star[0]=IMG_Load("starcoin1.png");
s->Star[1]=IMG_Load("starcoin2.png");
s->Star[2]=IMG_Load("starcoin3.png");
s->Star[3]=IMG_Load("starcoin4.png");
s->Star[4]=IMG_Load("starcoin5.png");
s->Star[5]=IMG_Load("starcoin6.png");
s->Starpos.x=1110;
s->Starpos.y=330;
s->i=0; 
}
void Initstar2stage1_1(star *s)
{
s->Star[0]=IMG_Load("starcoin1.png");
s->Star[1]=IMG_Load("starcoin2.png");
s->Star[2]=IMG_Load("starcoin3.png");
s->Star[3]=IMG_Load("starcoin4.png");
s->Star[4]=IMG_Load("starcoin5.png");
s->Star[5]=IMG_Load("starcoin6.png");
s->Starpos.x=510;
s->Starpos.y=260;
s->i=0;                             //Les etoiles du stage 1-1 chaque etoiles est 100 score
}
void Initstar2stage1_12(star *s)
{
s->Star[0]=IMG_Load("starcoin1.png");
s->Star[1]=IMG_Load("starcoin2.png");
s->Star[2]=IMG_Load("starcoin3.png");
s->Star[3]=IMG_Load("starcoin4.png");
s->Star[4]=IMG_Load("starcoin5.png");
s->Star[5]=IMG_Load("starcoin6.png");
s->Starpos.x=1310;
s->Starpos.y=260;
s->i=0;                             //Les etoiles du stage 1-1 chaque etoiles est 100 score
}
void Initstar3stage1_1(star *s)
{
s->Star[0]=IMG_Load("starcoin1.png");
s->Star[1]=IMG_Load("starcoin2.png");
s->Star[2]=IMG_Load("starcoin3.png");
s->Star[3]=IMG_Load("starcoin4.png");
s->Star[4]=IMG_Load("starcoin5.png");
s->Star[5]=IMG_Load("starcoin6.png");
s->Starpos.x=700;
s->Starpos.y=180;
s->i=0;
}
void Initstar3stage1_12(star *s)
{
s->Star[0]=IMG_Load("starcoin1.png");
s->Star[1]=IMG_Load("starcoin2.png");
s->Star[2]=IMG_Load("starcoin3.png");
s->Star[3]=IMG_Load("starcoin4.png");
s->Star[4]=IMG_Load("starcoin5.png");
s->Star[5]=IMG_Load("starcoin6.png");
s->Starpos.x=1500;
s->Starpos.y=180;
s->i=0;
}
void changescoinstage1_2(star *s1,star *s2,star *s3)
{
s1->Starpos.x=400;
s1->Starpos.y=420;
s2->Starpos.x=150;
s2->Starpos.y=190;
s3->Starpos.x=400;
s3->Starpos.y=190;
}
void changescoinstage1_22(star *s1,star *s2,star *s3)
{
s1->Starpos.x=1200;
s1->Starpos.y=420;
s2->Starpos.x=950;
s2->Starpos.y=190;
s3->Starpos.x=1200;
s3->Starpos.y=190;
}
void affichezstar(star *s,SDL_Surface* screen)
{
	
SDL_BlitSurface(s->Star[s->i],NULL,screen,&s->Starpos);
s->i++;
if(s->i>5)
{
s->i=0;	
}	
}

void affichezcoin(coin *co,SDL_Surface* screen)
{
	
SDL_BlitSurface(co->coin[co->i],NULL,screen,&co->coinpos);
co->i++;
if(co->i>5)
{
co->i=0;	
}	
}

void affichezcross(coin *co,SDL_Surface* screen)
{
SDL_BlitSurface(co->cross,NULL,screen,&co->crosspos);
}

void affichezscoreboard(coin* co,SDL_Surface* screen,int scorenb)
{
SDL_BlitSurface(co->scoreboard[scorenb],NULL,screen,&co->scoreboardpos);
}


