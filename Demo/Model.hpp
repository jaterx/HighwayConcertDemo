#pragma once

#include <stdio.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Model {
public:
	Model();
	~Model();

	void update(sf::Time);

	int gameState;
	//0 initial value
	//1 main menu
	//2 gameplay (single player split screen multiplayer)

	int menuLayer;
	//0 initial value
	//1 select cars
	//2 select maps
	//3 select songs
	//4 creidt

	//position related
	int mapy;
	int mapyy;
	int mapx;
	int mspeed;
	int pposx;
	int pposy;
	int ppposx;
	int ppposy;
	int p2posx;
	int p2posy;
	
	//barrier position related
	int totalbarriers;
	int totalbarriers2;
	std::vector<int> fallpos;
	std::vector<int> fallpos2;
	float fallposy;
	float fallposy2;
	float titlepos;

	//button related
	int buttontracker;
	int buttontracker1;
	int buttontracker2;
	int buttontracker3;
	int buttontracker4;
	int buttontracker5;
	int buttontracker6;
	int buttontracker7;
	int buttonpos1;
	int buttonpos2;
	int buttonpos3;
	int buttonpos4;
	int buttonpos;
	int buttonpos5;
	int buttonpos6;
	int buttonpos7;
	int bspeed;
	int bspeedm;
	int buttonlock;
	int buttonlock1;
	int buttonlock2;
	int buttonlock3;
	int buttonlock4;
	int buttonlock5;
	int buttonlock6;
	int buttonlock7;
	int buttonlocko;

	//int maplock;
	int buttonselected;
	int carselected;
	int mapselected;
	int songselected;
	int modeselected;

	int fontlock;
	int fontlock2;

	//multiplayer confirmation
	int isDual;

	//item related
	int isItem;
	int isItem2;
	int itemrotation;
	int itemno;
	int itemnorng;
	int itemno2;
	int itemnorng2;
	//1. shield
	//2. missle
	//3. reverse key
	//4. bomb
	//5. invisible

	//game value related
	int currency;
	int completion;
	int combo;
	int combo2;
	int dysize;
	int dysize2;
	int score;
	int score2;

	//distance and time check related
	sf::Clock clock2;
	int pixelReceived;
	int timeGone;
	int switcher;
	int quitswitcher;

	//random replay
	std::vector<int> rngxv;
	std::vector<int> rngxv2;
	int xrng;
	int xrng2;

	//line indicator related
	int lineposy;
	int dylineposy;

	int collisionjudge;
	int collisionjudge2;

	float songspeed;
	float songspeedrate;

	int gamestart;
	int teststart;
	int record_score;
	int record_score2;
	int displayleaderboard;
	std::vector<int> scorerecord;
	std::vector<int> scorerecord2;

	int movex;
	int movey;

	bool up;
	bool down;
	bool left;
	bool right;

	float zoomx;
	float zoomy;
	int zoomswitch;
	int todraw;
	int currentxl;
	int currentxr;

	sf::Texture crosshairTexture;
	sf::Sprite crosshair;
	sf::RectangleShape crosshairplate;
	sf::Text crosshairtext;

	//functions
	void set_speed();
	void object_limit();
	void locked_button_animation();
	void unlocked_button_animation();
	void map_scroll();
	void barrier_set();
	void item_rotate();
	void item_zoom();
	void time_check();
	void reset();
	void rngx();
	void prop_rng();
	void prop_rng2();
	void score_calculate();
	void score2_calculate();

};