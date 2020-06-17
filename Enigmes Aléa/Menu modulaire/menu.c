#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include  <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"


void initialiserinput(Input *input)
{
                input->enter = -1;
		input->space = -1;
	        input->echap= -1;
		input->left = -1;
		input->right = -1;
		input->up = -1;
		input->down = -1;

}
void initialisermenu(Menu *menu)
{
  
SDL_Surface *screen;
//int x=0;
Mix_Chunk *music;
Mix_Chunk *music1;
int i1=0;

SDL_Init(SDL_INIT_VIDEO);


  if(SDL_Init(SDL_INIT_VIDEO)!=0){
	printf("unable to initialize SDL: %s\n",SDL_GetError());
		 // x=1;

				}
 screen=SDL_SetVideoMode(1000,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

  if(screen==NULL){
     printf("unable to set video mode:%s\n",SDL_GetError());
		  // x=1;
		}
//gestion son
Mix_AllocateChannels(2);
 if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
 {
   printf("%s",Mix_GetError());
 }
music=Mix_LoadWAV("Clic De Souris.wav");
music1=Mix_LoadWAV("fond.wav");
Mix_VolumeChunk(music1,i1);

//titre jeu
SDL_WM_SetCaption("NUMERETRY ROAD",NULL);


//gestion image

menu->img.volume[0] =IMG_Load("V1.png");
menu->img.resolution[0] =IMG_Load("resolution.png");
menu->img.resolution[1] =IMG_Load("reso1.png");
menu->img.volume[1] =IMG_Load("volume2.png");
menu->img.volume[2]=IMG_Load("volume3.png");
//titre equipe
menu->img.L[0]=IMG_Load("1a.png");
menu->img.L[1]=IMG_Load("2a.png");
menu->img.L[2]=IMG_Load("3a.png");
menu->img.L[3]=IMG_Load("4a.png");
menu->img.L[4]=IMG_Load("5a.png");
menu->img.L[5]=IMG_Load("6.png");
menu->img.L[6]=IMG_Load("7.png");
menu->img.L[7]=IMG_Load("8.png");
menu->img.L[8]=IMG_Load("9.png");
menu->img.L[9]=IMG_Load("10.png");

menu->img.logo=IMG_Load("logo-jeu-2.png");
menu->img.image=IMG_Load("fond.jpg");
menu->img.jouer[0]=IMG_Load("PP.png");
menu->img.jouer[1]=IMG_Load("PLAY.png");
menu->img.parametre[0]=IMG_Load("SETTINGS.png");
menu->img.parametre[1]=IMG_Load("SETTINGS1.png");
menu->img.quitter[0]=IMG_Load("EXIT.png");
menu->img.quitter[1]=IMG_Load("EXIT1.png");
menu->img.personnage=IMG_Load("per.png");

//Rect

menu->pos.positionimage.x=0;
menu->pos.positionimage.y=0;

menu->pos.positionjoueur.x=150;
menu->pos.positionjoueur.y=70;

menu->pos.posvolume[0].x=600;
menu->pos.posvolume[0].y=125;

menu->pos.posvolume[1].x=882;
menu->pos.posvolume[1].y=120;

menu->pos.posvolume[2].x=200;
menu->pos.posvolume[2].y=100;

menu->pos.posresolution[0].x=200;
menu->pos.posresolution[0].y=300;

menu->pos.posresolution[1].x=600;
menu->pos.posresolution[1].y=300;

menu->pos.positionimage.w=1000;
menu->pos.positionimage.h=667;


menu->pos.posjouer.x=270;
menu->pos.posjouer.y=160;

menu->pos.posparametre.x=270;
menu->pos.posparametre.y=300;

menu->pos.posquitter.x=270;
menu->pos.posquitter.y=440;


menu->pos.poslogo.x=352;
menu->pos.poslogo.y=80;
}


void affichermenu(Menu menu,SDL_Surface *screen)
{
   int i=0;
   int ta2=0;
   int tp2=0;

while(i!=10)
{

ta2 = SDL_GetTicks();


        if (ta2 - tp2 >= 250)
        {   i++;

          SDL_BlitSurface(menu.img.L[i],NULL,screen,&menu.pos.positionimage);
           SDL_Flip(screen);
            tp2 = ta2;

        }
}
SDL_BlitSurface(menu.img.image,NULL,screen,&menu.pos.positionimage);
SDL_BlitSurface(menu.img.volume[0],NULL,screen,&menu.pos.posvolume[0]);
SDL_BlitSurface(menu.img.volume[1],NULL,screen,&menu.pos.posvolume[1]);
SDL_BlitSurface(menu.img.volume[2],NULL,screen,&menu.pos.posvolume[2]);
SDL_BlitSurface(menu.img.resolution[0],NULL,screen,&menu.pos.posresolution[0]);
SDL_BlitSurface(menu.img.resolution[1],NULL,screen,&menu.pos.posresolution[1]);
SDL_BlitSurface(menu.img.logo,NULL,screen,&menu.pos.poslogo);
SDL_BlitSurface(menu.img.jouer[1],NULL,screen,&menu.pos.posjouer);
SDL_BlitSurface(menu.img.parametre[1],NULL,screen,&menu.pos.posparametre);
SDL_BlitSurface(menu.img.quitter[0],NULL,screen,&menu.pos.posquitter);
SDL_Flip(screen);


}

void getInput(Menu menu)
{
  int done1=1;
  int cont=0;
  SDL_Event event;
  Mix_Chunk *music;
  Mix_Chunk *music1;
  int i1 = 128;
  SDL_Surface *screen;
  Input input;
initialiserinput(&input);
Mix_VolumeChunk(music1,i1);


if (SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				cont=0;
				break;
                       case SDL_KEYDOWN:
                               switch (event.key.keysym.sym)
				{
                                      case SDLK_ESCAPE:
						menu.input.echap = 1;
                                                cont =1;
						Mix_PlayChannel(-1,music1,0);
					break;

					case SDLK_DOWN:
						menu.input.down=1;
                                                cont=1;
					break;

					case SDLK_UP:
						menu.input.up=1;
                                                cont=1;
					break;

					case SDLK_RIGHT:
						menu.input.right=1;
                                                cont=1;
					break;

					case SDLK_LEFT:
						menu.input.left=1;
                                                cont=1;
					break;
                                        case SDLK_KP_ENTER:
						menu.input.enter =1;
						Mix_PlayChannel(-1,music,0);
					break;

					case SDLK_SPACE:
						menu.input.space =1;
						Mix_PlayChannel(-1,music,0);
					break;
                                   }
				case SDL_KEYUP:
				switch (event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							menu.input.echap= 1;
						break;

						case SDLK_DOWN:
							menu.input.down=1;
						break;

						case SDLK_UP:
							  menu.input.up=1;
						break;

						case SDLK_RIGHT:
							menu.input.right=1;
						break;

						case SDLK_LEFT:
							menu.input.left=1;
						break;

						case SDLK_KP_ENTER:
							menu.input.enter =1;

						break;

						case SDLK_SPACE:
							menu.input.space =1;

						break;
					}
                          case SDL_MOUSEBUTTONDOWN :
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<900&&event.button.x>600)&&(event.button.y<133&&event.button.y>125))
menu.pos.posvolume[0].x=event.button.x;
if(((menu.pos.posvolume[0].x-600)/2)>22)
i1=((menu.pos.posvolume[0].x-600)/2)-22;
if(((menu.pos.posvolume[0].x-600)/2)<=22)
i1=-(((menu.pos.posvolume[0].x-600)/2)-22);
break;


                                 }
                           }
}


void freemenu(Menu *menu)
{
 SDL_Surface *screen;
  int i,j,n,k,m,q;

SDL_FreeSurface(menu->img.logo);

   for (i=0;i<3;i++)
   {
	 SDL_FreeSurface(menu->img.jouer[i]);  
   }
   
   for (j=0;j<2;j++)
   {
	   SDL_FreeSurface(menu->img.parametre[j]);
   }
   
   for (n=0; n<2;n++)
   {
	 SDL_FreeSurface(menu->img.quitter[n]);
   }

   for (k=0; k<10;k++)
   {
         SDL_FreeSurface(menu->img.L[k]);
   }

    for (m=0; m<3;m++)
   {
         SDL_FreeSurface(menu->img.volume[m]);
   }

    for (q=0; q<2;q++)
   {
         SDL_FreeSurface(menu->img.resolution[q]);
   }




   SDL_FreeSurface(screen);

}
