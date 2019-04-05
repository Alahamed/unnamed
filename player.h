#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"



typedef struct player 1
{
SDL_Rect scrn;
SDL_Rect Sprite;
SDL_Surface* image;
int nb_images;
int timerMort ;


};

typedef struct player 2
{
SDL_Rect scrn;
SDL_Rect Sprite;
SDL_Surface* image;
int nb_images;

int timerMort ;

};


void initialiser(player * p);
void afficher(SDL_Surface* fenetre,player p);
void liberer_hero(player * p);
