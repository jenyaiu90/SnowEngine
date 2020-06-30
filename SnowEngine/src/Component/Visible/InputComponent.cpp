    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: InputComponent.cpp          //
////////////////////////////////////////

#include "InputComponent.h"

snow::InputComponent* snow::InputComponent::active_ = nullptr;

snow::InputComponent::InputComponent(Actor* actor, int fontSize, const std::string& fontFile,
									 Vector2f buttonSize, Vector2f pos) :
	TextComponent(actor, "", fontSize, fontFile, pos),
	clickable_(actor, buttonSize, pos)
{
	clickable_.onMousePressed = [this](snow::MouseButton button, snow::Vector2f position)
	{
		this->setActive();
	};
}

void snow::InputComponent::deactivate()
{
	if (active_ != nullptr)
	{
		std::string str = active_->getText();
		str.pop_back();
		active_->setText(str);
		active_ = nullptr;
	}
}

bool snow::InputComponent::thereIsActive()
{
	return active_ != nullptr;
}

void snow::InputComponent::inputToActive(char c)
{
	if (thereIsActive())
	{
		active_->input(c);
	}
}

void snow::InputComponent::input(char c)
{
	std::string str = getText();
	switch (c)
	{
	case '\b':
	{
		if (str.length() > 1)
		{
			str.pop_back();
			str.pop_back();
			str += '_';
			setText(str);
		}
		break;
	}
	case 127:
	{
		if (str.length() > 1)
		{
			str.pop_back();
			char back;
			do
			{
				back = str.back();
				str.pop_back();
			} while (str.length() > 0 &&
					 back != ' ' && back != '\t');
			str += '_';
			setText(str);
		}
		break;
	}
	case '\n':
	case 27:
	case '\r':
	{
		break;
	}
	default:
	{
		str.pop_back();
		str += c;
		str += '_';
		setText(str);
	}
	}
}

void snow::InputComponent::setActive()
{
	active_ = this;
	setText(getText() + '_');
}