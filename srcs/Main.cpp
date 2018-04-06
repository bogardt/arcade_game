#include <iostream>
#include "mSDL.h"

int main(int ac, char **av)
{
    mSDL *msdl = new mSDL("toto", 200, 200, 32);
    while (msdl->event())
    {
        msdl->createBackground();
    }
    return 0;
}