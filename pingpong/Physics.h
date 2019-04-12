#pragma once

#define PHYSICS_DEFAULT_VISCOSITY 1.225f
#define PHYSICS_DEFAULT_GRAV 9.80665f
#define PHYSICS_DEFAULT_PIXEL_TO_REAL_RATIO 0.005f //Jeden piksel to 0,005 metra

#define PI 3.141592f

struct Physics {
	float viscosity, pressure, grav, wind, pixelToRealRatio;

	Physics(float viscosity, float grav, float wind);
	Physics();



};