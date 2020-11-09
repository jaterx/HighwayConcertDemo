#pragma once

#include <stdio.h>
#include "Model.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class View {
public:
	Model* model;
	View(Model* model);
	~View();

	sf::RenderWindow window;
	sf::RenderWindow window2;
	int swidth;
	int sheight;
	sf::View view;

	//image related

	sf::Image test;
	sf::Texture testt;

	sf::Image cbarrierImage;
	sf::Image cbarrier1Image;
	sf::Image cbarrier2Image;
	sf::Image cbarrier3Image;

	sf::Image dbarrierImage;
	sf::Image dbarrier1Image;
	sf::Image dbarrier2Image;
	sf::Image dbarrier3Image;

	sf::Image fbarrierImage;
	sf::Image fbarrier1Image;
	sf::Image fbarrier2Image;
	sf::Image fbarrier3Image;

	sf::Image ibarrierImage;
	sf::Image ibarrier1Image;
	sf::Image ibarrier2Image;
	sf::Image ibarrier3Image;

	sf::Image titleImage;
	sf::Image blurredtitleImage;

	sf::Image locationImage;
	sf::Image vehicleImage;
	sf::Image exitImage;
	sf::Image leaderboardImage;
	sf::Image creditImage;
	sf::Image songImage;
	sf::Image startImage;
	sf::Image modeImage;
	sf::Image locationImage_s;
	sf::Image vehicleImage_s;
	sf::Image exitImage_s;
	sf::Image leaderboardImage_s;
	sf::Image creditImage_s;
	sf::Image songImage_s;
	sf::Image startImage_s;
	sf::Image modeImage_s;

	//item related
	sf::Image items;
	sf::Texture itemTexture;
	
	//item icon
	sf::Image missleImage;
	sf::Image reverseImage;
	sf::Image bombImage;

	sf::Texture shieldiv;
	sf::Texture missleTexture;
	sf::Texture bombTexture;
	sf::Texture reverseTexture;
	sf::Texture invisibleTexture;

	//item effect
	sf::Image shieldeffect;
	sf::Texture shieldeffectTexture;
	sf::Texture bombeffectTexture;
	sf::Texture invisibleeffectTexture;
	//sf::Texture reverseeffectTexture;
	sf::Texture missleeffectTexture;

	//texture related

	sf::Texture cbarrierTexture;
	sf::Texture dbarrierTexture;
	sf::Texture fbarrierTexture;
	sf::Texture ibarrierTexture;
	sf::Texture ffbarrierTexture;

	sf::Texture futureTexture;
	sf::Texture future1Texture;
	sf::Texture futuredualTexture;
	sf::Texture futuredual1Texture;

	sf::Texture cityTexture;
	sf::Texture city1Texture;
	sf::Texture citydualTexture;
	sf::Texture citydual1Texture;

	sf::Texture desertTexture;
	sf::Texture desert1Texture;
	sf::Texture desertdualTexture;
	sf::Texture desertdual1Texture;

	sf::Texture firnTexture;
	sf::Texture firn1Texture;
	sf::Texture firndualTexture;
	sf::Texture firndual1Texture;

	//not applied yet
	sf::Texture islandTexture;
	sf::Texture island1Texture;
	sf::Texture islanddualTexture;
	sf::Texture islanddual1Texture;

	//vehicle related
	sf::Texture taxiTexture;
	sf::Texture p911Texture;
	sf::Texture r8Texture;
	sf::Texture pickupTexture;
	sf::Texture minivanTexture;
	sf::Texture policeTexture;
	sf::Texture ambulanceTexture;
	sf::Texture truckTexture;
	sf::Texture sportcarTexture;

	//song related
	sf::Texture chasingcarsTexture;
	sf::Texture comeoutoftheshadeTexture;
	sf::Texture castawayTexture;
	sf::Texture safeandsoundTexture;
	sf::Texture animalTexture;
	sf::Texture carriedawayTexture;
	sf::Texture voteTexture;

	sf::Texture titleTexture;
	sf::Texture blurredtitleTexture;
	sf::Texture loadingTexture;

	sf::Texture generalTexture;
	sf::Texture general1Texture;

	sf::Texture menubgTexture;
	sf::Texture menubg1Texture;
	sf::Texture menubgdualTexture;
	sf::Texture menubgdual1Texture;
	sf::Texture creditmapTexture;
	sf::Texture creditmap1Texture;

	sf::Texture locationTexture;
	sf::Texture vehicleTexture;
	sf::Texture exitTexture;
	sf::Texture leaderboardTexture;
	sf::Texture creditTexture;
	sf::Texture songTexture;
	sf::Texture startTexture;
	sf::Texture modeTexture;
	sf::Texture locationTexture_s;
	sf::Texture vehicleTexture_s;
	sf::Texture exitTexture_s;
	sf::Texture leaderboardTexture_s;
	sf::Texture creditTexture_s;
	sf::Texture songTexture_s;
	sf::Texture startTexture_s;
	sf::Texture modeTexture_s;

	sf::Texture test1Texture;
	sf::Texture test2Texture;
	sf::Texture test3Texture;
	sf::Texture test4Texture;
	sf::Texture test5Texture;
	sf::Texture test6Texture;
	sf::Texture test7Texture;
	sf::Texture test8Texture;
	sf::Texture test9Texture;
	
	sf::Texture testbgTexture;

	sf::Texture tutorialTexture;

	sf::Texture transparentTexture;

	//sprite related
	sf::Sprite bg;
	sf::Sprite bg1;

	sf::Sprite cb;
	sf::Sprite cb1;
	sf::Sprite cb2;
	sf::Sprite cb3;

	sf::Sprite db;
	sf::Sprite db1;
	sf::Sprite db2;
	sf::Sprite db3;

	sf::Sprite fb;
	sf::Sprite fb1;
	sf::Sprite fb2;
	sf::Sprite fb3;

	sf::Sprite ib;
	sf::Sprite ib1;
	sf::Sprite ib2;
	sf::Sprite ib3;

	sf::Sprite player;
	sf::Sprite player2;

	sf::Sprite title;
	sf::Sprite blurredtitle;
	sf::Sprite loading;

	sf::Sprite tutorial;

	sf::Sprite location;
	sf::Sprite vehicle;
	sf::Sprite exit;
	sf::Sprite leaderboard;
	sf::Sprite credit;
	sf::Sprite start;
	sf::Sprite mode;
	sf::Sprite song;
	sf::Sprite tempSprite;
	sf::Sprite tempSprite2;

	//item related
	sf::Sprite shield;
	sf::Sprite invisible;
	sf::Sprite reverse;
	sf::Sprite missle;
	sf::Sprite bomb;
	sf::Sprite item;
	sf::Sprite shield2;
	sf::Sprite invisible2;
	sf::Sprite reverse2;
	sf::Sprite missle2;
	sf::Sprite bomb2;
	sf::Sprite item2;
	sf::Sprite itemeffect;
	sf::Sprite itemeffect2;
	sf::Sprite test1;
	sf::Sprite test2;
	sf::Sprite test3;
	sf::Sprite test4;
	sf::Sprite test5;
	sf::Sprite test6;
	sf::Sprite test7;
	sf::Sprite test8;
	sf::Sprite test9;

	sf::Sprite songimgingame;

	//text related
	sf::Font font;
	sf::FloatRect textRect;
	sf::FloatRect textRect2;
	sf::Text cardes;
	sf::Text cardetail;
	sf::Text cardetail2;
	sf::Text mapdes;
	sf::Text confirm;
	sf::Text prev;
	sf::Text next;
	sf::Text heading;
	sf::Text se;
	sf::Text se1;
	sf::Text itemdes;
	sf::Text songinfo;
	sf::Text comboinfo;
	sf::Text comboinfo2;
	sf::Text completioninfo;
	sf::Text quitmsg;
	sf::Text quittitle;
	sf::Text itemdes2;
	sf::Text scoreinfo;
	sf::Text scoreinfo2;
	sf::Text finalscore;
	sf::Text winner;
	sf::Text finalscorep1;
	sf::Text finalscorep2;
	sf::Text songdetail;

	//text plate related
	sf::RectangleShape headingplate;
	sf::RectangleShape cardetailplate;
	sf::RectangleShape bottomplate;
	sf::RectangleShape itemplate;
	sf::RectangleShape itemplate2;
	sf::RectangleShape songplate;
	sf::RectangleShape blurredplate;
	sf::RectangleShape scoreplate;
	sf::RectangleShape dbg;
	sf::RectangleShape dbg1;
	sf::RectangleShape cbg;
	sf::RectangleShape cbg1;
	sf::RectangleShape tbg;
	sf::RectangleShape tbg1;

	//line indicator related
	sf::RectangleShape startlineL;
	sf::RectangleShape startlineR;
	sf::RectangleShape lineinsL;
	sf::RectangleShape lineinsR;
	sf::RectangleShape startlineL2;
	sf::RectangleShape startlineR2;
	sf::RectangleShape lineinsL2;
	sf::RectangleShape lineinsM;
	sf::RectangleShape lineinsR2;

	//barrier container
	std::vector<sf::Sprite> cbs;
	std::vector<sf::Sprite> cbs2;

	//audio related
	sf::Sprite songimg;
	sf::Music titlebgm;
	sf::Music chasingcars;
	sf::Music comeoutoftheshade;
	sf::Music castaway;
	sf::Music animal;
	sf::Music carriedaway;
	sf::Music vote;
	sf::Music chasingcarspre;
	sf::Music comeoutoftheshadepre;
	sf::Music animalpre;
	sf::Music carriedawaypre;
	sf::Music votepre;
	sf::Music castawaypre;
	sf::Music safeandsoundpre;
	sf::Music safeandsound;
	sf::Music tunersong;

	sf::SoundBuffer pressbuffer;
	sf::SoundBuffer destorybuffer;
	sf::SoundBuffer shieldonbuffer;
	sf::SoundBuffer itemusedbuffer;
	sf::SoundBuffer itempickupbuffer;
	sf::SoundBuffer missleincomingbuffer;
	sf::SoundBuffer barrierexplodedbuffer;

	sf::Sound presssound;
	sf::Sound destorysound;
	sf::Sound shieldonsound;
	sf::Sound itemusedsound;
	sf::Sound itempickupsound;
	sf::Sound missleincoming;
	sf::Sound barrierexploded;

	sf::Image icon;

	int transcolor;
	int transcolor2;
	int transcolor3;

	int currentcombo;
	int currentcombo2;
	int currentmspeed;

	int comboswitcher;
	int comboswitcher2;
	int bumped;
	int bumped2;
	int rotated;
	int record_i;
	int record_i2;

	//item related
	int itemconfirm;
	int itemconfirm2;
	int textureflip;
	int textureflip2;
	int textureflip3;
	int textureflip4;
	int still;
	int active;
	int active2;
	int expiration_record;
	int expiration_record2;

	int testcarselected;
	int backscroll;

	int test1x;
	int test2x;
	int test3x;
	int test4x;
	int test5x;
	int test6x;
	int test7x;
	int test8x;
	int test9x;

	void render();
	void song_control();
	void quit_control();
	void replay();
	void djpause();
	void collision();
	void collision2();
	void djplay();
	void explosion();
	void explosion2();
	void final_test();
};