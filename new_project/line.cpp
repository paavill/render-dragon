#include "line.h"
#include <iostream>
line::line()
{

};

line::line(float x1, float y1, float x2, float y2)
{
	lin[0].position = sf::Vector2f(x1, y1);
	lin[1].position = sf::Vector2f(x2, y2);
	dx = lin[1].position.x - lin[0].position.x;
	dy = lin[1].position.y - lin[0].position.y;
	leaght = sqrt(dx * dx + dy * dy);
	for (int i = 0; i < 2; i++)
	{
		lin[i].color = sf::Color(255, 255, 255, 100);
	}
};

void line::lineMoving(float x1, float y1,float rot)
{
	int cof = 0;
	if (dy < 0)
	{
		cof = -1;
	}
	else
	{
		cof = 1;
	}
	float sn = (float)dy / leaght;
	float cs = (float)dx / leaght;
	lin[0].position = sf::Vector2f(x1, y1);
	lin[1].position = sf::Vector2f(x1 + (float)leaght * cos(rot +cof*acos(cs)), y1 + (float)leaght * sin(rot+cof*acos(cs)));
}

bool line::crossCheck(line * obj)
{
	//sf::Vector2f vecLights = lin[1].position - lin[0].position;
	sf::Vector2f vec1 = (*obj).lin[0].position - lin[0].position;
	sf::Vector2f vec2 = (*obj).lin[0].position - lin[1].position;
	sf::Vector2f vec3 = (*obj).lin[1].position - lin[0].position;
	sf::Vector2f vec4 = (*obj).lin[1].position - lin[1].position;
	float cross1 = vec1.x * vec2.x + vec1.y * vec2.y;
	float cross2 = vec3.x * vec4.x + vec3.y * vec4.y;
	std::cout << "!!!" << cross1 << "!!!\n";
	if (cross1 < 0 || cross2 < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void line::drawLine(sf::RenderWindow * window)
{
	(*window).draw(lin, 2, sf::Lines);
}
