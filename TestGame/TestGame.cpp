#include <conio.h>
#include "SnowEngine.h"
#include <windows.h>
#include <iostream>

int main()
{
	snow::Gui gui;

	snow::Actor actor1(&gui);
	snow::Actor actor2(&gui);

	snow::TextureComponent component1(&actor1, "1.png");
	snow::TextureComponent component2(&actor2, "1.png");
	component2.setTextureRect(snow::IntRect(500, 500, 200, 200));

	snow::Window window("Hello world!", snow::Vector2i(800, 600));
	window.attach(gui);

	_getch();

	gui.follow(&actor2);

	_getch();

	actor2.move(snow::Vector2f(500, 500), 2000);

	_getch();
}