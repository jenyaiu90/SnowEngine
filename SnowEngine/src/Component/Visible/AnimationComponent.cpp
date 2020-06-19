    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: AnimationComponent.cpp      //
////////////////////////////////////////

#include "AnimationComponent.h"

snow::AnimationComponent::AnimationComponent(snow::Actor* actor, const std::string& file,
											 snow::TextureAnimation* animation,
											 snow::Vector2f pos) :
	TextureComponent(actor, file, pos),
	animation_(animation)
{
	if (animation_ == nullptr)
	{
		throw std::invalid_argument("animation cannot be null");
	}
	animation->setSprite(sprite_);
}

void snow::AnimationComponent::tick(const int& delta, sf::RenderWindow& window)
{
	animation_->tick(delta);
	__super::tick(delta, window);
}