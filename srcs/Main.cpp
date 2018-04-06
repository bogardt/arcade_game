#include <iostream>
#include "mSDL.h"

int main(int ac, char **av)
{
    mSDL *msdl = new mSDL("toto", 200, 200, 32);
    msdl->createBackground();

    std::cout << "test" << std::endl;

    return 0;
}