    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: CircleColisionComponent.cpp //
////////////////////////////////////////

#include "CircleCollisionComponent.h"
#include "RectCollisionComponent.h"

snow::CircleCollisionComponent::CircleCollisionComponent(snow::Actor* actor,
														 sf::RenderWindow* window,
														 float radius, snow::Vector2f pos) :
	CollisionComponent(actor, window, "circle", pos),
	radius_(radius),
	first_(((getWorldPosition() - Vector2f(radius_, radius_)) / SEGMENT_SIZE).floor()),
	last_(((getWorldPosition() + Vector2f(radius_, radius_)) / SEGMENT_SIZE).floor())
{
	std::lock_guard<std::mutex> lock(collisionsMutex_);
	int windowId = collisions_.findKey(window_);
	if (windowId == -1)
	{
		collisions_.set(window_, Dictionary<Vector2i, ArrayList<CollisionComponent*>>());
		windowId = collisions_.findKey(window_);
	}

	for (int i = first_.x; i <= last_.x; i++)
	{
		for (int j = first_.y; j <= last_.y; j++)
		{
			addToSegment_(i, j, windowId);
		}
	}
}

snow::CircleCollisionComponent::~CircleCollisionComponent()
{
	std::lock_guard<std::mutex> lock(collisionsMutex_);
	int windowId = collisions_.findKey(window_);
	for (int i = first_.x; i <= last_.x; i++)
	{
		for (int j = first_.y; j <= last_.y; j++)
		{
			removeFromSegment_(i, j, windowId);
		}
	}
}

void snow::CircleCollisionComponent::actorMove(snow::Vector2f to)
{
	Vector2i newFirst = ((getWorldPosition() - Vector2f(radius_, radius_)) / SEGMENT_SIZE).floor();
	Vector2i newLast = ((getWorldPosition() + Vector2f(radius_, radius_)) / SEGMENT_SIZE).floor();
	std::lock_guard<std::mutex> lock(collisionsMutex_);
	int windowId = collisions_.findKey(window_);
	if (newFirst.x > first_.x)
	{
		for (int i = first_.y; i <= last_.y; i++)
		{
			removeFromSegment_(first_.x, i, windowId);
		}
	}
	else if (newFirst.x < first_.x)
	{
		for (int i = first_.y; i <= last_.y; i++)
		{
			addToSegment_(newFirst.x, i, windowId);
		}
	}

	if (newFirst.y > first_.y)
	{
		for (int i = first_.x; i <= last_.x; i++)
		{
			removeFromSegment_(i, first_.y, windowId);
		}
	}
	else if (newFirst.y < first_.y)
	{
		for (int i = first_.x; i <= last_.x; i++)
		{
			addToSegment_(i, newFirst.y, windowId);
		}
	}

	if (newLast.x < last_.x)
	{
		for (int i = first_.y; i <= last_.y; i++)
		{
			removeFromSegment_(last_.x, i, windowId);
		}
	}
	else if (newLast.x > last_.x)
	{
		for (int i = first_.y; i <= last_.y; i++)
		{
			addToSegment_(newLast.x, i, windowId);
		}
	}

	if (newLast.y < last_.y)
	{
		for (int i = first_.x; i <= last_.x; i++)
		{
			removeFromSegment_(i, last_.y, windowId);
		}
	}
	else if (newLast.y > last_.y)
	{
		for (int i = first_.x; i <= last_.x; i++)
		{
			addToSegment_(i, newLast.y, windowId);
		}
	}
}

bool snow::CircleCollisionComponent::isCollide(const snow::CollisionComponent* collision) const
{
	if (collision->getType() == "circle")
	{
		return sqrt(pow(getWorldPosition().x - collision->getWorldPosition().x, 2) +
					pow(getWorldPosition().y - collision->getWorldPosition().y, 2)) <=
			   getRadius() + static_cast<const CircleCollisionComponent*>(collision)->getRadius();
	}
	else if (collision->getType() == "rectangle")
	{
		Vector2f fo = collision->getWorldPosition();
		Vector2f lo = fo + (static_cast<const RectCollisionComponent*>(collision))->getSize();
		Vector2f worldPos = getWorldPosition();

		if (worldPos.x <= lo.x && worldPos.x >= fo.x &&
			worldPos.y <= lo.y && worldPos.y >= fo.y)
		{
			return true;
		}
		else
		{
			float forSqrt = pow(radius_, 2) - pow(fo.x - worldPos.x, 2);
			if (forSqrt >= 0)
			{
				float sqr = sqrt(forSqrt);
				if (worldPos.y + sqr >= fo.y && worldPos.y + sqr <= lo.y ||
					worldPos.y - sqr >= fo.y && worldPos.y - sqr <= lo.y)
				{
					return true;
				}
			}

			forSqrt = pow(radius_, 2) - pow(lo.x - worldPos.x, 2);
			if (forSqrt >= 0)
			{
				float sqr = sqrt(forSqrt);
				if (worldPos.y + sqr >= fo.y && worldPos.y + sqr <= lo.y ||
					worldPos.y - sqr >= fo.y && worldPos.y - sqr <= lo.y)
				{
					return true;
				}
			}

			forSqrt = pow(radius_, 2) - pow(fo.y - worldPos.y, 2);
			if (forSqrt >= 0)
			{
				float sqr = sqrt(forSqrt);
				if (worldPos.x + sqr >= fo.x && worldPos.x + sqr <= lo.x ||
					worldPos.x - sqr >= fo.x && worldPos.x - sqr <= lo.x)
				{
					return true;
				}
			}

			forSqrt = pow(radius_, 2) - pow(lo.y - worldPos.y, 2);
			if (forSqrt >= 0)
			{
				float sqr = sqrt(forSqrt);
				if (worldPos.x + sqr >= fo.x && worldPos.x + sqr <= lo.x ||
					worldPos.x - sqr >= fo.x && worldPos.x - sqr <= lo.x)
				{
					return true;
				}
			}
		}
		return false;
	}
	else
	{
		return collision->isCollide(this);
	}
}

float snow::CircleCollisionComponent::getRadius() const
{
	return radius_;
}