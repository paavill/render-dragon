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

void line::lineMoving(float x1, float y1, float rot)
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
	lin[1].position = sf::Vector2f(x1 + (float)leaght * cos(rot + cof * acos(cs)), y1 + (float)leaght * sin(rot + cof * acos(cs)));
};

bool line::crossCheck(line* obj)
{
	bool cross = false;
	sf::Vector2f main = (*obj).lin[1].position - (*obj).lin[0].position;
	main.x = main.x / (*obj).leaght;
	main.y = main.y / (*obj).leaght;

	sf::Vector2f vec1n = -(*obj).lin[0].position + lin[0].position;
	float leaght = sqrt(vec1n.x * vec1n.x + vec1n.y * vec1n.y);
	vec1n.x = vec1n.x / leaght;
	vec1n.y = vec1n.y / leaght;

	sf::Vector2f vecKN = vec1n - main;

	//,std::cout << chtv1 << "!!!\n";
	sf::Vector2f vec2k = -(*obj).lin[0].position + lin[1].position;
	leaght = sqrt(vec2k.x * vec2k.x + vec2k.y * vec2k.y);
	vec2k.x = vec2k.x / leaght;
	vec2k.y = vec2k.y / leaght;

	sf::Vector2f vecKK = vec2k - main;

	double sklr = vecKN.x * vecKK.x + vecKN.y * vecKK.y;

	if (sklr <= 0)
	{
		cross = true;
	}

	return cross;
};

float crossDist(line* obj)
{
	obj->
	return 20.f;
};

void line::drawLine(sf::RenderWindow * window)
{
	(*window).draw(lin, 2, sf::Lines);
}
