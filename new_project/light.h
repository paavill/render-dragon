#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"
#include "line.h"
class light
{
public:

	line lineSightArr[10];

	light(player * gamer);

	void lineSight(player * gamer, sf::RenderWindow * window);

};

