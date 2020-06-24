    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: SimpleTextureAnimation.cpp  //
////////////////////////////////////////

#include "AdvancedTextureAnimation.h"

snow::AdvancedTextureAnimation::AdvancedTextureAnimation(snow::Vector2i spriteSize,
														 snow::ArrayList<int> durations,
														 snow::ArrayList<snow::Vector2i> tilePositions) :
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
}

void snow::AdvancedTextureAnimation::tick(const int& delta)
{
	if (sprite_ == nullptr)
	{
		return;
	}
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
	if (sprite_ != nullptr)
	{
		sprite_->setTextureRect(IntRect(tilePositions_[0], spriteSize_));
	}
}