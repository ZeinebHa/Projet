#include "map.h"

void loadMap(char *name)
{
	int x, y;
	FILE *fp;

	fp = fopen(name, "rb");


	if (fp == NULL)
	{
		printf("Failed to open map %s\n", name);
		exit(1);
	}

	
	map.maxX = map.maxY = 0;

	for (y=0;y<MAX_MAP_Y;y++)
	{
		for (x=0;x<MAX_MAP_X;x++)
		{
			
			fscanf(fp, "%d", &map.tile[y][x]);

	
			if (map.tile[y][x] > 0)
			{
				if (x > map.maxX)
				{
					map.maxX = x;
				}

				if (y > map.maxY)
				{
					map.maxY = y;
				}
			}
		}
	}

	
	
	map.maxX = (map.maxX + 1) * TILE_SIZE;
	map.maxY = (map.maxY + 1) * TILE_SIZE;

	
	map.startX = map.startY = 0;

	
	fclose(fp);

}




void drawMap(void)
{
	int x, y, mapX, x1, x2, mapY, y1, y2, xsource, ysource, a;


	mapX = map.startX / TILE_SIZE;


	x1 = (map.startX % TILE_SIZE) * -1;

	
	x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);

   
	mapY = map.startY / TILE_SIZE;
	y1 = (map.startY % TILE_SIZE) * -1;
	y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);


   
    if(map.mapTimer <= 0)
    {
        if(map.tileSetNumber == 0)
        {
            map.tileSetNumber = 1;
            map.mapTimer = TIME_BETWEEN_2_FRAMES*3;
        }
        else
        {
            map.tileSetNumber = 0;
            map.mapTimer = TIME_BETWEEN_2_FRAMES*3;
        }

    }
    else
        map.mapTimer--;




	for (y = y1; y < y2; y += TILE_SIZE)
	{
		
		mapX = map.startX / TILE_SIZE;

        
        de x = 0 à x = 640 */
		for (x = x1; x < x2; x += TILE_SIZE)
		{
		    
		    if (map.tile[mapY][mapX] != 0)
            {
               
                if (map.tile[mapY][mapX] == 10)
                {
                  
                    initializeMonster(mapX * TILE_SIZE, mapY * TILE_SIZE);
                 
                    map.tile[mapY][mapX] = 0;
                }
            }

           
            a = map.tile[mapY][mapX];

            
            ysource = a / 10 * TILE_SIZE;
           
            xsource = a % 10 * TILE_SIZE;

           
            if(map.tileSetNumber == 0)
                drawTile(map.tileSet, x, y, xsource, ysource);
            else
                drawTile(map.tileSetB, x, y, xsource, ysource);

            mapX++;
		}

		mapY++;
	}
}


void changeLevel(void)
{

    char file[200];

	
    sprintf(file, "map/map%d.txt", jeu.level );
    loadMap(file);

  
    if(map.tileSet != NULL)
    {
        SDL_FreeSurface(map.tileSet);
    }
    if(map.tileSetB != NULL)
    {
        SDL_FreeSurface(map.tileSetB);
    }
    sprintf(file, "graphics/tileset%d.png", jeu.level );
    map.tileSet = loadImage(file);
    sprintf(file, "graphics/tileset%dB.png", jeu.level );
    map.tileSetB = loadImage(file);

}



void mapCollision(GameObject *entity)
{

	int i, x1, x2, y1, y2;


	entity->onGround = 0;



	if(entity->h > TILE_SIZE)
		i = TILE_SIZE;
    else
		i = entity->h;

   
	for (;;)
	{
		
		x1 = (entity->x + entity->dirX) / TILE_SIZE;
		x2 = (entity->x + entity->dirX + entity->w - 1) / TILE_SIZE;

       
		y1 = (entity->y) / TILE_SIZE;
		y2 = (entity->y + i - 1) / TILE_SIZE;

       
		if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
		{
		
			if (entity->dirX > 0)
			{

              
				if (map.tile[y1][x2] == 5)
				{
				    
				    getItem();

				   
				    map.tile[y1][x2] = 0;
				}
				else if(map.tile[y2][x2] == 5)
				{
				   
				    getItem();
				    
				    map.tile[y2][x2] = 0;
				}

			
				if (map.tile[y1][x2] > BLANK_TILE || map.tile[y2][x2] > BLANK_TILE)
				{
					
					entity->x = x2 * TILE_SIZE;
					entity->x -= entity->w + 1;
					entity->dirX = 0;

				}

			}

            
			else if (entity->dirX < 0)
			{

				
				if (map.tile[y1][x1] == 5)
				{
				    
				    getItem();

				   
				    map.tile[y1][x1] = 0;
				}
				else if(map.tile[y2][x1] == 5)
				{
				    
				    getItem();
				  
				    map.tile[y2][x1] = 0;
				}


				if (map.tile[y1][x1] > BLANK_TILE || map.tile[y2][x1] > BLANK_TILE)
				{
					entity->x = (x1 + 1) * TILE_SIZE;
					entity->dirX = 0;
				}

			}

		}

	
		if (i == entity->h)
		{
			break;
		}

	
		i += TILE_SIZE;

		if (i > entity->h)
		{
			i = entity->h;
		}
	}

	
    if(entity->w > TILE_SIZE)
		i = TILE_SIZE;
    else
		i = entity->w;


	for (;;)
	{
		x1 = (entity->x) / TILE_SIZE;
		x2 = (entity->x + i) / TILE_SIZE;

		y1 = (entity->y + entity->dirY) / TILE_SIZE;
		y2 = (entity->y + entity->dirY + entity->h) / TILE_SIZE;

		if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
		{
			if (entity->dirY > 0)
			{

				

			
				if (map.tile[y2][x1] == 5)
				{
				    getItem();

				  
				    map.tile[y2][x1] = 0;
				}
				else if(map.tile[y2][x2] == 5)
				{
				   
				    getItem();
				   
				    map.tile[y2][x2] = 0;
				}


			
				if ((map.tile[y2][x1] == 7 ) || (map.tile[y2][x2] == 7 ))
				{
					entity->dirY = -20;
					
					entity->onGround = 1;
					playSoundFx(BUMPER);
				}


				else if (map.tile[y2][x1] > BLANK_TILE || map.tile[y2][x2] > BLANK_TILE)
				{
                   
					entity->y = y2 * TILE_SIZE;
					entity->y -= entity->h;
					entity->dirY = 0;
					entity->onGround = 1;
				}

			}

			else if (entity->dirY < 0)
			{

				/* Déplacement vers le haut */

				
				if (map.tile[y1][x1] == 5)
				{
				    
				    getItem();

				   
				    map.tile[y1][x1] = 0;
				}
				else if(map.tile[y1][x2] == 5)
				{
				   
				    getItem();
				  
				    map.tile[y1][x2] = 0;
				}


				if (map.tile[y1][x1] > BLANK_TILE || map.tile[y1][x2] > BLANK_TILE)
				{
					entity->y = (y1 + 1) * TILE_SIZE;
					entity->dirY = 0;
				}

            }
		}

       
		if (i == entity->w)
		{
			break;
		}

		i += TILE_SIZE;

		if (i > entity->w)
		{
			i = entity->w;
		}
	}

	
	entity->x += entity->dirX;
	entity->y += entity->dirY;

   
	if (entity->x < 0)
	{
		entity->x = 0;
	}

	else if (entity->x + entity->w >= map.maxX)
	{
	    
	    jeu.level++;
	   
		if(jeu.level > LEVEL_MAX)
		{
		    jeu.level = LEVEL_MAX;
		    entity->x = map.maxX - entity->w - 1;
		}
	
		else
		{
		    changeLevel();
		    initializePlayer();
		}

	}

   
	if (entity->y > map.maxY)
	{
		entity->timerMort = 60;
	}
}


void monsterCollisionToMap(GameObject *entity)
{

	int i, x1, x2, y1, y2;

	entity->onGround = 0;

	if(entity->h > TILE_SIZE)
		i = TILE_SIZE;
    else
		i = entity->h;

	for (;;)
	{
		x1 = (entity->x + entity->dirX) / TILE_SIZE;
		x2 = (entity->x + entity->dirX + entity->w - 1) / TILE_SIZE;

		y1 = (entity->y) / TILE_SIZE;
		y2 = (entity->y + i - 1) / TILE_SIZE;

		if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
		{
			
			if (entity->dirX > 0)
			{
			
				if (map.tile[y1][x2] > BLANK_TILE || map.tile[y2][x2] > BLANK_TILE)
				{
					entity->x = x2 * TILE_SIZE;
					entity->x -= entity->w + 1;
					entity->dirX = 0;

				}

			}

            
			else if (entity->dirX < 0)
			{

				if (map.tile[y1][x1] > BLANK_TILE || map.tile[y2][x1] > BLANK_TILE)
				{
					entity->x = (x1 + 1) * TILE_SIZE;
					entity->dirX = 0;
				}

			}

		}

	
		if (i == entity->h)
		{
			break;
		}

	
		i += TILE_SIZE;

		if (i > entity->h)
		{
			i = entity->h;
		}
	}

	
    if(entity->w > TILE_SIZE)
		i = TILE_SIZE;
    else
		i = entity->w;


	for (;;)
	{
		x1 = (entity->x) / TILE_SIZE;
		x2 = (entity->x + i) / TILE_SIZE;

		y1 = (entity->y + entity->dirY) / TILE_SIZE;
		y2 = (entity->y + entity->dirY + entity->h) / TILE_SIZE;

		if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
		{
			if (entity->dirY > 0)
			{

			

				if (map.tile[y2][x1] > BLANK_TILE || map.tile[y2][x2] > BLANK_TILE)
				{
					entity->y = y2 * TILE_SIZE;
					entity->y -= entity->h;
					entity->dirY = 0;
					entity->onGround = 1;
				}

			}

			else if (entity->dirY < 0)
			{

			

				if (map.tile[y1][x1] > BLANK_TILE || map.tile[y1][x2] > BLANK_TILE)
				{
					entity->y = (y1 + 1) * TILE_SIZE;
					entity->dirY = 0;
				}

            }
		}

        
		if (i == entity->w)
		{
			break;
		}

		i += TILE_SIZE;

		if (i > entity->w)
		{
			i = entity->w;
		}
	}


	entity->x += entity->dirX;
	entity->y += entity->dirY;

  
	if (entity->x < 0)
	{
		entity->x = 0;
	}

	else if (entity->x + entity->w >= map.maxX)
	{
	    entity->x = map.maxX - entity->w - 1;
	}

   
	if (entity->y > map.maxY)
	{
		entity->timerMort = 60;
	}
}


