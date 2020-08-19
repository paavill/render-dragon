#include "light.h"
#include "line.h"
#include "player.h"
#include<iostream>
#include<Windows.h>

light::light(player * gamer) 
{
	for (int i = 0; i < 10; i++)
	{
		lineSightArr[i] = line((*gamer).x + 10, (*gamer).y + 10, (*gamer).x + 10 + (float)80 * cos((*gamer).rot - M_PI/6 + M_PI*i/27), (*gamer).y + 10 + (float)80 * sin((*gamer).rot -M_PI / 6 + M_PI * i / 27));
	}
};

void light::lineSight(player * gamer, sf::RenderWindow * window, line * obj)
{
	for (int i = 0; i < 10; i++)
	{
		lineSightArr[i].lineMoving((*gamer).x + 10, (*gamer).y + 10, gamer->rot);
		if (lineSightArr[i].crossCheck(obj))
		{
			lineSightArr[i].drawLine(window);
		}
	}
};
