#include "player.h"


void initializePlayer(void)
{

    
    changeAnimation(&player, "graphics/walkright.png");

    
    player.direction = RIGHT;
    player.etat = IDLE;

    
    player.x = 0;
    player.y = 0;

    
    player.w = PLAYER_WIDTH;
    player.h = PLAYER_HEIGTH;

   
    player.timerMort = 0;
    player.onGround = 0;

   
    jeu.nombreMonstres = 0;

}



void updatePlayer(void)
{

   
  if (player.timerMort == 0)
  {

    
	player.dirX = 0;

    
	player.dirY += GRAVITY_SPEED;

    
	if (player.dirY >= MAX_FALL_SPEED)
	{
		player.dirY = MAX_FALL_SPEED;
	}

    
 	if (input.left == 1)
	{
		player.dirX -= PLAYER_SPEED;
		player.direction = LEFT;

		if(player.etat != WALK_LEFT && player.onGround == 1)
		{
		    player.etat = WALK_LEFT;
		    changeAnimation(&player, "graphics/walkleft.png");
		}
	}

	else if (input.right == 1)
	{
		player.dirX += PLAYER_SPEED;
		player.direction = RIGHT;

		if(player.etat != WALK_RIGHT && player.onGround == 1)
		{
		    player.etat = WALK_RIGHT;
		    changeAnimation(&player, "graphics/walkright.png");
		}
    }

   
    else if(input.right == 0 && input.left == 0 && player.onGround == 1)
    {
       

        if(player.etat != IDLE)
        {
            player.etat = IDLE;
            
            if(player.direction == LEFT)
            {
		        changeAnimation(&player, "graphics/IdleLeft.png");
            }
            else
            {
		        changeAnimation(&player, "graphics/IdleRight.png");
            }

        }

    }


    
    if (input.jump == 1)
    {
        if(player.onGround == 1)
        {
            player.dirY = -JUMP_HEIGHT;
            player.onGround = 0;
            player.jump = 1;
            playSoundFx(JUMP);
        }
        
        else if (player.jump == 1)
        {
            player.dirY = -JUMP_HEIGHT;
            player.jump = 0;
            playSoundFx(JUMP);
        }
        input.jump = 0;
    }

    if(input.enter == 1)
    {
        
        jeu.onMenu = 1;
        jeu.menuType = PAUSE;
        input.enter = 0;
    }

    
    if (player.onGround == 1)
		player.jump = 1;


	
	if(player.onGround == 0)
	{
	    if(player.direction == RIGHT && player.etat != JUMP_RIGHT)
        {
            player.etat = JUMP_RIGHT;
            changeAnimation(&player, "graphics/JumpRight.png");
        }
        else if(player.direction == LEFT && player.etat != JUMP_LEFT)
        {
            player.etat = JUMP_LEFT;
            changeAnimation(&player, "graphics/JumpLeft.png");
        }

    }


    
    mapCollision(&player);
    centerScrollingOnPlayer();

  }

    
    if (player.timerMort > 0)
	{
		player.timerMort--;

		if (player.timerMort == 0)
		{
			
			jeu.vies--;
			if(jeu.vies < 0)
			{
			    
                jeu.onMenu = 1;
                jeu.menuType = START;
			}
			initializePlayer();
			changeLevel();
		}
	}

}


void centerScrollingOnPlayer(void)
{
	
	map.startX = player.x - (SCREEN_WIDTH / 2);

	if (map.startX < 0)
	{
		map.startX = 0;
	}

	else if (map.startX + SCREEN_WIDTH >= map.maxX)
	{
		map.startX = map.maxX - SCREEN_WIDTH;
	}

	map.startY = player.y - (SCREEN_HEIGHT / 2);

	if (map.startY < 0)
	{
		map.startY = 0;
	}

	else if (map.startY + SCREEN_HEIGHT >= map.maxY)
	{
		map.startY = map.maxY - SCREEN_HEIGHT;
	}
}


void getItem(void)
{
  
	jeu.etoiles++;
	playSoundFx(STAR);

	
	if(jeu.etoiles >= 5)
	{
		jeu.etoiles = 0;
		jeu.vies++;
	}
}
