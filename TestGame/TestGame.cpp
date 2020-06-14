#include <conio.h>
#include "SnowEngine.h"

int main()
{
	snow::Window window("Hello", snow::Vector2i(800, 600));

	snow::Gui gui;
	window.attach(gui);

	_getch();
}