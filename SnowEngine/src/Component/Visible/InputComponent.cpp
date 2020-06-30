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
		InputComponent* tmp = active_;
		active_ = nullptr;
		std::string str = tmp->getText();
		str.pop_back();
		tmp->setText(str);
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
		if (str.length() > 0)
		{
			str.pop_back();
			setText(str);
		}
		break;
	}
	case 127:
	{
		if (str.length() > 0)
		{
			char back;
			do
			{
				back = str.back();
				str.pop_back();
			} while (str.length() > 0 &&
					 back != ' ' && back != '\t');
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
		str += c;
		setText(str);
	}
	}
}

void snow::InputComponent::setActive()
{
	setText(getText() + '_');
	active_ = this;
}

std::string snow::InputComponent::getText() const
{
	std::string result = __super::getText();
	if (active_ == this)
	{
		result.pop_back();
	}
	return result;
}

void snow::InputComponent::setText(const std::string& text)
{
	__super::setText((active_ == this) ? text + '_' : text);
}