#include <iostream>
#include "mSFML.hpp"

int main(int ac, char **av)
{
	IGui *gui = new mSFML();
	while (gui->isAlive())
	{
		gui->clear();
		gui->handleEvents();
		gui->display();
	}
	return 0;
}