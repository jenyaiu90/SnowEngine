    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: SimpleTextureAnimation.h    //
////////////////////////////////////////

#pragma once

#include "TextureAnimation.h"
#include "../../Types/Vectors.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief This class creates a simple animation.
///	
///	Sequentially changes tiles from a tileset. Has a fixed duration for all tiles.
////////////////////////////////////////////////////////////
class SimpleTextureAnimation : public TextureAnimation
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The constructor of SimpleTextureAnimation (it doesn`t seem simple).
	///	
	///	Creates a new SimpleTextureAnimation object.
	///	\param duration The duration of one animation frame.
	///	\param spriteSize The size of one tile in pixels.
	///	\param tilesCount x is the count of tiles in one row, y — in one column.
	///	\param tilesInLastRow The count of tiles in the last row of tileset.
	///	\param firstTile The coordinates of the first tile in the tileset in pixels. The default
	///	value is (0, 0).
	////////////////////////////////////////////////////////////
	SimpleTextureAnimation(int duration, Vector2i spriteSize,
						   Vector2i tilesCount, int tilesInLastRow,
						   Vector2i firstTile=snow::Vector2i(0, 0));

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
	int duration_;					///< The duration of one animation frame.
	Vector2i spriteSize_;			///< The size of the sprite in pixels.
	Vector2i firstTile_;			///< The coordinates of the first (left and up) tile in tileset.
	Vector2i tilesCount_;			///< x — count of tiles in one row, y — in one column.
	int tilesInLastRow_;			///< Count of tiles in the last row.

	// Changing
	int timeCounter_;				///< Counts the time.
	Vector2i currentRectPosition_;	///< The current frame position (starting from (0, 0)).

};

}
