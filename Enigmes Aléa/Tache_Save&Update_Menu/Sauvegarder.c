#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Sauvegarder.h"

void update_save (save *s, personnage pers, zombie zom, SDL_Surface *back)
{
	s->p=pers; 
	s->z=zom;
  s->background=back;
}

void enregistrer (save s)
{
	s.fichier=fopen("Sauvegarde","wb");
	if (s.fichier !=NULL)
	{
		fwrite(&s,sizeof(save),1,s.fichier);
		printf("Sauvegarde reussie ! \n");	
		fclose (s.fichier);
	}else 
		printf("Impossible d'ouvrir le fichier !\n");
}

void recuperer (save *s)
{
	s->fichier=fopen("Sauvegarde","rb");
	if (s->fichier !=NULL)
	{
		fread(&s,sizeof(save),1,s->fichier);
		printf("perso.x=%d, perso.y=%d\n", s->p.posperso.x, s->p.posperso.y);
		printf("zombie.x=%d, zombie.y=%d\n", s->e.poszombie.x, s->e.poszombie.y);
		//printf("camera.x=%d, camera.y=%d\n", s->poscamera.x, s->poscamera.y);
		printf("vies=%d, temps=%d, score=%d\n", s->p.vies, s->p.temps, s->p.score);	
		fclose (s->fichier);
	}else 
		printf("Impossible d'ouvrir le fichier !\n");
}
