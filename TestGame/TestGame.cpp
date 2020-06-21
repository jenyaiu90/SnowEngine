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
	snow::Actor levelActor(&level, snow::Vector2i(400, 300));
	snow::Actor guiActor(&gui, snow::Vector2i(400, 300));
	snow::TextureComponent levelComponent(&levelActor, "1.png");
	levelComponent.setTextureRect(snow::IntRect(0, 0, 50, 50));
	snow::TextureComponent guiComponent(&guiActor, "1.png");
	guiComponent.setTextureRect(snow::IntRect(0, 0, 50, 50));
	snow::Window window("Hi!", snow::Vector2i(800, 600));
	window.attach(level);
	window.attach(gui);

	window.getInput()->mouseMoved = [](snow::Vector2f vector)
	{
		std::cout << vector.x << " " << vector.y << std::endl;
	};
	
	_getch();
}