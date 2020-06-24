    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: SimpleTextureAnimation.cpp  //
////////////////////////////////////////

#include "SimpleTextureAnimation.h"

snow::SimpleTextureAnimation::SimpleTextureAnimation(int duration,
													 snow::Vector2i spriteSize,
													 snow::Vector2i tilesCount,
													 int tilesInLastRow,
													 snow::Vector2i firstTile) :
	duration_(duration),
	spriteSize_(spriteSize),
	firstTile_(firstTile),
	tilesCount_(tilesCount),
	tilesInLastRow_(tilesInLastRow),
	timeCounter_(0),
	currentRectPosition_(0, 0)
{
}

void snow::SimpleTextureAnimation::tick(const int& delta)
{
	if (sprite_ == nullptr)
	{
		return;
	}
	timeCounter_ += delta;
	if (timeCounter_ >= duration_)
	{
		timeCounter_ -= duration_;
		if (currentRectPosition_.y >= tilesCount_.y - 1)
		{
			if (currentRectPosition_.x >= tilesInLastRow_ - 1)
			{
				currentRectPosition_.x = 0;
				currentRectPosition_.y = 0;
			}
			else
			{
				currentRectPosition_.x++;
			}
		}
		else
		{
			if (currentRectPosition_.x >= tilesCount_.x - 1)
			{
				currentRectPosition_.x = 0;
				currentRectPosition_.y++;
			}
			else
			{
				currentRectPosition_.x++;
			}
		}

		sprite_->setTextureRect(IntRect(
								firstTile_.x + currentRectPosition_.x * spriteSize_.x,
								firstTile_.y + currentRectPosition_.y * spriteSize_.y,
								spriteSize_.x, spriteSize_.y));
	}
}

void snow::SimpleTextureAnimation::reset()
{
	timeCounter_ = 0;
	currentRectPosition_.x = 0;
	currentRectPosition_.y = 0;
	if (sprite_ != nullptr)
	{
		sprite_->setTextureRect(IntRect(firstTile_, spriteSize_));
	}
}