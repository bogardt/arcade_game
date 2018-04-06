#include <iostream>
#include "SDL.h"

int main(int ac, char **av)
{

    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "->msdl init error\n");
        return (0);
    }

    std::cout << "test" << std::endl;

    return 0;
}