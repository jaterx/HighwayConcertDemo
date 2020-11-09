#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Model.hpp"
#include "View.hpp"
#include "Controller.hpp"

class Game
{

	public:

		Game();
		~Game();

		Model* model;
		View* view;
		Controller* controller;

		float fpsTarget;

		sf::Time dt;

		sf::Clock clock;

		void loop();		
};
