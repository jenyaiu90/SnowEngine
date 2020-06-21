#include <conio.h>
#include "SnowEngine.h"
#include "Component/Visible/AnimationComponent.h"
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
	snow::Gui gui;
	snow::Actor actor1(&gui);
	snow::Actor actor2(&gui, snow::Vector2i(200, 200));
	snow::Window window("Hi!", snow::Vector2i(800, 600));
	snow::RectCollisionComponent component1(&actor1, window.getWindow(), snow::Vector2f(300, 300));
	snow::RectCollisionComponent component2(&actor2, window.getWindow(), snow::Vector2f(100, 100));
	window.attach(gui);
	
	std::cout << component1.isCollide(&component2);

	_getch();
}