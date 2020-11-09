#pragma once

#include <stdio.h>
#include "Model.hpp"
#include "View.hpp"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Controller {
	public:
		Model* model;
		View* view;
		Controller(Model* model, View* view);
		~Controller();

		sf::Clock presstime;
		

		void inputs();
};