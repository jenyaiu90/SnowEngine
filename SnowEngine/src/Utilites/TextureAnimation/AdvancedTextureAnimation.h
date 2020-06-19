    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: AdvancedTextureAnimation.h  //
////////////////////////////////////////

#pragma once

#include "TextureAnimation.h"
#include "../../Types/Vectors.h"
#include "../../Types/List/ArrayList.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief This class creates an advanced animation.
///	
///	The advenced version of SimpleTextureAnimation. Allows to set 
////////////////////////////////////////////////////////////
class AdvancedTextureAnimation : public TextureAnimation
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The constructor of SimpleTextureAnimation (it doesn`t seem simple).
	///	
	///	Creates a new SimpleTextureAnimation object.
	///	\param sprite The sprite that will be animated.
	///	\param spriteSize The size of one tile in pixels.
	///	\param durations The array list with durations of tiles. durations[i] is a duration of the
	///	i-th tile.
	///	\param tilePositions The array list with positions of tiles. tilePositions[i] is a position
	///	of the i-th tile.
	///	\throws std::logic_error if The durations` and tilePositions` sizes aren`t equal.
	////////////////////////////////////////////////////////////
	AdvancedTextureAnimation(sf::Sprite& sprite, Vector2i spriteSize, ArrayList<int> durations,
							 ArrayList<Vector2i> tilePositions);

	////////////////////////////////////////////////////////////
	///	\brief Is called every tick.
	///	
	///	This method counts the time and moves a rectangle of passed sprite.
	///	\param delta The duration of the previous tick.
	////////////////////////////////////////////////////////////
	virtual void tick(const int& delta) override;

	////////////////////////////////////////////////////////////
	///	\brief Resets the animation.
	///	
	///	Resets the time counter and starts it from the begin
	////////////////////////////////////////////////////////////
	virtual void reset() override;

protected:

	// Non-changing
	Vector2i spriteSize_;				///< The size of the sprite.
	ArrayList<int> durations_;			///< The durations of the tiles.
	ArrayList<Vector2i> tilePositions_;	///< The coordinates of the tiles.

	// Changing
	int timeCounter_;					///< Counts the time.
	int currentTile_;					///< The current tile number.

};

}
