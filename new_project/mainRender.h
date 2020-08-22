#pragma once
#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include "light.h";
class mainRender
{
public:
	mainRender();

	void ps3dObjRend(sf::RenderWindow * window, float* dist);
};

