#include "monster.h"


void initializeMonster(int x, int y)
{
 
    if (jeu.nombreMonstres < MONSTRES_MAX )
	{

        monster[jeu.nombreMonstres].sprite = loadImage("graphics/monster1.png");

    
        monster[jeu.nombreMonstres].frameNumber = 0;
        monster[jeu.nombreMonstres].frameTimer = TIME_BETWEEN_2_FRAMES;

        monster[jeu.nombreMonstres].direction = LEFT;

       
        monster[jeu.nombreMonstres].x = x;
        monster[jeu.nombreMonstres].y = y;

       
        monster[jeu.nombreMonstres].w = TILE_SIZE;
        monster[jeu.nombreMonstres].h = TILE_SIZE;

       
        monster[jeu.nombreMonstres].timerMort = 0;
        monster[jeu.nombreMonstres].onGround = 0;

        jeu.nombreMonstres++;

	}

}


void updateMonsters(void)
{

    int i;

 
    for ( i = 0; i < jeu.nombreMonstres; i++ )
    {
       
        if (monster[i].timerMort == 0)
        {

            monster[i].dirX = 0;
            monster[i].dirY += GRAVITY_SPEED;

            if (monster[i].dirY >= MAX_FALL_SPEED)
                monster[i].dirY = MAX_FALL_SPEED;

          
            if (monster[i].x == monster[i].saveX || checkFall(monster[i]) == 1 )
            {
                if (monster[i].direction == LEFT)
                {
                    monster[i].direction = RIGHT;
                    changeAnimation(&monster[i], "graphics/monster1right.png");
                }
                else
                {
                    monster[i].direction = LEFT;
                    changeAnimation(&monster[i], "graphics/monster1.png");
                }

            }

            
            if(monster[i].direction == LEFT)
                monster[i].dirX -= 2;
            else
                monster[i].dirX += 2;


           
            monster[i].saveX = monster[i].x;

           
            monsterCollisionToMap(&monster[i]);


            
            if (collide(&player, &monster[i]) == 1)
            {
                
                player.timerMort = 1;
                playSoundFx(DESTROY);
            }
            else if (collide(&player, &monster[i]) == 2)
            {
               
                monster[i].timerMort = 1;
                playSoundFx(DESTROY);
            }


          }

       
        if (monster[i].timerMort > 0)
        {
            monster[i].timerMort--;

          
            if (monster[i].timerMort == 0)
            {
                
                if (monster[i].sprite != NULL)
                {
                    SDL_FreeSurface(monster[i].sprite);
                }
                monster[i] = monster[jeu.nombreMonstres-1];
                jeu.nombreMonstres--;
            }
        }
    }

}



int collidebox(GameObject *player, GameObject *monster)
{
    //On teste pour voir s'il n'y a pas collision, si c'est le cas, on renvoie 0
    if ((player->x >= monster->x + monster->w)
    || (player->x + player->w <= monster->x)
    || (player->y >= monster->y + monster->h)
    || (player->y + player->h <= monster->y)
    )
        return 0;
   
    else if (player->y + player->h <= monster->y + 10)
    {
        player->dirY = -JUMP_HEIGHT;
        return 2;
    }
   
    else
        return 1;
}



int checkFall(GameObject monster)
{
    int x, y;

    

    
    if (monster.direction == LEFT)
    {
        
        x = (int)(monster.x + monster.dirX) / TILE_SIZE;
        y = (int)(monster.y + monster.h - 1) /  TILE_SIZE;
        if (y < 0)
            y = 1;
        if (y > MAX_MAP_Y)
            y = MAX_MAP_Y;
        if (x < 0)
            x = 1;
        if (x > MAX_MAP_X)
            x = MAX_MAP_X;

      
        if (map.tile[y + 1][x] < BLANK_TILE)
            return 1;

        else
            return 0;
    }
    else
    {
       
        x = (int)(monster.x + monster.w + monster.dirX) / TILE_SIZE;
        y = (int)(monster.y + monster.h - 1) / TILE_SIZE;
        if (y <= 0)
            y = 1;
        if (y >= MAX_MAP_Y)
            y = MAX_MAP_Y - 1;
        if (x <= 0)
            x = 1;
        if (x >= MAX_MAP_X)
            x = MAX_MAP_X - 1;

        if (map.tile[y + 1][x] < BLANK_TILE)
            return 1;

        else
            return 0;
    }
}









