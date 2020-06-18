#include <conio.h>
#include "SnowEngine.h"
#include "Component/Visible/TextureComponent.h"
#include "Utilites/Animation.h"
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
	snow::Gui gui;
	snow::Actor actor(&gui);
	snow::TextureComponent component(&actor, "1.png", snow::Vector2f());
	snow::Window window("Hi!", snow::Vector2i(800, 600));
	window.attach(gui);

	Sleep(2000);

	MyAnimation an;
	auto first_time = std::chrono::system_clock::now();
	auto second_time = first_time;
	int c = 0;
	while (c <= 3000)
	{
		second_time = std::chrono::system_clock::now();
		c += (second_time - first_time).count() / 10000;
		first_time = second_time;
		actor.setPosition(an.animate(c));
	}

	_getch();
}