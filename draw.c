#include "draw.h"



 void drawImage(SDL_Surface *image, int x, int y)
{
	SDL_Rect dest;

	
	dest.x = x;
	dest.y = y;
	dest.w = image->w;
	dest.h = image->h;


	SDL_BlitSurface(image, NULL, jeu.screen, &dest);
}


void drawTile(SDL_Surface *image, int destx, int desty, int srcx, int srcy)
{
   
	SDL_Rect dest;

	dest.x = destx;
	dest.y = desty;
	dest.w = TILE_SIZE;
	dest.h = TILE_SIZE;

	
	SDL_Rect src;

	src.x = srcx;
	src.y = srcy;
	src.w = TILE_SIZE;
	src.h = TILE_SIZE;

	
	SDL_BlitSurface(image, &src, jeu.screen, &dest);
}


void draw(void)
{

    int i;

    
    drawImage(map.background, 0, 0);


    drawMap();

   
    drawAnimatedEntity(&player);

   
    for(i = 0 ; i < jeu.nombreMonstres ; i++)
    {
        drawAnimatedEntity(&monster[i]);
    }

    
    drawHud();

  
    SDL_Flip(jeu.screen);

  
    SDL_Delay(1);

}



SDL_Surface *loadImage(char *name)
{
	
	SDL_Surface *temp = IMG_Load(name);
	SDL_Surface *image;

	if (temp == NULL)
	{
		printf("Failed to load image %s\n", name);
		return NULL;
	}

	
	SDL_SetColorKey(temp, (SDL_SRCCOLORKEY|SDL_RLEACCEL), SDL_MapRGB(temp->format, TRANS_R, TRANS_G, TRANS_B));


	
	image = SDL_DisplayFormat(temp);

	SDL_FreeSurface(temp);

	if (image == NULL)
	{
		printf("Failed to convert image %s to native format\n", name);

		return NULL;
	}

	
	return image;

}



void delay(unsigned int frameLimit)
{

    
    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}


void drawHud(void)
{
    
    char text[200];

   
    drawImage(jeu.HUD_vie, 480, 410);
   
    sprintf(text, "%d", jeu.vies);
 
    drawString(text, 560, 420, font);

   
    drawImage(jeu.HUD_etoiles, 60, 60);
    sprintf(text, "%d", jeu.etoiles);
    drawString(text, 100, 57, font);

}
