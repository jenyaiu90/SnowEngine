#include <conio.h>
#include "SnowEngine.h"
#include <windows.h>
#include <iostream>

int main()
{
	snow::Gui gui;

	snow::Actor guiActor(&gui);

	snow::TextureComponent text(&guiActor, "1.png");
	text.setTextureRect(snow::IntRect(500, 500, 300, 300));

	snow::Window window("Hello!", snow::Vector2i(800, 600));
	window.attach(gui);

	_getch();
	text.setEnable(false);
	_getch();
	text.setEnable(true);
	_getch();
	text.setColor(snow::Color(255, 255, 0));
	_getch();
	guiActor.move(snow::Vector2f(200, 200), 3000);

	_getch();
}