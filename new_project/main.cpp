#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "light.h"

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1024, 720), "something!");

	Time tm;
	sf::Int64 time = 0;
	Keyboard key;
	Event event;
	Mouse mouse;
	Vector2i vec;
	sf::RectangleShape rec;
	
	player gamer = player(20, 20, 0);
	light ligh = light(&gamer);
	line dirline = line(gamer.x,gamer.y,gamer.x + 80, gamer.y);
	line obj = line(512, 200, 512, 520);

	while (window.isOpen())
	{
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
		ligh.lineSight(&gamer, &window, &obj);
		window.draw(rec);

		std::cout << gamer.rot <<"|x:"<<gamer.x<<"|y:"<<gamer.y<<"|"<<dirline.lin[0].position.x<<"\n";

		time = tm.asMicroseconds();
		window.display();
	}
	return 0;
}