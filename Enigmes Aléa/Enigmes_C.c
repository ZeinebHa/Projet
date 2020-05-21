#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Enigmes.h"
#include "time.h"

void initialiser_enigme(Enigme *E)
{
	int i,j,k,l;
	
	
	E->temps= 0000
	E->resolu =0;
	
	// initialiser les chaines ou les champs question , reponsvraie ainsi que les 2 alternatives a des chaines vides
	for (i=0;i<20;i++)
	{
	E->question[i] = "";
	}
	
	for (j=0;j<10;j++)
	{
		E->R_True[j] = "";
	}
	
	for (k=0;k<10;k++)
	{
		E->re1 [k]= "";
	        
	}
	
	for (l=0;l<10;l++)
	{
		E->re2[k]= "";
	}
	
	E->Questions.x= 0;
	E->Questions.y= 0;
	E->Question= NULL;
	
	//initialiser boutons de l'enigme
	
	E->Bouton[0]=IMG_Load("Question 1.jpg");
	E->Bouton[1]=IMG_Load("Reponse.jpg");
	E->Bouton[2]=IMG_Load("Reponse.jpg");
	E->Bouton[3]=IMG_Load("Reponse.jpg");
	E->Bouton[4]=IMG_Load("vrai.jpg");
	E->Bouton[5]=IMG_Load("faux.jpg");
	
	//initialiser pos Bouton
	
	E->posbouton[0].x=181; 
	E->posbouton[0].y=95; 
	E->posbouton[1].x=130; 
	E->posbouton[1].y=395; 
	E->posbouton[2].x=385; 
	E->posbouton[2].y=395; 
	E->posbouton[3].x=640; 
	E->posbouton[3].y=395; 
	E->posbouton[4].x=650; 
	E->posbouton[4].y=100;
	E->posbouton[5].x=650; 
	E->posbouton[5].y=100;
}

void init_input(input *inp)
{
	//*****clavier
	
	inp->c.droite=-1;
	inp->c.gauche=-1;
	inp->c.echap=-1;
	inp->c.entrer=-1;
	inp->c.a=-1;
	inp->c.b=-1;
	
	//****souris
	inp->s.click=-1;
	inp->s.motion=-1;
}
void generer_Question( Enigme E, char nomFich[])
{
     // enregistrement des Questions
    
     char chaine[100];
     int ligneActu=1,
     char QuestActu[0];
     int ligneVoulu = (rand() % 4) ;

    Initialiser_Enigme(&E);

    E.fichierQ=fopen(nomFich,"w");
    if(E.fichierQ==NULL)
        printf("impossible d'ouvrir le fichier \n");
    else
    {

        fprintf(fichier,"1)Quelle est le quotient et le reste de la division euclidienne de: (X²)²+5X(X²)+12(X²)+19X−7 par X²+3X−1 ?\n");
        fprintf(fichier,"2)Qui a découvert la célèbre formule E = mc² ?\n");
        fprintf(fichier,"3) Quel physicien a démontré grâce à un pendule, la rotation de la Terre sur elle-même autour de l'axe des pôles géographiques qui relie le pôle nord au pôle sud ?\n");

    }

    fclose(E.fichierQ);

   //Generation Aleatoire de la question

srand(E.time(NULL));

E.fichierQ= fopen(nomFich, "r");
        if (E.fichierQ == NULL)
            printf("impossible d'ouvrir le ficier \n");

        else
        {
            while(!EOF || ligneActu==ligneVoulu );

            {
                QuestActu=fgetc(E.fichierQ);
                if (strcmp(QuestActu,'\n')==0)
                    ligneActu++;
            }
            fgets ( chaine,100,E.fichierQ);//on range le mot de la ligne voulu dans chaine
        }
        fclose(E.fichierQ);
//printf("%s",chaine);
        E.question = chaine;

}

/**---------------------Blitter la question sur une nouvelle interface afin de la blitter sur la photo finale (SDL_ttf)---------------------*/

void afficher_Question(Enigme E, SDL_Surface *ecran,char nomFich[]) 
{
   TTF_Font* Font=NULL;
   SDL_Surface *nouv=NULL;
   SDL_Event event;
   int done=1;

generer_Question(E,nomFich);

/* Initialisation de SDL_ttf */


    if(TTF_Init() < 0 )
    {
        printf("Impossible d'initialiser SDL_ttf : %s", SDL_GetError());

    }

   else
   {
//police//
    Font=TTF_OpenFont("Dealer Strikes Straight.ttf", 25);

    if(Font==NULL)
    {
        printf("Erreur de creation de la police : %s", TTF_GetError());

    }

    /* Couleur du texte (noir) */
    SDL_Color TextColor= {(0,0,0)};

//coller le texte sur le background//

    nouv=TTF_RenderText_Solid(Font, question, TextColor);

    /* Si la surface est nulle, il y a eu une erreur */
    if(!nouv)
    {
        printf("Erreur de rendu du texte : %s", TTF_GetError());
        return 1;
    }

//blitter sur un rectan ensuite background//

    E.Question.x = 0;
    E.Question.y = 0;
    E.Question.w = nouv->w;
    E.Question.h = nouv->h;



    
    while(done)
    {

        SDL_BlitSurface(nouv, NULL,ecran, &E.Question);
        SDL_Flip(ecran);
    }

    SDL_FreeSurface(ecran);
    SDL_FreeSurface(nouv);
    TTF_CloseFont(Font);
}

}
void generer_Reponse(char *reponse1, *reponse2,*reponse3)
{
   
   
   int i;
 //  char Reponse1[3],char Reponse2[3], char Reponse3[3];

  Enigme E;

  /*********************************Generer les Reponses à la première Question *********************/
   E.fichierRep=fopen(reponse1,"w")
    {
    if(E.fichierRep==NULL)
        printf("impossible d'ouvrir le fichier \n");
    else
    {
               fprintf(E.fichierRep,"a) Le quotient est X²+2X+7, le reste est nul \n");
               fprintf(E.fichierRep,"b) Le quotient est X²−3X−5, le reste est X+3 \n");
               fprintf(E.fichierRep,"c) Le quotient est X²−7X−5, le reste est X+5 \n");
    }
        // Reponse1 = "a"; // reponse vraie
         
    fclose(E.fichierRep);
    }

/*********************************Generer les Reponses à la 2eme Question *********************/
    E.fichierRep=fopen(reponse2,"w")
       {
            if(E.fichierRep==NULL)
                 printf("impossible d'ouvrir le fichier \n");
            else
            {
               fprintf(E.fichierRep,"a) Isaac Newton \n");
               fprintf(E.fichierRep,"b) Albert Einstein \n");
               fprintf(E.fichierRep,"c) Copernic \n");
            }
        // Reponse2 = "b"; // reponse vraie
     fclose(E.fichierRep);
      }
/*********************************Generer les Reponses à la 3eme Question *********************/

E.fichierRep=fopen(reponse3,"w")
       {
            if(E.fichierRep==NULL)
                 printf("impossible d'ouvrir le fichier \n");
            else
            {
               fprintf(E.fichierRep,"a) Foucault \n");
               fprintf(E.fichierRep,"b) Kepler \n");
               fprintf(E.fichierRep,"c) Copernic \n");
            }
         // Reponse3 = "a"; // reponse vraie
     fclose(E.fichierRep);
      }
}
/*********************************Stockage des réponses vraies dans le tableau *********************/

char ReponseVrai( char  TabRep_vrai[3])    
	{
for (i=0;i<3;i++)
{
    TabRep_vrai[0]= "a";
    TabRep_vrai[1]= "b";
    TabRep_vrai[2]= "a";
}

return(TabRep_vrai[i]);
}

void afficher_Reponses(Enigme E)
{
    TTF_Font* Font=NULL;
    char Tab[4];

afficher_Question( E,ecran,nomFich);

E.R_True= ReponseVrai(Tab[]);

do
{
   printf("Erreur code \n");
}while((E.re1 == ReponseVrai(Tab[])) || (E.re2 == ReponseVrai(Tab[])) ||(E.re1== E.re2));

/* Initialisation de SDL_ttf */

    if(TTF_Init() < 0 )
    {
        printf("Impossible d'initialiser SDL_ttf : %s", SDL_GetError());

    }

//police//
    Font=TTF_OpenFont("Dealer Strikes Straight.ttf", 25);

    if(Font==NULL)
    {
        printf("Erreur de creation de la police : %s", TTF_GetError());
    }

    /* Couleur du texte (rouge) */
    SDL_Color TextColor= {(255,255,255)};

//coller le texte sur le background//

    E->ReponseT=TTF_RenderText_Solid(Font,E.R_True, TextColor); // blitter la repo juste sur le rectangle 1
    E->Reponse1=TTF_RenderText_Solid(Font,E.re1, TextColor); // blitter la reponse incorrecte sur le rectan 2
    E->Reponse2=TTF_RenderText_Solid(Font,E.re2, TextColor); // blitter la repo incorrect 2 sur le rectan 3

/* Si la surface est nulle, il y a eu une erreur */
    if(!(E->ReponseT))
    {
        printf("Erreur de rendu du texte : %s", TTF_GetError());
    }
    if(!(E->Reponse1))
    {
        printf("Erreur de rendu du texte : %s", TTF_GetError());
    }
    if(!(E->Reponse2))
    {
        printf("Erreur de rendu du texte : %s", TTF_GetError());

//blitter sur un rectan ensuite backgroung//

    Reponse0T.x = 300;
    Reponse0T.y = 450;
    Reponse0T.w = (*(E->ReponseT))->w;
    Reponse0T.h = (*(E->ReponseT))->h;

    Reponse01.x = 500;
    Reponse01.y = 650;
    Reponse01.w = (*(E->Reponse1))->w;
    Reponse01.h = (*(E->Reponse1))->h;


    Reponse02.x = 600;
    Reponse02.y = 850;
    Reponse02.w = (*(E->Reponse2))->w;
    Reponse02.h = (*(E->Reponse2))->h;



    int done=1;
    while(done)
    {

        SDL_BlitSurface(E->ReponseT, NULL, ecran, &Reponse0T);
        SDL_BlitSurface(E->Reponse1, NULL, ecran, &Reponse01);
        SDL_BlitSurface(E->Reponse2, NULL, ecran, &Reponse02);

        SDL_Flip(ecran);


    }

    SDL_FreeSurface(ecran);

    SDL_FreeSurface(E->ReponseT);

    TTF_CloseFont(Font);

}

int solution_enigme(Enigme E)
{
int  scorevie=3;
char Tab[3],reponse[3];
afficher_Question(E,ecran, nomFich);
afficher_Reponses(E);
reponse= ReponseVrai(Tab[3]);

if (strcmp(R_True,reponse)==0)
{
  SDL_BlitSurface(&E->bouton[4],NULL,ecran,&enig->posbouton[4]);
  SDL_Flip(ecran);			
  (E.resolu)++;
  printf("Bravo et bonne continuation \n");
  return 1;
}
else
{
  (E.resolu =0);
   SDL_BlitSurface(&E->bouton[5],NULL,ecran,&E->posbouton[5]);
   SDL_Flip(ecran);
   scorevie = scorevie -1;
   printf(" reponse fausse! Veuillez réessaiyez encore une fois \n");
return 0;
}

if (scorevie ==0)
{
  printf(" GAME OVER ! ");
}  
}	

void EventBoutons_Enigme(SDL_Event event,Enigme E,input *inp)
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
						inp->c.droite=1;
						break; 
						
					case SDLK_LEFT:
						inp->c.gauche=1;
						break;
						
					case SDLK_RETURN:
						inp->c.entrer=1;
						break;
						
					case SDLK_a:
						inp->c.a=1;
						break; 
						
					case SDLK_b:
						inp->c.b=1;
						break;
					
				}
				break;
			
			case SDL_MOUSEMOTION:
			
				if ((event.motion.x>=E.posbouton[1].x)&&(event.motion.x<=E.posbouton[1].x+180)&&(event.motion.y>=E.posbouton[1].y)&&(event.motion.y<=E.posbouton[1].y+70))
				{
					inp->s.motion=1;//sur case reponse num 1
					//printf("sur la premiere case\n");
				}
			        else if ((event.motion.x>=E.posbouton[2].x)&&(event.motion.x<=E.posbouton[2].x+180)&&(event.motion.y>=E.posbouton[2].y)&&(event.motion.y<=E.posbouton[2].y+70))
				{					
					inp->s.motion=2;//sur case reponse num 2
					//printf("sur la deuxieme case\n");
				}
			        else if ((event.motion.x>=E.posbouton[3].x)&&(event.motion.x<=E.posbouton[3].x+180)&&(event.motion.y>=E.posbouton[3].y)&&(event.motion.y<=E.posbouton[3].y+70))
				{
					inp->s.motion=3;//sur case reponse num 3
					//printf("sur la troisieme case\n");
				}else 
					inp->s.motion=-1;
				break;

			case SDL_MOUSEBUTTONDOWN:
				inp->s.click=1;//click
				break;
		}
void liberer (Enigme *E)
{
	int i;
	
  	for (int i=0;i<5;i++)
	{
		SDL_FreeSurface(E->Bouton[i]);
	}		
	SDL_FreeSurface(ecran);
	free(E->fichierQ);
	free(E->fichierRep);

}
