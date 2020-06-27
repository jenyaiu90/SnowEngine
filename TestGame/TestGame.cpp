#include <conio.h>
#include "SnowEngine.h"
#include <windows.h>
#include <iostream>

int main()
{
	snow::Gui gui;

	snow::Actor guiActor(&gui);

	snow::TextComponent text(&guiActor, "Hello!", 30, "font.ttf");

	snow::Window window("Hello!", snow::Vector2i(800, 600));
	window.attach(gui);

	_getch();
	text.setColor(snow::Color(255, 255, 0));
	_getch();
	text.setSize(20);

	_getch();
}