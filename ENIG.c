#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include "enigme.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
void init_enigme(enigme *enig)
{
    enig->fenetre_enigme=NULL;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    enig->image=NULL;
    enig->posim.x=0;
    enig->posim.y=0;
    enig->post.x=120;
    enig->post.y=50;
}

void remplir_fichier(char fichier_question[])
{
    FILE *fq=NULL;
    fq=fopen(fichier_question,"w");
    if(fq==NULL) printf("erreur de l'ouverture");
    else
    {
	fprintf(fq,"Les cellules sanguines sont elles fabriquees dans le coeur? \nAs-t-on plus de 100 millions de neurones dans notre cerveau? \nEst-ce que la peau est l'organe le plus lourd du corps humain? \nAs-t-on 20 vertebres dans notre colonnes vertebrale? \nL'estomac peut-il contenir 5 litres d'eau? \nUn adulte as-t-il 34 dents? \n");
	fclose(fq);
    }
}

void afficher_enigme(enigme *enig,int *ancienne,char fichier_question[])
{
    FILE *fq=NULL;
    int taille=100,l=1;
    char ch[60];
    SDL_Color couleur={0,255,0};

    enig->fenetre_enigme= SDL_SetVideoMode(1300, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    fq=fopen(fichier_question,"r");
    enig->image=IMG_Load("labo.png");
    enig->police=TTF_OpenFont("labo.ttf",60);
    if(fq==NULL) printf("erreur de l'ouverture");
    else
    {   if((*ancienne)==0)
		{
		    if(fgets(ch,taille,fq)!=NULL) {   
                                                      enig->texte=TTF_RenderText_Blended(enig->police,ch,couleur);
	                                              SDL_BlitSurface(enig->image,NULL,enig->fenetre_enigme,&(enig->posim));
	                                              SDL_BlitSurface(enig->texte,NULL,enig->fenetre_enigme,&(enig->post));
						      SDL_Flip(enig->fenetre_enigme);
                                                      (*ancienne)++;
                                                  } 
		}
          else{
		while((fgets(ch,taille,fq)!=NULL)&&(l<=(*ancienne)))
	        {
	    	    l++;
	        }
		enig->texte=TTF_RenderText_Blended(enig->police,ch,couleur);
		SDL_BlitSurface(enig->image,NULL,enig->fenetre_enigme,&(enig->posim));
		SDL_BlitSurface(enig->texte,NULL,enig->fenetre_enigme,&(enig->post));
		SDL_Flip(enig->fenetre_enigme);
                (*ancienne)++;
	      }	
	fclose(fq);
    } 
}

int solution(int q)
{
int s=0;
    switch(q)
    {
    case 1:
        s=2;
        break;
    case 2:
        s=1;
        break;
    case 3:
        s=1;
        break;
    case 4:
        s=2;
        break;
    case 5:
        s=2;
        break;
    case 6:
        s=1;
        break;
    }
    return s;
}

int resolution(int *affiche)
{
    SDL_Event event;
    int r=0;
    SDL_PollEvent(&event);
    switch(event.type)
    {

    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
        case SDLK_a:
            r=1;
	    *affiche=1;
            break;
        case SDLK_z:
            r=2;
	    *affiche=1;
            break;
   
        }
        break;
    }
    return r;
}

void afficher_resultat(enigme *enig,int solution,int resolution)
{
   
    if(solution==resolution)
    {
        enig->image=IMG_Load("0.png");
        SDL_BlitSurface(enig->image,NULL,enig->fenetre_enigme,&(enig->posim));
        SDL_Flip(enig->fenetre_enigme);
    }
    else
    {
        enig->image=IMG_Load("1.png");
        SDL_BlitSurface(enig->image,NULL,enig->fenetre_enigme,&(enig->posim));
        SDL_Flip(enig->fenetre_enigme);
    }
}

void ffree(enigme *enig)
{
    TTF_CloseFont(enig->police);
    TTF_Quit();
    SDL_FreeSurface(enig->image);
    SDL_FreeSurface(enig->texte);
    SDL_Quit();
}

