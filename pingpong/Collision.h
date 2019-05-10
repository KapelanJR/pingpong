#pragma once

#include "Racket.h"
#include "Ball.h"
#include "Wall.h"
#include "ObjectsVector.h"

class Collision {
private:
	static ObjectsVector<Wall*> walls;
	static ObjectsVector<Racket*> rackets;
	static ObjectsVector<Ball*> balls;

	unsigned short ballRectCheck(Ball *ball, Rect *rect);
	void ballWallCol(Ball *ball, Wall *wall);
	void ballRacketCol(Ball *ball, Racket *racket);

public:
	
	static ObjectsVector<Wall*> &getWallCollisionVector();
	static ObjectsVector<Racket*> &getRacketCollisionVector();
	static ObjectsVector<Ball*> &getBallCollisionVector();

	void checkCollisions();

	
	
	
	~Collision();

	
};

