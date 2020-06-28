    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: VisibleComponent.cpp        //
////////////////////////////////////////

#include "VisibleComponent.h"

snow::VisibleComponent::VisibleComponent(Actor* actor, Vector2f pos) :
	Component(actor, pos),
	isEnabled_(true)
{
}

bool snow::VisibleComponent::isEnabled() const
{
	return isEnabled_;
}

void snow::VisibleComponent::setEnable(const bool enable)
{
	isEnabled_ = enable;
}