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

	Keyboard key;
	Event event;
	Mouse mouse;
	Vector2i vec;
	sf::RectangleShape rec;
	
	player gamer = player(20, 20, 0);
	light ligh = light(&gamer);
	line dirline = line(gamer.x,gamer.y,gamer.x + 80, gamer.y);
	line obj[8];
	
	obj[0] = line(0,0,1024,0);
	obj[1] = line(1024, 0, 1024, 720);
	obj[2] = line(1024, 720, 0, 720);
	obj[3] = line(0, 720, 0, 0);
	obj[4] = line(200, 360, 200, 700);
	obj[5] = line(180, 360, 180, 700);
	obj[6] = line(200, 360, 180, 360);
	obj[7] = line(200, 700, 180, 700);
	mainRender renderM;
	float dist[NUMBRAYS];

	int cw = 1024;
	int ch = 720;

	int w = 0;
	int h = 0;
	while (window.isOpen())
	{
		if (key.isKeyPressed(key.LControl))
		{
			window.setMouseCursorVisible(true);
		}
		else
		{
			window.setMouseCursorVisible(false);
		}
		if (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		w = window.getSize().x;
		h = window.getSize().y;
		if (w<cw || w>cw || h<ch || h>ch)
		{
			cw = w;
			ch = h;
			window.setSize(sf::Vector2u(w, h));
		}
		window.setVerticalSyncEnabled(true);
		window.setFramerateLimit(60);
		window.clear(Color(0, 0, 0, 0));


		gamer.rotation(&window);
		gamer.moving();
		rec.setSize(sf::Vector2f(20, 20));
		rec.setPosition(gamer.x, gamer.y);
		rec.setFillColor(Color(255, 255, 255, 128));
		dirline.lineMoving(gamer.x+10, gamer.y+10, gamer.rot);
		//dirline.drawLine(&window);
	
		renderM.floarANskyRend(&window);
		for (int i = 0; i < 8; i++)
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

		window.display();
	}
	return 0;
}