#pragma once
#include <SFML/Graphics.hpp>
#include "line.h"
#include "player.h"
#include<iostream>
#include<Windows.h>
#ifndef NUMBRAYS
#define NUMBRAYS 340
#endif // !NUMBRAYS

class light
{

public:

	line lineSightArr[NUMBRAYS];

	light(player * gamer);

	void lineSight(player * gamer, sf::RenderWindow * window, line* obj, float* dist);

};

