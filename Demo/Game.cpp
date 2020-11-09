#include <iostream>
#include <fstream>

#include "Game.hpp"

Game::Game()
{
	model = new Model();
	view = new View(model);
	controller = new Controller(model, view);
	fpsTarget = 1.f / 60.f;
}

Game::~Game()
{

}

void Game::loop()
{

	while (view->window.isOpen())
	{
		clock.restart();
		controller->inputs();
		model->update(dt);
		view->render();

		dt = clock.getElapsedTime();
		//std::cout << dt.asSeconds() << std::endl;
		if (dt.asSeconds() < fpsTarget) { //loop way to fast, get higher fps
			sf::sleep(sf::seconds(fpsTarget) - dt);
		}
	}

}

