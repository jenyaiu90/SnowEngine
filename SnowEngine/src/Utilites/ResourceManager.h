    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: ResourceManager.h           //
////////////////////////////////////////

#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "../Types/List/Dictionary.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The class that manage the textures.
///	
///	Contains all textures that are needed by the program now.
////////////////////////////////////////////////////////////
class ResourceManager
{
public:

	static const std::string SOUNDS_PATH;	///< Path to sounds folder.
	static const std::string MUSIC_PATH;	///< Path to music folder.
	static const std::string TEXTURES_PATH;	///< Path to textures folder.
	static const std::string FONTS_PATH;	///< Path to fonts folder.

	////////////////////////////////////////////////////////////
	/// \brief Returns the texture in passed file.
	///	
	///	Gives the texture that is in the file. All texture files must be in "res/textures/" folder.
	///	\param file The relative path to the texture file.
	///	\return The texture.
	////////////////////////////////////////////////////////////
	static sf::Texture* getTexture(const std::string& file);

	////////////////////////////////////////////////////////////
	///	\brief Decrements inner texture counter.
	///	
	///	Decreases inner texture counter and if it is zero, removes the texture from the memory.
	///	\param file The relative path to the texture file.
	////////////////////////////////////////////////////////////
	static void removeTexture(const std::string& file);

	////////////////////////////////////////////////////////////
	/// \brief Returns the font in passed file.
	///	
	///	Gives the font that is in the file. All fonts files must be in "res/fonts/" folder.
	///	\param file The relative path to the fonts file.
	///	\return The font.
	////////////////////////////////////////////////////////////
	static sf::Font* getFont(const std::string& file);

	////////////////////////////////////////////////////////////
	///	\brief Decrements inner font counter.
	///	
	///	Decreases inner font counter and if it is zero, removes the font from the memory.
	///	\param file The relative path to the font file.
	////////////////////////////////////////////////////////////
	static void removeFont(const std::string& file);

private:

	static Dictionary<std::string, sf::Texture*> textures_;	///< The list of using textures.
	static ArrayList<int> texturesCount_;					///< The count of using textures.

	static Dictionary<std::string, sf::Font*> fonts_;		///< The list of using fonts.
	static ArrayList<int> fontsCount_;						///< The count of using fonts.

};

}