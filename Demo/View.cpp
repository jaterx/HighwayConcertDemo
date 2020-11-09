#include "View.hpp"
#include "Model.hpp"
#include <iostream>

View::View(Model* model) {
	this->model = model;

	comboswitcher = 0;
	comboswitcher2 = 0;

	testcarselected = 0;
	still = 0;
	active = 0;
	active2 = 0;

	bumped = 0;
	bumped2 = 0;
	rotated = 0;
	backscroll = 0;

	test1x = 163;
	test2x = 233;
	test3x = 307;
	test4x = 377;
	test5x = 453;
	test6x = 523;
	test7x = 593;
	test8x = 667;
	test9x = 740;

	itemconfirm = 0;
	itemconfirm2 = 0;
	expiration_record = -1;

	swidth = 720;
	sheight = 850;
	window2.create(sf::VideoMode(666,631), "Highway Concert Tutorial");
	window.create(sf::VideoMode(swidth, sheight), "Highway Concert Final Alpha Build V1.6.0");
	window.setFramerateLimit(144);


	icon.loadFromFile("Assets/barrier/general_barrier.png");
	icon.createMaskFromColor(sf::Color::White);
	window.setIcon(48,48, icon.getPixelsPtr());
	window2.setIcon(48, 48, icon.getPixelsPtr());
	
	//general hidden texture
	transparentTexture.loadFromFile("Assets/item/mask.png");

	//text related
	font.loadFromFile("Assets/font/dodger3superital.ttf");

	winner.setFont(font);
	winner.setCharacterSize(40);
	winner.setColor(sf::Color::White);

	heading.setFont(font);
	heading.setCharacterSize(50);
	heading.setColor(sf::Color::White);
	heading.setPosition(30, 20);

	confirm.setFont(font);
	confirm.setCharacterSize(30);
	confirm.setColor(sf::Color::White);
	confirm.setPosition(95, 800);

	quittitle.setFont(font);
	quittitle.setCharacterSize(60);
	quittitle.setColor(sf::Color(0, 162, 232));
	quittitle.setPosition(250, 300);

	quitmsg.setFont(font);
	quitmsg.setCharacterSize(40);
	quitmsg.setColor(sf::Color::White);
	quitmsg.setPosition(200, 400);

	next.setFont(font);
	next.setCharacterSize(24);
	next.setColor(sf::Color(0, 162, 232));
	next.setPosition(660, 800);

	prev.setFont(font);
	prev.setCharacterSize(24);
	prev.setColor(sf::Color(0, 162, 232));
	prev.setPosition(20, 800);

	se.setFont(font);
	se.setCharacterSize(26);
	se.setPosition(30, 180);
	se1.setFont(font);
	se1.setCharacterSize(26);

	cardes.setFont(font);
	cardes.setCharacterSize(30);
	cardes.setColor(sf::Color(0, 162, 232));
	cardes.setPosition(30, 70);

	cardetail.setFont(font);
	cardetail.setCharacterSize(24);
	cardetail.setColor(sf::Color(0, 162, 232));
	cardetail.setPosition(30, 270);
	cardetail.setString("speed\n\n\ndifficulty\n\n\ntest drive\n\n\n");

	cardetail2.setFont(font);
	cardetail2.setCharacterSize(24);
	cardetail2.setColor(sf::Color::White);
	cardetail2.setPosition(30, 300);

	itemdes.setFont(font);
	itemdes.setCharacterSize(24);
	itemdes.setPosition(10, 790);
	itemdes2.setFont(font);
	itemdes2.setCharacterSize(24);

	songdetail.setFont(font);
	songdetail.setCharacterSize(34);
	songdetail.setColor(sf::Color::White);
	songdetail.setPosition(130, 600);

	songinfo.setFont(font);
	songinfo.setCharacterSize(24);
	songinfo.setColor(sf::Color::White);
	songinfo.setPosition(150, 10);

	comboinfo.setFont(font);
	comboinfo.setColor(sf::Color(0, 162, 232));
	comboinfo2.setFont(font);
	comboinfo2.setColor(sf::Color(0, 162, 232));

	scoreinfo.setFont(font);
	scoreinfo.setCharacterSize(30);
	scoreinfo.setColor(sf::Color(0, 162, 232));
	scoreinfo.setPosition(5,135);
	scoreinfo2.setFont(font);
	scoreinfo2.setCharacterSize(30);
	scoreinfo2.setPosition(850, 135);
	scoreinfo2.setColor(sf::Color(0, 162, 232));

	//line indicator related
	lineinsL.setFillColor(sf::Color(0, 162, 232));
	lineinsL.setPosition(0, model->pposy);
	lineinsL.setSize(sf::Vector2f(model->pposx-15, 5));

	lineinsR.setFillColor(sf::Color(0, 162, 232));
	lineinsR.setPosition(model->pposx+133, model->pposy);
	lineinsR.setSize(sf::Vector2f(model->pposx, 5));

	lineinsL2.setFillColor(sf::Color(0, 162, 232));
	lineinsL2.setPosition(0, model->pposy);
	lineinsL2.setSize(sf::Vector2f(model->ppposx - 15, 5));

	lineinsM.setFillColor(sf::Color(0, 162, 232));
	lineinsM.setPosition(model->ppposx + 132, model->pposy);
	lineinsM.setSize(sf::Vector2f(290, 5));

	lineinsR2.setFillColor(sf::Color(0, 162, 232));
	lineinsR2.setPosition(model->p2posx + 135, model->pposy);
	lineinsR2.setSize(sf::Vector2f(model->ppposx, 5));

	//test drive plate related
	model->crosshairplate.setFillColor(sf::Color(0, 0, 0, 100));
	model->crosshairplate.setSize(sf::Vector2f(310, 30));
	model->crosshairtext.setFont(font);
	model->crosshairtext.setCharacterSize(20);
	model->crosshairtext.setColor(sf::Color(0, 162, 232));
	model->crosshairtext.setString(" enter this car (C)");

	//text plate related
	headingplate.setFillColor(sf::Color(0, 0, 0, 100));
	headingplate.setPosition(0, 0);

	cardetailplate.setFillColor(sf::Color(0, 0, 0, 100));
	cardetailplate.setPosition(0, 250);
	cardetailplate.setSize(sf::Vector2f(270, 400));

	bottomplate.setFillColor(sf::Color(0, 0, 0, 100));
	bottomplate.setPosition(0, 790);

	itemplate.setFillColor(sf::Color(0, 0, 0, 100));
	itemplate.setPosition(0, 700);
	itemplate.setSize(sf::Vector2f(84, 84));

	itemplate2.setFillColor(sf::Color(0, 0, 0, 100));
	itemplate2.setPosition(940, 700);
	itemplate2.setSize(sf::Vector2f(84, 84));

	songplate.setFillColor(sf::Color(0, 0, 0, 100));
	songplate.setSize(sf::Vector2f(1024, 130));
	songplate.setPosition(0,0);

	blurredplate.setFillColor(sf::Color::Black);
	scoreplate.setFillColor(sf::Color(0, 0, 0, 100));
	scoreplate.setPosition(50, 50);
	
	tutorialTexture.loadFromFile("Assets/tutorial/tut.png");
	tutorial.setTexture(tutorialTexture);
	tutorial.setPosition(0,0);

	blurredtitleImage.loadFromFile("Assets/logo/titleblurred.png");
	blurredtitleImage.createMaskFromColor(sf::Color(0, 0, 0, 100));
	blurredtitleTexture.loadFromImage(blurredtitleImage);
	blurredtitleTexture.setSmooth(true);
	blurredtitle.setTexture(blurredtitleTexture);
	blurredtitle.setScale(0.7f, 0.7f);

	//image/texture/sprite related
	titleImage.loadFromFile("Assets/logo/title.png");
	titleImage.createMaskFromColor(sf::Color::Black);
	titleTexture.loadFromImage(titleImage);
	titleTexture.setSmooth(true);
	title.setTexture(titleTexture);
	title.setScale(0.7f, 0.7f);

	loadingTexture.loadFromFile("Assets/logo/titleblurred.png");
	loadingTexture.setSmooth(true);
	loading.setTexture(titleTexture);

	menubgTexture.loadFromFile("Assets/map/menumap.png");
	menubgTexture.setSmooth(true);

	menubg1Texture.loadFromFile("Assets/map/menumap1.png");
	menubg1Texture.setSmooth(true);

	generalTexture.loadFromFile("Assets/map/general.png");
	generalTexture.setSmooth(true);

	general1Texture.loadFromFile("Assets/map/general1.png");
	general1Texture.setSmooth(true);

	creditmapTexture.loadFromFile("Assets/map/creditmap.png");
	creditmapTexture.setSmooth(true);

	creditmap1Texture.loadFromFile("Assets/map/creditmap1.png");
	creditmap1Texture.setSmooth(true);

	menubgdualTexture.loadFromFile("Assets/map/menumap_dual.png");
	menubgdualTexture.setSmooth(true);

	menubgdual1Texture.loadFromFile("Assets/map/menumap_dual1.png");
	menubgdual1Texture.setSmooth(true);

	testbgTexture.loadFromFile("Assets/testdrive/testdrivemap.png");
	testbgTexture.setSmooth(true);

	bg.setTexture(menubgTexture);
	bg1.setTexture(menubg1Texture);

	dbg.setSize(sf::Vector2f(1024, 866));
	dbg1.setSize(sf::Vector2f(1024, 866));

	tbg.setSize(sf::Vector2f(1024, 866));
	tbg1.setSize(sf::Vector2f(1024, 866));
	tbg.setTexture(&testbgTexture);
	tbg1.setTexture(&testbgTexture);

	cbg.setSize(sf::Vector2f(720, 866));
	cbg1.setSize(sf::Vector2f(720, 866));
	cbg.setTexture(&creditmapTexture);
	cbg1.setTexture(&creditmap1Texture);

	locationImage.loadFromFile("Assets/button/b_location.png");
	locationImage.createMaskFromColor(sf::Color(0, 162, 232));
	locationTexture.loadFromImage(locationImage);
	locationTexture.setSmooth(true);
	location.setTexture(locationTexture);

	locationImage_s.loadFromFile("Assets/button/b_location_selected.png");
	locationImage_s.createMaskFromColor(sf::Color(0, 162, 232));
	locationTexture_s.loadFromImage(locationImage_s);
	locationTexture_s.setSmooth(true);

	vehicleImage.loadFromFile("Assets/button/b_vehicle.png");
	vehicleImage.createMaskFromColor(sf::Color(0, 162, 232));
	vehicleTexture.loadFromImage(vehicleImage);
	vehicleTexture.setSmooth(true);
	vehicle.setTexture(vehicleTexture);

	vehicleImage_s.loadFromFile("Assets/button/b_vehicle_selected.png");
	vehicleImage_s.createMaskFromColor(sf::Color(0, 162, 232));
	vehicleTexture_s.loadFromImage(vehicleImage_s);
	vehicleTexture_s.setSmooth(true);

	leaderboardImage.loadFromFile("Assets/button/b_leaderboard.png");
	leaderboardImage.createMaskFromColor(sf::Color(0, 162, 232));
	leaderboardTexture.loadFromImage(leaderboardImage);
	leaderboardTexture.setSmooth(true);
	leaderboard.setTexture(leaderboardTexture);

	leaderboardImage_s.loadFromFile("Assets/button/b_leaderboard_selected.png");
	leaderboardImage_s.createMaskFromColor(sf::Color(0, 162, 232));
	leaderboardTexture_s.loadFromImage(leaderboardImage_s);
	leaderboardTexture_s.setSmooth(true);

	creditImage.loadFromFile("Assets/button/b_credit.png");
	creditImage.createMaskFromColor(sf::Color(0, 162, 232));
	creditTexture.loadFromImage(creditImage);
	creditTexture.setSmooth(true);
	credit.setTexture(creditTexture);

	creditImage_s.loadFromFile("Assets/button/b_credit_selected.png");
	creditImage_s.createMaskFromColor(sf::Color(0, 162, 232));
	creditTexture_s.loadFromImage(creditImage_s);
	creditTexture_s.setSmooth(true);

	exitImage.loadFromFile("Assets/button/b_exit.png");
	exitImage.createMaskFromColor(sf::Color(0, 162, 232));
	exitTexture.loadFromImage(exitImage);
	exitTexture.setSmooth(true);
	exit.setTexture(exitTexture);

	exitImage_s.loadFromFile("Assets/button/b_exit_selected.png");
	exitImage_s.createMaskFromColor(sf::Color(0, 162, 232));
	exitTexture_s.loadFromImage(exitImage_s);
	exitTexture_s.setSmooth(true);

	songImage.loadFromFile("Assets/button/b_song.png");
	songImage.createMaskFromColor(sf::Color(0, 162, 232));
	songTexture.loadFromImage(songImage);
	songTexture.setSmooth(true);
	song.setTexture(songTexture);

	songImage_s.loadFromFile("Assets/button/b_song_selected.png");
	songImage_s.createMaskFromColor(sf::Color(0, 162, 232));
	songTexture_s.loadFromImage(songImage_s);
	songTexture_s.setSmooth(true);

	startImage.loadFromFile("Assets/button/b_start.png");
	startImage.createMaskFromColor(sf::Color::Black);
	startTexture.loadFromImage(startImage);
	startTexture.setSmooth(true);
	start.setTexture(startTexture);

	startImage_s.loadFromFile("Assets/button/b_start_selected.png");
	startImage_s.createMaskFromColor(sf::Color::Black);
	startTexture_s.loadFromImage(startImage_s);
	startTexture_s.setSmooth(true);

	modeImage.loadFromFile("Assets/button/b_mode.png");
	modeImage.createMaskFromColor(sf::Color(0, 162, 232));
	modeTexture.loadFromImage(modeImage);
	modeTexture.setSmooth(true);
	mode.setTexture(modeTexture);

	modeImage_s.loadFromFile("Assets/button/b_mode_selected.png");
	modeImage_s.createMaskFromColor(sf::Color(0, 162, 232));
	modeTexture_s.loadFromImage(modeImage_s);
	modeTexture_s.setSmooth(true);

	songimgingame.setPosition(0,0);

	leaderboard.setScale(0.9f, 0.9f);
	location.setScale(0.9f, 0.9f);
	vehicle.setScale(0.9f, 0.9f);
	credit.setScale(0.9f, 0.9f);
	exit.setScale(0.9f, 0.9f);
	mode.setScale(0.9f, 0.9f);
	song.setScale(0.9f, 0.9f);
	start.setScale(0.9f, 0.9f);

	//future theme related
	futureTexture.loadFromFile("Assets/map/future.png");
	futureTexture.setSmooth(true);

	future1Texture.loadFromFile("Assets/map/future1.png");
	future1Texture.setSmooth(true);

	futuredualTexture.loadFromFile("Assets/map/future_dual.png");
	futuredualTexture.setSmooth(true);

	futuredual1Texture.loadFromFile("Assets/map/future_dual1.png");
	futuredual1Texture.setSmooth(true);

	//city theme related
	cityTexture.loadFromFile("Assets/map/city.png");
	cityTexture.setSmooth(true);

	city1Texture.loadFromFile("Assets/map/city1.png");
	city1Texture.setSmooth(true);

	citydualTexture.loadFromFile("Assets/map/city_dual.png");
	citydualTexture.setSmooth(true);

	citydual1Texture.loadFromFile("Assets/map/city_dual1.png");
	citydual1Texture.setSmooth(true);

	cbarrierImage.loadFromFile("Assets/barrier/general_barrier.png");
	cbarrierImage.createMaskFromColor(sf::Color::White);
	cbarrierTexture.loadFromImage(cbarrierImage);
	cbarrierTexture.setSmooth(true);
	cb.setTexture(cbarrierTexture);

	//desert theme related
	desertTexture.loadFromFile("Assets/map/desert.png");
	desertTexture.setSmooth(true);

	desert1Texture.loadFromFile("Assets/map/desert1.png");
	desert1Texture.setSmooth(true);

	desertdualTexture.loadFromFile("Assets/map/desert_dual.png");
	desertdualTexture.setSmooth(true);

	desertdual1Texture.loadFromFile("Assets/map/desert_dual1.png");
	desertdual1Texture.setSmooth(true);

	//firn theme related
	firnTexture.loadFromFile("Assets/map/firn.png");
	firnTexture.setSmooth(true);

	firn1Texture.loadFromFile("Assets/map/firn1.png");
	firn1Texture.setSmooth(true);

	firndualTexture.loadFromFile("Assets/map/firn_dual.png");
	firndualTexture.setSmooth(true);

	firndual1Texture.loadFromFile("Assets/map/firn_dual1.png");
	firndual1Texture.setSmooth(true);

	//island theme related
	islandTexture.loadFromFile("Assets/map/island.png");
	islandTexture.setSmooth(true);

	island1Texture.loadFromFile("Assets/map/island1.png");
	island1Texture.setSmooth(true);

	islanddualTexture.loadFromFile("Assets/map/island_dual.png");
	islanddualTexture.setSmooth(true);

	islanddual1Texture.loadFromFile("Assets/map/island_dual1.png");
	islanddual1Texture.setSmooth(true);

	//player realted
	taxiTexture.loadFromFile("Assets/car/taxi.png");
	taxiTexture.setSmooth(true);

	p911Texture.loadFromFile("Assets/car/p911.png");
	p911Texture.setSmooth(true);

	r8Texture.loadFromFile("Assets/car/r8.png");
	r8Texture.setSmooth(true);

	policeTexture.loadFromFile("Assets/car/police.png");
	policeTexture.setSmooth(true);

	pickupTexture.loadFromFile("Assets/car/pickup.png");
	pickupTexture.setSmooth(true);

	minivanTexture.loadFromFile("Assets/car/minivan.png");
	minivanTexture.setSmooth(true);

	sportcarTexture.loadFromFile("Assets/car/sportcar.png");
	sportcarTexture.setSmooth(true);

	truckTexture.loadFromFile("Assets/car/truck.png");
	truckTexture.setSmooth(true);

	ambulanceTexture.loadFromFile("Assets/car/ambulance.png");
	ambulanceTexture.setSmooth(true);

	player.setTexture(r8Texture);
	player2.setTexture(r8Texture);

	player.setScale(0.5f, 0.5f);
	player2.setScale(0.5f, 0.5f);

	chasingcarsTexture.loadFromFile("Assets/song/artwork/chasingcars.png");
	chasingcarsTexture.setSmooth(true);

	comeoutoftheshadeTexture.loadFromFile("Assets/song/artwork/comeoutoftheshade.png");
	comeoutoftheshadeTexture.setSmooth(true);

	safeandsoundTexture.loadFromFile("Assets/song/artwork/safeandsound.png");
	safeandsoundTexture.setSmooth(true);

	castawayTexture.loadFromFile("Assets/song/artwork/castaway.png");
	castawayTexture.setSmooth(true);

	animalTexture.loadFromFile("Assets/song/artwork/animal.png");
	animalTexture.setSmooth(true);

	carriedawayTexture.loadFromFile("Assets/song/artwork/carriedaway.png");
	carriedawayTexture.setSmooth(true);

	voteTexture.loadFromFile("Assets/song/artwork/vote.png");
	voteTexture.setSmooth(true);

	songimg.setPosition(200, 200);
	songimg.setScale(0.5f, 0.5f);

	//audio related
	//music related
	tunersong.openFromFile("Assets/testdrive/tunersong.ogg");
	titlebgm.openFromFile("Assets/bgm/title_notfinished.ogg");
	chasingcarspre.openFromFile("Assets/song/preview/chasingcarspre.ogg");
	comeoutoftheshadepre.openFromFile("Assets/song/preview/comeoutoftheshadepre.ogg");
	chasingcars.openFromFile("Assets/song/ogg/chasingcars.ogg");
	comeoutoftheshade.openFromFile("Assets/song/ogg/comeoutoftheshade.ogg");
	castawaypre.openFromFile("Assets/song/preview/castawaypre.ogg");
	castaway.openFromFile("Assets/song/ogg/castaway.ogg");
	safeandsoundpre.openFromFile("Assets/song/preview/safeandsoundpre.ogg");
	safeandsound.openFromFile("Assets/song/ogg/safeandsound.ogg");
	animalpre.openFromFile("Assets/song/preview/animalpre.ogg");
	animal.openFromFile("Assets/song/ogg/animal.ogg");
	carriedawaypre.openFromFile("Assets/song/preview/carriedawaypre.ogg");
	carriedaway.openFromFile("Assets/song/ogg/carriedaway.ogg");
	votepre.openFromFile("Assets/song/preview/votepre.ogg");
	vote.openFromFile("Assets/song/ogg/vote.ogg");
	tunersong.setLoop(false);
	titlebgm.setLoop(true);
	chasingcarspre.setLoop(true);
	castawaypre.setLoop(true);
	votepre.setLoop(true);
	carriedawaypre.setLoop(true);
	safeandsoundpre.setLoop(true);
	comeoutoftheshadepre.setLoop(true);
	chasingcars.setLoop(false);
	comeoutoftheshade.setLoop(false);
	castaway.setLoop(false);
	safeandsound.setLoop(false);
	animal.setLoop(false);
	carriedaway.setLoop(false);
	vote.setLoop(false);
	titlebgm.play();

	//sound related
	pressbuffer.loadFromFile("Assets/sfx/button_pressed.wav");
	destorybuffer.loadFromFile("Assets/sfx/barrier_destoryed.wav");
	shieldonbuffer.loadFromFile("Assets/sfx/shield_on.wav");
	itemusedbuffer.loadFromFile("Assets/sfx/item_used.wav");
	itempickupbuffer.loadFromFile("Assets/sfx/item_picked.wav");
	missleincomingbuffer.loadFromFile("Assets/sfx/missle_incoming.wav");
	barrierexplodedbuffer.loadFromFile("Assets/sfx/barrier_exploded.wav");
	missleincoming.setBuffer(missleincomingbuffer);
	barrierexploded.setBuffer(barrierexplodedbuffer);
	presssound.setBuffer(pressbuffer);
	destorysound.setBuffer(destorybuffer);
	shieldonsound.setBuffer(shieldonbuffer);
	itemusedsound.setBuffer(itemusedbuffer);
	itempickupsound.setBuffer(itempickupbuffer);
	//not applied yet

	//item related
	//set item icon
	shieldiv.loadFromFile("Assets/item/icon/shield.png");
	shieldiv.setSmooth(true);
	shield.setTexture(shieldiv);
	shield.setPosition(0, 700);
	shield2.setTexture(shieldiv);
	shield2.setPosition(940, 700);

	invisibleTexture.loadFromFile("Assets/item/icon/invisible.png");
	invisibleTexture.setSmooth(true);
	invisible.setTexture(invisibleTexture);
	invisible.setPosition(0, 700);
	invisible2.setTexture(invisibleTexture);
	invisible2.setPosition(940, 700);

	reverseImage.loadFromFile("Assets/item/icon/reverse.png");
	reverseImage.createMaskFromColor(sf::Color::White);
	reverseTexture.loadFromImage(reverseImage);
	reverseTexture.setSmooth(true);
	reverse.setTexture(reverseTexture);
	reverse.setPosition(0, 700);
	reverse2.setTexture(reverseTexture);
	reverse2.setPosition(940, 700);

	bombImage.loadFromFile("Assets/item/icon/bomb.png");
	bombImage.createMaskFromColor(sf::Color::White);
	bombTexture.loadFromImage(bombImage);
	bombTexture.setSmooth(true);
	bomb.setTexture(bombTexture);
	bomb.setPosition(0, 700);
	bomb2.setTexture(bombTexture);
	bomb2.setPosition(940, 700);

	missleImage.loadFromFile("Assets/item/icon/missle.png");
	missleImage.createMaskFromColor(sf::Color::White);
	missleTexture.loadFromImage(missleImage);
	missleTexture.setSmooth(true);
	missle.setTexture(missleTexture);
	missle.setPosition(0, 700);
	missle2.setTexture(missleTexture);
	missle2.setPosition(940, 700);

	//set item on the road
	items.loadFromFile("Assets/item/itemrd.png");
	items.createMaskFromColor(sf::Color::White);
	itemTexture.loadFromImage(items);
	itemTexture.setSmooth(true);
	item.setTexture(itemTexture);

	//set item effect
	shieldeffect.loadFromFile("Assets/item/effect/shield_on.png");
	shieldeffect.createMaskFromColor(sf::Color::White);
	shieldeffectTexture.loadFromImage(shieldeffect);
	shieldeffectTexture.setSmooth(true);

	missleeffectTexture.loadFromFile("Assets/item/effect/missle_on.png");
	missleeffectTexture.setSmooth(true);

	bombeffectTexture.loadFromFile("Assets/item/effect/bomb_on.png");
	bombeffectTexture.setSmooth(true);

	//reverseeffectTexture.loadFromFile("Assets/item/effect/reverse_on.png");
	//reverseeffectTexture.setSmooth(true);

	invisibleeffectTexture.loadFromFile("Assets/item/effect/invisible_on.png");
	invisibleeffectTexture.setSmooth(true);

	test1Texture.loadFromFile("Assets/car/r8.png");
	test1Texture.setSmooth(true);
	test1.setTexture(test1Texture);
	test1.setScale(0.5f,0.5f);
	test2Texture.loadFromFile("Assets/car/p911.png");
	test2Texture.setSmooth(true);
	test2.setTexture(test2Texture);
	test2.setScale(0.5f, 0.5f);
	test3Texture.loadFromFile("Assets/car/sportcar.png");
	test3Texture.setSmooth(true);
	test3.setTexture(test3Texture);
	test3.setScale(0.5f, 0.5f);
	test4Texture.loadFromFile("Assets/car/taxi.png");
	test4Texture.setSmooth(true);
	test4.setTexture(test4Texture);
	test4.setScale(0.5f, 0.5f);
	test5Texture.loadFromFile("Assets/car/pickup.png");
	test5Texture.setSmooth(true);
	test5.setTexture(test5Texture);
	test5.setScale(0.5f, 0.5f);
	test6Texture.loadFromFile("Assets/car/minivan.png");
	test6Texture.setSmooth(true);
	test6.setTexture(test6Texture);
	test6.setScale(0.5f, 0.5f);
	test7Texture.loadFromFile("Assets/car/ambulance.png");
	test7Texture.setSmooth(true);
	test7.setTexture(test7Texture);
	test7.setScale(0.5f, 0.5f);
	test8Texture.loadFromFile("Assets/car/police.png");
	test8Texture.setSmooth(true);
	test8.setTexture(test8Texture);
	test8.setScale(0.5f, 0.5f);
	test9Texture.loadFromFile("Assets/car/truck.png");
	test9Texture.setSmooth(true);
	test9.setTexture(test9Texture);
	test9.setScale(0.5f, 0.5f);

	model->crosshairTexture.loadFromFile("Assets/testdrive/crosshair.png");
	model->crosshairTexture.setSmooth(true);
	model->crosshair.setTexture(model->crosshairTexture);
	model->crosshair.setOrigin(156,156);
	model->crosshair.setScale(0.2f, 0.2f);
}

View::~View()
{ }

void View::replay() {
	if (model->gameState == 3 || model->gameState == 4) {
		model->totalbarriers = 16;
		model->songspeed = (277.5 + 10)*2 + 10;
		model->fallposy2 = 0;
		model->fallposy = 0;
	}
	if (model->isDual == 0) {
		cbs.erase(cbs.begin(), cbs.end());
		for (int i = 0; i < model->totalbarriers; i++) {
			cbs.push_back(cb);
		}
	}
	if (model->isDual == 1) {
		cbs.erase(cbs.begin(), cbs.end());
		cbs2.erase(cbs2.begin(), cbs2.end());
		for (int i = 0; i < model->totalbarriers; i++) {
			if (i % 40 == 0){
				cbs.push_back(item);
			}
			else {
				cbs.push_back(cb);
			}

		}
		
		for (int j = 0; j < model->totalbarriers; j++) {
			if (j % 40 == 0) {
				cbs2.push_back(item);
			}
			else {
				cbs2.push_back(cb);
			}
		}
	}

	itemdes.setString("");
	itemdes2.setString("");

	itemconfirm = 0;
	itemconfirm2 = 0;

	//tempSprite.setTexture(*player.getTexture());
	//tempSprite2.setTexture(*player2.getTexture());

	//player.setTexture(*tempSprite.getTexture());
	//player2.setTexture(*tempSprite2.getTexture());

	active = 300*model->mspeed;
	active2 = 300*model->mspeed;
	
	record_i = -1;
	record_i2 = -1;

	transcolor = 0;
	transcolor2 = 0;
	transcolor3 = 0;

	itemeffect.setTexture(transparentTexture);
	itemeffect2.setTexture(transparentTexture);
	player.setTexture(*tempSprite.getTexture());
	player2.setTexture(*tempSprite.getTexture());

	model->reset();
}

void View::render()
{
	window.setSize(sf::Vector2u(swidth, sheight));

	window.clear();

	finalscore.setFont(font);
	finalscorep1.setFont(font);
	finalscorep2.setFont(font);
	finalscorep1.setPosition(sf::Vector2f(swidth / 2 - 200, 235));
	finalscorep2.setPosition(sf::Vector2f(swidth / 2 - 200, 325));
	finalscore.setPosition(sf::Vector2f(swidth / 2 - 200, 200));
	finalscore.setCharacterSize(30);
	finalscore.setColor(sf::Color(0, 162, 232));
	finalscorep1.setCharacterSize(30);
	finalscorep2.setCharacterSize(30);
	winner.setPosition(sf::Vector2f(swidth/2 - 200, 400));
	scoreplate.setSize(sf::Vector2f(swidth - 100, sheight - 100));

	if (model->gamestart == 1 && model->gameState != 3 && model->gameState != 4) {
		model->score = model->score + 1;
		if (model->isDual == 1) {
			model->score2 = model->score2 + 1;
		}
	}

	bg.setPosition(0, model->mapy);
	bg1.setPosition(0, model->mapyy);
	dbg.setPosition(0, model->mapy);
	dbg1.setPosition(0, model->mapyy);
	cbg.setPosition(0, model->mapy);
	cbg1.setPosition(0, model->mapyy);

	headingplate.setSize(sf::Vector2f(swidth, 140));
	bottomplate.setSize(sf::Vector2f(swidth, 100));
	
	if (model->songselected == 0 && model->gameState == 2) {
		songinfo.setString("Now Playing:\nChasing Cars\nSnow Patrol");
		songimgingame.setScale(0.2f, 0.2f);
		
	}
	if (model->songselected == 1 && model->gameState == 2) {
		songinfo.setString("Now Playing:\nCome Out Of The Shade\nThe Perishers");
		songimgingame.setScale(0.2f, 0.2f);
	}
	if (model->songselected == 2 && model->gameState == 2) {
		songinfo.setString("Now Playing:\nCastaway\nStrange Talk");
		songimgingame.setScale(0.2f, 0.2f);
	}
	if (model->songselected == 3 && model->gameState == 2) {
		songinfo.setString("Now Playing:\nSafe and Sound\nCapital Cities");
		songimgingame.setScale(0.2f, 0.2f);
	}
	if (model->songselected == 4 && model->gameState == 2) {
		songinfo.setString("Now Playing:\nanimal\nneon trees");
		songimgingame.setScale(0.2f, 0.2f);
	}
	if (model->songselected == 5 && model->gameState == 2) {
		songinfo.setString("Now Playing:\ncarried away\npassion pit");
		songimgingame.setScale(0.2f, 0.2f);
	}
	if (model->songselected == 6 && model->gameState == 2) {
		songinfo.setString("Now Playing:\nvote\nthe submarines");
		songimgingame.setScale(0.2f, 0.2f);
	}

	if ((model->isDual == 1 && model->gameState == 2) || (model->modeselected == 1 && model->menuLayer == 4)) {
		window.draw(dbg);
		window.draw(dbg1);
		player2.setPosition(model->p2posx, model->p2posy);
	}
	
	if (!((model->isDual == 1 && model->gameState == 2) || (model->modeselected == 1 && model->menuLayer == 4)) && !(model->menuLayer == 5 && model->gameState == 1)) {
		window.draw(bg);
		window.draw(bg1);
	}

	if (model->gameState == 1) {
		player.setPosition(model->pposx, model->pposy);
	}

	if (model->isDual == 1 && model->gameState == 2) {
		player.setPosition(model->ppposx, model->ppposy);
		
		comboinfo.setPosition(swidth / 4 -50, 150);
		comboinfo2.setPosition(swidth / 4 * 3-120, 150);
	}
	if (model->isDual == 0 && model->gameState == 2) {
		player.setPosition(model->pposx, model->pposy);
		comboinfo.setPosition(swidth / 2 - 100, 100);
	}

	if (model->menuLayer == 5 && model->gameState == 1) {
		window.draw(cbg);
		window.draw(cbg1);
	}

	if (model->gameState == 4){
		cardes.setString("press enter to exit test drive");
		backscroll += model->mspeed;
		tbg.setPosition(0, model->mapy);
		tbg1.setPosition(0, model->mapyy);
		
		if (testcarselected == 1) {
			model->mspeed = 10;
			test1.setPosition(test1x,600);
			test2.setPosition(233, 600 + backscroll);
			test3.setPosition(307, 600 + backscroll);
			test4.setPosition(377, 600 + backscroll);
			test5.setPosition(453, 600 + backscroll);
			test6.setPosition(523, 600 + backscroll);
			test7.setPosition(593, 600 + backscroll);
			test8.setPosition(667, 600 + backscroll);
			test9.setPosition(740, 600 + backscroll);
		}
		if (testcarselected == 2) {
			model->mspeed = 10;
			
			test2.setPosition(test2x, 600);
			test1.setPosition(163, 600 + backscroll);
			test3.setPosition(307, 600 + backscroll);
			test4.setPosition(377, 600 + backscroll);
			test5.setPosition(453, 600 + backscroll);
			test6.setPosition(523, 600 + backscroll);
			test7.setPosition(593, 600 + backscroll);
			test8.setPosition(667, 600 + backscroll);
			test9.setPosition(740, 600 + backscroll);
		}
		if (testcarselected == 3) {
			model->mspeed = 20;
			test3.setPosition(test3x, 600);
			test1.setPosition(163, 600 + backscroll);
			test2.setPosition(233, 600 + backscroll);
			test4.setPosition(377, 600 + backscroll);
			test5.setPosition(453, 600 + backscroll);
			test6.setPosition(523, 600 + backscroll);
			test7.setPosition(593, 600 + backscroll);
			test8.setPosition(667, 600 + backscroll);
			test9.setPosition(740, 600 + backscroll);
		}
		if (testcarselected == 4) {
			model->mspeed = 15;
			test4.setPosition(test4x, 600);
			test1.setPosition(163, 600 + backscroll);
			test2.setPosition(233, 600 + backscroll);
			test3.setPosition(307, 600 + backscroll);
			test5.setPosition(453, 600 + backscroll);
			test6.setPosition(523, 600 + backscroll);
			test7.setPosition(593, 600 + backscroll);
			test8.setPosition(667, 600 + backscroll);
			test9.setPosition(740, 600 + backscroll);
		}
		if (testcarselected == 5) {
			model->mspeed = 8;
			test5.setPosition(test5x, 600);
			test1.setPosition(163, 600 + backscroll);
			test2.setPosition(233, 600 + backscroll);
			test3.setPosition(307, 600 + backscroll);
			test4.setPosition(377, 600 + backscroll);
			test6.setPosition(523, 600 + backscroll);
			test7.setPosition(593, 600 + backscroll);
			test8.setPosition(667, 600 + backscroll);
			test9.setPosition(740, 600 + backscroll);
		}
		if (testcarselected == 6) {
			model->mspeed = 5;
			test6.setPosition(test6x, 600);
			test1.setPosition(163, 600 + backscroll);
			test2.setPosition(233, 600 + backscroll);
			test3.setPosition(307, 600 + backscroll);
			test4.setPosition(377, 600 + backscroll);
			test5.setPosition(453, 600 + backscroll);
			test7.setPosition(593, 600 + backscroll);
			test8.setPosition(667, 600 + backscroll);
			test9.setPosition(740, 600 + backscroll);
		}
		if (testcarselected == 7) {
			model->mspeed = 30;
			test7.setPosition(test7x, 600);
			test1.setPosition(163, 600 + backscroll);
			test2.setPosition(233, 600 + backscroll);
			test3.setPosition(307, 600 + backscroll);
			test4.setPosition(377, 600 + backscroll);
			test5.setPosition(453, 600 + backscroll);
			test6.setPosition(523, 600 + backscroll);
			test8.setPosition(667, 600 + backscroll);
			test9.setPosition(740, 600 + backscroll);
		}
		if (testcarselected == 8) {
			model->mspeed = 40;
			test8.setPosition(test8x, 600);
			test1.setPosition(163, 600 + backscroll);
			test2.setPosition(233, 600 + backscroll);
			test3.setPosition(307, 600 + backscroll);
			test4.setPosition(377, 600 + backscroll);
			test5.setPosition(453, 600 + backscroll);
			test6.setPosition(523, 600 + backscroll);
			test7.setPosition(593, 600 + backscroll);
			test9.setPosition(740, 600 + backscroll);
		}
		if (testcarselected == 9) {
			model->mspeed = 3;
			test9.setPosition(test9x, 600);
			test1.setPosition(163, 600 + backscroll);
			test2.setPosition(233, 600 + backscroll);
			test3.setPosition(307, 600 + backscroll);
			test4.setPosition(377, 600 + backscroll);
			test5.setPosition(453, 600 + backscroll);
			test6.setPosition(523, 600 + backscroll);
			test7.setPosition(593, 600 + backscroll);
			test8.setPosition(667, 600 + backscroll);
		}
		window.draw(tbg);
		window.draw(tbg1);
		window.draw(test1);
		window.draw(test2);
		window.draw(test3);
		window.draw(test4);
		window.draw(test5);
		window.draw(test6);
		window.draw(test7);
		window.draw(test8);
		window.draw(test9);
		window.draw(headingplate);
		window.draw(heading);
		window.draw(cardes);
		for (int j = 0; j < cbs.size(); j += 1) {
			cbs[j].setPosition(model->rngxv[j], model->fallpos[j]);
			window.draw(cbs[j]);
		}

		for (int i = 0; i < cbs.size(); i++) {
			model->fallpos[i] = model->fallpos[i] + model->mspeed;
		}
	}

	if (model->gameState == 3) {
			heading.setString("test drive");
			cardes.setString("arrow keys to move the indicator");
			confirm.setString("backspace to go back");
			tbg.setPosition(0, 0);
			tbg1.setPosition(0, -866);
			test1.setPosition(163, 600);
			test2.setPosition(233, 600);
			test3.setPosition(307, 600);
			test4.setPosition(377, 600);
			test5.setPosition(453, 600);
			test6.setPosition(523, 600);
			test7.setPosition(593, 600);
			test8.setPosition(667, 600);
			test9.setPosition(740, 600);
			window.draw(tbg);
			window.draw(tbg1);
			window.draw(test1);
			window.draw(test2);
			window.draw(test3);
			window.draw(test4);
			window.draw(test5);
			window.draw(test6);
			window.draw(test7);
			window.draw(test8);
			window.draw(test9);
			window.draw(model->crosshair);
			window.draw(headingplate);
			window.draw(heading);
			window.draw(cardes);
			window.draw(bottomplate);
			window.draw(confirm);
			if (model->crosshair.getPosition().x > 193 && model->crosshair.getPosition().x < 243 && model->crosshair.getPosition().y > 600 && model->crosshair.getPosition().y < 715) {
				model->crosshair.setScale(model->zoomx, model->zoomy);
				window.draw(model->crosshairplate);
				window.draw(model->crosshairtext);
				model->songspeedrate = 1;
				testcarselected = 1;
				model->currentxl = 168;
				model->currentxr = 243;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
					model->gameState = 4;
					replay();
					titlebgm.pause();
					model->switcher = 1;
				}
			}
			if (model->crosshair.getPosition().x > 263 && model->crosshair.getPosition().x < 313 && model->crosshair.getPosition().y > 600 && model->crosshair.getPosition().y < 715) {
				model->crosshair.setScale(model->zoomx, model->zoomy);
				window.draw(model->crosshairplate);
				window.draw(model->crosshairtext);
				model->songspeedrate = 1;
				testcarselected = 2;
				model->currentxl = 238;
				model->currentxr = 313;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
					model->gameState = 4;
					replay();
					titlebgm.pause();
					model->switcher = 1;
				}
			}
			if (model->crosshair.getPosition().x > 337 && model->crosshair.getPosition().x < 387 && model->crosshair.getPosition().y > 600 && model->crosshair.getPosition().y < 715) {
				model->crosshair.setScale(model->zoomx, model->zoomy);
				window.draw(model->crosshairplate);
				window.draw(model->crosshairtext);
				model->songspeedrate = 2;
				testcarselected = 3;
				model->currentxl = 312;
				model->currentxr = 387;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
					model->gameState = 4;
					replay();
					titlebgm.pause();
					model->switcher = 1;
				}
			}
			if (model->crosshair.getPosition().x > 407 && model->crosshair.getPosition().x < 457 && model->crosshair.getPosition().y > 600 && model->crosshair.getPosition().y < 715) {
				model->crosshair.setScale(model->zoomx, model->zoomy);
				window.draw(model->crosshairplate);
				window.draw(model->crosshairtext);
				model->songspeedrate = 1.5;
				testcarselected = 4;
				model->currentxl = 382;
				model->currentxr = 457;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
					model->gameState = 4;
					replay();
					titlebgm.pause();
					model->switcher = 1;
				}
			}
			if (model->crosshair.getPosition().x > 483 && model->crosshair.getPosition().x < 533 && model->crosshair.getPosition().y > 600 && model->crosshair.getPosition().y < 715) {
				model->crosshair.setScale(model->zoomx, model->zoomy);
				window.draw(model->crosshairplate);
				window.draw(model->crosshairtext);
				model->songspeedrate = 0.8;
				testcarselected = 5;
				model->currentxl = 458;
				model->currentxr = 533;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
					model->gameState = 4;
					replay();
					titlebgm.pause();
					model->switcher = 1;
				}
			}
			if (model->crosshair.getPosition().x > 553 && model->crosshair.getPosition().x < 603 && model->crosshair.getPosition().y > 600 && model->crosshair.getPosition().y < 715) {
				model->crosshair.setScale(model->zoomx, model->zoomy);
				window.draw(model->crosshairplate);
				window.draw(model->crosshairtext);
				model->songspeedrate = 0.5;
				testcarselected = 6;
				model->currentxl = 528;
				model->currentxr = 603;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
					model->gameState = 4;
					replay();
					titlebgm.pause();
					model->switcher = 1;
				}
			}
			if (model->crosshair.getPosition().x > 623 && model->crosshair.getPosition().x < 673 && model->crosshair.getPosition().y > 600 && model->crosshair.getPosition().y < 715) {
				model->crosshair.setScale(model->zoomx, model->zoomy);
				window.draw(model->crosshairplate);
				window.draw(model->crosshairtext);
				model->songspeedrate = 3;
				testcarselected = 7;
				model->currentxl = 598;
				model->currentxr = 673;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
					model->gameState = 4;
					replay();
					titlebgm.pause();
					model->switcher = 1;
				}
			}
			if (model->crosshair.getPosition().x > 697 && model->crosshair.getPosition().x < 747 && model->crosshair.getPosition().y > 600 && model->crosshair.getPosition().y < 715) {
				model->crosshair.setScale(model->zoomx, model->zoomy);
				window.draw(model->crosshairplate);
				window.draw(model->crosshairtext);
				model->songspeedrate = 4;
				testcarselected = 8;
				model->currentxl = 672;
				model->currentxr = 747;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
					model->gameState = 4;
					replay();
					titlebgm.pause();
					model->switcher = 1;
				}
			}
			if (model->crosshair.getPosition().x > 770 && model->crosshair.getPosition().x < 820 && model->crosshair.getPosition().y > 600 && model->crosshair.getPosition().y < 715) {
				model->crosshair.setScale(model->zoomx, model->zoomy);
				window.draw(model->crosshairplate);
				window.draw(model->crosshairtext);
				testcarselected = 9;
				model->songspeedrate = 0.3;
				model->currentxl = 745;
				model->currentxr = 820;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
					model->gameState = 4;
					replay();
					titlebgm.pause();
					model->switcher = 1;
				}
			}
	}

	title.setPosition(model->titlepos, 100);
	
	exit.setPosition(model->buttonpos7, 770);
	credit.setPosition(model->buttonpos6, 710);
	leaderboard.setPosition(model->buttonpos5, 650);
	location.setPosition(model->buttonpos4, 590);
	song.setPosition(model->buttonpos3, 530);
	vehicle.setPosition(model->buttonpos2, 470);
	mode.setPosition(model->buttonpos1, 410);
	start.setPosition(model->buttonpos, 350);

	if (model->gameState == 1) {

		if (model->menuLayer == 0) {

			if (model->buttonselected == 1) {
				mode.setTexture(modeTexture_s);
				vehicle.setTexture(vehicleTexture);
				song.setTexture(songTexture);
				location.setTexture(locationTexture);
				leaderboard.setTexture(leaderboardTexture);
				credit.setTexture(creditTexture);
				exit.setTexture(exitTexture);
				start.setTexture(startTexture);
				model->buttonlock = 0;
				model->buttonlock1 = 1;
				model->buttonlock2 = 0;
				model->buttonlock3 = 0;
				model->buttonlock4 = 0;
				model->buttonlock5 = 0;
				model->buttonlock6 = 0;
				model->buttonlock7 = 0;
			}
			if (model->buttonselected == 2) {
				mode.setTexture(modeTexture);
				vehicle.setTexture(vehicleTexture_s);
				song.setTexture(songTexture);
				location.setTexture(locationTexture);
				leaderboard.setTexture(leaderboardTexture);
				credit.setTexture(creditTexture);
				exit.setTexture(exitTexture);
				start.setTexture(startTexture);
				model->buttonlock = 0;
				model->buttonlock1 = 0;
				model->buttonlock2 = 1;
				model->buttonlock3 = 0;
				model->buttonlock4 = 0;
				model->buttonlock5 = 0;
				model->buttonlock6 = 0;
				model->buttonlock7 = 0;
			}
			if (model->buttonselected == 3) {
				mode.setTexture(modeTexture);
				vehicle.setTexture(vehicleTexture);
				song.setTexture(songTexture_s);
				location.setTexture(locationTexture);
				leaderboard.setTexture(leaderboardTexture);
				credit.setTexture(creditTexture);
				exit.setTexture(exitTexture);
				start.setTexture(startTexture);
				model->buttonlock = 0;
				model->buttonlock1 = 0;
				model->buttonlock2 = 0;
				model->buttonlock3 = 1;
				model->buttonlock4 = 0;
				model->buttonlock5 = 0;
				model->buttonlock6 = 0;
				model->buttonlock7 = 0;
			}
			if (model->buttonselected == 4) {
				mode.setTexture(modeTexture);
				vehicle.setTexture(vehicleTexture);
				song.setTexture(songTexture);
				location.setTexture(locationTexture_s);
				leaderboard.setTexture(leaderboardTexture);
				credit.setTexture(creditTexture);
				exit.setTexture(exitTexture);
				start.setTexture(startTexture);
				model->buttonlock = 0;
				model->buttonlock1 = 0;
				model->buttonlock2 = 0;
				model->buttonlock3 = 0;
				model->buttonlock4 = 1;
				model->buttonlock5 = 0;
				model->buttonlock6 = 0;
				model->buttonlock7 = 0;
			}
			if (model->buttonselected == 5) {
				mode.setTexture(modeTexture);
				vehicle.setTexture(vehicleTexture);
				song.setTexture(songTexture);
				location.setTexture(locationTexture);
				leaderboard.setTexture(leaderboardTexture_s);
				credit.setTexture(creditTexture);
				exit.setTexture(exitTexture);
				start.setTexture(startTexture);
				model->buttonlock = 0;
				model->buttonlock1 = 0;
				model->buttonlock2 = 0;
				model->buttonlock3 = 0;
				model->buttonlock4 = 0;
				model->buttonlock5 = 1;
				model->buttonlock6 = 0;
				model->buttonlock7 = 0;
			}
			if (model->buttonselected == 6) {
				mode.setTexture(modeTexture);
				vehicle.setTexture(vehicleTexture);
				song.setTexture(songTexture);
				location.setTexture(locationTexture);
				leaderboard.setTexture(leaderboardTexture);
				credit.setTexture(creditTexture_s);
				exit.setTexture(exitTexture);
				start.setTexture(startTexture);
				model->buttonlock = 0;
				model->buttonlock1 = 0;
				model->buttonlock2 = 0;
				model->buttonlock3 = 0;
				model->buttonlock4 = 0;
				model->buttonlock5 = 0;
				model->buttonlock6 = 1;
				model->buttonlock7 = 0;
			}
			if (model->buttonselected == 0) {
				mode.setTexture(modeTexture);
				vehicle.setTexture(vehicleTexture);
				song.setTexture(songTexture);
				location.setTexture(locationTexture);
				leaderboard.setTexture(leaderboardTexture);
				credit.setTexture(creditTexture);
				exit.setTexture(exitTexture);
				start.setTexture(startTexture_s);
				model->buttonlock = model->buttonlocko;
				model->buttonlock1 = 0;
				model->buttonlock2 = 0;
				model->buttonlock3 = 0;
				model->buttonlock4 = 0;
				model->buttonlock5 = 0;
				model->buttonlock6 = 0;
				model->buttonlock7 = 0;
			}
			if (model->buttonselected == 7) {
				mode.setTexture(modeTexture);
				vehicle.setTexture(vehicleTexture);
				song.setTexture(songTexture);
				location.setTexture(locationTexture);
				leaderboard.setTexture(leaderboardTexture);
				credit.setTexture(creditTexture);
				exit.setTexture(exitTexture_s);
				start.setTexture(startTexture);
				model->buttonlock = 0;
				model->buttonlock1 = 0;
				model->buttonlock2 = 0;
				model->buttonlock3 = 0;
				model->buttonlock4 = 0;
				model->buttonlock5 = 0;
				model->buttonlock6 = 0;
				model->buttonlock7 = 1;
			}

			window.draw(title);
			window.draw(leaderboard);
			window.draw(mode);
			window.draw(song);
			window.draw(vehicle);
			window.draw(location);
			window.draw(credit);
			window.draw(exit);
			window.draw(start);
			//std::cout << "Button locko is:" << model->buttonlocko << std::endl;
		}

		if (model->menuLayer == 1) {
			//change cars will affect game speed, implied by increasing / decreasing frame limit from 30 to 120
			//either fast or slow speed will increase the gameplay difficulty, it's a rhythm based game, we prefer 1.0x speed (easy), not anything else
			//player.setPosition(200, model->pposy);
			if (model->carselected == 0) {
				player.setTexture(r8Texture);
				player2.setTexture(r8Texture);
				cardes.setString("audi r8");
				cardetail2.setString("1OO km/h\n\n\neasy\n\n\npress f");
				se.setString("");
				se1.setString("");
				model->mspeed = 10;
				model->songspeedrate = 1.0;
			}
			if (model->carselected == 1) {
				player.setTexture(p911Texture);
				player2.setTexture(p911Texture);
				cardes.setString("porsche 911");
				cardetail2.setString("1OO km/h\n\n\neasy\n\n\npress f");
				se.setString("");
				se1.setString("");
				model->mspeed = 10;
				model->songspeedrate = 1.0;
			}
			if (model->carselected == 2) {
				player.setTexture(sportcarTexture);
				player2.setTexture(sportcarTexture);
				cardes.setString("ford gt");
				cardetail2.setString("2OO km/h\n\n\nhard\n\n\npress f");
				se.setString("");
				se1.setString("");
				model->mspeed = 15;
				model->songspeedrate = 1.5;
			}
			if (model->carselected == 3) {
				player.setTexture(taxiTexture);
				player2.setTexture(taxiTexture);
				cardes.setString("ford stretch crown");
				se.setColor(sf::Color::Yellow);
				se.setPosition(25, 100);
				se.setString("taxi edition");
				se1.setString("");
				cardetail2.setString("15O km/h\n\n\nnormal\n\n\npress f");
				model->mspeed = 15;
				model->songspeedrate = 1.5;
			}
			if (model->carselected == 4) {
				player.setTexture(pickupTexture);
				player2.setTexture(pickupTexture);
				cardes.setString("chevy thunder");
				se.setString("");
				se1.setString("");
				cardetail2.setString("8O km/h\n\n\nnormal\n\n\npress f");
				model->mspeed = 8;
				model->songspeedrate = 0.8;
			}
			if (model->carselected == 5) {
				player.setTexture(minivanTexture);
				player2.setTexture(minivanTexture);
				cardes.setString("iveco daily");
				se.setString("");
				se1.setString("");
				cardetail2.setString("5O km/h\n\n\nhard\n\n\npress f");
				model->mspeed = 5;
				model->songspeedrate = 0.5;
			}
			if (model->carselected == 6) {
				player.setTexture(ambulanceTexture);
				player2.setTexture(ambulanceTexture);
				cardes.setString("iveco daily\n");
				se.setColor(sf::Color::White);
				se.setPosition(30, 100);
				se.setString("ambulance ");
				se1.setPosition(270, 100);
				se1.setColor(sf::Color::Red);
				se1.setString("edition");
				model->mspeed = 30;
				cardetail2.setString("3OO km/h\n\n\nnightmare\n\n\npress f");
				model->songspeedrate = 3.0;
			}
			if (model->carselected == 7) {
				player.setTexture(policeTexture);
				player2.setTexture(policeTexture);
				cardes.setString("AUDI R8\n");
				se.setColor(sf::Color::Red);
				se.setPosition(30, 100);
				se.setString("POLICE ");
				se1.setColor(sf::Color(0, 0, 255));
				se1.setPosition(170, 100);
				se1.setString("EDITION");
				cardetail2.setString("4OO km/h\n\n\ninferno\n\n\npress f");
				model->mspeed = 40;
				model->songspeedrate = 4.0;
			}
			if (model->carselected == 8) {
				player.setTexture(truckTexture);
				player2.setTexture(truckTexture);
				cardes.setString("peternilt 389");
				se.setString("");
				se1.setString("");
				cardetail2.setString("3O km/h\n\n\ninferno\n\n\npress f");
				model->mspeed = 3;
				model->songspeedrate = 0.3;
			}

			heading.setString("select vehicle");
			confirm.setString("backspace to confrim");
			next.setString(">>>");
			prev.setString("<<<");

			window.draw(headingplate);
			window.draw(bottomplate);
			window.draw(cardetailplate);
			window.draw(cardetail);
			window.draw(cardetail2);
			window.draw(heading);
			window.draw(cardes);
			window.draw(se);
			window.draw(se1);
			window.draw(confirm);
			window.draw(prev);
			window.draw(next);
		}
		if (model->menuLayer == 2) {
			if (model->mapselected == 0) {
				bg.setTexture(menubgTexture);
				bg1.setTexture(menubg1Texture);
				cardes.setString("void");
			}
			if (model->mapselected == 1) {
				bg.setTexture(cityTexture);
				bg1.setTexture(city1Texture);
				cardes.setString("city");
			}
			if (model->mapselected == 2) {
				bg.setTexture(desertTexture);
				bg1.setTexture(desert1Texture);
				cardes.setString("desert");
			}
			if (model->mapselected == 3) {
				bg.setTexture(firnTexture);
				bg1.setTexture(firn1Texture);
				cardes.setString("firn");
			}
			if (model->mapselected == 4) {
				bg.setTexture(islandTexture);
				bg1.setTexture(island1Texture);
				cardes.setString("island");
			}
			if (model->mapselected == 5) {
				bg.setTexture(futureTexture);
				bg1.setTexture(future1Texture);
				cardes.setString("future world");
			}

			heading.setString("select location");
			confirm.setString("backspace to confrim");
			next.setString(">>>");
			prev.setString("<<<");

			window.draw(headingplate);
			window.draw(bottomplate);
			window.draw(heading);
			window.draw(cardes);
			window.draw(confirm);
			window.draw(prev);
			window.draw(next);
		}

		if (model->menuLayer == 3) {
			titlebgm.pause();

			bg.setTexture(generalTexture);
			bg1.setTexture(general1Texture);

			if (model->songselected == 0) {
				songimg.setTexture(chasingcarsTexture);
				songimgingame.setTexture(chasingcarsTexture);
				cardes.setString("chasing cars\nsnow patrol");
				songdetail.setString("Length: 3:40'\n\ndifficulty: Easy");
			}
			if (model->songselected == 1) {
				songimg.setTexture(comeoutoftheshadeTexture);
				songimgingame.setTexture(comeoutoftheshadeTexture);
				cardes.setString("come out of the shade\nthe pershiers");
				songdetail.setString("Length: 3:45'\n\ndifficulty: Normal");
			}
			if (model->songselected == 2) {
				songimg.setTexture(castawayTexture);
				songimgingame.setTexture(castawayTexture);
				cardes.setString("castaway\nstrange talk");
				songdetail.setString("Length: 4:28'\n\ndifficulty: Normal");
			}
			if (model->songselected == 3) {
				songimg.setTexture(safeandsoundTexture);
				songimgingame.setTexture(safeandsoundTexture);
				cardes.setString("safe and sound\ncapital cities");
				songdetail.setString("Length: 3:13'\n\ndifficulty: Hard");
			}
			if (model->songselected == 4) {
				songimg.setTexture(animalTexture);
				songimgingame.setTexture(animalTexture);
				cardes.setString("animal\nneon trees");
				songdetail.setString("Length: 3:28'\n\ndifficulty:\n Extremely Hard");
			}
			if (model->songselected == 5) {
				songimg.setTexture(carriedawayTexture);
				songimgingame.setTexture(carriedawayTexture);
				cardes.setString("carried away\npassion pit");
				songdetail.setString("Length: 3:42'\n\ndifficulty: Hard");
			}
			if (model->songselected == 6) {
				songimg.setTexture(voteTexture);
				songimgingame.setTexture(voteTexture);
				cardes.setString("vote\nthe submarines");
				songdetail.setString("Length: 4:02'\n\ndifficulty: Easy");
			}

			heading.setString("select song");
			confirm.setString("backspace to confrim");
			next.setString(">>>");
			prev.setString("<<<");

			window.draw(headingplate);
			window.draw(bottomplate);
			window.draw(heading);
			window.draw(cardes);
			window.draw(confirm);
			window.draw(prev);
			window.draw(next);
			window.draw(songimg);
			window.draw(songdetail);
		}

		if (model->menuLayer == 4) {
			if (model->modeselected == 0) {
				swidth = 720;
				if (model->mapselected == 0) {
					bg.setTexture(menubgTexture);
					bg1.setTexture(menubg1Texture);
				}
				if (model->mapselected == 1) {
					bg.setTexture(cityTexture);
					bg1.setTexture(city1Texture);
				}
				if (model->mapselected == 2) {
					bg.setTexture(desertTexture);
					bg1.setTexture(desert1Texture);
				}
				if (model->mapselected == 3) {
					bg.setTexture(firnTexture);
					bg1.setTexture(firn1Texture);
				}
				if (model->mapselected == 4) {
					bg.setTexture(islandTexture);
					bg1.setTexture(island1Texture);
				}
				if (model->mapselected == 5) {
					bg.setTexture(futureTexture);
					bg1.setTexture(future1Texture);
				}
				cardes.setString("single player");
			}
			if (model->modeselected == 1) {
				swidth = 1024;
				player.setPosition(model->ppposx, model->ppposy);
				if (model->mapselected == 0) {
					dbg.setTexture(&menubgdualTexture);
					dbg1.setTexture(&menubgdual1Texture);
				}
				if (model->mapselected == 1) {
					dbg.setTexture(&citydualTexture);
					dbg1.setTexture(&citydual1Texture);
				}
				if (model->mapselected == 2) {
					dbg.setTexture(&desertdualTexture);
					dbg1.setTexture(&desertdual1Texture);
				}
				if (model->mapselected == 3) {
					dbg.setTexture(&firndualTexture);
					dbg1.setTexture(&firndual1Texture);
				}
				if (model->mapselected == 4) {
					dbg.setTexture(&islanddualTexture);
					dbg1.setTexture(&islanddual1Texture);
				}
				if (model->mapselected == 5) {
					dbg.setTexture(&futuredualTexture);
					dbg1.setTexture(&futuredual1Texture);
				}
				cardes.setString("split screen multiplayer");
			}

			heading.setString("SELECT MODE");
			confirm.setString("BACKSPACE TO CONFIRM");
			next.setString(">>>");
			prev.setString("<<<");

			window.draw(headingplate);
			window.draw(bottomplate);
			window.draw(heading);
			window.draw(cardes);
			window.draw(confirm);
			window.draw(prev);
			window.draw(next);
		}
		if (model->menuLayer == 5) {
			model->mspeed = -1;
		}
	}
	
	if (model->gameState == 2) {
		if (model->modeselected == 1) {
			swidth = 1024;
			player.setPosition(model->ppposx, model->ppposy);
			if (model->mapselected == 0) {
				dbg.setTexture(&menubgdualTexture);
				dbg1.setTexture(&menubgdual1Texture);
			}
			if (model->mapselected == 1) {
				dbg.setTexture(&citydualTexture);
				dbg1.setTexture(&citydual1Texture);
			}
			if (model->mapselected == 2) {
				dbg.setTexture(&desertdualTexture);
				dbg1.setTexture(&desertdual1Texture);
			}
			if (model->mapselected == 3) {
				dbg.setTexture(&firndualTexture);
				dbg1.setTexture(&firndual1Texture);
			}
			if (model->mapselected == 4) {
				dbg.setTexture(&islanddualTexture);
				dbg1.setTexture(&islanddual1Texture);
			}
			if (model->mapselected == 5) {
				dbg.setTexture(&futuredualTexture);
				dbg1.setTexture(&futuredual1Texture);
			}
			cardes.setString("split screen multiplayer");
		}
		//barrier position related

		if (model->isDual == 0) {
			for (int j = 0; j < cbs.size(); j += 1) {
				cbs[j].setPosition(model->rngxv[j], model->fallpos[j]);
				window.draw(cbs[j]);
			}

			for (int i = 0; i < cbs.size(); i++) {
				model->fallpos[i] = model->fallpos[i] + model->mspeed;
			}
		}
		if (model->isDual == 1) {
			for (int j = 0; j < cbs.size(); j += 1) {
				cbs[j].setPosition(model->rngxv[j], model->fallpos[j]);
				window.draw(cbs[j]);
			}

			for (int k = 0; k < cbs2.size(); k += 1) {
				cbs2[k].setPosition(model->rngxv2[k], model->fallpos2[k]);
				window.draw(cbs2[k]);

			}

			for (int i = 0; i < cbs.size(); i++) {
				model->fallpos[i] = model->fallpos[i] + model->mspeed;
			}

			for (int i = 0; i < cbs2.size(); i++) {
				model->fallpos2[i] = model->fallpos2[i] + model->mspeed;
			}
		}

		if (record_i != -1) {
			if (bumped == 1) {
				rotated = rotated + 15;
				model->rngxv[record_i] += 15;
				model->fallpos[record_i] -= 15;
				cbs[record_i].setRotation(rotated);
			}

			if (bumped == 2) {
				rotated = rotated + 15;
				model->rngxv[record_i] -= 15;
				model->fallpos[record_i] -= 15;
				cbs[record_i].setRotation(-rotated);
			}

			if (model->isItem == 1) {
				model->rngxv[record_i] -= 15;
				model->fallpos[record_i] += 15;
				cbs[record_i].setRotation(0);
				model->prop_rng();
			}
		}

		if (record_i2 != -1) {
			if (bumped2 == 1) {
				rotated = rotated + 15;
				model->rngxv2[record_i2] += 15;
				model->fallpos2[record_i2] -= 15;
				cbs2[record_i2].setRotation(rotated);
			}

			if (bumped2 == 2) {
				rotated = rotated + 15;
				model->rngxv2[record_i2] -= 15;
				model->fallpos2[record_i2] -= 15;
				cbs2[record_i2].setRotation(-rotated);
			}

			if (model->isItem2 == 1) {
				model->rngxv2[record_i2] += 15;
				model->fallpos2[record_i2] += 15;
				cbs2[record_i2].setRotation(0);
				model->prop_rng2();
			}
		}

		song_control();

		//hud value related
		comboinfo.setCharacterSize(model->dysize);
		comboinfo2.setCharacterSize(model->dysize2);
		comboinfo.setString(std::to_string(model->combo));
		scoreinfo.setString(std::to_string(model->score));
		comboinfo2.setString(std::to_string(model->combo2));
		scoreinfo2.setString(std::to_string(model->score2));

		window.draw(songplate);
		window.draw(songimgingame);
		window.draw(songinfo);
		if (!(model->ppposy - model->fallpos[model->totalbarriers - 1] < model->mspeed)){
			window.draw(comboinfo);
			window.draw(scoreinfo);
		}
	}

	if (model->mapselected == 0) {
		itemdes.setColor(sf::Color::White);
		itemdes2.setColor(sf::Color::White);
	}
	if (model->mapselected == 1) {
		itemdes.setColor(sf::Color::White);
		itemdes2.setColor(sf::Color::White);
	}
	if (model->mapselected == 3) {
		itemdes.setColor(sf::Color(0, 162, 232));
		itemdes2.setColor(sf::Color(0, 162, 232));
	}
	if (model->mapselected == 4) {
		itemdes.setColor(sf::Color(0, 162, 232));
		itemdes2.setColor(sf::Color(0, 162, 232));
	}
	if (model->mapselected == 2) {
		itemdes.setColor(sf::Color(0, 162, 232));
		itemdes2.setColor(sf::Color(0, 162, 232));
	}
	if (model->mapselected == 5) {
		itemdes.setColor(sf::Color::Red);
		itemdes2.setColor(sf::Color::Red);
	}

	//std::cout << "isDual is: " << model->isDual << std::endl;
	if ((model->menuLayer != 5) && (model->menuLayer != 3) && (model->gameState != 3) && (model->gameState != 4)) {
		window.draw(player);
	}
	if ((model->isDual == 1 && model->gameState == 2) || (model->modeselected == 1 && model->menuLayer == 4)) {
		window.draw(player2);
		
	}

	if ((model->isDual == 1 && model->gameState == 2)) {
		if (!(model->ppposy - model->fallpos[model->totalbarriers - 1] < model->mspeed)){
			window.draw(comboinfo2);
			window.draw(scoreinfo2);
		}
	}
	
	if (model->gameState == 4) {
		song_control();
	}

	if (model->gameState == 2) {

		if (model->isDual == 0) {
			window.draw(lineinsL);
			window.draw(lineinsR);
		}
		if (model->isDual == 1) {
			
			window.draw(lineinsL2);
			window.draw(lineinsM);
			window.draw(lineinsR2);

			//item related
			window.draw(itemplate);
			window.draw(itemplate2);

			//if (model->itemno != 0) {

				if (model->itemno == 1) {
					shield.setTexture(shieldiv);
					if (textureflip == 1) {
						window.draw(shield);
					}
				}
				if (model->itemno == 2) {
					missle.setTexture(missleTexture);
					if (textureflip == 1) {
						window.draw(missle);
					}
					
				}
				if (model->itemno == 3) {
					reverse.setTexture(reverseTexture);
					if (textureflip == 1) {
						window.draw(reverse);
					}
					
				}
				if (model->itemno == 4) {
					bomb.setTexture(bombTexture);
					if (textureflip == 1) {
						window.draw(bomb);
					}
				}
				if (model->itemno == 5) {
					invisible.setTexture(invisibleTexture);
					if (textureflip == 1) {
						window.draw(invisible);
					}
				}

				//if (itemconfirm2 != 0) {
					if (itemconfirm == 1) {
						itemeffect.setPosition(model->ppposx + 60, model->ppposy + 65);
						itemeffect.setTexture(shieldeffectTexture);
						itemeffect.setOrigin(150, 150);
						itemeffect.setScale(0.5f, 0.5f);
						itemeffect.setRotation(model->itemrotation);
						itemdes.setString("shield activiated");
						window.draw(itemeffect);
						if (itemconfirm2 == 2 || itemconfirm2 == 3 || itemconfirm2 == 5) {
							model->score = model->score + 100;
						}
					}
					if (itemconfirm == 2 && itemconfirm2 != 1) {

						active2 = active2 - 2 * model->mspeed;
						itemdes2.setPosition(725, 790);
						itemdes2.setString("missle incoming");
						itemeffect2.setPosition(690, active2);
						itemeffect2.setOrigin(0,0);
						itemeffect2.setScale(0.5f, 0.5f);
						itemeffect2.setRotation(0);
						itemeffect2.setTexture(missleeffectTexture);
						if (active2 <= -300) {
							active2 = 300 * model->mspeed;
							itemdes2.setString("");
							model->score2 = model->score2 - 30000;
							itemconfirm = 0;
						}
						window.draw(itemeffect2);
						if (active2 < 866) {
							explosion2();
						}
					}
					if (itemconfirm == 3 && itemconfirm2 != 1) {
						itemdes2.setPosition(745, 790);
						itemdes2.setString("key reversed");
					}
					if (itemconfirm == 4) {
						model->score_calculate();
						itemdes.setString("double points");
					}
					if (itemconfirm == 5 && itemconfirm2 != 1) {
						if (itemconfirm2 != 1) {
							player2.setTexture(invisibleeffectTexture);
							itemdes2.setPosition(725, 790);
							itemdes2.setString("visual lost");
						}
					}
				//}
					
				//std::cout << "Recorded Item Number is: " << expiration_record << std::endl;
				if (expiration_record + 25 > model->totalbarriers - 1) {
					expiration_record = model->totalbarriers - 1 - 25;
				}
				if (expiration_record2 + 25 > model->totalbarriers - 1) {
					expiration_record2 = model->totalbarriers - 1 - 25;
				}
				if ((model->ppposy - model->fallpos[expiration_record + 25] < model->songspeed)) {
					//std::cout << "I am here" << std::endl;
						if (itemconfirm == 1 || itemconfirm == 4) {
							itemdes.setString("");
							itemeffect.setTexture(transparentTexture);
						}
						if (itemconfirm == 3 || itemconfirm == 5 || itemconfirm == 2) {
							itemdes2.setString("");
							model->score2 = model->score2 - 20000;
						}
						if (itemconfirm == 5){
								if (model->carselected == 0) {
									player2.setTexture(r8Texture);
								}
								if (model->carselected == 1) {
									player2.setTexture(p911Texture);
								}
								if (model->carselected == 2) {
									player2.setTexture(sportcarTexture);
								}
								if (model->carselected == 3) {
									player2.setTexture(taxiTexture);
								}
								if (model->carselected == 4) {
									player2.setTexture(pickupTexture);
								}
								if (model->carselected == 5) {
									player2.setTexture(minivanTexture);
								}
								if (model->carselected == 6) {
									player2.setTexture(ambulanceTexture);
								}
								if (model->carselected == 7) {
									player2.setTexture(policeTexture);
								}
								if (model->carselected == 8) {
									player2.setTexture(truckTexture);
								}

						}
						itemconfirm = 0;
				}

				if (model->itemno2 == 1) {
					shield2.setTexture(shieldiv);
					if (textureflip2 == 1) {
						window.draw(shield2);
					}
				}
				if (model->itemno2 == 2) {
					missle2.setTexture(missleTexture);
					if (textureflip2 == 1) {
						window.draw(missle2);
					}
				}
				if (model->itemno2 == 3) {
					reverse2.setTexture(reverseTexture);
					if (textureflip2 == 1) {
						window.draw(reverse2);
					}
				}
				if (model->itemno2 == 4) {
					bomb2.setTexture(bombTexture);
					if (textureflip2 == 1) {
						window.draw(bomb2);
					}
				}
				if (model->itemno2 == 5) {
					invisible2.setTexture(invisibleTexture);
					if (textureflip2 == 1) {
						window.draw(invisible2);
					}
				}

					if (itemconfirm2 == 1) {
						itemeffect2.setPosition(model->p2posx + 60, model->p2posy + 65);
						itemeffect2.setTexture(shieldeffectTexture);
						itemeffect2.setOrigin(150, 150);
						itemeffect2.setScale(0.5f, 0.5f);
						itemeffect2.setRotation(model->itemrotation);
						itemdes2.setPosition(700, 790);
						itemdes2.setString("shield activiated");
						window.draw(itemeffect2);
						if (itemconfirm == 2 || itemconfirm == 3 || itemconfirm == 5) {
							model->score2 = model->score2 + 100;
						}
					}
					if (itemconfirm2 == 2 && itemconfirm != 1) {
						active = active - 2 * model->mspeed;
						itemdes.setString("missle incoming");
						itemeffect.setPosition(260, active);
						itemeffect.setOrigin(0, 0);
						itemeffect.setScale(0.5f,0.5f);
						itemeffect.setRotation(0);
						itemeffect.setTexture(missleeffectTexture);
						if (active <= -300) {
							active = 300 * model->mspeed;
							itemdes.setString("");
							model->score = model->score - 30000;
							itemconfirm2 = 0;
							
						}
						if (active < 866) {
							explosion();
						}
						window.draw(itemeffect);

					}
					if (itemconfirm2 == 3 && itemconfirm != 1) {
						itemdes.setString("key reversed");
					}
					if (itemconfirm2 == 4) {
						itemdes2.setPosition(745, 790);
						model->score2_calculate();
						itemdes2.setString("double points");
					}
					if (itemconfirm2 == 5 && itemconfirm != 1) {
						if (itemconfirm != 1) {
							player.setTexture(invisibleeffectTexture);
							itemdes.setString("visual lost");
						}
					}
					window.draw(itemeffect2);
				//}

				//std::cout << "Recorded Item Number 2 is: " << expiration_record2 << std::endl;

				if ((model->p2posy - model->fallpos2[expiration_record2 + 25] < model->songspeed)) {
					if (itemconfirm2 == 1 || itemconfirm2 == 4) {
						itemdes2.setString("");
						itemeffect2.setTexture(transparentTexture);
					}
					if (itemconfirm2 == 3 || itemconfirm2 == 5 || itemconfirm2 == 2) {
						itemdes.setString("");
						model->score = model->score - 20000;
					}
					if (itemconfirm2 == 5) {
						if (model->carselected == 0) {
							player.setTexture(r8Texture);
						}
						if (model->carselected == 1) {
							player.setTexture(p911Texture);
						}
						if (model->carselected == 2) {
							player.setTexture(sportcarTexture);
						}
						if (model->carselected == 3) {
							player.setTexture(taxiTexture);
						}
						if (model->carselected == 4) {
							player.setTexture(pickupTexture);
						}
						if (model->carselected == 5) {
							player.setTexture(minivanTexture);
						}
						if (model->carselected == 6) {
							player.setTexture(ambulanceTexture);
						}
						if (model->carselected == 7) {
							player.setTexture(policeTexture);
						}
						if (model->carselected == 8) {
							player.setTexture(truckTexture);
						}
					}
					itemconfirm2 = 0;
					
				}
			}

			final_test();

			window.draw(itemdes);
			window.draw(itemdes2);
	}
	if (model->quitswitcher == 1) {
		quit_control();
	}

	if (model->displayleaderboard == 1) {
		finalscore.setString("player 1 score: \n\n\nplayer 2 score: ");
		finalscorep1.setString(std::to_string(model->score));
		finalscorep2.setString(std::to_string(model->score2));
		winner.setString("latest\nscore\ninformation");
		window.draw(scoreplate);
		window.draw(finalscore);
		window.draw(finalscorep1);
		window.draw(finalscorep2);
		window.draw(winner);
	}
	if (model->gameState != 4) {
		if (model->songselected == 0) {
			model->totalbarriers = 914;
			model->songspeed = 157.0755 + 10;//174.7259;
			model->fallposy2 = 0;
			model->fallposy = 0;
		}
		if (model->songselected == 1) {
			model->totalbarriers = 752;
			model->songspeed = 166.5 + 10;
			model->fallposy2 = 0;
			model->fallposy = 0;
		}
		if (model->songselected == 2) {
			model->totalbarriers = 966;
			model->songspeed = 158.5714 + 10;
			model->fallposy2 = 0;
			model->fallposy = 0;
		}
		if (model->songselected == 3) {
			model->totalbarriers = 756;
			model->songspeed = 141.1088 + 10;
			model->fallposy2 = 0;
			model->fallposy = 0;
		}
		if (model->songselected == 4) {
			model->totalbarriers = 1018;
			model->songspeed = 112.5 + 10;
			model->fallposy2 = 0;
			model->fallposy = 0;
		}
		if (model->songselected == 5) {
			model->totalbarriers = 888;
			model->songspeed = 138.75 + 10;
			model->fallposy2 = 0;
			model->fallposy = 0;
		}
		if (model->songselected == 6) {
			model->totalbarriers = 812;
			model->songspeed = 169.8980 + 10;
			model->fallposy2 = 0;
			model->fallposy = 0;
		}
	}

	if (model->fontlock == 1) {
		transcolor = rand() % 255 + 0;
		transcolor2 = rand() % 255 + 0;
		transcolor3 = rand() % 255 + 0;
		//comboinfo.setColor(sf::Color(transcolor, transcolor2, transcolor3));
		comboinfo.setColor(sf::Color::White);
	}
	if (model->fontlock2 == 1) {
		transcolor = rand() % 255 + 0;
		transcolor2 = rand() % 255 + 0;
		transcolor3 = rand() % 255 + 0;
		//comboinfo.setColor(sf::Color(transcolor, transcolor2, transcolor3));
		comboinfo2.setColor(sf::Color::White);
	}

	if (model->fontlock == 0) {
		comboinfo.setColor(sf::Color(0, 162, 232));
	}
	if (model->fontlock2 == 0) {
		comboinfo2.setColor(sf::Color(0, 162, 232));
	}

	//std::cout << "Item Number is: " << model->itemno << std::endl;
	//std::cout << "Item Confirm Number is: " << itemconfirm << std::endl;
	if (model->carselected == 0) {
		tempSprite.setTexture(r8Texture);
	}
	if (model->carselected == 1) {
		tempSprite.setTexture(p911Texture);
	}
	if (model->carselected == 2) {
		tempSprite.setTexture(sportcarTexture);
	}
	if (model->carselected == 3) {
		tempSprite.setTexture(taxiTexture);
	}
	if (model->carselected == 4) {
		tempSprite.setTexture(pickupTexture);
	}
	if (model->carselected == 5) {
		tempSprite.setTexture(minivanTexture);
	}
	if (model->carselected == 6) {
		tempSprite.setTexture(ambulanceTexture);
	}
	if (model->carselected == 7) {
		tempSprite.setTexture(policeTexture);
	}
	if (model->carselected == 8) {
		tempSprite.setTexture(truckTexture);
	}
	std::cout << "Total Barrier is: " << model->totalbarriers << std::endl;
	std::cout << "Song Selected is: " << model->songselected << std::endl;
	std::cout << "Song Speed is: " << model->songspeed << std::endl;
	window.display();
	
	window2.clear();
	window2.draw(tutorial);
	window2.display();
}

void View::song_control() {
	//std::cout << player.getPosition().y - model->fallpos[0] << std::endl;
	//std::cout << model->switcher << std::endl;
	if (model->switcher == 1) {
		if (model->gameState != 4) {
			if (model->songselected == 0) {
				if (player.getPosition().y - model->fallpos[0] < model->mspeed * 4) {
					chasingcars.play();
					model->gamestart = 1;
					model->switcher = 0;
				}

			}
			if (model->songselected == 1) {
				if (player.getPosition().y - model->fallpos[0] < model->mspeed * 4) {
					comeoutoftheshade.play();
					model->gamestart = 1;
					model->switcher = 0;
				}
			}
			if (model->songselected == 2) {
				if (player.getPosition().y - model->fallpos[0] < model->mspeed * 4) {
					castaway.play();
					model->gamestart = 1;
					model->switcher = 0;
				}
			}
			if (model->songselected == 3) {
				if (player.getPosition().y - model->fallpos[0] < model->mspeed * 4) {
					safeandsound.play();
					model->gamestart = 1;
					model->switcher = 0;
				}
			}
			if (model->songselected == 4) {
				if (player.getPosition().y - model->fallpos[0] < model->mspeed * 4) {
					animal.play();
					model->gamestart = 1;
					model->switcher = 0;
				}
			}
			if (model->songselected == 5) {
				if (player.getPosition().y - model->fallpos[0] < model->mspeed * 4) {
					carriedaway.play();
					model->gamestart = 1;
					model->switcher = 0;
				}
			}
			if (model->songselected == 6) {
				if (player.getPosition().y - model->fallpos[0] < model->mspeed * 4) {
					vote.play();
					model->gamestart = 1;
					model->switcher = 0;
				}
			}
		}
		if (model->gameState == 4) {
			if (test1.getPosition().y - model->fallpos[0] < model->mspeed * 4) {
				tunersong.play();
				model->gamestart = 1;
				model->switcher = 0;
			}
			if (test2.getPosition().y - model->fallpos[0] < model->mspeed * 4) {
				tunersong.play();
				model->gamestart = 1;
				model->switcher = 0;
			}
			if (test3.getPosition().y - model->fallpos[0] < model->mspeed * 4) {
				tunersong.play();
				model->gamestart = 1;
				model->switcher = 0;
			}
			if (test4.getPosition().y - model->fallpos[0] < model->mspeed * 4) {
				tunersong.play();
				model->gamestart = 1;
				model->switcher = 0;
			}
			if (test5.getPosition().y - model->fallpos[0] < model->mspeed * 4) {
				tunersong.play();
				model->gamestart = 1;
				model->switcher = 0;
			}
			if (test6.getPosition().y - model->fallpos[0] < model->mspeed * 4) {
				tunersong.play();
				model->gamestart = 1;
				model->switcher = 0;
			}
			if (test7.getPosition().y - model->fallpos[0] < model->mspeed * 4) {
				tunersong.play();
				model->gamestart = 1;
				model->switcher = 0;
			}
			if (test8.getPosition().y - model->fallpos[0] < model->mspeed * 4) {
				tunersong.play();
				model->gamestart = 1;
				model->switcher = 0;
			}
			if (test9.getPosition().y - model->fallpos[0] < model->mspeed * 4) {
				tunersong.play();
				model->gamestart = 1;
				model->switcher = 0;
			}
		}
	}
}

void View::final_test() {
	
	if (model->ppposy - model->fallpos[model->totalbarriers-1] < model->mspeed) {
		model->gamestart = 0;
		finalscore.setString("player 1 score: \n\n\nplayer 2 score: ");
		finalscorep1.setString(std::to_string(model->score));
		finalscorep2.setString(std::to_string(model->score2));
		if (model->score > model->score2) {
			winner.setString("player 1 won\n\nPress\nBackspace\nto go back");
		}
		if (model->score < model->score2) {
			winner.setString("player 2 won\n\nPress\nBackspace\nto go back");
		}
		if (model->score == model->score2) {
			winner.setString("game draw\n\nPress\nBackspace\nto go back");
		}
		window.draw(scoreplate);
		window.draw(finalscore);
		window.draw(finalscorep1);
		window.draw(finalscorep2);
		window.draw(winner);
	}
}

void View::djpause() {
	if (model->songselected == 0) {
		chasingcars.pause();
	}
	if (model->songselected == 1) {
		comeoutoftheshade.pause();
	}
	if (model->songselected == 2) {
		castaway.pause();
	}
	if (model->songselected == 3) {
		safeandsound.pause();
	}
	if (model->songselected == 4) {
		animal.pause();
	}
	if (model->songselected == 5) {
		carriedaway.pause();
	}
	if (model->songselected == 6) {
		vote.pause();
	}
}

void View::djplay() {
	if (model->songselected == 0) {
		chasingcars.play();
	}
	if (model->songselected == 1) {
		comeoutoftheshade.play();
	}
	if (model->songselected == 2) {
		castaway.play();
	}
	if (model->songselected == 3) {
		safeandsound.play();
	}
	if (model->songselected == 4) {
		animal.play();
	}
	if (model->songselected == 5) {
		carriedaway.play();
	}
	if (model->songselected == 6) {
		vote.play();
	}
}

void View::quit_control() {
	int movequit2 = 0;
	int movequit = 22;
	blurredplate.setPosition(movequit2, 0);
	blurredtitle.setPosition(movequit, 100);
	blurredplate.setSize(sf::Vector2f(swidth, sheight));
	//window.setFramerateLimit(0);
	window.draw(blurredplate);
	window.draw(blurredtitle);
	quittitle.setString("quit?");
	quitmsg.setString("\nO: confirm\n\nP: go back");
	window.draw(quittitle);
	window.draw(quitmsg);
	model->mspeed = 0;
	model->combo = 0;
	model->combo2 = 0;
	djpause();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
		movequit = -9999;
		movequit2 = -9999;
		model->mspeed = currentmspeed;
		model->combo = currentcombo;
		model->combo2 = currentcombo2;
		model->quitswitcher = 0;
		djplay();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {

		model->isDual == 0;
		model->gameState = 1;
		model->buttonlocko = 1;
		titlebgm.play();
		swidth = 720;
		if (model->mapselected == 0) {
			bg.setTexture(menubgTexture);
			bg1.setTexture(menubg1Texture);
		}
		if (model->mapselected == 1) {
			bg.setTexture(cityTexture);
			bg1.setTexture(city1Texture);
		}
		if (model->mapselected == 2) {
			bg.setTexture(desertTexture);
			bg1.setTexture(desert1Texture);
		}
		if (model->mapselected == 3) {
			bg.setTexture(firnTexture);
			bg1.setTexture(firn1Texture);
		}
		if (model->mapselected == 4) {
			bg.setTexture(islandTexture);
			bg1.setTexture(island1Texture);
		}
		if (model->mapselected == 5) {
			bg.setTexture(futureTexture);
			bg1.setTexture(future1Texture);
		}
		if (model->songselected == 0) {
			chasingcars.stop();
		}
		if (model->songselected == 1) {
			comeoutoftheshade.stop();
		}
		if (model->songselected == 2) {
			castaway.stop();
		}
		if (model->songselected == 3) {
			safeandsound.stop();
		}
		if (model->songselected == 4) {
			animal.stop();
		}
		if (model->songselected == 5) {
			carriedaway.stop();
		}
		if (model->songselected == 6) {
			vote.stop();
		}

		//window.setFramerateLimit(60);
		itemeffect.setTexture(transparentTexture);
		itemeffect2.setTexture(transparentTexture);
		player.setTexture(*tempSprite.getTexture());
		player2.setTexture(*tempSprite.getTexture());
		model->mspeed = currentmspeed;
		model->combo = currentcombo;
		model->combo2 = currentcombo2;
		model->quitswitcher = 0;
	}
}

void View::collision() {
	//collision detection
	rotated = rotated += 10;

	for (int i = 0; i < model->fallpos.size(); i++) {
		if (model->isDual == 0) {
			//successful hit, normal barrier
			if (model->fallpos[i] > model->pposy - 48 && model->fallpos[i] < 720 && model->rngxv[i] == 305) {
				if (model->collisionjudge == 1) {
					model->combo += 1;
					
				}
			}
			if (model->fallpos[i] > model->pposy - 48 && model->fallpos[i] < 720 && model->rngxv[i] == 380) {
				if (model->collisionjudge == 2) {
					model->combo += 1;
					if (model->combo <= 50) {
						model->score += 10;
					}
				}
			}

			//failed hit
			if (model->fallpos[i] > model->pposy - 48 && model->fallpos[i] < 720 && model->rngxv[i] == 380) {
				if (model->collisionjudge == 1) {
					model->combo = 0;
					bumped = 1;
					//bump left
					record_i = i;
					destorysound.play();
				}

			}
			if (model->fallpos[i] > model->pposy - 48 && model->fallpos[i] < 720 && model->rngxv[i] == 305) {
				if (model->collisionjudge == 2) {
					model->combo = 0;
					bumped = 2;
					//bump right
					record_i = i;
					destorysound.play();
				}
			}
		}
		if (model->isDual == 1) {
			if (model->fallpos[i] > model->pposy - 48 && model->fallpos[i] < 720 && model->rngxv[i] == 235) {
				if (model->collisionjudge == 1) {
					model->combo += 1;
				}
			}
			if (model->fallpos[i] > model->pposy - 48 && model->fallpos[i] < 720 && model->rngxv[i] == 308) {
				if (model->collisionjudge == 2) {
					model->combo += 1;
				}
			}

			//successful hit, item
			if (model->fallpos[i] > model->pposy - 48 && model->fallpos[i] < 720 && model->rngxv[i] == 235 && cbs[i].getTexture() == &itemTexture) {
				if (model->collisionjudge == 2) {
					model->combo += 1;
					model->isItem = 1;
					textureflip = 1;
					record_i = i;
					itempickupsound.play();
				}
			}
			if (model->fallpos[i] > model->pposy - 48 && model->fallpos[i] < 720 && model->rngxv[i] == 308 && cbs[i].getTexture() == &itemTexture) {
				if (model->collisionjudge == 1) {
					model->combo += 1;
					model->isItem = 1;
					textureflip = 1;
					record_i = i;
					itempickupsound.play();
				}
			}

			if (model->fallpos[i] > model->pposy - 48 && model->fallpos[i] < 720 && model->rngxv[i] == 308) {
				
				if (model->isItem != 1) {
					if (model->collisionjudge == 1) {
						model->combo = 0;
						bumped = 1;
						//bump left
						record_i = i;
						destorysound.play();
					}
				}
			}
			if (model->fallpos[i] > model->pposy - 48 && model->fallpos[i] < 720 && model->rngxv[i] == 235) {
				
				if (model->isItem != 1) {
					if (model->collisionjudge == 2) {
						model->combo = 0;
						bumped = 2;
						//bump right
						record_i = i;
						destorysound.play();
					}
				}
			}
		}
	}
	std::cout << "Collision Judge is: " << model->collisionjudge << std::endl;
	std::cout << "Collision Judge 2 is: " << model->collisionjudge2 << std::endl;
}

void View::collision2() {
	//duet mode collision detection
	//successful hit, normal barrier
	for (int j = 0; j < model->fallpos2.size(); j++) {
		if (model->fallpos2[j] > model->p2posy - 50 && model->fallpos2[j] < 720 && model->rngxv2[j] == 665) {
			if (model->collisionjudge2 == 1) {
				model->combo2 += 1;
			}
		}
		if (model->fallpos2[j] > model->p2posy - 50 && model->fallpos2[j] < 720 && model->rngxv2[j] == 738) {
			if (model->collisionjudge2 == 2) {
				model->combo2 += 1;
			}
		}
		//successful hit, item
		if (model->fallpos2[j] > model->p2posy - 50 && model->fallpos2[j] < 720 && model->rngxv2[j] == 665 && cbs2[j].getTexture() == &itemTexture) {
			if (model->collisionjudge2 == 2) {
				model->combo2 += 1;
				model->isItem2 = 1;
				textureflip2 = 1;
				record_i2 = j;
				itempickupsound.play();
			}
		}
		if (model->fallpos2[j] > model->p2posy - 50 && model->fallpos2[j] < 720 && model->rngxv2[j] == 738 && cbs2[j].getTexture() == &itemTexture) {
			if (model->collisionjudge2 == 1) {
				model->combo2 += 1;
				model->isItem2 = 1;
				textureflip2 = 1;
				record_i2 = j;
				itempickupsound.play();
			}
		}

		//failed hit
		if (model->fallpos2[j] > model->p2posy - 50 && model->fallpos2[j] < 720 && model->rngxv2[j] == 738) {
			
			if (model->isItem2 != 1) {
				
				if (model->collisionjudge2 == 0) {
					model->combo2 = 0;
					destorysound.play();
				}
				if (model->collisionjudge2 == 1) {
					model->combo2 = 0;
					bumped2 = 1;
					record_i2 = j;
					destorysound.play();
				}
			}

		}
		if (model->fallpos2[j] > model->p2posy - 50 && model->fallpos2[j] < 720 && model->rngxv2[j] == 665) {
			
			if (model->isItem2 != 1) {
				
				if (model->collisionjudge2 == 0) {
					model->combo2 = 0;
					destorysound.play();
				}
				if (model->collisionjudge2 == 2) {
					model->combo2 = 0;
					bumped2 = 2;
					record_i2 = j;
					destorysound.play();
				}
			}
		}
	}
}

void View::explosion2(){
			for (int i = 0; i < model->fallpos2.size(); i++) {
				if (active2 - model->fallpos2[i] < 20) {
					textureflip = 1;
					if (textureflip == 1) {
						barrierexploded.play();
					}
					textureflip = 2;
					if (model->rngxv2[i] == 738) { //bump right
						rotated = rotated + 15;
						model->rngxv2[i] += 50;
						model->fallpos2[i] -= 50;
						cbs2[i].setRotation(rotated);
					}

					if (model->rngxv2[i] == 665) { //bump left
						rotated = rotated + 15;
						model->rngxv2[i] -= 50;
						model->fallpos2[i] -= 50;
						cbs2[i].setRotation(-rotated);
					}
				}
				if (active2 <= -200) {
					break;
				}
			}
}

void View::explosion() {
			for (int i = 0; i < model->fallpos.size(); i++) {
				if (active - model->fallpos[i] < 20) {
					textureflip2 = 1;
					if (textureflip2 == 1) {
						barrierexploded.play();
					}
					textureflip2 = 2;
					if (model->rngxv[i] == 308) { //bump right
						rotated = rotated + 15;
						model->rngxv[i] += 50;
						model->fallpos[i] -= 50;
						cbs[i].setRotation(rotated);
					}

					if (model->rngxv[i] == 235) { //bump left
						rotated = rotated + 15;
						model->rngxv[i] -= 50;
						model->fallpos[i] -= 50;
						cbs[i].setRotation(-rotated);
					}
				}
				if (active <=-200) {
					break;
				}
			}
}