#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "Menu.h"

void musique (Mix_Music *music)
{
	if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
		printf("%s",Mix_GetError());
	}
	music=Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(music,-1);
}

void init_menu(menu *m,SDL_Surface *ecran)
{
	SDL_Color couleurNoire = {0, 0, 0};

	//******Background
	m->back[0] = IMG_Load("back.jpg") ;
	m->back[1] = IMG_Load("back2.png") ;
	m->back[2] = IMG_Load("back3.png") ;
	m->back[3] = IMG_Load("back4.png") ;
	m->back[4] = IMG_Load("back5.png") ;
	m->back[5] = IMG_Load("intro.png") ;
	m->back[6] = IMG_Load("intro2.png") ;
		
	m->posback.x= (ecran->w) - (m->back[0]->w) ; 
	m->posback.y= (ecran->h) - (m->back[0]->h);

	//*****texte : dans credits
	m->txt.couleur=couleurNoire;
	m->txt.police = TTF_OpenFont("Dealer Strikes.ttf", 20);
	m->txt.texte = TTF_RenderText_Blended(m->txt.police, "ALL RIGHTS RESERVED.", m->txt.couleur);
	m->txt.postxt.x= (ecran->w/2)-(m->txt.texte->w*2.35);
	m->txt.postxt.y=(ecran->h/1.02) - (m->txt.texte->h*0.75);
	
//Tab Bouton
	
	//******Bouton Play
	m->boutons[0]= IMG_Load("Play.png") ;
	m->posboutons[0].x=(ecran->w/2)-(m->boutons[0]->w*1.75); 
	m->posboutons[0].y=(ecran->h/2)-(m->boutons[0]->h);


	//******Bouton Settings
	m->boutons[1] = IMG_Load("SETTINGS1.png") ;
	m->posboutons[1].x=(ecran->w/2)-(m->boutons[1]->w*1.75); 
	m->posboutons[1].y=(ecran->h/1.75)-(m->boutons[1]->h/4);
	

	//*******Bouton Credits
	m->boutons[2] = IMG_Load("Credits.png") ;
	m->posboutons[2].x=(ecran->w/2)-(m->boutons[2]->w*1.75); 
	m->posboutons[2].y=(ecran->h/1.27)-(m->boutons[2]->h/1.3); 

	//******Bouton Exit
	m->boutons[3]=IMG_Load("Exit.png") ;
	m->posboutons[3].x=(ecran->w/2)+(m->boutons[3]->w*0.85);
	m->posboutons[3].y=(ecran->h/1.27)-(m->boutons[3]->h/1.3);

	//***** Titre & design
	m->boutons[4]=IMG_Load("Title.png") ;// nom du jeu
	m->posboutons[4].x=(ecran->w/2)-(m->boutons[4]->w/1.65); 
	m->posboutons[4].y=(ecran->h/1.2)-(m->boutons[4]->h/0.5);
 
	m->boutons[5]=IMG_Load("Zombie.png") ;//ennemie
	m->posboutons[5].x=(ecran->w/3)*2.2;
	m->posboutons[5].y=(ecran->h/2.5)-(m->boutons[5]->h);
	
//Tab Option
	
	//******Option Fullscreen
	m->options[0]=IMG_Load("fullscreen.png") ;*
	m->posoptions[0].x=(ecran->w/2)-(m->options[0]->w*1.75); 
	m->posoptions[0].y=(ecran->h/2)-(m->options[0]->h*2.5);
	
	//***** Options Son
	m->options[1]=IMG_Load("audiofull.png") ; //augmentation son
	m->posoptions[1].x=(ecran->w/2)-(m->options[1]->w*2.4);  
	m->posoptions[1].y=(ecran->h/2)-(m->options[1]->h/1.35);   

	m->options[6]=IMG_Load("audioMute.png") ;// diminuation son
	m->posoptions[6].x=(ecran->w/2)-(m->options[6]->w*2.4); 
	m->posoptions[6].y=(ecran->h/2)-(m->options[6]->h/1.35);
	 
	//***** Options Barres son
	m->options[2]= SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 50, 32, 0, 0, 0, 0);//Barre Noire
	SDL_FillRect(m->options[2], NULL, SDL_MapRGB(m->options[2]->format, 0, 0, 0));
	m->posoptions[2].x=(ecran->w/2)-(m->options[2]->w*0.328);
	m->posoptions[2].y=(ecran->h/2)-(m->options[2]->h*0.8);

	m->posoptions[7].x= 410 ; //Barre Rouge //Si je mets les memes coordonnees que barre noire -->bug
	m->posoptions[7].y= 260 ; 

	//****** Option Retour
	m->options[3]=IMG_Load("Return.png") ;
	m->posoptions[3].x = (ecran->w/3)*2.4;
	m->posoptions[3].y = (ecran->h/4)-(m->options[3]->h*2);

	//***** Options GUI 
	m->options[4]=IMG_Load("SettingText.png") ;// menu settings
	m->posoptions[4].x=(ecran->w) - (m->options[4]->w) ; 
	m->posoptions[4].y=(ecran->h) - (m->options[4]->h) ;

	m->options[9]=IMG_Load("Credits.png") ;//Credits 
	m->posoptions[9].x=(ecran->w) - (m->options[9]->w) ; 
	m->posoptions[9].y=(ecran->h) - (m->options[9]->h) ;

	m->options[10]=IMG_Load("ExitText.png") ;//Text exit
	m->posoptions[10].x=(ecran->w) - (m->options[10]->w) ; 
	m->posoptions[10].y=(ecran->h) - (m->options[10]->h) ;
	
	//****** Option Exit : Yes NO
	m->options[11]=IMG_Load("Yes.png");//bouton yes
	m->posoptions[11].x=250;
	m->posoptions[11].y=240;

	m->options[12]=IMG_Load("No.png");//bouton non
	m->posoptions[12].x=250;
	m->posoptions[12].y=370;
	
//Tab Play
	
	// Play
	m->play[0]=IMG_Load("Backplay.png");
	m->posplay[0].x=(ecran->w)-(m->play[0]->w);
	m->posplay[0].y=(ecran->h)-(m->play[0]->h);

	m->play[5]=IMG_Load("playMenu.png");
	m->posplay[5].x=(ecran->w)-(m->play[5]->w);
	m->posplay[5].y=(ecran->h)-(m->play[5]->h);

	m->play[1]=IMG_Load("Solo.png");
	m->posplay[1].x=400;
	m->posplay[1].y=200;

	m->play[2]=IMG_Load("Multiplayer.png");
	m->posplay[2].x=400;
	m->posplay[2].y=355;

	m->play[3]=IMG_Load("PP.png"); // bouton new game
	m->posplay[3].x=240;
	m->posplay[3].y=280;

	m->play[4]=IMG_Load("Load Game.png");
	m->posplay[4].x=530;
	m->posplay[4].y=280;

	m->play[6]=IMG_Load("icone.png");
	m->posplay[6].x=890;
	m->posplay[6].y=5;
	
	

	//*********PAUSE: resume restart settings exit 

	m->play[7]=IMG_Load("PauseMenu.png");
	m->pospause[0].x=0;
	m->pospause[0].y=0;

	m->play[8]=IMG_Load("Resume.png");
	m->pospause[1].x=383; 
	m->pospause[1].y=153;
	
	m->play[9]=IMG_Load("Restart.png");
	m->pospause[2].x=383; 
	m->pospause[2].y=253;
	
	m->pospause[3].x=383; //settings
	m->pospause[3].y=353;

	m->pospause[4].x=383; //exit
	m->pospause[4].y=453;

	m->play[10]=IMG_Load("SaveMenu.png");
	m->pospause[9].x=0;
	m->pospause[9].y=0;	

	m->pospause[10].x=240;//yes (save)
	m->pospause[10].y=330;
	
	m->pospause[11].x=530;//(don't save)
	m->pospause[11].y=330;
	

	//*****Autres
	m->intro=1;
	m->choix_boutons=-1;
	m->choix_options=-1;
	m->grand=-1;
	m->mode=-1;

	for (int j=0;j<4;j++)
		m->choix_mode[j]=-1;
	
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

	//****souris
	inp->s.left=-1;
	inp->s.right=-1;
	inp->s.middle=-1;
	inp->s.posclick.x=-1;
	inp->s.posclick.y=-1;
	inp->s.motion.x=-1;
	inp->s.motion.y=-1;
}

menu afficher_intro(menu m,SDL_Surface *ecran)
{
	SDL_BlitSurface(m.back[5],NULL,ecran,&m.posback);
	SDL_Flip(ecran);
	SDL_Delay(500);
	SDL_BlitSurface(m.back[6],NULL,ecran,&m.posback);
	SDL_Flip(ecran);
	SDL_Delay(1500);
	m.intro=0;

	return m; 
}

void afficher_menu(menu m,SDL_Surface *ecran)
{
	
	SDL_BlitSurface(m.back[0],NULL,ecran,&m.posback) ;
	SDL_BlitSurface(m.boutons[4],NULL,ecran,&m.posboutons[4]);
	SDL_BlitSurface(m.boutons[9],NULL,ecran,&m.posboutons[9]);
	for (int i=0; i<4;i++)
	{
		SDL_BlitSurface(m.boutons[i],NULL,ecran,&m.posboutons[i]) ;
		if (m.grand==i)
			SDL_BlitSurface(m.boutons[i+5],NULL,ecran,&m.posboutons[i+5]) ;
	} 
}

void afficher_play1(menu m,SDL_Surface *ecran)
{
	SDL_BlitSurface(m.back[0],NULL,ecran,&m.posback);
	SDL_BlitSurface(m.play[5],NULL,ecran,&m.posplay[5]);//GUI
	SDL_BlitSurface(m.options[3],NULL,ecran,&m.posoptions[3]);//Return
	
	SDL_BlitSurface(m.play[1],NULL,ecran,&m.posplay[1]);//Solo
	SDL_BlitSurface(m.play[2],NULL,ecran,&m.posplay[2]);//multi
	if (m.grand==8)
		SDL_BlitSurface(m.play[6],NULL,ecran,&m.posplay[6]);//Solo big
	else if (m.grand==9)
		SDL_BlitSurface(m.play[7],NULL,ecran,&m.posplay[7]);//multi big
	else if (m.grand==4)//retour
		SDL_BlitSurface(m.options[8],NULL,ecran,&m.posoptions[8]);	
}

void afficher_play2(menu m,SDL_Surface *ecran)
{
	SDL_BlitSurface(m.back[0],NULL,ecran,&m.posback);
	SDL_BlitSurface(m.play[18],NULL,ecran,&m.posplay[5]);//
	SDL_BlitSurface(m.options[3],NULL,ecran,&m.posoptions[3]);//Return

	SDL_BlitSurface(m.play[3],NULL,ecran,&m.posplay[3]);//New Game
	SDL_BlitSurface(m.play[4],NULL,ecran,&m.posplay[4]);//Load Game
	
}

void afficher_play(menu m,SDL_Surface *ecran)
{
	SDL_BlitSurface(m.play[0],NULL,ecran,&m.posplay[0]);//map level 1
	SDL_BlitSurface(m.play[10],NULL,ecran,&m.posplay[10]);//icone
	
}

void afficher_pause(menu m,SDL_Surface *ecran)
{
	SDL_BlitSurface(m.play[0],NULL,ecran,&m.posplay[0]);//play menu
	SDL_BlitSurface(m.play[12],NULL,ecran,&m.pospause[0]);//pause menu	
	SDL_BlitSurface(m.play[13],NULL,ecran,&m.pospause[1]);//Resume
	SDL_BlitSurface(m.play[14],NULL,ecran,&m.pospause[2]);//Restart
	SDL_BlitSurface(m.boutons[1],NULL,ecran,&m.pospause[3]);//Settings
	SDL_BlitSurface(m.boutons[3],NULL,ecran,&m.pospause[4]);//Exit

}

void afficher_save(menu m,SDL_Surface *ecran)
{
	SDL_BlitSurface(m.play[17],NULL,ecran,&m.pospause[9]);//Save menu
	SDL_BlitSurface(m.options[11],NULL,ecran,&m.pospause[10]);//YES
	SDL_BlitSurface(m.options[12],NULL,ecran,&m.pospause[11]);//NO
}

void afficher_settings(menu m,SDL_Surface *ecran,int *volume,int barrougeX,int *full)
{
	int longbarRouge=0,aux;

	if (m.mode==-1)
	{
		SDL_BlitSurface(m.back[0],NULL,ecran,&m.posback);
		SDL_BlitSurface(m.options[3],NULL,ecran,&m.posoptions[3]);//Retour
		if (m.grand==4)//retour
			SDL_BlitSurface(m.options[8],NULL,ecran,&m.posoptions[8]);
	}

	SDL_BlitSurface(m.options[4],NULL,ecran,&m.posoptions[4]);//Settings menu
	SDL_BlitSurface(m.options[0],NULL,ecran,&m.posoptions[0]);//Fullscreen
	SDL_BlitSurface(m.options[2],NULL,ecran,&m.posoptions[2]);//Barre son
	SDL_BlitSurface(m.boutons[3],NULL,ecran,&m.posboutons[3]);//Exit
	
	longbarRouge=((200*(*volume))/128)+410 ;
	m.options[7] = SDL_CreateRGBSurface(SDL_HWSURFACE, longbarRouge-410, 50, 32, 0, 0, 0, 0);
	SDL_FillRect(m.options[7], NULL, SDL_MapRGB(m.options[7]->format, 255, 0, 0));
	SDL_BlitSurface(m.options[7],NULL,ecran,&m.posoptions[7]);
	
	//*****Reglage son
	aux=*volume;
	if (m.choix_options==7) 
	{
		m.options[7]=SDL_CreateRGBSurface(SDL_HWSURFACE, barrougeX-410, 50, 32, 0, 0, 0, 0);
		SDL_FillRect(m.options[7], NULL, SDL_MapRGB(m.options[7]->format, 255, 0, 0));
		SDL_BlitSurface(m.options[7],NULL,ecran,&m.posoptions[7]) ;
	 	*volume=(int)((barrougeX-410)*128)/200 ; 
	 	Mix_VolumeMusic(*volume) ;
		aux=(*volume);
		 	
	}else if (m.choix_options==6)
	{
		if ((*volume) !=0)//mute
		{
			(*volume)=0 ; 
			Mix_VolumeMusic(*volume) ;				
		}else if ((*volume)==0)//play
		{
			(*volume)=aux ; 
			Mix_VolumeMusic(*volume) ; 
		}
	}
	if ((*volume)==0)  
		SDL_BlitSurface(m.options[1],NULL,ecran,&m.posoptions[1]);//Mute
	
	else
		SDL_BlitSurface(m.options[6],NULL,ecran,&m.posoptions[6]);//Full 
	
	
	if (m.choix_options==5)//Gestion mode plein ecran
		fullscreen(ecran,&(*full));
}

void fullscreen(SDL_Surface *ecran,int *full)
{
	if (*full==0)
	{
		ecran = SDL_SetVideoMode(950,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN) ;	
	      	*full=1 ;
	} else 
	{
	 	ecran = SDL_SetVideoMode(950,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF ) ;	
		*full=0 ;
	}
}

void afficher_credits(menu m,SDL_Surface *ecran)
{
	SDL_BlitSurface(m.back[0],NULL,ecran,&m.posback);
	SDL_BlitSurface(m.options[9],NULL,ecran,&m.posoptions[9]);//Credits 
	SDL_BlitSurface(m.options[3],NULL,ecran,&m.posoptions[3]);//Retour
	SDL_BlitSurface(m.boutons[3],NULL,ecran,&m.posboutons[3]);//Exit
	SDL_BlitSurface(m.txt.texte,NULL,ecran,&m.txt.postxt);
		
}

void afficher_exit(menu m,SDL_Surface *ecran)
{
	SDL_BlitSurface(m.back[0],NULL,ecran,&m.posback);
	SDL_BlitSurface(m.options[10],NULL,ecran,&m.posoptions[10]);//Exit text 

	SDL_BlitSurface(m.options[11],NULL,ecran,&m.posoptions[11]);// bouton yes
	SDL_BlitSurface(m.options[12],NULL,ecran,&m.posoptions[12]);// bouton non

}

void get_input_menu(input *inp,menu m,int *continuer,Mix_Chunk *sound, int *barrougeX)
{
	SDL_Event event; 
	if(SDL_PollEvent(&event))
	{  
		switch(event.type)
		{
			case SDL_QUIT:
				*continuer=0;
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE://echap
						if ((m.choix_boutons!=-1)&&(m.choix_boutons!=3))
						{
							inp->c.echap=1;
							Mix_PlayChannel(-1,sound,0);
						}
						break;
					case SDLK_DOWN:
						inp->c.bas=1;
						break;
					case SDLK_UP:
						inp->c.haut=1;
						break;
					case SDLK_RIGHT:
						inp->c.droite=1;
						break;
					case SDLK_LEFT:
						inp->c.gauche=1;
						break;
					case SDLK_RETURN://entrer
						inp->c.entrer=1;
						Mix_PlayChannel(-1,sound,0);//click
						break;
					case SDLK_p://play
						if (m.choix_boutons==-1)
						{
							inp->c.p=1;
							Mix_PlayChannel(-1,sound,0);//click	
						}
						break; 
					case SDLK_s://settings
						if (m.choix_boutons==-1)
						{
							inp->c.s=1;
							Mix_PlayChannel(-1,sound,0);//click
						}
						break;
					case SDLK_c://credits
						if (m.choix_boutons==-1)
						{
							inp->c.c=1;
							Mix_PlayChannel(-1,sound,0);//click
						}
						break;
					case SDLK_n://NO
						if ((m.choix_boutons==3)||((m.choix_boutons==0)&&(m.mode==5)))
						{
							inp->c.n=1;
							Mix_PlayChannel(-1,sound,0);//click
						}
						break;
					case SDLK_y://YES
						if ((m.choix_boutons=3)||((m.choix_boutons==0)&&(m.mode==5)))
						{
							inp->c.y=1;
							Mix_PlayChannel(-1,sound,0);//click
						}
						break;
					case SDLK_SPACE://espace
						if ((m.choix_boutons==0)&&(m.mode==3))
						{
							inp->c.espace=1;
							Mix_PlayChannel(-1,sound,0);//click
						}	
						break;
				}
				break;	
			case SDL_KEYUP:
				switch (event.key.keysym.sym)
					{
						case SDLK_ESCAPE:				
							inp->c.echap=-1;
							break;
						case SDLK_DOWN:
							inp->c.bas=-1;
							break;
						case SDLK_UP:
							inp->c.haut=-1;
							break;
						case SDLK_RIGHT:
							inp->c.droite=-1;
							break;
						case SDLK_LEFT:
							inp->c.gauche=-1;
							break;
						case SDLK_RETURN://entrer
							inp->c.entrer=-1;
							break;
						case SDLK_p://play
							inp->c.p=-1;
							break; 
						case SDLK_s://settings
							inp->c.s=-1;
							break;
						case SDLK_c://credits
							inp->c.c=-1;
							break;
						case SDLK_n://NO
							inp->c.n=-1;
							break;
						case SDLK_y://YES
							inp->c.y=-1;
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
				{	//*******Gestion bruit du click + eviter d'ouvrir settings a partir de credits (par exemple)
					if ((m.choix_boutons==-1)&&((m.grand>=0)&&(m.grand<=3)))//Menu
					{
						inp->s.posclick.x=event.button.x;
						inp->s.posclick.y=event.button.y;
						Mix_PlayChannel(-1,sound,0);//click
					}else if (m.choix_boutons==0)//Play
					{
						if ((m.mode==1))//solo/multi
						{
							inp->s.posclick.x=event.button.x;
							inp->s.posclick.y=event.button.y;
							Mix_PlayChannel(-1,sound,0);//click
						}else if ((m.mode==2))//New Game/Load
						{
							inp->s.posclick.x=event.button.x;
							inp->s.posclick.y=event.button.y;
							Mix_PlayChannel(-1,sound,0);//click
						}else if (m.mode==3)//icone pour afficher menu pause
						{
							inp->s.posclick.x=event.button.x;
							inp->s.posclick.y=event.button.y;
							Mix_PlayChannel(-1,sound,0);//click
						}else if ((m.mode==4))//menu pause
						{
							inp->s.posclick.x=event.button.x;
							inp->s.posclick.y=event.button.y;
							Mix_PlayChannel(-1,sound,0);//click
						}else if (m.mode==5)//sauvegarde
						{
							inp->s.posclick.x=event.button.x;
							inp->s.posclick.y=event.button.y;
							Mix_PlayChannel(-1,sound,0);//click
						}
					}else if (m.choix_boutons==1)//Settings
					{
						inp->s.posclick.x=event.button.x;
						inp->s.posclick.y=event.button.y;
						Mix_PlayChannel(-1,sound,0);//click
					}else if (m.choix_boutons==2)//Credits
					{
						inp->s.posclick.x=event.button.x;
						inp->s.posclick.y=event.button.y;
						Mix_PlayChannel(-1,sound,0);//click
					}else if (m.choix_boutons==3)//Exit
					{
						inp->s.posclick.x=event.button.x;
						inp->s.posclick.y=event.button.y;
						Mix_PlayChannel(-1,sound,0);//click
					}
					//*******Gestion barre son
					if (m.choix_boutons==1)
					{
						*barrougeX =inp->s.posclick.x;
						printf ("Niveau son = %d \n",*barrougeX-411) ; 
					}
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

	
menu choix_menu(menu m,input inp)
{
		//******** Choisir la case avec la souris et les lettres p s c
	if ((inp.c.p==1)||((inp.s.posclick.x>=m.posboutons[0].x)&&(inp.s.posclick.x<=m.posboutons[0].x+180)&&(inp.s.posclick.y>=m.posboutons[0].y)&&(inp.s.posclick.y<=m.posboutons[0].y+70)))
		m.choix_boutons=0;//play
	else if ((inp.c.s==1)||((inp.s.posclick.x>=m.posboutons[1].x)&&(inp.s.posclick.x<=m.posboutons[1].x+180)&&(inp.s.posclick.y>=m.posboutons[1].y)&&(inp.s.posclick.y<=m.posboutons[1].y+70)))
		m.choix_boutons=1;//settings
	else if ((inp.c.c==1)||((inp.s.posclick.x>=m.posboutons[2].x)&&(inp.s.posclick.x<=m.posboutons[2].x+180)&&(inp.s.posclick.y>=m.posboutons[2].y)&&(inp.s.posclick.y<=m.posboutons[2].y+70)))
		m.choix_boutons=2;//credits
	else if ((inp.s.posclick.x>=m.posboutons[3].x)&&(inp.s.posclick.x<=m.posboutons[3].x+180)&&(inp.s.posclick.y>=m.posboutons[3].y)&&(inp.s.posclick.y<=m.posboutons[3].y+70))
		m.choix_boutons=3;//exit

		//****** Choisir la case avec les fleches du clavier
	if (inp.c.entrer==1)
	{
		if (m.grand==0)
			m.choix_boutons=0;//play
		else if(m.grand==1)
			m.choix_boutons=1;//settings
		else if (m.grand==2)
			m.choix_boutons=2;//credits
		else if (m.grand==3)
			m.choix_boutons=3;//exit
	}
	return m;
}

menu choix_settings(menu m,input inp)
{
		//******** Choisir la case avec la souris et echap
	if ((inp.s.posclick.x>=m.posoptions[0].x)&&(inp.s.posclick.x<=m.posoptions[0].x+60)&&(inp.s.posclick.y>=m.posoptions[0].y)&&(inp.s.posclick.y<=m.posoptions[0].y+60))
		m.choix_options=5;//fullscreen
	else if ((inp.s.posclick.x>=m.posoptions[1].x)&&(inp.s.posclick.x<=m.posoptions[1].x+60)&&(inp.s.posclick.y>=m.posoptions[1].y)&&(inp.s.posclick.y<=m.posoptions[1].y+60))
		m.choix_options=6;//audiomute
	else if ((m.choix_mode[2]==-1)&&(((inp.s.posclick.x>=m.posoptions[3].x)&&(inp.s.posclick.x<=m.posoptions[3].x+180)&&(inp.s.posclick.y>=m.posoptions[3].y)&&(inp.s.posclick.y<=m.posoptions[3].y+70))||(inp.c.echap==1)))
		m.choix_options=3;//return
	else if ((inp.s.posclick.x>=m.posoptions[2].x)&&(inp.s.posclick.x<=m.posoptions[2].x+200)&&(inp.s.posclick.y>=m.posoptions[2].y)&&(inp.s.posclick.y<=m.posoptions[2].y+50))
		m.choix_options=7;//barre son
	else if (((inp.s.posclick.x>=m.posboutons[3].x)&&(inp.s.posclick.x<=m.posboutons[3].x+180)&&(inp.s.posclick.y>=m.posboutons[3].y)&&(inp.s.posclick.y<=m.posboutons[3].y+70))||((inp.c.echap==1)&&(m.choix_mode[2]==3)))
		m.choix_boutons=3;//exit

		//******* Choisir la case avec les fleches du clavier 
	if (inp.c.entrer==1)
	{
		if (m.grand==3)
			m.choix_boutons=3;//exit
		else if (m.grand==4)
			m.choix_options=3;//return
	}
		//******* Traitement
	if (m.choix_mode[2]==3)
	{
		if (m.choix_boutons==3)
		{
			m.choix_mode[2]=-1;
			m.choix_boutons=0;
			m.mode=4;
			m.grand=-1;
		}
	}else if ((m.choix_mode[2]==-1)&&(m.choix_options==3))
		m.choix_boutons=-1;//retour au menu principal

	return m;
}

menu choix_credits(menu m,input inp)
{
		//******** Choisir la case avec la souris et echap
	if (((inp.s.posclick.x>=m.posoptions[3].x)&&(inp.s.posclick.x<=m.posoptions[3].x+180)&&(inp.s.posclick.y>=m.posoptions[3].y)&&(inp.s.posclick.y<=m.posoptions[3].y+70))||(inp.c.echap==1))
		m.choix_options=3;//return
	else if ((inp.s.posclick.x>=m.posboutons[3].x)&&(inp.s.posclick.x<=m.posboutons[3].x+180)&&(inp.s.posclick.y>=m.posboutons[3].y)&&(inp.s.posclick.y<=m.posboutons[3].y+70))
		m.choix_boutons=3;//exit
	
		//******** Choisir la case avec les fleches du clavier 
	if (inp.c.entrer==1)
	{
		if (m.grand==3)
			m.choix_boutons=3;//exit
		else if (m.grand==4)
			m.choix_options=3;//return
	}
		//******** Traitement 
	if (m.choix_options==3)
		m.choix_boutons=-1;
	return m;
}

menu choix_exit(menu m,input inp,int *continuer)
{
		//******** Choisir la case avec la souris et les lettres y n
	if ((inp.c.y==1)||((inp.s.posclick.x>=m.posoptions[11].x)&&(inp.s.posclick.x<=m.posoptions[11].x+180)&&(inp.s.posclick.y>=m.posoptions[11].y)&&(inp.s.posclick.y<=m.posoptions[11].y+70)))
		m.choix_options=4;//YES
	else if ((inp.c.n==1)||((inp.s.posclick.x>=m.posoptions[12].x)&&(inp.s.posclick.x<=m.posoptions[12].x+180)&&(inp.s.posclick.y>=m.posoptions[12].y)&&(inp.s.posclick.y<=m.posoptions[12].y+70)))
		m.choix_options=5;//NO

		//******** Choisir la case avec les fleches du clavier
	if (inp.c.entrer==1)
	{
		if (m.grand==12)
			m.choix_options=4;//yes
		else if (m.grand==13)
			m.choix_options=5;//no
	}
		//******* Traitement 
	if (m.choix_options==4)
		*continuer=0;//fermer le jeu
	else if (m.choix_options==5)
		m.choix_boutons=-1;//revenir au menu principal
	return m;
}

menu choix_play1(menu m,input inp)
{	
		//******** Choisir la case avec la souris et echap
	if ((inp.s.posclick.x>=m.posplay[1].x)&&(inp.s.posclick.x<=m.posplay[1].x+180)&&(inp.s.posclick.y>=m.posplay[1].y)&&(inp.s.posclick.y<=m.posplay[1].y+70))
		m.choix_mode[0]=1;//Solo
	else if ((inp.s.posclick.x>=m.posplay[2].x)&&(inp.s.posclick.x<=m.posplay[2].x+180)&&(inp.s.posclick.y>=m.posplay[2].y)&&(inp.s.posclick.y<=m.posplay[2].y+70))
		m.choix_mode[0]=2;//Multi
	else if (((inp.s.posclick.x>=m.posoptions[3].x)&&(inp.s.posclick.x<=m.posoptions[3].x+180)&&(inp.s.posclick.y>=m.posoptions[3].y)&&(inp.s.posclick.y<=m.posoptions[3].y+70))||(inp.c.echap==1))
		m.choix_mode[0]=3;//retour
	
		
		//******* Traitement 
	if (m.choix_mode[0]==1)
		m.mode=2;//nouvelle partie ou charger une partie
	else if (m.choix_mode[0]==2)
		m.mode=3;//commencer la partie directement
	else if (m.choix_mode[0]==3)
	{
		for (int i=0;i<4;i++)
			m.choix_mode[i]=-1;
		m.choix_boutons=-1;//revenir au menu principal
	}
	return m;
}

menu choix_play2(menu m,input inp)
{
		//******** Choisir la case avec la souris et echap
	if ((inp.s.posclick.x>=m.posplay[3].x)&&(inp.s.posclick.x<=m.posplay[3].x+180)&&(inp.s.posclick.y>=m.posplay[3].y)&&(inp.s.posclick.y<=m.posplay[3].y+70))
		m.choix_mode[1]=1;//New game
	else if ((inp.s.posclick.x>=m.posplay[4].x)&&(inp.s.posclick.x<=m.posplay[4].x+180)&&(inp.s.posclick.y>=m.posplay[4].y)&&(inp.s.posclick.y<=m.posplay[4].y+70))
		m.choix_mode[1]=2;//Load game
	else if (((inp.s.posclick.x>=m.posoptions[3].x)&&(inp.s.posclick.x<=m.posoptions[3].x+180)&&(inp.s.posclick.y>=m.posoptions[3].y)&&(inp.s.posclick.y<=m.posoptions[3].y+70))||(inp.c.echap==1))
		m.choix_mode[1]=3;//retour

		//******** Traitement 
	if (m.choix_mode[1]==1)
		m.mode=3;
	else if (m.choix_mode[1]==2)
	{
		//appeler la fonction de recuperation
		m.mode=3;
	}else if (m.choix_mode[1]==3)
	{
		m.mode=1;//revenir en arriere: play1: solo ou multi
		for (int i=0;i<4;i++)
			m.choix_mode[i]=-1;
	}

	return m;
}

menu choix_pause (menu m,input inp)
{
		//******** Choisir la case avec la souris
	if ((inp.s.posclick.x>=m.pospause[1].x)&&(inp.s.posclick.x<=m.pospause[1].x+180)&&(inp.s.posclick.y>=m.pospause[1].y)&&(inp.s.posclick.y<=m.pospause[1].y+70))
		m.choix_mode[2]=1;//Resume
	else if ((inp.s.posclick.x>=m.pospause[2].x)&&(inp.s.posclick.x<=m.pospause[2].x+180)&&(inp.s.posclick.y>=m.pospause[2].y)&&(inp.s.posclick.y<=m.pospause[2].y+70))
		m.choix_mode[2]=2;//Restart
	else if ((inp.s.posclick.x>=m.pospause[3].x)&&(inp.s.posclick.x<=m.pospause[3].x+180)&&(inp.s.posclick.y>=m.pospause[3].y)&&(inp.s.posclick.y<=m.pospause[3].y+70))
		m.choix_mode[2]=3;//settings
	else if ((inp.s.posclick.x>=m.pospause[4].x)&&(inp.s.posclick.x<=m.pospause[4].x+180)&&(inp.s.posclick.y>=m.pospause[4].y)&&(inp.s.posclick.y<=m.pospause[4].y+70))
		m.choix_mode[2]=4;//Exit

		//******** Traitement 
	if (m.choix_mode[2]==1)//resume
	{
		//faire appel a la fonction de recuperation ?
		m.mode=3;
		m.choix_mode[2]=-1;
	}else if (m.choix_mode[2]==2)//restart
	{
		//reinitialiser toutes les variables perso ennemi enigme....
		m.mode=3;
		m.choix_mode[2]=-1;
	}else if (m.choix_mode[2]==3)//settings
		m.choix_boutons=1;
	else if (m.choix_mode[2]==4)
	{
		m.mode=5;//menu de sauvegarde
		m.choix_mode[2]=-1;
	}

	return m;
}

menu choix_sauvegarde(menu m, input inp)
{
		//******** Choisir la case avec la souris et les lettres y n 
	if ((inp.c.y==1)||((inp.s.posclick.x>=m.pospause[10].x)&&(inp.s.posclick.x<=m.pospause[10].x+180)&&(inp.s.posclick.y>=m.pospause[10].y)&&(inp.s.posclick.y<=m.pospause[10].y+70)))
		m.choix_mode[3]=1;//SAVE (yes)
	else if ((inp.c.y==1)||((inp.s.posclick.x>=m.pospause[11].x)&&(inp.s.posclick.x<=m.pospause[11].x+180)&&(inp.s.posclick.y>=m.pospause[11].y)&&(inp.s.posclick.y<=m.pospause[11].y+70)))
		m.choix_mode[3]=2;//DONT SAVE (no)

		//******* Traitement
	if (m.choix_mode[3]==1)
	{
		//faire appel a la fonction de sauvegarde
		m.choix_boutons=-1;//retour au menu principal
		m.mode=-1;
		for (int i=0;i<4;i++)	
			m.choix_mode[i]=-1;
	}else if (m.choix_mode[3]==2)
	{
		m.choix_boutons=-1;//retour au menu principal
		m.mode=-1;
		for (int i=0;i<4;i++)	
			m.choix_mode[i]=-1;
	}

	return m;
}

void update_menu(menu *m,input *inp,int *continuer)
{

	if (m->choix_boutons==-1)
		*m=choix_menu(*m,*inp);
	else if (m->choix_boutons==1)
		*m=choix_settings(*m,*inp);
	else if (m->choix_boutons==2)
		*m=choix_credits(*m,*inp);
	else if (m->choix_boutons==3)
		*m=choix_exit(*m,*inp,&(*continuer));
	else if (m->choix_boutons==0)
	{
		if (m->mode==-1)
		{
			for (int i=0;i<4;i++)
				m->choix_mode[i]=-1;
			m->mode=1;
		}else if (m->mode==1)
			*m=choix_play1(*m,*inp);
		else if (m->mode==2)
			*m=choix_play2(*m,*inp);
		else if ((m->mode==3)&&((inp->c.espace==1)||((inp->s.posclick.x>=m->posplay[10].x)&&(inp->s.posclick.x<=m->posplay[10].x+55)&&(inp->s.posclick.y>=m->posplay[10].y)&&(inp->s.posclick.y<=m->posplay[10].y+55))))
			m->mode=4;//menu icone
		else if (m->mode==4)
			*m=choix_pause(*m,*inp);
		else if (m->mode==5)
			*m=choix_sauvegarde(*m,*inp);
	}	
		
	inp->s.motion.x=-1;//Pour pouvoir switcher entre clavier et souris sans pb
	inp->s.motion.y=-1;
	inp->s.posclick.x=-1;
	inp->s.posclick.y=-1;
	inp->c.droite=-1; 
	inp->c.gauche=-1;
	inp->c.entrer=-1;
	inp->c.haut=-1;
	inp->c.bas=-1;
	inp->c.echap=-1;
	inp->c.entrer=-1;
}

void liberer_menu(menu *m)
{	
	for (int k=0;k<15;k++)
		SDL_FreeSurface(m->options[k]);

	for(int i=0;i<7;i++)
		SDL_FreeSurface(m->back[i]);
	
	for (int j=0;j<10;j++)
		SDL_FreeSurface(m->boutons[j]);
	
	for (int h=1;h<19;h++)
		SDL_FreeSurface(m->play[h]);	

	SDL_FreeSurface(m->txt.texte);
	TTF_CloseFont(m->txt.police);
}

