    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: ResourceManager.cpp         //
////////////////////////////////////////

#include "ResourceManager.h"

const std::string snow::ResourceManager::SOUNDS_PATH = "res/sounds/";
const std::string snow::ResourceManager::MUSIC_PATH = "res/music/";
const std::string snow::ResourceManager::TEXTURES_PATH = "res/textures/";
const std::string snow::ResourceManager::FONTS_PATH = "res/fonts/";

snow::Dictionary<std::string, sf::Texture*> snow::ResourceManager::textures_;
snow::ArrayList<int> snow::ResourceManager::texturesCount_;

snow::Dictionary<std::string, sf::Font*> snow::ResourceManager::fonts_;
snow::ArrayList<int> snow::ResourceManager::fontsCount_;

sf::Texture* snow::ResourceManager::getTexture(const std::string& file)
{
	int pos = textures_.findKey(file);
	if (pos >= 0)
	{
		texturesCount_[pos]++;
		return textures_.getById(pos);
	}
	else
	{
		sf::Texture* tmp = new sf::Texture();
		tmp->loadFromFile(TEXTURES_PATH + file);
		textures_.set(file, tmp);
		texturesCount_.add(1);
		return tmp;
	}
}

void snow::ResourceManager::removeTexture(const std::string& file)
{
	int pos = textures_.findKey(file);
	if (pos >= 0)
	{
		texturesCount_[pos]--;
		if (texturesCount_[pos] <= 0)
		{
			texturesCount_.remove(pos);
			delete textures_.getById(pos);
			textures_.removeById(pos);
		}
	}
}

sf::Font* snow::ResourceManager::getFont(const std::string& file)
{
	int pos = fonts_.findKey(file);
	if (pos >= 0)
	{
		fontsCount_[pos]++;
		return fonts_.getById(pos);
	}
	else
	{
		sf::Font* tmp = new sf::Font();
		tmp->loadFromFile(FONTS_PATH + file);
		fonts_.set(file, tmp);
		fontsCount_.add(1);
		return tmp;
	}
}

void snow::ResourceManager::removeFont(const std::string& file)
{
	int pos = fonts_.findKey(file);
	if (pos >= 0)
	{
		fontsCount_[pos]--;
		if (fontsCount_[pos] <= 0)
		{
			fontsCount_.remove(pos);
			delete fonts_.getById(pos);
			fonts_.removeById(pos);
		}
	}
}