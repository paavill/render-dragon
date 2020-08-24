#include "player.h"
#include <iostream>
#include <Windows.h>


player::player(float xk, float yk, float rotk)
{
	x = xk;
	y = yk;
	rot = rotk;
};

void player::moving()
{
	sf::Keyboard key;

	if (key.isKeyPressed(key.W))
	{
		x = x + (2 * cos(rot)) / 1;
		y = y + (2 * sin(rot)) / 1;
	}
	if (key.isKeyPressed(key.S))
	{
		x = x - (2 * cos(rot)) / 1;
		y = y - (2 * sin(rot)) / 1;
	}
	if (key.isKeyPressed(key.A))
	{
		x = x + (2 * sin(rot)) / 1;
		y = y - (2 * cos(rot)) / 1;
	}
	if (key.isKeyPressed(key.D))
	{
		x = x - (2 * sin(rot)) / 1;
		y = y + (2 * cos(rot)) / 1;
	}
};

void player::rotation(sf::RenderWindow * window)
{
	
	sf::Mouse mouse;
	sf::Keyboard key;

	int deltaMouse = 0;

	if (!key.isKeyPressed(key.LControl))
	{
		mouse.setPosition(sf::Vector2i((*window).getSize().x, (*window).getSize().y)/2, (*window));
		deltaMouse = (*window).getSize().x / 2;
		Sleep(1);
		deltaMouse = mouse.getPosition((*window)).x - deltaMouse;
		rot = rot + sens*(float)deltaMouse / (float)(*window).getSize().x / 2;
		if (rot < 0)
		{
			rot = 2 * M_PI - 1e-4;
		}
		else if (rot > 2 * M_PI)
		{
			rot = 0 + 1e-4;
		}

	}
};
