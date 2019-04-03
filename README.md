# unnamed
jeux : treasure
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include "souris.h"
void mouse(SDL_Event event,SDL_Rect* positionperso)
{
                positionperso->x = event.motion.x;
}


#ifndef SOURIS_H_INCLUDED
#define SOURIS_H_INCLUDED
void mouse(SDL_Event event,SDL_Rect* positionperso);
#endif
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include "clavier.h"
void boucle(SDL_Event event,SDL_Rect* positionperso)
{
                switch(event.key.keysym.sym)
                {
                    case SDLK_RIGHT: // Fl�che droite
                        positionperso->x++;
                        break;
                    case SDLK_LEFT: // Fl�che gauche
                        positionperso->x--;
                        break;
                }


}

#ifndef CLAVIER_H_INCLUDED
#define CLAVIER_H_INCLUDED
void boucle(SDL_Event event,SDL_Rect* positionperso);#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include "personnages_init.h"
void init_pers(SDL_Surface** img,SDL_Surface* ecran,char place[20],SDL_Rect pos)
{
    (*img) = IMG_Load(place);
    SDL_BlitSurface((*img), NULL, ecran, &pos);

}

#ifndef PERSONNAGES_H_INCLUDED
#define PERSONNAGES_H_INCLUDED
void init_pers(SDL_Surface** img,SDL_Surface* ecran,char place[],SDL_Rect pos);
#endif
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include "clavier.h"
SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;


	char* pPosition = ( char* ) surface->pixels ;


	pPosition += ( surface->pitch * y ) ;


	pPosition += ( surface->format->BytesPerPixel * x ) ;


	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;


	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}



int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,int d)
{

  SDL_Color col;
  if(d==0)//imin
  {
    col=GetPixel(calque,posperso.x+perso->w ,posperso.y+(perso->h/2));
  }
else  if(d==1)
  {
    col=GetPixel(calque,posperso.x ,posperso.y+(perso->h/2));
  }
else  if(d==2)
  {
    col=GetPixel(calque,posperso.x+(perso->w/2) ,posperso.y);
  }
else  if(d==3)
  {
    col=GetPixel(calque,posperso.x+(perso->w/2),posperso.y+perso->h );
  }
  printf("%d    %d   %d\n",col.r,col.b,col.g );
if ((col.r==0)&&(col.b==255)&&(col.g==0))
{

  return 1;
}
else
{

	return 0;
}
}

#ifndef COLLISION_PARFAITE_H
#define COLLISION_PARFAITE_H
SDL_Color GetPixel(SDL_Surface *surface,int x,int y);
int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,int d);
#endif



#endif
