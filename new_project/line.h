#pragma once
#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
class line
{
public:
	sf::Vertex lin[2];
	int leaght;
	int dx;
	int dy;

	line();
	line(float x1, float y1, float x2, float y2);

	void lineMoving(float x1, float y1, float rot);
	void drawLine(sf::RenderWindow * window);
	bool crossCheck(line * obj);
};

