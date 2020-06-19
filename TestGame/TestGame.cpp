#include <conio.h>
#include "SnowEngine.h"
#include "Component/Visible/AnimationComponent.h"
#include "Utilites/TextureAnimation/AdvancedTextureAnimation.h"
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
	snow::ArrayList<int> durations(5);
	durations.add(500);
	durations.add(1500);
	durations.add(1000);
	durations.add(2000);
	durations.add(1000);

	snow::ArrayList<snow::Vector2i> positions(5);
	positions.add(snow::Vector2i(500, 500));
	positions.add(snow::Vector2i(510, 510));
	positions.add(snow::Vector2i(520, 520));
	positions.add(snow::Vector2i(530, 530));
	positions.add(snow::Vector2i(540, 540));

	snow::AdvancedTextureAnimation anim(snow::Vector2i(200, 200), durations, positions);

	snow::Gui gui;
	snow::Actor actor(&gui);
	snow::AnimationComponent component(&actor, "1.png", &anim);
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