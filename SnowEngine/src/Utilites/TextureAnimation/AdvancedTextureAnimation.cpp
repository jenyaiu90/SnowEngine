////////////////////////////////////////
//         After by SnegirSoft        //
//                                    //
//  File: SimpleTextureAnimation.cpp  //
////////////////////////////////////////

#include "AdvancedTextureAnimation.h"

snow::AdvancedTextureAnimation::AdvancedTextureAnimation(sf::Sprite& sprite,
														 snow::Vector2i spriteSize,
														 snow::ArrayList<int> durations,
														 snow::ArrayList<snow::Vector2i> tilePositions) :
	TextureAnimation(sprite),
	spriteSize_(spriteSize),
	durations_(durations),
	tilePositions_(tilePositions),
	timeCounter_(0),
	currentTile_(0)
{
	if (durations.length() != tilePositions.length())
	{
		throw std::logic_error("durations and tilePositions have different sizes");
	}
	sprite_->setTextureRect(IntRect(tilePositions_[0], spriteSize_));
}

void snow::AdvancedTextureAnimation::tick(const int& delta)
{
	timeCounter_ += delta;
	if (timeCounter_ >= durations_[currentTile_])
	{
		timeCounter_ -= durations_[currentTile_];
		if (currentTile_ >= durations_.length() - 1)
		{
			currentTile_ = 0;
		}
		else
		{
			currentTile_++;
		}
		sprite_->setTextureRect(IntRect(tilePositions_[currentTile_], spriteSize_));
	}
}

void snow::AdvancedTextureAnimation::reset()
{
	timeCounter_ = 0;
	currentTile_ = 0;
	sprite_->setTextureRect(IntRect(tilePositions_[0], spriteSize_));
}