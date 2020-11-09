#include "Controller.hpp"
#include <iostream>

Controller::Controller(Model* model, View* view) {
	this->model = model;
	this->view = view;
	
}

Controller::~Controller() {
}

void Controller::inputs()
{

	sf::Event event;

	while (view->window.pollEvent(event))
	{
		
		if (event.type == sf::Event::Resized)
		{
			sf::FloatRect visibleArea(0, 0, view->swidth, view->sheight);
			view->window.setView(sf::View(visibleArea));
		}
		
		if (event.type == sf::Event::Closed) {
				view->window.close();
		}

		if (sf::Event::KeyReleased) {
			model->up = false;
			model->down = false;
			model->left = false;
			model->right = false;
		}

		if (event.type == sf::Event::KeyPressed) {
			
			if (model->gameState == 1) {
				
				view->presssound.play();
				if (model->menuLayer == 0) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
						if (model->buttonselected >= 0) {
							model->buttonselected += 1;
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
						if (model->buttonselected <= 7) {
							model->buttonselected -= 1;
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
							if (model->menuLayer == 0 && model->buttonselected == 2) {
								model->menuLayer = 1;
							}
							if (model->menuLayer == 0 && model->buttonselected == 4) {
								model->menuLayer = 2;
							}
							if (model->menuLayer == 0 && model->buttonselected == 0) {
								model->buttonlocko = 2;
								model->clock2.restart();
								view->titlebgm.stop();
								view->replay();
								model->switcher = 1;
								//std::cout << model->switcher << std::endl;
							}
							if (model->menuLayer == 0 && model->buttonselected == 3) {
								model->menuLayer = 3;
							}
							if (model->menuLayer == 0 && model->buttonselected == 1) {
								model->menuLayer = 4;
							}
							if (model->menuLayer == 0 && model->buttonselected == 6) {
								model->menuLayer = 5;
							}
							if (model->menuLayer == 0 && model->buttonselected == 5) {
								model->menuLayer = 6;
							}
							if (model->menuLayer == 0 && model->buttonselected == 7) {
								exit(0);
							}
					}
				}
				if (model->menuLayer == 6) {
					model->displayleaderboard = 1;
					if ((sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))){
						model->displayleaderboard = 0;
						model->menuLayer = 0;
					}
				}
				if (model->menuLayer == 1) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
						if (model->carselected >= 0) {
							model->carselected += 1;
							
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
						if (model->carselected <= 8) {
							model->carselected -= 1;
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
						if (model->menuLayer == 1) {
							model->menuLayer = 0;
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						model->gameState = 3;
						view->swidth = 1024;
					}
				}
				if (model->menuLayer == 2) {

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
						if (model->mapselected >= 0) {
							model->mapselected += 1;
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
						if (model->mapselected <= 5) {
							model->mapselected -= 1;
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
						if (model->menuLayer == 2) {
							model->menuLayer = 0;
						}
					}
				}
				if (model->menuLayer == 3) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
						if (model->songselected >= 0) {
							model->songselected += 1;
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
						if (model->songselected <= 6) {
							model->songselected -= 1;
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
						if (model->menuLayer == 3) {
							model->menuLayer = 0;
							view->chasingcarspre.stop();
							view->comeoutoftheshadepre.stop();
							view->animalpre.stop();
							view->castawaypre.stop();
							view->carriedawaypre.stop();
							view->votepre.stop();
							view->safeandsoundpre.stop();
							view->titlebgm.play();
							if (model->mapselected == 0) {
								view->bg.setTexture(view->menubgTexture);
								view->bg1.setTexture(view->menubg1Texture);
							}
							if (model->mapselected == 1) {
								view->bg.setTexture(view->cityTexture);
								view->bg1.setTexture(view->city1Texture);
							}
							if (model->mapselected == 2) {
								view->bg.setTexture(view->desertTexture);
								view->bg1.setTexture(view->desert1Texture);
							}
							if (model->mapselected == 3) {
								view->bg.setTexture(view->firnTexture);
								view->bg1.setTexture(view->firn1Texture);
							}
							if (model->mapselected == 4) {
								view->bg.setTexture(view->islandTexture);
								view->bg1.setTexture(view->island1Texture);
							}
							if (model->mapselected == 5) {
								view->bg.setTexture(view->futureTexture);
								view->bg1.setTexture(view->future1Texture);
							}
						}
					}
					if (model->songselected == 0 && model->menuLayer == 3) {
						view->chasingcarspre.play();
						view->comeoutoftheshadepre.stop();
						view->castawaypre.stop();
						view->safeandsoundpre.stop();
						view->animalpre.stop();
						view->votepre.stop();
						view->carriedawaypre.stop();
					}
					if (model->songselected == 1 && model->menuLayer == 3) {
						view->comeoutoftheshadepre.play();
						view->chasingcarspre.stop();
						view->castawaypre.stop();
						view->safeandsoundpre.stop();
						view->animalpre.stop();
						view->votepre.stop();
						view->carriedawaypre.stop();
					}
					if (model->songselected == 2 && model->menuLayer == 3) {
						view->castawaypre.play();
						view->chasingcarspre.stop();
						view->comeoutoftheshadepre.stop();
						view->safeandsoundpre.stop();
						view->animalpre.stop();
						view->votepre.stop();
						view->carriedawaypre.stop();
					}
					if (model->songselected == 3 && model->menuLayer == 3) {
						view->safeandsoundpre.play();
						view->castawaypre.stop();
						view->chasingcarspre.stop();
						view->comeoutoftheshadepre.stop();
						view->animalpre.stop();
						view->votepre.stop();
						view->carriedawaypre.stop();
					}
					if (model->songselected == 4 && model->menuLayer == 3) {
						view->safeandsoundpre.stop();
						view->castawaypre.stop();
						view->chasingcarspre.stop();
						view->comeoutoftheshadepre.stop();
						view->animalpre.play();
						view->votepre.stop();
						view->carriedawaypre.stop();
					}
					if (model->songselected == 5 && model->menuLayer == 3) {
						view->safeandsoundpre.stop();
						view->castawaypre.stop();
						view->chasingcarspre.stop();
						view->comeoutoftheshadepre.stop();
						view->animalpre.stop();
						view->votepre.stop();
						view->carriedawaypre.play();
					}
					if (model->songselected == 6 && model->menuLayer == 3) {
						view->safeandsoundpre.stop();
						view->castawaypre.stop();
						view->chasingcarspre.stop();
						view->comeoutoftheshadepre.stop();
						view->animalpre.stop();
						view->votepre.play();
						view->carriedawaypre.stop();
					}
				}
				if (model->menuLayer == 4) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
						if (model->modeselected >= 0) {
							model->modeselected += 1;
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
						if (model->modeselected <= 1) {
							model->modeselected -= 1;
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
						if (model->menuLayer == 4) {
							view->swidth = 720;
							if (model->modeselected == 0) {
								model->isDual = 0;
							}
							if (model->modeselected == 1) {
								model->isDual = 1;
							}
							
							model->menuLayer = 0;
						}
					}
				}
				if (model->menuLayer == 5) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
						model->menuLayer = 0;
						model->set_speed();
					}
				}
			}
			if (model->gameState == 4) {
				view->window.setKeyRepeatEnabled(false);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					view->test1x = 163 - 40;
					view->test2x = 233- 40;
					view->test3x = 307 - 40;
					view->test4x = 377 - 40;
					view->test5x = 453 - 40;
					view->test6x = 523 - 40;
					view->test7x = 593 - 40;
					view->test8x = 667 - 40;
					view->test9x = 740 - 40;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					view->test1x = 163 + 40;
					view->test2x = 233 + 40;
					view->test3x = 307 + 40;
					view->test4x = 377 + 40;
					view->test5x = 453 + 40;
					view->test6x = 523 + 40;
					view->test7x = 593 + 40;
					view->test8x = 667 + 40;
					view->test9x = 740 + 40;
				}
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
					model->gameState = 3;
					view->backscroll = 0;
					view->titlebgm.play();
					view->tunersong.stop();
					model->gamestart = 0;
				}
			}

			if (model->gameState == 3) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					model->up = true;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					model->down = true;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					model->left = true;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					model->right = true;
				}
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
					view->test1x = 163;
					view->test2x = 233;
					view->test3x = 307;
					view->test4x = 377;
					view->test5x = 453;
					view->test6x = 523;
					view->test7x = 593;
					view->test8x = 667;
					view->test9x = 740;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
					model->gameState = 1;
					model->menuLayer = 1;
					view->swidth = 720;
					model->crosshair.setPosition(500, 400);
					model->crosshairplate.setPosition(540, 360);
					model->crosshairtext.setPosition(540, 360);
					
				}
			}
			if (model->gameState == 2) {
				view->window.setKeyRepeatEnabled(false);
				if (view->itemconfirm != 3 || view->itemconfirm2 == 1) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
						model->p2posx = 700;
						view->comboswitcher2 = 1;
						model->collisionjudge2 = 1;
						view->collision2();
						model->fontlock2 = 1;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
						model->p2posx = 620;
						view->comboswitcher2 = 1;
						model->collisionjudge2 = 2;
						view->collision2();
						model->fontlock2 = 1;
					}
				}
				if (view->itemconfirm == 3 && view->itemconfirm2 != 1) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
						model->p2posx = 700;
						view->comboswitcher2 = 1;
						model->collisionjudge2 = 1;
						view->collision2();
						model->fontlock2 = 1;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
						model->p2posx = 620;
						view->comboswitcher2 = 1;
						model->collisionjudge2 = 2;
						view->collision2();
						model->fontlock2 = 1;
					}
				}
				
				if (view->itemconfirm2 != 3 || view->itemconfirm == 1) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
						model->pposx = 340;
						model->ppposx = 270;
						view->comboswitcher = 1;
						model->collisionjudge = 1;
						view->collision();
						model->fontlock = 1;

					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
						model->pposx = 260;
						model->ppposx = 190;
						view->comboswitcher = 1;
						model->collisionjudge = 2;
						view->collision();
						model->fontlock = 1;
					}
				}
				if (view->itemconfirm2 == 3 && view->itemconfirm != 1) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
						model->pposx = 340;
						model->ppposx = 270;
						view->comboswitcher = 1;
						model->collisionjudge = 1;
						view->collision();
						model->fontlock = 1;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
						model->pposx = 260;
						model->ppposx = 190;
						view->comboswitcher = 1;
						model->collisionjudge = 2;
						view->collision();
						model->fontlock = 1;
					}
				}

				if (model->isDual == 0) {
					model->score_calculate();
					view->swidth = 720;
					if (model->mapselected == 0) {
						view->bg.setTexture(view->menubgTexture);
						view->bg1.setTexture(view->menubg1Texture);
					}
					if (model->mapselected == 1) {
						view->bg.setTexture(view->cityTexture);
						view->bg1.setTexture(view->city1Texture);
					}
					if (model->mapselected == 2) {
						view->bg.setTexture(view->desertTexture);
						view->bg1.setTexture(view->desert1Texture);
					}
					if (model->mapselected == 3) {
						view->bg.setTexture(view->firnTexture);
						view->bg1.setTexture(view->firn1Texture);
					}
					if (model->mapselected == 4) {
						view->bg.setTexture(view->islandTexture);
						view->bg1.setTexture(view->island1Texture);
					}
					if (model->mapselected == 5) {
						view->bg.setTexture(view->futureTexture);
						view->bg1.setTexture(view->future1Texture);
					}
					
				}
				if (model->isDual == 1) {
					model->score_calculate();
					model->score2_calculate();
					view->swidth = 1024;
					if (model->mapselected == 0) {
						view->bg.setTexture(view->menubgdualTexture);
						view->bg1.setTexture(view->menubgdual1Texture);
					}
					if (model->mapselected == 1) {
						view->bg.setTexture(view->citydualTexture);
						view->bg1.setTexture(view->citydual1Texture);
					}
					if (model->mapselected == 2) {
						view->bg.setTexture(view->desertdualTexture);
						view->bg1.setTexture(view->desertdual1Texture);
					}
					if (model->mapselected == 3) {
						view->bg.setTexture(view->firndualTexture);
						view->bg1.setTexture(view->firndual1Texture);
					}
					if (model->mapselected == 4) {
						view->bg.setTexture(view->islanddualTexture);
						view->bg1.setTexture(view->islanddual1Texture);
					}
					if (model->mapselected == 5) {
						view->bg.setTexture(view->futuredualTexture);
						view->bg1.setTexture(view->futuredual1Texture);
					}
					
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
						if (model->itemno != 0) {
							for (int i = 0; i < model->fallpos.size(); i++) {
								if ((model->ppposy - model->fallpos[i] < model->songspeed)) {
									view->expiration_record = i;
								}
							}
						}

						if (model->itemno == 1) {
							view->itemconfirm = 1;
							if (view->textureflip == 1) {
								view->itemusedsound.play();
							}
							view->textureflip = 2;
						}
						if (model->itemno == 2) {
							view->itemconfirm = 2;
							if (view->textureflip == 1) {
								view->itemusedsound.play();
								view->missleincoming.play();
							}
							view->textureflip = 2;
						}
						if (model->itemno == 3) {
							view->itemconfirm = 3;
							if (view->textureflip == 1) {
								view->itemusedsound.play();
							}
							view->textureflip = 2;
						}
						if (model->itemno == 4) {
							view->itemconfirm = 4;
							if (view->textureflip == 1) {
								view->itemusedsound.play();
							}
							view->textureflip = 2;
						}
						if (model->itemno == 5) {
							if (model->carselected == 0) {
								view->tempSprite2.setTexture(view->r8Texture);
							}
							if (model->carselected == 1) {
								view->tempSprite2.setTexture(view->p911Texture);
							}
							if (model->carselected == 2) {
								view->tempSprite2.setTexture(view->sportcarTexture);
							}
							if (model->carselected == 3) {
								view->tempSprite2.setTexture(view->taxiTexture);
							}
							if (model->carselected == 4) {
								view->tempSprite2.setTexture(view->pickupTexture);
							}
							if (model->carselected == 5) {
								view->tempSprite2.setTexture(view->minivanTexture);
							}
							if (model->carselected == 6) {
								view->tempSprite2.setTexture(view->ambulanceTexture);
							}
							if (model->carselected == 7) {
								view->tempSprite2.setTexture(view->policeTexture);
							}
							if (model->carselected == 8) {
								view->tempSprite2.setTexture(view->truckTexture);
							}
							view->tempSprite2.setTexture(*view->player2.getTexture());
							view->itemconfirm = 5;
							if (view->textureflip == 1) {
								view->itemusedsound.play();
							}
							view->textureflip = 2;
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

						if (model->itemno2 != 0) {
							for (int i = 0; i < model->fallpos2.size(); i++) {
								if ((model->p2posy - model->fallpos2[i] < model->songspeed)) {
									view->expiration_record2 = i;
									//break;
								}
							}
						}

						if (model->itemno2 == 1) {
							view->itemconfirm2 = 1;
							if (view->textureflip2 == 1) {
								view->itemusedsound.play();
							}
							view->textureflip2 = 2;
						}
						if (model->itemno2 == 2) {
							view->itemconfirm2 = 2;
							
							if (view->textureflip2 == 1) {
								view->itemusedsound.play();
								view->missleincoming.play();
							}
							view->textureflip2 = 2;
							
						}
						if (model->itemno2 == 3) {
							view->itemconfirm2 = 3;
							if (view->textureflip2 == 1) {
								view->itemusedsound.play();
							}
							view->textureflip2 = 2;
						}
						if (model->itemno2 == 4) {
							view->itemconfirm2 = 4;
							if (view->textureflip2 == 1) {
								view->itemusedsound.play();
							}
							view->textureflip2 = 2;
						}
						if (model->itemno2 == 5) {
							if (model->carselected == 0) {
								view->tempSprite.setTexture(view->r8Texture);
							}
							if (model->carselected == 1) {
								view->tempSprite.setTexture(view->p911Texture);
							}
							if (model->carselected == 2) {
								view->tempSprite.setTexture(view->sportcarTexture);
							}
							if (model->carselected == 3) {
								view->tempSprite.setTexture(view->taxiTexture);
							}
							if (model->carselected == 4) {
								view->tempSprite.setTexture(view->pickupTexture);
							}
							if (model->carselected == 5) {
								view->tempSprite.setTexture(view->minivanTexture);
							}
							if (model->carselected == 6) {
								view->tempSprite.setTexture(view->ambulanceTexture);
							}
							if (model->carselected == 7) {
								view->tempSprite.setTexture(view->policeTexture);
							}
							if (model->carselected == 8) {
								view->tempSprite.setTexture(view->truckTexture);
							}
							view->itemconfirm2 = 5;
							if (view->textureflip2 == 1) {
								view->itemusedsound.play();
							}
							view->textureflip2 = 2;
						}
					}
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
					model->quitswitcher = 1;
					view->currentcombo = model->combo;
					view->currentcombo2 = model->combo2;
					view->currentmspeed = model->mspeed;
					model->gamestart = 0;
				}
			}
		}
		else if ((event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::A) || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::D)) {
			model->p2posx = 660;
			model->p2posy = 600;
			view->comboswitcher = 0;
			view->comboswitcher2 = 0;
			//model->collisionjudge2 = 0;
			model->fontlock2 = 0;
			model->isItem2 = 0;
		}
		else if (model->gameState != 4 && ((event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left) || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right))) {
			model->pposx = 300;
			model->pposy = 600;
			model->ppposx = 230;
			model->ppposy = 600;
			view->comboswitcher = 0;
			view->comboswitcher2 = 0;
			//model->collisionjudge = 0;
			model->isItem = 0;
			model->fontlock = 0;
				
		}
		else if (model->gameState == 4 && ((event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left) || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right))) {
			view->test1x = 163;
			view->test2x = 233;
			view->test3x = 307;
			view->test4x = 377;
			view->test5x = 453;
			view->test6x = 523;
			view->test7x = 593;
			view->test8x = 667;
			view->test9x = 740;
		}
		else if ((event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)) {
			model->itemno = 0;
		}
		else if ((event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W)) {
			model->itemno2 = 0;
		}
	}
}