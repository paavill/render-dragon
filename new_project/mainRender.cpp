#include "mainRender.h"
mainRender::mainRender()
{

};

void mainRender::ps3dObjRend(sf::RenderWindow* window, float * dist)
{
	sf::RectangleShape rec[NUMBRAYS];
	float h = 0;
	float width = 1024 / NUMBRAYS;
	for (int i = 0; i < NUMBRAYS; i++)
	{
		rec[i].setFillColor(sf::Color(255, 255, 255, 128));
		h = (float)20/ dist[i];
		if (dist[i] > 0)
		{
			rec[i].setSize(sf::Vector2f(width,(float) h * 720));
			rec[i].setPosition(width * i, 360 - (float)h * 360);
			window->draw(rec[i]);
		}
	}
}