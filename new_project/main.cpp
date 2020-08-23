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
	line obj[5];
	
	obj[0] = line(0,0,1024,0);
	obj[1] = line(1024, 0, 1024, 720);
	obj[2] = line(1024, 720, 0, 720);
	obj[3] = line(0, 720, 0, 0);
	obj[4] = line(200, 360, 100, 720);
	mainRender renderM;
	float dist[NUMBRAYS];
	while (window.isOpen())
	{
		time = tm.asMicroseconds();
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
		//dirline.drawLine(&window);
	
		renderM.floarANskyRend(&window);
		for (int i = 0; i < 5; i++)
		{
			//obj[i].drawLine(&window);
			ligh.lineSight(&gamer, &window, &obj[i], dist);
			renderM.ps3dObjRend(&window, dist);
			for (int k = 0; k < NUMBRAYS; k++)
			{
				dist[k] = -1;
			}
		}
		
		//window.draw(rec);

		std::cout << gamer.rot <<"|x:"<<gamer.x<<"|y:"<<gamer.y<<"|\n";

		time1 = tm.asMicroseconds();
		dtime = time1 - time;
		if (dtime < 1)
		{
			dtime = 1;
		}
		window.setTitle("somesing!"+to_string( dtime));
		window.display();
	}
	return 0;
}