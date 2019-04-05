#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"
#include"collision.h"
#include"jeu.h"
#include"obstacle.h"
#include"player.h"



void initialiser(player *p)
{
    p->image= IMG_Load("perso.png");

h->Sprite.x=100;
h->Sprite.y=480;


 p->scrn.x =202;
   p->scrn.y = 0;
   p->scrn.w =95.72;
  p->scrn.h =115;

}

void afficher(SDL_Surface* fenetre,player p)
{


SDL_BlitSurface(p.image,& p->scrn,fenetre,&p.Sprite);
SDL_Flip(fenetre);

}


void liberer_player(player * p)
{


SDL_FreeSurface(p->image);




}







