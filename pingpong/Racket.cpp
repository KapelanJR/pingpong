#include "pch.h"
#include "Racket.h"
#include "Game.h"

Racket::Racket(float posX, float posY,bool isAI, int whichPlayer) :
	MovingObject(RACKET_DEFAULT_MASS), 
	Rect(RACKET_DEFAULT_PIXEL_SIZE_X, RACKET_DEFAULT_PIXEL_SIZE_Y, 0.0f, Physics::Materials::racket, posX, posY),
	windowObj(Game::getWindowObj()) {
	Collision::getRacketCollisionVector()._add(this);
	this->isAI = isAI;
	this->whichPlayer = whichPlayer;
	this->oldRealPos = this->realPos;

	

	
}

void Racket::rotation() {

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) angle -= (150.5f / Game::getSimPerFrame()) * elapsedTime;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) angle += (150.5f / Game::getSimPerFrame()) * elapsedTime;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) angle = 0.0f;

		if (angle >= 180.0f) angle -= 180.0f;
		if (angle <= -180.0f) angle += 180.0f;

		dObject->setRotation(angle);
}

void Racket::update() {

		getSimTime();
		getElapsedTime();
		velocityVector = quickVelocityVector / (float)Game::getSimPerFrame();
		quickVelocityVector = { 0.0f, 0.0f };

		velocity = calcVelocityFromVelocityVector(velocityVector);
		if (velocity != 0.0f) {
			unitVector = calcUnitVector(velocityVector, velocity);
		}
		
		
		
}

void Racket::simulation() {

	
	if (realPos != oldRealPos) {
		if ((realPos.x - oldRealPos.x) > (RACKET_DEFAULT_MAX_VELOCITY * simTime)) realPos.x = oldRealPos.x + (RACKET_DEFAULT_MAX_VELOCITY * simTime);
		if ((realPos.x - oldRealPos.x) < (-RACKET_DEFAULT_MAX_VELOCITY * simTime)) realPos.x = oldRealPos.x - (RACKET_DEFAULT_MAX_VELOCITY * simTime);
		if ((realPos.y - oldRealPos.y) > (RACKET_DEFAULT_MAX_VELOCITY * simTime)) realPos.y = oldRealPos.y + (RACKET_DEFAULT_MAX_VELOCITY * simTime);
		if ((realPos.y - oldRealPos.y) < (-RACKET_DEFAULT_MAX_VELOCITY * simTime)) realPos.y = oldRealPos.y - (RACKET_DEFAULT_MAX_VELOCITY * simTime);
	}

	if (!isAI)
	{
		
	
		quickVelocityVector += calcVelocityVector(oldRealPos, realPos, simTime);
		dObject->setPosition(Physics::swapY(Physics::calcPixelVector(realPos)));
		oldRealPos = realPos;
		
	}
	else
	{
		
		quickVelocityVector += calcVelocityVector(oldRealPos, realPos, simTime);
		oldRealPos = realPos;
	}
	
}

Racket::~Racket() {
	Collision::getRacketCollisionVector()._delete(this);
}



void Racket::test() {
	
}
