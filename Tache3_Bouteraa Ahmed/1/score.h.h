#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

typedef struct
{
SDL_Surface *Star[7];
SDL_Rect Starpos;
int i;
}star; 

typedef struct
{
SDL_Surface* coin[6];
SDL_Rect coinpos;
SDL_Surface* scoreboard[10];
SDL_Surface* cross;
SDL_Rect scoreboardpos;
SDL_Rect crosspos;
int i;
}coin;

void initscoreboard(coin *co);
void changescoinstage1_2(star *s1,star *s2,star *s3);
void affichezscoreboard(coin* co,SDL_Surface* screen,int scorenb);
void initcoin(coin *co);
void  Initstar1stage1_1(star *s);
void Initstar2stage1_1(star *s);
void affichezcross(coin *co,SDL_Surface* screen);
void Initstar3stage1_1(star *s);
void affichezstar(star *s,SDL_Surface* screen);
void affichezcoin(coin *co,SDL_Surface* screen);


#endif 