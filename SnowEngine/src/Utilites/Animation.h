    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Animation.h                 //
////////////////////////////////////////

////////////////////////////////////////////////////////////
///	\file
///	\brief The file with the Animation abstract class.
///
///	In this file there is the declaration of the Animation abstract class.
////////////////////////////////////////////////////////////

#pragma once

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The abstract class that allows to create an animation.
///	
///	To create an animation you should define a new class that is inherited from this and override
///	its animate() method. This method should return some value depending on the parameter.
////////////////////////////////////////////////////////////
template<typename T, typename U>
class Animation
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The base method for creating an animation. Need to be overrided.
	///	
	///	Override this method in your class to create an animation. It should returns the value
	///	depending on the parameter. For example, we need to create an animation for an actor`s
	///	moving. It must move from (3, 5) to (9, 10) in two seconds. We will pass to the method the
	///	time elapsed from the moving start in milliseconds (int). The method will return the
	///	actor`s position corresponding to the time (snow::Vector2f). Now we need to find a dependence
	///	of the coordinate of the time (<b>t</b> is the time in milliseconds).
	///	X: At time 0 ms x = 3, at time 2000 ms x = 9. So x = 3 + t * 3 / 1000.
	///	Y: At time 0 ms y = 5, at time 2000 ms y = 10. So y = 5 + t / 400.
	///	We also should return (3, 5) if t < 0 and (9, 10) if t > 2000.
	///	\code
	///		class MyAnimation : public snow::Animation<snow::Vector2f, int>
	///		{
	///		public:
	///			snow::Vector2f animate(const int& input) override
	///			{
	///				snow::Vector2f result;
	///				if (input < 0)
	///				{
	///					result = snow::Vector2f(3, 5);
	///				}
	///				else if (input > 2000)
	///				{
	///					result = snow::Vector2f(9, 10);
	///				}
	///				else
	///				{
	///					result.x = 3 + input * 3 / 1000;
	///					result.y = 5 + input / 400;
	///				}
	///				return result;
	///			}
	///		};
	///	\endcode
	///	Now we can use this animation to move an actor:
	///	\code
	///		// In the other thread (for example, not obligatory)
	///		// actor is the target actor
	///		sf::Clock clock; // An SFML clock
	///		int time = 0; // A time spending from start
	///		MyAnimation animation;
	///		do
	///		{
	///			time += clock.getElapsedTime().asMilliseconds();
	///			actor.move(animation.animate(time));
	///		} while (time <= 2000);
	///	\endcode
	///	Note that in this case it is recommended to use an animation enbedded in the Actor. Just
	/// write:
	///	\code
	///		actor.move(snow::Vector2f(9, 10), 2000);
	///	\endcode
	///	An actor will automatically moved in its own thread.
	///	\param input An input value.
	///	\return A value depending of the input.
	////////////////////////////////////////////////////////////
	virtual T animate(const U& input) = 0;

};

}
