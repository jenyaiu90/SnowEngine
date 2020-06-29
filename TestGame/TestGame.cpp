#include <conio.h>
#include "SnowEngine.h"
#include <windows.h>
#include <iostream>

int main()
{
	snow::Gui gui;

	snow::Actor guiActor(&gui);

	snow::InputComponent texture(&guiActor, 30, "font.ttf", snow::Vector2f(500, 100));

	snow::Window window("Hello!", snow::Vector2i(800, 600));
	window.attach(gui);

	_getch();
	texture.setEnable(false);
	_getch();
	texture.setEnable(true);
	_getch();
	texture.setColor(snow::Color(255, 255, 0));
	_getch();
	guiActor.move(snow::Vector2f(200, 200), 3000);

	_getch();
}