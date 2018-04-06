#ifndef __M_SDL_H__
#define __M_SDL_H__

#include "SDL.h"
// # include	"SDL_ttf.h"
// # include   "SDL_image.h"

# define	key		_event.key.keysym.sym

class mSDL
{
  public:
    explicit mSDL(const char * const windowName,
                  const unsigned int width,
                  const unsigned int height,
                  const unsigned int bpp);
    ~mSDL();
    void createBackground();
    void close();
    void update();
    void sleep(const unsigned int time);
    bool event();
    void spriteAt();

  private:
    SDL_Surface   *_screen;
    SDL_Surface   *_background;
    SDL_Event     _event;

    const char    *_windowName;
    unsigned int  _width;
    unsigned int  _height;
    unsigned int  _bpp;
};

#endif /* !__M_SDL_H__ */