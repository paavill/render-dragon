#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "player.h"
#include "light.h"
#include "mainRender.h"

using namespace std;
using namespace sf;

int main()
{
	VideoMode vmode;
	vmode.height = 720;
	vmode.width = 1024;
	RenderWindow window(vmode, "something!");

	Time tm;
	int time = 0;
	int time1 = 0;
	int dtime = 0;
	Keyboard key;
	Event event;
	Mouse mouse;
	Vector2i vec;
	sf::RectangleShape rec;
	
	player gamer = player(20, 20, 0);
	light ligh = light(&gamer);
	line dirline = line(gamer.x,gamer.y,gamer.x + 80, gamer.y);
	line obj = line(512, 200, 512, 500);
	mainRender renderM;
	float dist[NUMBRAYS];
	while (window.isOpen())
	{
		time = tm.asMilliseconds();
		if (key.isKeyPressed(key.LControl))
		{
			window.setMouseCursorVisible(true);
		}
		else
		{
			window.setMouseCursorVisible(false);
		}

		time = tm.asMicroseconds();
		if (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.setFramerateLimit(60);
		window.clear(Color(0, 0, 0, 0));


		gamer.rotation(&window);
		gamer.moving(time);
		rec.setSize(sf::Vector2f(20, 20));
		rec.setPosition(gamer.x, gamer.y);
		rec.setFillColor(Color(255, 255, 255, 128));
		dirline.lineMoving(gamer.x+10, gamer.y+10, gamer.rot);
		dirline.drawLine(&window);
		obj.drawLine(&window);
		ligh.lineSight(&gamer, &window, &obj, dist);
		renderM.ps3dObjRend(&window, dist);
		window.draw(rec);

		std::cout << gamer.rot <<"|x:"<<gamer.x<<"|y:"<<gamer.y<<"|\n";

		time1 = tm.asMilliseconds();
		dtime = time1 - time;
		if (dtime < 1)
		{
			dtime = 1;
		}
		window.setTitle("somesing!"+to_string(1000 / dtime));
		window.display();
	}
	return 0;
}