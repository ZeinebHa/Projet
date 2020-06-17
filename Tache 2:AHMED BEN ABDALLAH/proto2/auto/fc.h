
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
/**
* @struct Perso
* @struct ennemi 
* @struct box
* @brief sturct for perso
* @brief sturct for ennemi
* @brief sturct for box
*
*/
struct perso
 { SDL_Surface *perso; /*!<Surface . */
  SDL_Rect posperso;
  int h;
  int w;
      
  }; 
typedef struct perso personnage;
struct Enemy
{
  SDL_Surface *en; /*!<Surface . */
  SDL_Rect posen;
  int direction;
  int distance;
  int position_initiale;
 };
typedef struct Enemy enemy;

struct boxx
 {
  SDL_Surface *box; /*!<Surface . */
  SDL_Rect posbox;
   
 };
typedef struct boxx box;
enemy deplacement_aleatoire(enemy enemyy);
enemy intialisation_enemy(enemy enemyy);
personnage initialisation_perso(personnage perso);
enemy initialisation_box(enemy nar);
void afficher (enemy enemy1,SDL_Surface *ecran);
void afficher_perso (personnage perso,enemy nar,SDL_Surface *ecran,int *d);
void afficher_nar (enemy nar,SDL_Surface *ecran);

int callenemy(personnage per, enemy en);
enemy automatisation (SDL_Rect pos, enemy en4,SDL_Rect *posfire,int *firee,int *direct);
