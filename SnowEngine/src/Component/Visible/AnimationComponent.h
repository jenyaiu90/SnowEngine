    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: AnimationComponent.h        //
////////////////////////////////////////

#pragma once

#include "TextureComponent.h"
#include "../../Utilites/TextureAnimation/TextureAnimation.h"

namespace snow
{

////////////////////////////////////////////////////////////
/// \brief The component for displaying a sprite with integrated animation support.
///	
///	Use this class if you need to create an animated sprite. You can create an object of this class
///	of create a new class that is inherited from this.
////////////////////////////////////////////////////////////
class AnimationComponent : public TextureComponent
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The constructor of the TextureComponent.
	///	
	///	This constructor attaches new component to an actor, sets its relative position and a file
	///	with a source texture. It doesn`t set the texture rect.
	///	\param actor An actor that the component will be attached to.
	///	\param file A file with a source texture.
	///	\param animation A pointer to an object of a class that is inherited from TextureAnimation.
	///	\param pos A position of the component relative to a base actor. The default value
	///	is (0, 0).
	///	\throws std::invalid_argument if the animation is null.
	///	\warning Passed TextureAnimation doesn`t be removed in the destructor. You should delete it
	///	from the heap manually. Also you can use one animation for different components.
	////////////////////////////////////////////////////////////
	AnimationComponent(Actor* actor, const std::string& file,
					   TextureAnimation* animation, Vector2f pos=Vector2f());

	////////////////////////////////////////////////////////////
	///	\brief Method that is called every tick.
	///	
	///	This method draws the texture and switch the sprite`s tile. It is called every tick. If you
	///	need to override it, you should call a parent`s method:
	///	\code
	///		void tick(const int& delta, sf::RenderWindow& window) override
	///		{
	///			// Do what you need
	///			__super::tick(delta, window);
	///		}
	///	\endcode
	///	It isn`t recommended to do any lengthly calculations in this method because it will affect
	///	perfomance.
	////////////////////////////////////////////////////////////
	virtual void tick(const int& delta, sf::RenderWindow& window) override;

protected:

	TextureAnimation* animation_; ///< A sprite`s animation

};

}