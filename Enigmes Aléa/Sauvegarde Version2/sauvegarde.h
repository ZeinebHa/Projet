#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Enigmes.h"

typedef struct save
{
        Enigme e;
	int enigmeresolu;
}sauvegarde;

void enregistrersauvegarde(sauvegarde Save);
void recuperersauvegarde(sauvegarde Save);
