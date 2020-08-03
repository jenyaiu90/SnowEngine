    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: RectColisionComponent.cpp   //
////////////////////////////////////////

#include "RectCollisionComponent.h"

const std::string snow::RectCollisionComponent::RECT_TYPE = "rectangle";

snow::RectCollisionComponent::RectCollisionComponent(Actor* actor,
													 sf::RenderWindow* window,
													 Vector2f size, Vector2f pos) :
	RectCollisionComponent(actor, window, size, DEFAULT_KIND, pos)
{
}

snow::RectCollisionComponent::RectCollisionComponent(Actor* actor,
													 sf::RenderWindow* window,
													 Vector2f size, const std::string& kind,
													 Vector2f pos) :
	CollisionComponent(actor, window, RECT_TYPE, kind, pos),
	size_(size),
	first_((getWorldPosition() / SEGMENT_SIZE).floor()),
	last_(((getWorldPosition() + size) / SEGMENT_SIZE).floor())
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

snow::RectCollisionComponent::~RectCollisionComponent()
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

void snow::RectCollisionComponent::actorMove(snow::Vector2f to)
{
	Vector2i newFirst = ((to + position_) / SEGMENT_SIZE).floor();
	Vector2i newLast = ((to + position_ + size_) / SEGMENT_SIZE).floor();
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

bool snow::RectCollisionComponent::isCollide(const snow::CollisionComponent* collision) const
{
	if (collision->getType() == RECT_TYPE)
	{
		Vector2f ft = getWorldPosition();
		Vector2f lt = ft + size_;
		Vector2f fo = collision->getWorldPosition();
		Vector2f lo = fo + (static_cast<const RectCollisionComponent*>(collision))->getSize();

		return fo.x <= lt.x && fo.x >= ft.x && fo.y <= lt.y && fo.y >= ft.y ||
			   lo.x <= lt.x && lo.x >= ft.x && lo.y <= lt.y && lo.y >= ft.y ||
			   fo.x <= lt.x && fo.x >= ft.x && lo.y <= lt.y && lo.y >= ft.y ||
			   lo.x <= lt.x && lo.x >= ft.x && fo.y <= lt.y && fo.y >= ft.y ||
			   ft.x <= lo.x && ft.x >= fo.x && ft.y <= lo.y && ft.y >= fo.y ||
			   lt.x <= lo.x && lt.x >= fo.x && lt.y <= lo.y && lt.y >= fo.y ||
			   ft.x <= lo.x && ft.x >= fo.x && lt.y <= lo.y && lt.y >= fo.y ||
			   lt.x <= lo.x && lt.x >= fo.x && ft.y <= lo.y && ft.y >= fo.y; // Are you a perfectionist?
	}
	else
	{
		return collision->isCollide(this);
	}
}

snow::Vector2f snow::RectCollisionComponent::getSize() const
{
	return size_;
}