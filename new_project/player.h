#pragma once
#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

class player
{
public:
	float x;
	float y;
	float rot;
	float sens = 10; //���������������� ������, ��������� � ����� ������

	player(float xk, float yk, float rotk);

	void moving(int deltaTime);

	void rotation(sf::RenderWindow * window);
};

