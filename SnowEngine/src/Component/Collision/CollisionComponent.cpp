    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: ColisionComponent.cpp       //
////////////////////////////////////////

#include "CollisionComponent.h"

snow::Dictionary<sf::RenderWindow*, snow::Dictionary<snow::Vector2i, // Yes, it can seem scary...
	snow::ArrayList<snow::CollisionComponent*>>> snow::CollisionComponent::collisions_;

snow::CollisionComponent::CollisionComponent(Actor* actor, sf::RenderWindow* window,
											 const std::string& type, Vector2f pos) :
	Component(actor, pos),
	type_(type),
	window_(window)
{
}

void snow::CollisionComponent::tick(const int& delta, sf::RenderWindow& window)
{
	// I`m useless!
}

snow::ArrayList<snow::CollisionComponent*> snow::CollisionComponent::checkCollision()
{
	ArrayList<CollisionComponent*> res;
	Dictionary<Vector2i, ArrayList<CollisionComponent*>>* dict = &collisions_[window_];
	// Mutex zone
	{
		std::lock_guard<std::mutex> lock(collisionsMutex_);
		for (int i = 0; i < segments_.length(); i++)
		{
			int id = dict->findKey(segments_[i]);
			for (int j = 0; j < dict->getById(id).length(); j++)
			{
				if (dict->getById(id)[j] != this && isCollide(dict->getById(id)[j]))
				{
					res.add(dict->getById(id)[j]);
				}
			}
		}
	}
	return res;
}

void snow::CollisionComponent::removeFromSegment_(int x, int y, int windowId)
{
	int vectorId = collisions_.getById(windowId).findKey(Vector2i(x, y));
	int componentId = collisions_.getById(windowId).getById(vectorId).find(this);
	collisions_.getById(windowId).getById(vectorId).remove(componentId);
	if (collisions_.getById(windowId).getById(vectorId).isEmpty())
	{
		collisions_.getById(windowId).removeById(vectorId);
	}
}

void snow::CollisionComponent::addToSegment_(int x, int y, int windowId)
{
	int vectorId = collisions_.getById(windowId).findKey(Vector2i(x, y));
	if (vectorId == -1)
	{
		collisions_.getById(windowId).set(Vector2i(x, y), ArrayList<CollisionComponent*>());
	}
	collisions_.getById(windowId)[Vector2i(x, y)].add(this);
}

const std::string& snow::CollisionComponent::getType() const
{
	return type_;
}