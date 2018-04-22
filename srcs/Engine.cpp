#include "Engine.h"

Engine::Engine()
	: _gui(new mSFML())
{}

Engine::~Engine()
{}

void		Engine::start()
{
	while (_gui->isAlive())
	{
		_gui->clear();
		_gui->handleEvents();
		_gui->update();
		_gui->display();
	}
}