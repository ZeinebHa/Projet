#ifndef FONCTIONS_H_
#define FONCTIONS_H_

typedef struct save//toutes les structures+collision?
{
	personnage p; 
	zombie z;
  SDL_Surface *background;
	FILE *fichier;
}save; 

void update_save (save *s, personnage p,zombie z,SDL_Surface back);
void enregistrer (save s);
void recuperer (save *s);

#endif
