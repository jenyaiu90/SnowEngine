    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: SaveLoad.cpp                //
////////////////////////////////////////

#include "SaveLoad.h"

#include <string>
#include <cstdio>

const std::string snow::SaveLoad::SAVES_PATH = "saves/";

snow::ArrayList<std::string>* snow::SaveLoad::keys_ = nullptr;
std::ofstream* snow::SaveLoad::saveFile_ = nullptr;
std::ifstream* snow::SaveLoad::loadFile_ = nullptr;
std::string snow::SaveLoad::currentSave_;

snow::ArrayList<std::string> snow::SaveLoad::getSaves()
{
	ArrayList<std::string> result;
	std::ifstream saves(SAVES_PATH + "saves.dat");
	if (saves.is_open())
	{
		std::string buff;
		while (std::getline(saves, buff))
		{
			result.add(buff);
		}
		saves.close();
	}
	return result;
}

bool snow::SaveLoad::removeSave(const std::string& name)
{
	ArrayList<std::string> saves = getSaves();
	int pos = saves.find(name);
	if (pos > -1)
	{
		saves.remove(pos);
		std::ofstream file(SAVES_PATH + "saves.dat", std::ios_base::trunc);
		if (file.is_open())
		{
			for (int i = 0; i < saves.length(); i++)
			{
				file << saves[i] << std::endl;
			}
			file.close();
			remove((SAVES_PATH + name + ".sav").c_str());
			return true;
		}
	}
	return false;
}

bool snow::SaveLoad::startSaving(const std::string& name)
{
	if (saveFile_ != nullptr || loadFile_ != nullptr)
	{
		return false;
	}

	if (getSaves().find(name) == -1)
	{
		std::ofstream saves(SAVES_PATH + "saves.dat", std::ios_base::app);
		saves << name << std::endl;
		saves.close();
	}

	rename((SAVES_PATH + name + ".sav").c_str(), (SAVES_PATH + name + ".tmp").c_str());
	saveFile_ = new std::ofstream(SAVES_PATH + name + ".sav", std::ios_base::trunc);
	currentSave_ = name;
	return true;
}

bool snow::SaveLoad::save(const std::string& key, const std::string& data)
{
	if (saveFile_ == nullptr || !saveFile_->is_open())
	{
		return false;
	}

	*saveFile_ << key << "=" << data << std::endl;
	return true;
}

bool snow::SaveLoad::stopSaving()
{
	if (saveFile_ == nullptr)
	{
		return false;
	}

	saveFile_->close();
	delete saveFile_;
	saveFile_ = nullptr;
	remove((SAVES_PATH + currentSave_ + ".tmp").c_str());
	return true;
}

bool snow::SaveLoad::startLoading(const std::string& name)
{
	if (saveFile_ != nullptr || loadFile_ != nullptr)
	{
		return false;
	}
	
	loadFile_ = new std::ifstream(SAVES_PATH + name + ".sav");
	if (loadFile_->is_open())
	{
		currentSave_ = name;
		return true;
	}
	else
	{
		delete loadFile_;
		return false;
	}
}

std::string snow::SaveLoad::load(const std::string& key)
{
	if (loadFile_ == nullptr || !loadFile_->is_open())
	{
		return false;
	}

	std::string buff;
	for (int i = 0; i < 2; i++)
	{
		while (std::getline(*loadFile_, buff))
		{
			size_t pos = buff.find_first_of('=');
			if (pos != std::string::npos)
			{
				std::string currentKey = buff;
				currentKey.erase(pos, currentKey.length());
				if (currentKey == key)
				{
					buff.erase(0, pos + 1);
					return buff;
				}
			}
		}
		loadFile_->clear();
		loadFile_->seekg(0, std::ios::beg);
	}

	return std::string();
}

bool snow::SaveLoad::stopLoading()
{
	if (loadFile_ == nullptr)
	{
		return false;
	}

	loadFile_->close();
	delete loadFile_;
	loadFile_ = nullptr;
	return true;
}