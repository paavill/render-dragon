#include "light.h"

light::light(player * gamer) 
{
	int del = 3 * (NUMBRAYS - 1);
	for (int i = 0; i < NUMBRAYS; i++)
	{
		lineSightArr[i] = line((*gamer).x + 10, (*gamer).y + 10, (*gamer).x + 10 + 180 * cos((*gamer).rot - M_PI/6 + M_PI*i/ del), (*gamer).y + 10 + 180 * sin((*gamer).rot - M_PI / 6 + M_PI * i / del));
	}
};

void light::lineSight(player * gamer, sf::RenderWindow * window, line * obj, float * dist)
{
	for (int i = 0; i < NUMBRAYS; i++)
	{
		lineSightArr[i].lineMoving((*gamer).x + 10, (*gamer).y + 10, gamer->rot);
		
		if (lineSightArr[i].crossCheck(obj))
		{
			dist[i] = lineSightArr[i].crossDist(obj, window);
			lineSightArr[i].drawLine(window);
		}
		else
		{
			dist[i] = (float)-1;
		}
	}
};
