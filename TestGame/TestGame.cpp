#include <conio.h>
#include "SnowEngine.h"
#include "Component/Visible/TextureComponent.h"
#include <windows.h>

int main()
{
	snow::Gui gui;
	snow::Actor actor(&gui);
	snow::TextureComponent component(&actor, "1.png", snow::Vector2f());
	snow::Window window("Hi!", snow::Vector2i(800, 600));
	window.attach(gui);

	Sleep(2000);
	actor.move(snow::Vector2f(200, 200), 2000);
	

	_getch();
}