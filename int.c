#include "init.h"


void init(char *title)
{
	
	if (SDL_Init(SDL_INIT_VIDEO ) < 0)
	{
		printf("Could not initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	jeu.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);

    if (jeu.screen == NULL)
        {
            printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
            exit(1);
        }

	
	SDL_WM_SetCaption(title, NULL);


	
	SDL_ShowCursor(SDL_DISABLE);


	
	if (TTF_Init() < 0)
	{
		printf("Couldn't initialize SDL TTF: %s\n", SDL_GetError());

		exit(1);
	}

	
	font = loadFont("font/GenBasB.ttf", 32);


	

    int flags=MIX_INIT_MP3;
    int initted=Mix_Init(flags);
    if((initted & flags) != flags)
    {
        printf("Mix_Init: Failed to init SDL_Mixer\n");
        printf("Mix_Init: %s\n", Mix_GetError());
        exit(1);
    }

	
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024)==-1)
    {
        printf("Mix_OpenAudio: %s\n", Mix_GetError());
        exit(1);
    }

    
    Mix_AllocateChannels(32);

}


void loadGame(void)
{

    
    map.background = loadImage("graphics/background.png");

    
    jeu.level = 1;
    changeLevel();

  
     map.mapTimer = TIME_BETWEEN_2_FRAMES * 3;
     map.tileSetNumber = 0;

   
    jeu.vies = 3;
    jeu.etoiles = 0;

   
    jeu.HUD_vie = loadImage("graphics/life.png");
    jeu.HUD_etoiles = loadImage("graphics/stars.png");

   
    loadSong("music/RabidjaGo.mp3");

   
    loadSound();

    
    jeu.onMenu = 1;
    jeu.menuType = START;

}



void cleanup()
{

    int i;

    
	if (map.background != NULL)
	{
		SDL_FreeSurface(map.background);
	}


    
    if (map.tileSet != NULL)
    {
        SDL_FreeSurface(map.tileSet);
    }
    if (map.tileSetB != NULL)
    {
        SDL_FreeSurface(map.tileSetB);
    }


	
	if (player.sprite != NULL)
	{
		SDL_FreeSurface(player.sprite);
	}

	
	for(i = 0 ; i < MONSTRES_MAX ; i++)
    {
        if (monster[i].sprite != NULL)
        {
            SDL_FreeSurface(monster[i].sprite);
        }
    }

	
	if (jeu.HUD_etoiles != NULL)
	{
		SDL_FreeSurface(jeu.HUD_etoiles);
	}
	if (jeu.HUD_vie != NULL)
	{
		SDL_FreeSurface(jeu.HUD_vie);
	}

	
    if ( jeu.musique != NULL )
        Mix_FreeMusic(jeu.musique);

    
    freeSound();

	
    Mix_CloseAudio();
    Mix_Quit();

	
	closeFont(font);

	
	TTF_Quit();

	
	SDL_Quit();

}