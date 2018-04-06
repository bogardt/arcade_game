#include <iostream>
#include "mSDL.h"

mSDL::mSDL(const char *const windowName,
           const unsigned int width,
           const unsigned int height,
           const unsigned int bpp)
{
    _windowName = windowName;
    _width = width;
    _height = height;
    _bpp = bpp;
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
        std::cerr << "mSdl init error" << std::endl;
    SDL_WM_SetCaption(windowName, NULL);
    if (!(_screen = SDL_SetVideoMode(width, height, bpp, SDL_DOUBLEBUF | SDL_HWSURFACE)))
        std::cerr << "mSdl screen init error" << std::endl;
    // if (TTF_Init() == -1)
    //     std::cerr << "mSdl font init error" << std::endl;
}

mSDL::~mSDL()
{
}

void mSDL::createBackground()
{
    if (!(_background = SDL_AllocSurface(SDL_HWSURFACE, _width, _height, _bpp, 0, 0, 0, 0)))
        std::cerr << "mSdl background init error" << std::endl;
}

void mSDL::close()
{
    SDL_Quit();
}

void mSDL::update()
{
    SDL_Flip(_screen);
}

void mSDL::sleep(const unsigned int time)
{
    SDL_Delay(time);
}

bool mSDL::event()
{
    while (SDL_PollEvent(&_event))
    {
        if (_event.type == SDL_QUIT)
        {
            std::cout << "QUIT" << std::endl;
            return false;
        }
        else if (_event.type == SDL_KEYDOWN)
        {
            if (key == SDLK_ESCAPE)
            {
                std::cout << "ESCAPE" << std::endl;
                return false;
            }
            else
            {
                if (key == SDLK_UP)
                    std::cout << "UP" << std::endl;
                else if (key == SDLK_DOWN)
                    std::cout << "DOWN" << std::endl;
                else if (key == SDLK_LEFT)
                    std::cout << "LEFT" << std::endl;
                else if (key == SDLK_RIGHT)
                    std::cout << "RIGHT" << std::endl;
            }
        }
    }
    return true;
}