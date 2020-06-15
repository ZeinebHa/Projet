#ifndef TEMP_H_INCLUDED
#define TEMP_H_INCLUDED
typedef struct 
{
SDL_Surface *temp[6];
SDL_Rect temppos;	
}temp;
void inittemp(temp* t);
void affichertemp(temp* t,SDL_Surface* screen,int temp);
#endif 