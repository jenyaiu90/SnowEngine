#include <conio.h>
#include "SnowEngine.h"
#include "Component/Visible/TextureComponent.h"
#include "Utilites/Animation.h"
#include "Component/Collision/RectCollisionComponent.h"
#include <windows.h>
#include <iostream>

class MyAnimation : public snow::Animation<snow::Vector2f, int>
{
public:
	snow::Vector2f animate(const int& input) override
	{
		if (input <= 0)
		{
			return snow::Vector2f(0.f, 0.f);
		}
		else if (input >= 2000)
		{
			return snow::Vector2f(300.f, 300.f);
		}
		else
		{
			float x = input / 1000.f;
			float y;
			if (x < 1)
			{
				y = x * x;
			}
			else
			{
				y = -x * x + 4 * x - 2;
			}
			y *= 150;
			return snow::Vector2f(y, y);
		}
	}
};

int main()
{
	snow::Level level;
	snow::Gui gui;

	snow::Actor levelActor(&level);
	snow::Actor guiActor(&gui);

	snow::ClickableComponent levelComponent(&levelActor, snow::Vector2f(200, 200));
	snow::ClickableComponent guiComponent(&guiActor, snow::Vector2f(100, 100));

	snow::Window window("Hello!", snow::Vector2i(800, 600));
	window.attach(level);
	window.attach(gui);
	
	levelComponent.onMousePressed = [](snow::MouseButton button, snow::Vector2f position)
	{
		std::cout << "Level" << std::endl;
	};
	guiComponent.onMousePressed = [](snow::MouseButton button, snow::Vector2f position)
	{
		std::cout << "GUI" << std::endl;
	};
	
	_getch();
}