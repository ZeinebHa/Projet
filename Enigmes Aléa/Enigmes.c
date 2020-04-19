#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enigme.h"
#include "time.h"
void initialiser_enigme(Enigme *E)
{
		
	E->Img=NULL;
	E->temps= 0000
	E->resolu =0;
	E->R_True = "";
	E->question = "";
	E->re1 = "";
	E->re2 = "";
	E->Questions.x= 0;
	E->Questions.y= 0;
	E->Question= NULL;
}

void generer_Question( Enigme E, char nomFich[])
{
     // enregistrement des Questions
    FILE *fichier=NULL;

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

srand(time(NULL));

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


//police//
    Font=TTF_OpenFont("angelina.ttf", 50);

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
    Font=TTF_OpenFont("angelina.ttf", 50);

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
  (E.resolu)++;
   printf("Bravo et bonne continuation \n");
  return 1;
}
else
{
  (E.resolu =0);
   scorevie = scorevie -1;
   printf(" reponse fausse! Veuillez réessaiyez encore une fois \n");
return 0;
}

if (scorevie ==0)
{
  printf(" GAME OVER ! ");
}  


}	
