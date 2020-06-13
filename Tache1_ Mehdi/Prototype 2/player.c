#include "player.h"
#include <math.h>
void initialiser_personnage(personnage *p)
{
  
  
  
   
    p->tab[0]=IMG_Load("1.png");
    p->tab[1]=IMG_Load("2.png");
    p->tab[2]=IMG_Load("3.png");
    p->tab[3]=IMG_Load("4.png");
    p->tab[4]=IMG_Load("5.png");
    p->tab[5]=IMG_Load("6.png");
    p->tab[6]=IMG_Load("7.png");
    p->tab[7]=IMG_Load("8.png");
    
  p->position.x=40;
  p->position.y=420;
}

void afficher_personnage(personnage p,SDL_Surface *screen,int i)
{
  SDL_BlitSurface(p.tab[i],NULL,screen,&p.position);

}

void freesurfaceperso(personnage *perso)
{
SDL_FreeSurface(perso->tab[0]);
SDL_FreeSurface(perso->tab[1]);
SDL_FreeSurface(perso->tab[2]);
SDL_FreeSurface(perso->tab[3]);
SDL_FreeSurface(perso->tab[4]);
SDL_FreeSurface(perso->tab[5]);
SDL_FreeSurface(perso->tab[6]);
SDL_FreeSurface(perso->tab[7]);
}

void jump(personnage *p,SDL_Surface* bg,SDL_Surface* screen,SDL_Surface* bg1,SDL_Rect pos)
{	
    SDL_Rect posMarioRel,posMarioAbs;
    posMarioRel.x = -50;
    posMarioRel.y = 0;
	int t=0;
	int i=0;
	Uint8 r,g,bl;

	int endjump=1;
      
           int x;
	   int y;
            posMarioAbs.x = p->position.x;
            posMarioAbs.y = p->position.y-(p->tab[1]->h);
	
		  
		while(endjump){
		
            posMarioRel.x++;

            if(posMarioRel.x>=100)
            {
                posMarioRel.x=-50;
            }

            //On met à "0" les pos abs:

            //On calcule la valeur relative de y:
            posMarioRel.y=(-0.04*(posMarioRel.x*posMarioRel.x)+50);

            //On calcule maintenant les valeurs abs
            p->position.x = posMarioAbs.x + posMarioRel.x+50;
            p->position.y = posMarioAbs.y - posMarioRel.y+29;
	 
		//printf("////////////////////////////////////////%d \n///////////////////////////////",h.poshero.y);

        //Intervalle de 10ms
        SDL_Delay(1);
	  // if(posMarioRel.x ==99)
	    // endjump=0;
		      //SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        // On dessine les images aux positions respectives
     
		SDL_BlitSurface(bg1,NULL,screen,&pos);
	x=p->position.y+73;
			
			SDL_GetRGB(GetPixel(screen,p->position.y,x),bg1->format,&r,&g,&bl);
			
			/*printf("\n xh :%d\n",p.position.x);
			printf("yh :%d\n",p.position.y);
			printf("yh+wh :%d\n",x);
			
			printf(" r=%d : g=%d : b=%d\n",r,g,bl );*/
			if(((r==255)&&(g==255)&&(bl==255))||((r==255)&&(g==255)&&(bl==255)))
				i++;
			
	    		 if((i>=2))
			{
			printf(" %d i",i);
			endjump=0;
p->position.y-=5;
			}
SDL_BlitSurface(bg,NULL,screen,&pos);
//SDL_BlitSurface(en1,NULL,screen,pos);
	/*if (camera.x==1000)
		{
		SDL_BlitSurface(en1,NULL,screen,pos);
		pos->x--;
		}*/
		

        SDL_BlitSurface(p->tab[1],NULL,screen, &p->position);
	
	

        // FIN DESSIN

        // Et on oublie pas de rafraichir l'image !
       SDL_Flip(screen);
	

	}



endjump=1;
        


}
Vecteur InitVecteur(int angle, int distance)
{
     Vecteur vecteur;
     int a,b;

     // il faut faire attention le résultat est en radian donc il faut le metre en degrés 
     vecteur.x = distance*cos(angle/180*3.14);
     vecteur.y = distance*sin(angle/180*3.14);
     return vecteur;
}
