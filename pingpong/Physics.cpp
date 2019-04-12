#include "pch.h"
#include "Physics.h"

Physics::Physics(float viscosity, float grav, float wind) {
	this->wind = wind;
	this->viscosity = viscosity;
	this->grav = grav;
	this->pixelToRealRatio = PHYSICS_DEFAULT_PIXEL_TO_REAL_RATIO;
};

Physics::Physics() {
	this->wind = 0.0f;
	this->viscosity = PHYSICS_DEFAULT_VISCOSITY;
	this->grav = PHYSICS_DEFAULT_GRAV;
	this->pixelToRealRatio = PHYSICS_DEFAULT_PIXEL_TO_REAL_RATIO;
}