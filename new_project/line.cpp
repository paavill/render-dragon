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
	float sn = (float)dy / leaght;
	float cs = (float)dx / leaght;
	if (sn > 0)
	{
		if (cs > 0)
		{
			sn = asin(sn);
		}
		else
		{
			sn = M_PI - asin(sn);
		}
	}
	else
	{
		if (cs > 0)
		{
			sn = 2*M_PI + asin(sn);
		}
		else
		{
			sn = M_PI - asin(sn);
		}
	}
	lin[0].position = sf::Vector2f(x1, y1);
	lin[1].position = sf::Vector2f(x1 + (float)leaght * cos(rot + sn), y1 + (float)leaght * sin(rot + sn));
};

bool line::crossCheck(line* obj)
{
	bool cross1 = false;
	bool cross2 = false;
	sf::Vector2f main = (*obj).lin[1].position - (*obj).lin[0].position;
	main.x = main.x / (*obj).leaght;
	main.y = main.y / (*obj).leaght;

	sf::Vector2f vec1n = -(*obj).lin[0].position + lin[0].position;
	float leaght = sqrt(vec1n.x * vec1n.x + vec1n.y * vec1n.y);
	vec1n.x = vec1n.x / leaght;
	vec1n.y = vec1n.y / leaght;

	sf::Vector2f vecKN = vec1n - main;

	sf::Vector2f vec2k = -(*obj).lin[0].position + lin[1].position;
	leaght = sqrt(vec2k.x * vec2k.x + vec2k.y * vec2k.y);
	vec2k.x = vec2k.x / leaght;
	vec2k.y = vec2k.y / leaght;

	sf::Vector2f vecKK = vec2k - main;

	double sklr = vecKN.x * vecKK.x + vecKN.y * vecKK.y;

	if (sklr <= 0)
	{
		cross1 = true;
	}

	main = -(*obj).lin[1].position + (*obj).lin[0].position;
	main.x = main.x / (*obj).leaght;
	main.y = main.y / (*obj).leaght;

	vec1n = -(*obj).lin[1].position + lin[0].position;
	leaght = sqrt(vec1n.x * vec1n.x + vec1n.y * vec1n.y);
	vec1n.x = vec1n.x / leaght;
	vec1n.y = vec1n.y / leaght;

	vecKN = vec1n - main;

	vec2k = -(*obj).lin[1].position + lin[1].position;
	leaght = sqrt(vec2k.x * vec2k.x + vec2k.y * vec2k.y);
	vec2k.x = vec2k.x / leaght;
	vec2k.y = vec2k.y / leaght;

	vecKK = vec2k - main;

	sklr = vecKN.x * vecKK.x + vecKN.y * vecKK.y;

	if (sklr <= 0)
	{
		cross2 = true;
	}
	
	if (cross1 == true && cross2 == true)
	{
		return true;
	}
	else
	{
		return false;
	}
};

float line::crossDist(line* obj, sf::RenderWindow* window)
{
	sf::Vector2f main = (*obj).lin[1].position - (*obj).lin[0].position;
	main.x = main.x / (*obj).leaght;
	main.y = main.y / (*obj).leaght;

	sf::Vector2f vec1 = -(*obj).lin[0].position + lin[0].position;
	float leaghtt = sqrt(vec1.x * vec1.x + vec1.y * vec1.y);
	vec1.x = vec1.x / leaghtt;
	vec1.y = vec1.y / leaghtt;

	double COSsklr1 = main.x * vec1.x + main.y * vec1.y;
	COSsklr1 = acos(COSsklr1);

	main = lin[1].position - lin[0].position;
	main.x = (float)main.x / leaght;
	main.y = (float)main.y / leaght;

	vec1 = (*obj).lin[0].position - lin[0].position;
	leaghtt = sqrt(vec1.x * vec1.x + vec1.y * vec1.y);
	vec1.x = vec1.x / leaghtt;
	vec1.y = vec1.y / leaghtt;

	double COSsklr2 = main.x * vec1.x + main.y * vec1.y;
	COSsklr2 = acos(COSsklr2);

	double SINsklr3 = sin(M_PI - COSsklr1 - COSsklr2);

	double a = leaghtt / SINsklr3;
	
	double SINsklr2 = sqrt(1 - cos(COSsklr2)* cos(COSsklr2));

	a = a * SINsklr2;

	SINsklr2 = (*obj).dy / (*obj).leaght;
	COSsklr2 = (*obj).dx / (*obj).leaght;

	main.x = a * COSsklr2;
	main.y = a * SINsklr2;

	sf::RectangleShape r;
	sf::Vertex point;
	point.position = (*obj).lin[0].position + main;
	
	r.setSize(sf::Vector2f(10, 10));
	r.setFillColor(sf::Color(255, 0, 0, 128));
	r.setPosition(point.position.x - 5, point.position.y - 5);
	(*window).draw(r);
	main = point.position - lin[0].position;

	leaghtt = sqrt(main.x * main.x + main.y * main.y);
	return leaghtt;
};

void line::drawLine(sf::RenderWindow * window)
{
	(*window).draw(lin, 2, sf::Lines);
}
