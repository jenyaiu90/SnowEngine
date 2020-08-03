    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: SaveLoad.h                  //
////////////////////////////////////////

#pragma once

#include <fstream>

#include "../Types/List/ArrayList.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The class for saving and loading.
///	
///	The class that contains the static methods for saving and loading.
////////////////////////////////////////////////////////////
class SaveLoad
{
public:

	static const std::string SAVES_PATH; ///< The path to the folder with saves.

	////////////////////////////////////////////////////////////
	///	\brief Returns the list of all save files.
	///	
	///	Allows to get all save names.
	///	\return The array list with names of all saves.
	////////////////////////////////////////////////////////////
	static ArrayList<std::string> getSaves();

	////////////////////////////////////////////////////////////
	///	\brief Removes the save with passed name.
	///	
	///	Allows to remove a file with a save.
	///	\param name The name of removing save.
	///	\return <b>true</b> if the save was successfully removed.
	////////////////////////////////////////////////////////////
	static bool removeSave(const std::string& name);

	////////////////////////////////////////////////////////////
	///	\brief Creates a new save file.
	///	
	///	Creates a new file that the information will being saved to.
	///	\param name The save name. If the save with such name already exists, this method renames
	///	.sav file to .tmp file that will be removed by stopSaving().
	///	\return <b>true</b> if the saving was successfully started.
	////////////////////////////////////////////////////////////
	static bool startSaving(const std::string& name);

	////////////////////////////////////////////////////////////
	///	\brief Saves a data.
	///	
	///	Puts passed data to the save file. You have to start saving before calling this method.
	///	\param key The data\`s unique key.
	///	\param data The data.
	///	\return <b>true</b> if data was successfully saved.
	////////////////////////////////////////////////////////////
	static bool save(const std::string& key, const std::string& data);

	////////////////////////////////////////////////////////////
	///	\brief Stops the saving.
	///	
	///	This method must be called to close the save file.
	///	\return <b>true</b> if saving was stopped. <b>false</b> if, for example, saving hasn\`t
	///	been started so cannot be stopped.
	////////////////////////////////////////////////////////////
	static bool stopSaving();

	////////////////////////////////////////////////////////////
	///	\brief Opens a save file.
	///	
	///	Opens a new file and allows to get a data from it.
	///	\param name The save name.
	///	\return <b>true</b> if the file was successfully opened.
	////////////////////////////////////////////////////////////
	static bool startLoading(const std::string& name);

	////////////////////////////////////////////////////////////
	///	\brief Loads a data.
	///	
	///	Returns the data from the save file. You have to start loading before calling this method.
	///	\param key The data\`s unique key.
	///	\return The loaded data or the empty string if the data wasn\`t loaded.
	////////////////////////////////////////////////////////////
	static std::string load(const std::string& key);

	////////////////////////////////////////////////////////////
	///	\brief Stops the loading.
	///	
	///	This method must be called to close the save file.
	///	\return <b>true</b> if loading was stopped. <b>false</b> if, for example, loading hasn\`t
	///	been started so cannot be stopped.
	////////////////////////////////////////////////////////////
	static bool stopLoading();

private:

	static ArrayList<std::string>* keys_;	///< The keys that was saved.
	static std::ofstream* saveFile_;		///< The file for saving.
	static std::ifstream* loadFile_;		///< The file for loading.
	static std::string currentSave_;		///< The current save\`s name.

};

}