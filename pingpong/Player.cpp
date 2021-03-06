#include "pch.h"
#include "Player.h"
#include "Game.h"

bool Player::TPMousePlayer1 = false;
bool Player::TPMousePlayer2 = false;

Player::Player(int mode, Racket* racket, Table* table,Ball* ball, int playerNumber) {
	this->mode = mode;
	this->racket = racket;
	this->table = table;
	this->points = 0;
	this->ball = ball;
	this->playerNumber = playerNumber;
	licz = 0;
	this->TPMousePlayer1 = false;
	this->TPMousePlayer2 = false;
	if (racket->isAI) srand((unsigned int)time(NULL));
}

void Player::move() {

		
		if (mode == 0 && playerNumber == 1) {
			if (ball->p1Serv == 2 || Collision::who == 2) {
				if (TPMousePlayer1) {
					sf::Mouse::setPosition(racket->windowObj.mapCoordsToPixel(racket->dObject->getPosition()), racket->windowObj);
					TPMousePlayer1 = false;
					
				}
				racket->rotation();
				racket->realPos = Physics::swapY(Physics::calcRealVector(racket->windowObj.mapPixelToCoords(sf::Mouse::getPosition(racket->windowObj))));
				TPMousePlayer2 = true;
			}

		} else if (mode == 0 && playerNumber == 2) {
			if (ball->p2Serv == 2 || Collision::who == 1) {
				if (TPMousePlayer2) {
					sf::Mouse::setPosition(racket->windowObj.mapCoordsToPixel(racket->dObject->getPosition()), racket->windowObj);
					TPMousePlayer2 = false;
					
				}
				racket->rotation();
				racket->realPos = Physics::swapY(Physics::calcRealVector(racket->windowObj.mapPixelToCoords(sf::Mouse::getPosition(racket->windowObj))));
				TPMousePlayer1 = true;
			}
		} else if (mode == 1 && !racket->isAI) {
			racket->realPos = Physics::swapY(Physics::calcRealVector(racket->windowObj.mapPixelToCoords(sf::Mouse::getPosition(racket->windowObj))));
			racket->rotation();
		}
		else if (mode == 1 && racket->isAI) {
			
		
				float x = ball->dObject->getPosition().x - racket->dObject->getPosition().x;
				float y = ball->dObject->getPosition().y - racket->dObject->getPosition().y;
				float lenght = sqrt(x*x + y * y);
				int r1 = ((std::rand() % 60) + 1);
				float speed1 = (float)r1;
				int r2 = ((std::rand() % 60) + 1);
				float speed2 = (float)r2;
				float tempx = x / lenght; //znormalizowane x pileczka-rakietka
				float tempy = y / lenght; //znormalizowane y pileczka-rakietka

			if (ball->dObject->getPosition().x > 600 && ball->isballmove && ball->p2Serv !=2)
			{
				//std::cout << "x"<<ball->velocityVector.x << "\n";
				//std::cout << "y" << ball->velocityVector.y << "\n";
				if (ball->p2)
				{
					if (lenght < 30)
					{
						x = ball->dObject->getPosition().x - 50.0f - racket->dObject->getPosition().x;
						y = ball->dObject->getPosition().y + 50.0f- racket->dObject->getPosition().y;

						if (ball->velocityVector.x < 1.4f && ball->dObject->getPosition().x<800.0f) speed1 = speed1 * 0.8f;
						else if (abs(ball->velocityVector.x / ball->velocityVector.y) > 3) speed1 = speed1 * 1.7f;
						else if (abs(ball->velocityVector.y) > 3) speed1 = speed1 * 2.0f;
						else if (abs(ball->dObject->getPosition().y) > 310.0f && ball->Colision!=3)
						{
							licz=2;
							racket->dObject->setRotation(-20);
						}
						else if (ball->dObject->getPosition().x > 800)
						{
							racket->dObject->setRotation(30);
							speed1 = speed1 * 2.0f;
							std::cout << ball->dObject->getPosition().x << "\n";
							
						}
						if (licz == 0)
						{
							racket->dObject->setRotation((float)r1);
							licz = 1;
						}
						if (licz == 2) speed1 = speed1 * 0.6f;
						lenght = sqrt(x*x + y * y);
						tempx = x / lenght;
						tempy = y / lenght;
						//std::cout << ball->velocity << "\n";
						racket->dObject->move({ tempx * speed1 * Game::getElapsedTime(),0.0f });
					}
					else
					{
						if (abs(ball->velocityVector.x / ball->velocityVector.y) > 3 || ball->velocityVector.x<1) speed1 = speed1 * 1.7f;
						if (abs(ball->velocityVector.y) > 3) speed1 = speed1 * 2.0f;
						if (abs(ball->dObject->getPosition().y) > 310 && ball->Colision != 3)
						{
							float x = ball->dObject->getPosition().x - racket->dObject->getPosition().x + 30;
							float y = ball->dObject->getPosition().y - racket->dObject->getPosition().y - 40;
							float lenght = sqrt(x*x + y * y);
							float tempx = x / lenght; //znormalizowane x pileczka-rakietka
							float tempy = y / lenght; //znormalizowane y pileczka-rakietka
						}
						racket->dObject->move({ tempx * speed1 * Game::getElapsedTime(),tempy * speed2 * Game::getElapsedTime() });
					}
					racket->realPos = Physics::swapY(Physics::calcRealVector(racket->dObject->getPosition()));
				}
			}
			else 
			{
				
				if (ball->p2Serv == 2) //serwis
				{

					if (racket->dObject->getPosition().x < 1180 && !ball->p2) // ustawienie sie za pilka prze serwisie
					{
						moveTowardsPoint({ 1220,300 }, speed1, speed2);
						licz = 0;
					}
					else
					{
				if (!ball->p2)//podrzucenie pilki prze serwicie
				{

					ball->isballmove = true;
					ball->velocityVector.y = (float)((std::rand() % 3) + 1);
					pom = ball->velocityVector.y;
					if (ball->velocityVector.y < 2) ball->velocityVector.y = 2;
					if (ball->velocityVector.y > 5) ball->velocityVector.y = 5;
					ball->p1 = !ball->p1;
					ball->p2 = !ball->p2;
					ball->Colision = 3;
					licz = 0;

				}
				if (ball->Colision == 3)//zaserwowanie
				{
					if (licz == 0)
					{
						if (pom == 1)
						{
							r1 = 30;
						}
						if (pom == 2)
						{
							r1 = 40;
						}
						if (pom == 3)
						{
							r1 = 50;
						}
						racket->dObject->setRotation((float)r1);
						licz = 1;

					}
					if (lenght < 20 && ball->p2 && ball->p1Serv != 2)
					{
						racket->angle = r1 * 3.0f;

						if (ball->p1)licz = 0;
						if (pom == 1) speed1 = 30;
						if (pom == 2) speed1 = 32;
						if (pom == 3) speed1 = 40;
						x = x - 50;
						y = y + 40;
						lenght = sqrt(x*x + y * y);
						tempx = x / lenght;
						tempy = y / lenght;
						racket->dObject->move({ tempx * speed1 * Game::getElapsedTime(),0 });

					}
					else if (lenght > 20 && ball->p2&& ball->p1Serv != 2)
					{
						
						lenght = sqrt(x*x + y * y);
						tempx = x / lenght;
						tempy = y / lenght;
						racket->dObject->move({ tempx * speed1 * Game::getElapsedTime(),tempy * speed2 * Game::getElapsedTime() });

					}
				}
					}
				}
				else if(racket->dObject->getPosition().x <1200)
				{
					licz = 0;
					moveTowardsPoint({ 1220,300 }, speed1, speed2);
				}
				
			}
			racket->realPos = Physics::swapY(Physics::calcRealVector(racket->dObject->getPosition()));
			
		}
		else if (mode == 2)
		{
		racket->realPos = Physics::swapY(Physics::calcRealVector(racket->windowObj.mapPixelToCoords(sf::Mouse::getPosition(racket->windowObj))));
		racket->rotation();
		}
	
}

void Player::moveTowardsPoint(sf::Vector2f point,float speed1,float speed2)
{
	sf::Vector2f rac = racket->dObject->getPosition();
	point.y = -point.y;
	rac.x = point.x - rac.x;
	rac.y = point.y - rac.y;


		float lenght = sqrt(rac.x*rac.x + rac.y + rac.y);
		rac.x = rac.x / lenght;
		rac.y = rac.y / lenght;
		//std::cout << "6";
		racket->dObject->move({ rac.x * speed1* Game::getElapsedTime(),rac.y * speed2* Game::getElapsedTime() });
		racket->realPos = Physics::swapY(Physics::calcRealVector(racket->dObject->getPosition()));
	
}

void Player::setPoints(int points) {
	this->points = points;
}

int Player::getPoints() {
	return points;
}

void Player::simulation() {
	move();
}

Player::~Player() {
	licz = 0;
}
