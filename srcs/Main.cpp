#include <iostream>
#include "mSFML.hpp"

int main(int ac, char **av)
{
	IGui *gui = new mSFML();
	while (gui->isAlive())
	{
		gui->clear();
		gui->handleEvents();
		gui->update();
		gui->display();
	}
	return 0;
}