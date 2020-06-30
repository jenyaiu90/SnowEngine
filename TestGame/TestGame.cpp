#include <conio.h>
#include "SnowEngine.h"
#include <windows.h>
#include <iostream>

int main()
{
	snow::Gui gui;

	snow::Actor guiActor(&gui);

	snow::InputComponent text(&guiActor, 30, "font.ttf", snow::Vector2f(500, 100));

	snow::Window window("Hello!", snow::Vector2i(800, 600));
	window.attach(gui);

	_getch();

	std::cout << snow::SaveLoad::startSaving("default") << std::endl;
	snow::SaveLoad::save("text", text.getText());
	snow::SaveLoad::save("hello", "Hello");
	std::cout << snow::SaveLoad::stopSaving() << std::endl;

	_getch();

	std::cout << snow::SaveLoad::startLoading("default") << std::endl;
	text.setText(snow::SaveLoad::load("hello") + snow::SaveLoad::load("text"));
	std::cout << snow::SaveLoad::stopLoading() << std::endl;

	_getch();
}