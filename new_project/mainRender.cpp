#include "mainRender.h"
mainRender::mainRender()
{

};

void mainRender::ps3dObjRend(sf::RenderWindow* window, float * dist)
{
	sf::RectangleShape rec[NUMBRAYS];
	float h = 0;
	int cl = 0;
	float width = 1024 / NUMBRAYS;
	for (int i = 0; i < NUMBRAYS; i++)
	{
		h = (float)22/ dist[i];
		
		cl = (int)255 * h;
		if (cl > 255)
		{
			cl = 255;
		}
		rec[i].setFillColor(sf::Color(cl, cl, cl, 255));
		if (dist[i] > 0)
		{
			rec[i].setSize(sf::Vector2f(width,(float) h * 720));
			rec[i].setPosition(width * i, 360 - (float)h * 360);
			window->draw(rec[i]);
		}
	}
}

void mainRender::floarRend(sf::RenderWindow* window)
{
	sf::RectangleShape floar[NUMBRAYS];
	for (int k = 0; k < NUMBRAYS; k++)
	{
		floar[k].setFillColor(sf::Color(k + 20, k + 20, 0, 255));
		floar[k].setSize(sf::Vector2f(1024, 3.6));
		floar[k].setPosition(sf::Vector2f(0, 360 + 3.6 * k));
		(*window).draw(floar[k]);
	}
}