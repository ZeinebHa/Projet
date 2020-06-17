#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "sauvegarde.h"
#include "Enigmes.h"
void enregistrersauvegarde(sauvegarde Save)
{
   FILE *fichier=NULL;

   char sauvegarde[20];

	fichier=fopen("sauvegarde","wb");
	if (fichier !=NULL)
	{
		fwrite(&Save,sizeof(sauvegarde),1,fichier);
		printf(" partie sauvegarde \n");
		fclose (fichier);
	}else 
		printf("Impossible d'ouvrir le fichier !\n");


}

void recuperersauvegarde(sauvegarde Save)
{
     char sauvegarde[20];
     FILE *fichier=NULL;

    fichier=fopen("sauvegarde","rb");
        if (fichier !=NULL)
        {
                fwrite(&Save,sizeof(sauvegarde),1,fichier);
                printf(" partie sauvegarde \n");
                fclose (fichier);
        }else 
                printf("Impossible d'ouvrir le fichier !\n");




}
