#include "model.hpp"
#include <iostream>

Model::Model()
{
	gameState = 0;

	up = false;
	down = false;
	left = false;
	right = false;

	todraw = 0;
	zoomswitch = 0;
	itemrotation = 0;
	collisionjudge = 0;
	collisionjudge2 = 0;
	songspeed = 0;
	songspeedrate = 1.0;
	itemno = 0;
	itemnorng = 0;
	itemno2 = 0;
	itemnorng2 = 0;
	displayleaderboard = 0;

	pposx = 300;
	pposy = 600;
	ppposx = 230;
	ppposy = 600;
	p2posx = 660;
	p2posy = 600;
	mapy = 0;
	mapx = 0;
	mapyy = -866;
	fallposy = 0;

	fontlock = 0;
	fontlock2 = 0;
	currency = 0;

	buttontracker = 10;
	buttontracker1 = 10;
	buttontracker2 = 10;
	buttontracker3 = 10;

	isDual = 0;
	isItem = 0;
	isItem2 = 0;

	gamestart = 0;
	teststart = 0;

	titlepos = 725;
	buttonpos = 725;
	buttonpos1 = 725;
	buttonpos2 = 725;
	buttonpos3 = 725;
	buttonpos4 = 725;
	buttonpos5 = 725;
	buttonpos6 = 725;
	buttonpos7 = 725;

	buttonselected = 0;
	carselected = 0;
	mapselected = 0;
	songselected = 0;
	
	gameState = 1;
	menuLayer = 0;
	mspeed = 10;
	bspeed = 30;
	bspeedm = 10;

	buttonlock = 0;
	buttonlock1 = 0;
	buttonlock2 = 0;
	buttonlock3 = 0;
	buttonlock4 = 0;
	buttonlock5 = 0;
	buttonlock6 = 0;
	buttonlock7 = 0;
	buttonlocko = 1;

	dysize = 100;
	dysize2 = 100;

	lineposy = pposy;
	dylineposy = 0;
	
	switcher = 0;
	quitswitcher = 0;

	score = 0;
	score2 = 0;

	zoomx = 0.2f;
	zoomy = 0.2f;

	currentxl = 0;
	currentxr = 0;

	crosshair.setPosition(500,400);
	crosshairplate.setPosition(540, 360);
	crosshairtext.setPosition(540,360);

	reset();

}

Model::~Model()
{ }

void Model::reset() {
	rngxv.erase(rngxv.begin(), rngxv.end());
	rngxv2.erase(rngxv2.begin(), rngxv2.end());
	fallpos.erase(fallpos.begin(), fallpos.end());
	fallpos2.erase(fallpos2.begin(), fallpos2.end());
	barrier_set(); //set y position for all barriers
	combo = 0;
	combo2 = 0;
	completion = 0;
	itemno = 0;
	itemno2 = 0;
	rngx(); //set x position for all barriers
	score = 0;
	score2 = 0;
}

void Model::update(sf::Time dt)
{
	if (gameState == 3) {
		item_rotate();
		item_zoom();
		sf::Vector2f moved(0.f, 0.f);
		if (up && crosshair.getPosition().y >= -10) { moved.y -= 10.f; }
		if (down && crosshair.getPosition().y <= 860) { moved.y += 10.f; }
		if (left && crosshair.getPosition().x >= -10) { moved.x -= 10.f; }
		if (right && crosshair.getPosition().x <= 1034) { moved.x += 10.f; }
		crosshair.move(moved);
		crosshairtext.move(moved);
		crosshairplate.move(moved);
		crosshair.setRotation(itemrotation);
	}
	map_scroll();
	std::cout << "Song Speed Rate is: " << songspeedrate << std::endl;
	if (gameState == 1) {
		locked_button_animation();
		unlocked_button_animation();
		object_limit();	
	}
	if (gameState == 2) {
		dylineposy = dylineposy + mspeed;
		item_rotate();
		time_check();
		//std::cout << "single or dual: " << isDual << std::endl;
		if (score2 <= 0) {
			score2 = 0;
		}
		if (score <= 0) {
			score = 0;
		}
	}
	
}

void Model::barrier_set()
{

	if (isDual == 0 || gameState == 3 || gameState == 4) {
		for (int i = 0; i < totalbarriers; i++) {
			fallpos.push_back(fallposy);
		}
		for (int i = 1; i < totalbarriers; i++) {
			fallpos[i] = fallpos[i - 1] - (songspeed * songspeedrate);
			//std::cout << fallpos[i] << std::endl;
		}
	}
	if (isDual == 1 && gameState != 3 && gameState != 4) {
		for (int i = 0; i < totalbarriers; i++) {
			fallpos.push_back(fallposy);
		}
		for (int i = 1; i < totalbarriers; i++) {
			fallpos[i] = fallpos[i - 1] - (songspeed * songspeedrate);
			//std::cout << fallpos[i] << std::endl;
		}
		for (int i = 0; i < totalbarriers; i++) {
			fallpos2.push_back(fallposy2);
		}
		for (int i = 1; i < totalbarriers; i++) {
			fallpos2[i] = fallpos2[i - 1] - (songspeed * songspeedrate);
			//std::cout << fallpos2[i] << std::endl;
		}
	}
	
}

void Model::rngx() {
	if (gameState != 4) {
		if (isDual == 0) {
			for (int i = 0; i < totalbarriers; i++) {
				if (rand() % 2 == 0) {
					xrng = 305;
				}
				else {
					xrng = 380;
				}
				rngxv.push_back(xrng);
			}
		}
		if (isDual == 1) {
			for (int i = 0; i < totalbarriers; i++) {
				if (rand() % 2 == 0) {
					xrng = 235;
				}
				else {
					xrng = 308;
				}
				rngxv.push_back(xrng);
			}
			for (int i = 0; i < totalbarriers; i++) {
				if (rand() % 2 == 1) {
					xrng2 = 665;
				}
				else {
					xrng2 = 738;
				}
				rngxv2.push_back(xrng2);
			}
		}
	}
	if (gameState == 4) {
		for (int i = 0; i < totalbarriers; i++) {
			if (rand() % 2 == 0) {
				xrng = currentxl;
			}
			else {
				xrng = currentxr;
			}
			rngxv.push_back(xrng);
		}
	}
}


void Model::item_rotate() {
	if (gameState == 3) {
		itemrotation += 4;
	}
	else {
		itemrotation += 1;
	}
}

void Model::item_zoom() {

	if (zoomx >= 0.2f) {
		zoomswitch = 2;
	}
	if (zoomx <= 0.15f) {
		zoomswitch = 1;
	}

	if (zoomswitch == 2) {
		zoomx -= 0.001f;
		zoomy -= 0.001f;

	}
	if (zoomswitch == 1) {
		zoomx += 0.001f;
		zoomy += 0.001f;
	}
}

void Model::object_limit()
{

	//button limit
	if (buttonselected > 7) {
		buttonselected = 7;
	}
	if (buttonselected < 0) {
		buttonselected = 0;
	}

	//car limit
	if (carselected > 8) {
		carselected = 8;
	}
	if (carselected < 0) {
		carselected = 0;
	}

	//map limit
	if (mapselected > 5) {
		mapselected = 5;
	}
	if (mapselected < 0) {
		mapselected = 0;
	}

	//song limit
	if (songselected > 6) {
		songselected = 6;
	}
	if (songselected < 0) {
		songselected = 0;
	}

	//mode limit
	if (modeselected > 1) {
		modeselected = 1;
	}
	if (modeselected < 0) {
		modeselected = 0;
	}

}

void Model::locked_button_animation()
{

	//logo animation
	if (titlepos > 22) {
		titlepos = titlepos - bspeed;
	}
	if (titlepos >= 600) {
		buttontracker = 0;
	}
	if (titlepos <= 22) {
		titlepos = 22;
	}

	//start
	if (buttontracker == 0) {
		buttonpos = buttonpos - (bspeedm);
	}
	if (titlepos >= 200) {
		buttontracker1 = 0;
	}
	if (buttonlock == 0) {
		if (buttonpos <= 550) {
			buttonpos = 550;
		}
	}

	//mode
	if (buttontracker1 == 0) {
		buttonpos1 = buttonpos1 - (bspeedm - 1);
	}
	if (titlepos >= 500) {
		buttontracker2 = 0;
	}
	if (buttonlock1 == 0) {
		if (buttonpos1 <= 550) {
			buttonpos1 = 550;
		}
	}

	//vehicle
	if (buttontracker2 == 0) {
		buttonpos2 = buttonpos2 - (bspeedm - 2);
	}
	if (titlepos >= 450) {
		buttontracker3 = 0;
	}
	if (buttonlock2 == 0) {
		if (buttonpos2 <= 550) {
			buttonpos2 = 550;
		}
	}

	//song
	if (buttontracker3 == 0) {
		buttonpos3 = buttonpos3 - (bspeedm - 3);
	}
	if (titlepos >= 400) {
		buttontracker4 = 0;
	}
	if (buttonlock3 == 0) {
		if (buttonpos3 <= 550) {
			buttonpos3 = 550;
		}
	}

	//location
	if (buttontracker4 == 0) {
		buttonpos4 = buttonpos4 - (bspeedm - 4);
	}
	if (titlepos >= 350) {
		buttontracker5 = 0;
	}
	if (buttonlock4 == 0) {
		if (buttonpos4 <= 550) {
			buttonpos4 = 550;
		}
	}

	//leaderboard
	if (buttontracker5 == 0) {
		buttonpos5 = buttonpos5 - (bspeedm - 5);
	}
	if (titlepos >= 300) {
		buttontracker6 = 0;
	}
	if (buttonlock5 == 0) {
		if (buttonpos5 <= 550) {
			buttonpos5 = 550;
		}
	}

	//credit
	if (buttontracker6 == 0) {
		buttonpos6 = buttonpos6 - (bspeedm - 6);
	}
	if (titlepos >= 250) {
		buttontracker7 = 0;
	}
	if (buttonlock6 == 0) {
		if (buttonpos6 <= 550) {
			buttonpos6 = 550;
		}
	}

	//exit
	if (buttontracker7 == 0) {
		buttonpos7 = buttonpos7 - (bspeedm - 7);
	}
	if (buttonlock7 == 0) {
		if (buttonpos7 <= 550) {
			buttonpos7 = 550;
		}
	}

}

void Model::unlocked_button_animation() {
	if (buttonlock == 1) {
		buttonpos = buttonpos - 5;

		if (buttonpos <= 480) {
			buttonpos = 480;
		}
	}
	if (buttonlock1 == 1) {
		buttonpos1 = buttonpos1 - 7;

		if (buttonpos1 <= 480) {
			buttonpos1 = 480;
		}
	}
	if (buttonlock2 == 1) {
		buttonpos2 = buttonpos2 - 7;

		if (buttonpos2 <= 480) {
			buttonpos2 = 480;
		}
	}
	if (buttonlock3 == 1) {
		buttonpos3 = buttonpos3 - 7;

		if (buttonpos3 <= 480) {
			buttonpos3 = 480;
		}
	}
	if (buttonlock4 == 1) {
		buttonpos4 = buttonpos4 - 7;

		if (buttonpos4 <= 480) {
			buttonpos4 = 480;
		}
	}
	if (buttonlock5 == 1) {
		buttonpos5 = buttonpos5 - 7;

		if (buttonpos5 <= 480) {
			buttonpos5 = 480;
		}
	}
	if (buttonlock6 == 1) {
		buttonpos6 = buttonpos6 - 7;

		if (buttonpos6 <= 480) {
			buttonpos6 = 480;
		}
	}
	if (buttonlock7 == 1) {
		buttonpos7 = buttonpos7 - 7;

		if (buttonpos7 <= 480) {
			buttonpos7 = 480;
		}
	}

	if (buttonlocko == 2) {
		buttonpos = buttonpos - 20;
		if (buttonpos <= -100) {
			gameState = 2;
			buttonpos = 550;
			buttonlocko = 0;
		}
	}
}

void Model::set_speed() {
	if (carselected == 0) {
		mspeed = 10;
		songspeedrate = 1.0;
		reset();
		//1.0x speed
		//free to use
	}
	if (carselected == 1) {
		mspeed = 10;
		songspeedrate = 1.0;
		reset();
		//1.0x speed
		//free to use
	}
	if (carselected == 2) {
		mspeed = 15;
		songspeedrate = 1.5;
		reset();
		//2.0x speed
		//need to be unlocked
		//when combo reach 500
	}
	if (carselected == 3) {
		mspeed = 15;
		songspeedrate = 1.5;
		reset();
		//1.5x speed
		//need to be unlocked
		//play the game 10 times
	}
	if (carselected == 4) {
		mspeed = 8;
		songspeedrate = 0.8;
		reset();
		//0.8x speed
		//need to be unlocked
		//combo reach 1000
	}
	if (carselected == 5) {
		mspeed = 5;
		songspeedrate = 0.5;
		reset();
		//0.5x speed
		//need to be unlocked
		//all combo a song
	}
	if (carselected == 6) {
		mspeed = 30;
		songspeedrate = 3.0;
		reset();
		//2.0x speed
		//need to be unlocked
		//reach the top 1 on the leaderboard
	}
	if (carselected == 7) {
		mspeed = 40;
		songspeedrate = 4.0;
		reset();
		//4.0x speed
		//all combo a random song 10 times
	}
	if (carselected == 8) {
		mspeed = 3;
		songspeedrate = 0.3;
		reset();
		//0.3x speed
		//need to be unlocked
		//hidden car, unlock requirement unknown
	}
}

void Model::map_scroll()
{
	mapy = mapy + mspeed;
	mapyy = mapyy + mspeed;

	//std::cout << mapy << std::endl;
	if (menuLayer == 5) {
		if (mapy <= -866) {
			mapy = mapyy + 866;
		}
		if (mapyy <= -866) {
			mapyy = mapy + 866;
		}
	}
	else {
		if (mapy >= 866) {
			mapy = mapyy - 866;
		}
		if (mapyy >= 866) {
			mapyy = mapy - 866;
		}
	}
}

void Model::time_check() {
	//pixelReceived = 0;
	pixelReceived = pixelReceived + mspeed;
	if (clock2.getElapsedTime().asSeconds() <= 4) {
		std::cout << "Pixels per 4 seconds are: " << pixelReceived << std::endl;
	}
}

void Model::prop_rng() {
	itemnorng = (rand() % 5) + 1;
	itemno = itemnorng;
	//below is the code for test purpose
	//itemno = 4;
}

void Model::prop_rng2() {
	itemnorng2 = (rand() % 5) + 1;
	itemno2 = itemnorng2;
	//below is the code for test purpose
	//itemno2 = 4;
}

void Model::score_calculate() {
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && !(ppposy - fallpos[totalbarriers - 1] < mspeed)) {
		if (combo == 0) {
			score = score - 5000;
		}
		if (combo <= 100) {
			score = score + 50;
		}
		if (101 <= combo <= 200) {
			score = score + 100;
		}
		if (201 <= combo <= 300) {
			score = score + 200;
		}
		if (301 <= combo <= 500) {
			score = score + 500;
		}
		if (combo >= 501) {
			score = score + 1000;
		}
	}
}

void Model::score2_calculate() {
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && !(ppposy - fallpos[totalbarriers - 1] < mspeed)) {
		if (combo2 == 0) {
			score2 = score2 - 5000;
		}
		if (combo2 <= 100) {
			score2 = score2 + 50;
		}
		if (101 <= combo2 <= 200) {
			score2 = score2 + 100;
		}
		if (201 <= combo2 <= 300) {
			score2 = score2 + 200;
		}
		if (301 <= combo2 <= 500) {
			score2 = score2 + 500;
		}
		if (combo2 >= 501) {
			score2 = score2 + 1000;
		}
		
	}
}

