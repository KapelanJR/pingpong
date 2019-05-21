#pragma once

#include "ObjectsVector.h"
#include "Gameplay.h"

class Game {
private:
	float licz;
	static sf::RenderWindow windowObj;
	static sf::Clock clock,clock1;
	
	static sf::Clock frameClock;
	static ObjectsVector<UpdateObject*> updateVector;
	static ObjectsVector<sf::Drawable*> drawVector;
	
	static const int simPerFrame;
	static float lastTime;
	static float elapsedTime;
	static float simTime;

	sf::View view;
	sf::Event _event;

	static void calcTimes();

public:
	static float timeForBall;
	Game(int xSize, int ySize, int refreshRate, bool verticalSync, std::string windowTitle);

	static Gameplay *gameplay;
	static sf::RenderWindow &getWindowObj();
	static float getTime();
	static int getSimPerFrame();
	static float getElapsedTime();
	static float getSimTime();
	static float getTimeForBall();
	static ObjectsVector<UpdateObject*>& getUpdateVector();
	static ObjectsVector<sf::Drawable*>& getDrawVector();
	static void startGameplay();
	void manageWindowEvents();
	void updateObjects();
	void drawObjects();
	void run();
	void tests();

	~Game();
};

