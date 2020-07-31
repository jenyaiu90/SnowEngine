     ////////////////////////////////////////
    //      SnowEngine by SnegirSoft      //
   //  Project creator                   //
  //                                    //
 //  File: creator.h                   //
////////////////////////////////////////

#pragma once

#include <string>
#include <fstream>
#include <experimental/filesystem>
#include <Windows.h>
#include <conio.h>

#include "Printer.h"

using namespace std;
using experimental::filesystem::exists;
using experimental::filesystem::create_directory;

const int FILES_COUNT = 54;
const std::string FILES[FILES_COUNT] =
{
	"SnowEngine.h", "Window/Input.h",
	"Actor/Actor.h", "Actor/Actor.cpp",
	"Component/Component.h", "Component/Component.cpp",
	"Component/Audio/MusicComponent.h", "Component/Audio/MusicComponent.cpp",
	"Component/Audio/SoundComponent.h", "Component/Audio/SoundComponent.cpp",
	"Component/Clickable/ClickableComponent.h", "Component/Clickable/ClickableComponent.cpp",
	"Component/Collision/CollisionComponent.h", "Component/Collision/CollisionComponent.cpp",
	"Component/Collision/CircleCollisionComponent.h", "Component/Collision/CircleCollisionComponent.cpp",
	"Component/Collision/RectCollisionComponent.h", "Component/Collision/RectCollisionComponent.cpp",
	"Component/Visible/VisibleComponent.h", "Component/Visible/VisibleComponent.cpp",
	"Component/Visible/AnimationComponent.h", "Component/Visible/AnimationComponent.cpp",
	"Component/Visible/InputComponent.h", "Component/Visible/InputComponent.cpp",
	"Component/Visible/TextComponent.h", "Component/Visible/TextComponent.cpp",
	"Component/Visible/TextureComponent.h", "Component/Visible/TextureComponent.cpp",
	"Layer/Layer.h", "Layer/Layer.cpp",
	"Layer/Gui/Gui.h", "Layer/Gui/Gui.cpp",
	"Layer/Level/Level.h", "Layer/Level/Level.cpp",
	"Types/Vectors.h", "Types/Vectors.cpp",
	"Types/List/List.h", "Types/List/ArrayList.h", "Types/List/LinkedList.h",
	"Types/List/Comparator.h", "Types/List/Dictionary.h",
	"Utilites/Animation.h",
	"Utilites/ResourceManager.h", "Utilites/ResourceManager.cpp",
	"Utilites/SaveLoad.h", "Utilites/SaveLoad.cpp",
	"Utilites/TextureAnimation/TextureAnimation.h", "Utilites/TextureAnimation/TextureAnimation.cpp",
	"Utilites/TextureAnimation/SimpleTextureAnimation.h", "Utilites/TextureAnimation/SimpleTextureAnimation.cpp",
	"Utilites/TextureAnimation/AdvancedTextureAnimation.h", "Utilites/TextureAnimation/AdvancedTextureAnimation.cpp",
	"Window/Window.h", "Window/Window.cpp"
};

void checkEngine(int& stage, const std::string& enginePath)
{
	for (stage = 0; stage < FILES_COUNT; stage++)
	{
		if (!exists(enginePath + "/src/" + FILES[stage]))
		{
			stage = -1;
			return;
		}
	}
	return;
}

void create(const std::string& enginePath,   const std::string& projectPath, const std::string& sfmlPath,
			const std::string& solutionName, const std::string& projectName)
{
	if (!exists(projectPath))
	{
		Printer::printTmp("Error: couldn`t find path " + projectPath);
		_getch();
		return;
	}
	if (!exists(sfmlPath + "/include"))
	{
		Printer::printTmp("Error: couldn`t find path " + sfmlPath + "/include");
		_getch();
		return;
	}
	if (!exists(sfmlPath + "/lib"))
	{
		Printer::printTmp("Error: couldn`t find path " + sfmlPath + "/lib");
		_getch();
		return;
	}

	create_directory(projectPath + "/" + solutionName);
	create_directory(projectPath + "/" + solutionName + "/SnowEngine");
	create_directory(projectPath + "/" + solutionName + "/" + projectName);

	// Creating .sln file
	ofstream file(projectPath + "/" + solutionName + "/SnowEngine/" + solutionName + ".sln", ios_base::ate);
	{
		file << "Microsoft Visual Studio Solution File, Format Version 12.00" << endl <<
			"# Visual Studio 15" << endl <<
			"VisualStudioVersion = 15.0.28307.1062" << endl <<
			"MinimumVisualStudioVersion = 10.0.40219.1" << endl <<
			"Project(\"{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}\") = \"SnowEngine\", \"SnowEngine.vcxproj\", \"{96FBFEF5-4D6F-455C-94EE-FFAC4788C918}\"" << endl <<
			"EndProject" << endl <<
			"Project(\"{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}\") = \"" << projectName << "\", \"..\\" << projectName << "\\" << projectName << ".vcxproj\", \"{E2509244-1A42-4B6F-8B32-C1B058AAFF42}\"" << endl <<
			"EndProject" << endl <<
			"Global" << endl <<
			"\tGlobalSection(SolutionConfigurationPlatforms) = preSolution" << endl <<
			"\t\tDebug|x64 = Debug|x64" << endl <<
			"\t\tDebug|x86 = Debug|x86" << endl <<
			"\t\tRelease|x64 = Release|x64" << endl <<
			"\t\tRelease|x86 = Release|x86" << endl <<
			"\tEndGlobalSection" << endl <<
			"\tGlobalSection(ProjectConfigurationPlatforms) = postSolution" << endl <<
			"\t\t{96FBFEF5-4D6F-455C-94EE-FFAC4788C918}.Debug|x64.ActiveCfg = Debug|x64" << endl <<
			"\t\t{96FBFEF5-4D6F-455C-94EE-FFAC4788C918}.Debug|x64.Build.0 = Debug|x64" << endl <<
			"\t\t{96FBFEF5-4D6F-455C-94EE-FFAC4788C918}.Debug|x86.ActiveCfg = Debug|Win32" << endl <<
			"\t\t{96FBFEF5-4D6F-455C-94EE-FFAC4788C918}.Debug|x86.Build.0 = Debug|Win32" << endl <<
			"\t\t{96FBFEF5-4D6F-455C-94EE-FFAC4788C918}.Release|x64.ActiveCfg = Release|x64" << endl <<
			"\t\t{96FBFEF5-4D6F-455C-94EE-FFAC4788C918}.Release|x64.Build.0 = Release|x64" << endl <<
			"\t\t{96FBFEF5-4D6F-455C-94EE-FFAC4788C918}.Release|x86.ActiveCfg = Release|Win32" << endl <<
			"\t\t{96FBFEF5-4D6F-455C-94EE-FFAC4788C918}.Release|x86.Build.0 = Release|Win32" << endl <<
			"\t\t{E2509244-1A42-4B6F-8B32-C1B058AAFF42}.Debug|x64.ActiveCfg = Debug|x64" << endl <<
			"\t\t{E2509244-1A42-4B6F-8B32-C1B058AAFF42}.Debug|x64.Build.0 = Debug|x64" << endl <<
			"\t\t{E2509244-1A42-4B6F-8B32-C1B058AAFF42}.Debug|x86.ActiveCfg = Debug|Win32" << endl <<
			"\t\t{E2509244-1A42-4B6F-8B32-C1B058AAFF42}.Debug|x86.Build.0 = Debug|Win32" << endl <<
			"\t\t{E2509244-1A42-4B6F-8B32-C1B058AAFF42}.Release|x64.ActiveCfg = Release|x64" << endl <<
			"\t\t{E2509244-1A42-4B6F-8B32-C1B058AAFF42}.Release|x64.Build.0 = Release|x64" << endl <<
			"\t\t{E2509244-1A42-4B6F-8B32-C1B058AAFF42}.Release|x86.ActiveCfg = Release|Win32" << endl <<
			"\t\t{E2509244-1A42-4B6F-8B32-C1B058AAFF42}.Release|x86.Build.0 = Release|Win32" << endl <<
			"\tEndGlobalSection" << endl <<
			"\t\tGlobalSection(SolutionProperties) = preSolution" << endl <<
			"\t\tHideSolutionNode = FALSE" << endl <<
			"\tEndGlobalSection" << endl <<
			"\tGlobalSection(ExtensibilityGlobals) = postSolution" << endl <<
			"\t\tSolutionGuid = {210836F4-139C-42A1-9F03-708915974C96}" << endl <<
			"\tEndGlobalSection" << endl <<
			"EndGlobal" << endl;
	}
	file.close();

	// Creating SnowEngine.vcxproj file
	file.open(projectPath + "/" + solutionName + "/SnowEngine/SnowEngine.vcxproj", ios_base::ate);
	{
		file << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl <<
			"<Project DefaultTargets=\"Build\" ToolsVersion=\"15.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">" << endl <<
			"  <ItemGroup Label=\"ProjectConfigurations\">" << endl <<
			"    <ProjectConfiguration Include=\"Debug|Win32\">" << endl <<
			"      <Configuration>Debug</Configuration>" << endl <<
			"      <Platform>Win32</Platform>" << endl <<
			"    </ProjectConfiguration>" << endl <<
			"    <ProjectConfiguration Include=\"Release|Win32\">" << endl <<
			"      <Configuration>Release</Configuration>" << endl <<
			"      <Platform>Win32</Platform>" << endl <<
			"    </ProjectConfiguration>" << endl <<
			"    <ProjectConfiguration Include=\"Debug|x64\">" << endl <<
			"      <Configuration>Debug</Configuration>" << endl <<
			"      <Platform>x64</Platform>" << endl <<
			"    </ProjectConfiguration>" << endl <<
			"    <ProjectConfiguration Include=\"Release|x64\">" << endl <<
			"      <Configuration>Release</Configuration>" << endl <<
			"      <Platform>x64</Platform>" << endl <<
			"    </ProjectConfiguration>" << endl <<
			"  </ItemGroup>" << endl <<
			"  <ItemGroup>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Audio\\MusicComponent.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Audio\\SoundComponent.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Clickable\\ClickableComponent.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Collision\\CircleCollisionComponent.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Collision\\CollisionComponent.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Collision\\RectCollisionComponent.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Component.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Visible\\AnimationComponent.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Visible\\InputComponent.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Visible\\TextComponent.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Visible\\TextureComponent.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Visible\\VisibleComponent.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Layer\\Gui\\Gui.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Layer\\Layer.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Layer\\Level\\Level.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\SnowEngine.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Types\\List\\ArrayList.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Types\\List\\CircularList.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Types\\List\\Comparator.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Types\\List\\Dictionaty.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Types\\List\\LinkedList.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Types\\List\\List.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Types\\Vectors.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Utilites\\Animation.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Utilites\\ResourceManager.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Utilites\\SaveLoad.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Utilites\\TextureAnimation\\AdvancedTextureAnimation.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Utilites\\TextureAnimation\\SimpleTextureAnimation.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Utilites\\TextureAnimation\\TextureAnimation.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Window\\Input.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Window\\Window.h\" />" << endl <<
			"  </ItemGroup>" << endl <<
			"  <ItemGroup>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Actor\\Actor.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Actor\\Actor.h\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Audio\\MusicComponent.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Audio\\SoundComponent.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Clickable\\ClickableComponent.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Collision\\CircleCollisionComponent.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Collision\\CollisionComponent.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Collision\\RectCollisionComponent.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Component.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Visible\\AnimationComponent.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Visible\\InputComponent.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Visible\\TextComponent.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Visible\\TextureComponent.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Visible\\VisibleComponent.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Layer\\Gui\\Gui.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Layer\\Layer.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Layer\\Level\\Level.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Types\\Vectors.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Utilites\\ResourceManager.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Utilites\\SaveLoad.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Utilites\\TextureAnimation\\AdvancedTextureAnimation.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Utilites\\TextureAnimation\\SimpleTextureAnimation.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Utilites\\TextureAnimation\\TextureAnimation.cpp\" />" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Window\\Window.cpp\" />" << endl <<
			"  </ItemGroup>" << endl <<
			"  <PropertyGroup Label=\"Globals\">" << endl <<
			"    <VCProjectVersion>15.0</VCProjectVersion>" << endl <<
			"    <ProjectGuid>{96FBFEF5-4D6F-455C-94EE-FFAC4788C918}</ProjectGuid>" << endl <<
			"    <Keyword>Win32Proj</Keyword>" << endl <<
			"    <RootNamespace>SnowEngine</RootNamespace>" << endl <<
			"    <WindowsTargetPlatformVersion>10.0.17763.0</WindowsTargetPlatformVersion>" << endl <<
			"  </PropertyGroup>" << endl <<
			"  <Import Project=\"$(VCTargetsPath)\\Microsoft.Cpp.Default.props\" />" << endl <<
			"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\" Label=\"Configuration\">" << endl <<
			"    <ConfigurationType>StaticLibrary</ConfigurationType>" << endl <<
			"    <UseDebugLibraries>true</UseDebugLibraries>" << endl <<
			"    <PlatformToolset>v141</PlatformToolset>" << endl <<
			"    <CharacterSet>Unicode</CharacterSet>" << endl <<
			"  </PropertyGroup>" << endl <<
			"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\" Label=\"Configuration\">" << endl <<
			"    <ConfigurationType>StaticLibrary</ConfigurationType>" << endl <<
			"    <UseDebugLibraries>false</UseDebugLibraries>" << endl <<
			"    <PlatformToolset>v141</PlatformToolset>" << endl <<
			"    <WholeProgramOptimization>true</WholeProgramOptimization>" << endl <<
			"    <CharacterSet>Unicode</CharacterSet>" << endl <<
			"  </PropertyGroup>" << endl <<
			"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|x64'\" Label=\"Configuration\">" << endl <<
			"    <ConfigurationType>StaticLibrary</ConfigurationType>" << endl <<
			"    <UseDebugLibraries>true</UseDebugLibraries>" << endl <<
			"    <PlatformToolset>v141</PlatformToolset>" << endl <<
			"    <CharacterSet>Unicode</CharacterSet>" << endl <<
			"  </PropertyGroup>" << endl <<
			"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|x64'\" Label=\"Configuration\">" << endl <<
			"    <ConfigurationType>StaticLibrary</ConfigurationType>" << endl <<
			"    <UseDebugLibraries>false</UseDebugLibraries>" << endl <<
			"    <PlatformToolset>v141</PlatformToolset>" << endl <<
			"    <WholeProgramOptimization>true</WholeProgramOptimization>" << endl <<
			"    <CharacterSet>Unicode</CharacterSet>" << endl <<
			"  </PropertyGroup>" << endl <<
			"  <Import Project=\"$(VCTargetsPath)\\Microsoft.Cpp.props\" />" << endl <<
			"  <ImportGroup Label=\"ExtensionSettings\">" << endl <<
			"  </ImportGroup>" << endl <<
			"  <ImportGroup Label=\"Shared\">" << endl <<
			"  </ImportGroup>" << endl <<
			"  <ImportGroup Label=\"PropertySheets\" Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\">" << endl <<
			"    <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists('$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />" << endl <<
			"  </ImportGroup>" << endl <<
			"  <ImportGroup Label=\"PropertySheets\" Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\">" << endl <<
			"    <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists('$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />" << endl <<
			"  </ImportGroup>" << endl <<
			"  <ImportGroup Label=\"PropertySheets\" Condition=\"'$(Configuration)|$(Platform)'=='Debug|x64'\">" << endl <<
			"    <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists('$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />" << endl <<
			"  </ImportGroup>" << endl <<
			"  <ImportGroup Label=\"PropertySheets\" Condition=\"'$(Configuration)|$(Platform)'=='Release|x64'\">" << endl <<
			"    <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists('$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />" << endl <<
			"  </ImportGroup>" << endl <<
			"  <PropertyGroup Label=\"UserMacros\" />" << endl <<
			"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\">" << endl <<
			"    <LinkIncremental>true</LinkIncremental>" << endl <<
			"  </PropertyGroup>" << endl <<
			"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|x64'\">" << endl <<
			"    <LinkIncremental>true</LinkIncremental>" << endl <<
			"  </PropertyGroup>" << endl <<
			"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\">" << endl <<
			"    <LinkIncremental>false</LinkIncremental>" << endl <<
			"  </PropertyGroup>" << endl <<
			"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|x64'\">" << endl <<
			"    <LinkIncremental>false</LinkIncremental>" << endl <<
			"  </PropertyGroup>" << endl <<
			"  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\">" << endl <<
			"    <ClCompile>" << endl <<
			"      <WarningLevel>Level3</WarningLevel>" << endl <<
			"      <Optimization>Disabled</Optimization>" << endl <<
			"      <SDLCheck>true</SDLCheck>" << endl <<
			"      <PreprocessorDefinitions>WIN32;_DEBUG;_LIB;%(PreprocessorDefinitions)</PreprocessorDefinitions>" << endl <<
			"      <ConformanceMode>true</ConformanceMode>" << endl <<
			"    </ClCompile>" << endl <<
			"    <Link>" << endl <<
			"      <SubSystem>Console</SubSystem>" << endl <<
			"      <GenerateDebugInformation>true</GenerateDebugInformation>" << endl <<
			"    </Link>" << endl <<
			"  </ItemDefinitionGroup>" << endl <<
			"  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|x64'\">" << endl <<
			"    <ClCompile>" << endl <<
			"      <WarningLevel>Level3</WarningLevel>" << endl <<
			"      <Optimization>Disabled</Optimization>" << endl <<
			"      <SDLCheck>true</SDLCheck>" << endl <<
			"      <PreprocessorDefinitions>SFML_STATIC;_DEBUG;_LIB;%(PreprocessorDefinitions)</PreprocessorDefinitions>" << endl <<
			"      <ConformanceMode>true</ConformanceMode>" << endl <<
			"      <AdditionalIncludeDirectories>" << sfmlPath << "\\include</AdditionalIncludeDirectories>" << endl <<
			"    </ClCompile>" << endl <<
			"    <Link>" << endl <<
			"      <SubSystem>Console</SubSystem>" << endl <<
			"      <GenerateDebugInformation>true</GenerateDebugInformation>" << endl <<
			"    </Link>" << endl <<
			"  </ItemDefinitionGroup>" << endl <<
			"  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\">" << endl <<
			"    <ClCompile>" << endl <<
			"      <WarningLevel>Level3</WarningLevel>" << endl <<
			"      <Optimization>MaxSpeed</Optimization>" << endl <<
			"      <FunctionLevelLinking>true</FunctionLevelLinking>" << endl <<
			"      <IntrinsicFunctions>true</IntrinsicFunctions>" << endl <<
			"      <SDLCheck>true</SDLCheck>" << endl <<
			"      <PreprocessorDefinitions>WIN32;NDEBUG;_LIB;%(PreprocessorDefinitions)</PreprocessorDefinitions>" << endl <<
			"      <ConformanceMode>true</ConformanceMode>" << endl <<
			"    </ClCompile>" << endl <<
			"    <Link>" << endl <<
			"      <SubSystem>Console</SubSystem>" << endl <<
			"      <EnableCOMDATFolding>true</EnableCOMDATFolding>" << endl <<
			"      <OptimizeReferences>true</OptimizeReferences>" << endl <<
			"      <GenerateDebugInformation>true</GenerateDebugInformation>" << endl <<
			"    </Link>" << endl <<
			"  </ItemDefinitionGroup>" << endl <<
			"  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|x64'\">" << endl <<
			"    <ClCompile>" << endl <<
			"      <WarningLevel>Level3</WarningLevel>" << endl <<
			"      <Optimization>MaxSpeed</Optimization>" << endl <<
			"      <FunctionLevelLinking>true</FunctionLevelLinking>" << endl <<
			"      <IntrinsicFunctions>true</IntrinsicFunctions>" << endl <<
			"      <SDLCheck>true</SDLCheck>" << endl <<
			"      <PreprocessorDefinitions>SFML_STATIC;NDEBUG;_LIB;%(PreprocessorDefinitions)</PreprocessorDefinitions>" << endl <<
			"      <ConformanceMode>true</ConformanceMode>" << endl <<
			"      <AdditionalIncludeDirectories>" << sfmlPath << "\\include</AdditionalIncludeDirectories>" << endl <<
			"    </ClCompile>" << endl <<
			"    <Link>" << endl <<
			"      <SubSystem>Console</SubSystem>" << endl <<
			"      <EnableCOMDATFolding>true</EnableCOMDATFolding>" << endl <<
			"      <OptimizeReferences>true</OptimizeReferences>" << endl <<
			"      <GenerateDebugInformation>true</GenerateDebugInformation>" << endl <<
			"    </Link>" << endl <<
			"  </ItemDefinitionGroup>" << endl <<
			"  <Import Project=\"$(VCTargetsPath)\\Microsoft.Cpp.targets\" />" << endl <<
			"  <ImportGroup Label=\"ExtensionTargets\">" << endl <<
			"  </ImportGroup>" << endl <<
			"</Project>";
	}
	file.close();

	// Creating SnowEngine.vcxproj.filters file
	file.open(projectPath + "/" + solutionName + "/SnowEngine/SnowEngine.vcxproj.filters", ios_base::ate);
	{
		file << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl <<
			"<Project ToolsVersion=\"4.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">" << endl <<
			"  <ItemGroup>" << endl <<
			"    <Filter Include=\"Source Files\">" << endl <<
			"      <UniqueIdentifier>{4FC737F1-C7A5-4376-A066-2A32D752A2FF}</UniqueIdentifier>" << endl <<
			"      <Extensions>cpp;c;cc;cxx;def;odl;idl;hpj;bat;asm;asmx</Extensions>" << endl <<
			"    </Filter>" << endl <<
			"    <Filter Include=\"Resource Files\">" << endl <<
			"      <UniqueIdentifier>{67DA6AB6-F800-4c08-8B7A-83BB121AAD01}</UniqueIdentifier>" << endl <<
			"      <Extensions>rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe;resx;tiff;tif;png;wav;mfcribbon-ms</Extensions>" << endl <<
			"    </Filter>" << endl <<
			"    <Filter Include=\"Source Files\\Window\">" << endl <<
			"      <UniqueIdentifier>{32c7e2df-a15d-4ea4-a19c-03300d6dc0bd}</UniqueIdentifier>" << endl <<
			"    </Filter>" << endl <<
			"    <Filter Include=\"Source Files\\Types\">" << endl <<
			"      <UniqueIdentifier>{cce0d441-d984-4c1f-a9ba-686516f62470}</UniqueIdentifier>" << endl <<
			"    </Filter>" << endl <<
			"    <Filter Include=\"Source Files\\Types\\List\">" << endl <<
			"      <UniqueIdentifier>{7270ff49-c1de-4857-9c77-082f90ae631f}</UniqueIdentifier>" << endl <<
			"    </Filter>" << endl <<
			"    <Filter Include=\"Source Files\\Layer\">" << endl <<
			"      <UniqueIdentifier>{18ee5dc5-ecf4-45fc-ac60-bcbd130798a4}</UniqueIdentifier>" << endl <<
			"    </Filter>" << endl <<
			"    <Filter Include=\"Source Files\\Layer\\Level\">" << endl <<
			"      <UniqueIdentifier>{854b19e0-0fd5-4f40-bae0-49793a1fae28}</UniqueIdentifier>" << endl <<
			"    </Filter>" << endl <<
			"    <Filter Include=\"Source Files\\Layer\\Gui\">" << endl <<
			"      <UniqueIdentifier>{ce11cae4-bc06-47e6-927b-02e3bca01c79}</UniqueIdentifier>" << endl <<
			"    </Filter>" << endl <<
			"    <Filter Include=\"Source Files\\Actor\">" << endl <<
			"      <UniqueIdentifier>{da53aaf1-ff63-4a97-bbcb-1bc7364527cc}</UniqueIdentifier>" << endl <<
			"    </Filter>" << endl <<
			"    <Filter Include=\"Source Files\\Component\">" << endl <<
			"      <UniqueIdentifier>{df09b4b9-429b-48ca-a2e9-5079749850e4}</UniqueIdentifier>" << endl <<
			"    </Filter>" << endl <<
			"    <Filter Include=\"Source Files\\Component\\Audio\">" << endl <<
			"      <UniqueIdentifier>{edc2b14d-0a83-4c76-8c8e-80ac055e665a}</UniqueIdentifier>" << endl <<
			"    </Filter>" << endl <<
			"    <Filter Include=\"Source Files\\Component\\Visible\">" << endl <<
			"      <UniqueIdentifier>{8fae1c48-23fc-41fa-85d9-b01dd7b42847}</UniqueIdentifier>" << endl <<
			"    </Filter>" << endl <<
			"    <Filter Include=\"Source Files\\Utilites\">" << endl <<
			"      <UniqueIdentifier>{bfb3fb41-f6cd-4c8e-b3f8-ec2b7655d890}</UniqueIdentifier>" << endl  << endl <<
			"    </Filter>" << endl <<
			"    <Filter Include=\"Source Files\\Utilites\\TextureAnimation\">" << endl <<
			"      <UniqueIdentifier>{2522bf2d-249d-4f5e-addb-f4b8744340a7}</UniqueIdentifier>" << endl <<
			"    </Filter>" << endl <<
			"    <Filter Include=\"Source Files\\Component\\Collision\">" << endl <<
			"      <UniqueIdentifier>{5aa41f31-1996-4e40-903d-ff1639760cf1}</UniqueIdentifier>" << endl <<
			"    </Filter>" << endl <<
			"    <Filter Include=\"Source Files\\Component\\Clickable\">" << endl <<
			"      <UniqueIdentifier>{1598da7f-2209-40cc-9312-7adb10f3bf5e}</UniqueIdentifier>" << endl <<
			"    </Filter>" << endl <<
			"  </ItemGroup>" << endl <<
			"  <ItemGroup>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\SnowEngine.h\" />" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Utilites\\TextureAnimation\\AdvancedTextureAnimation.h\">" << endl <<
			"      <Filter>Source Files\\Utilites\\TextureAnimation</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Utilites\\Animation.h\">" << endl <<
			"      <Filter>Source Files\\Utilites</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Visible\\AnimationComponent.h\">" << endl <<
			"      <Filter>Source Files\\Component\\Visible</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Types\\List\\ArrayList.h\">" << endl <<
			"      <Filter>Source Files\\Types\\List</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Clickable\\ClickableComponent.h\">" << endl <<
			"      <Filter>Source Files\\Component\\Clickable</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Collision\\CircleCollisionComponent.h\">" << endl <<
			"      <Filter>Source Files\\Component\\Collision</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Types\\List\\CircularList.h\">" << endl <<
			"      <Filter>Source Files\\Types\\List</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Collision\\CollisionComponent.h\">" << endl <<
			"      <Filter>Source Files\\Component\\Collision</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Types\\List\\Comparator.h\">" << endl <<
			"      <Filter>Source Files\\Types\\List</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Component.h\">" << endl <<
			"      <Filter>Source Files\\Component</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Types\\List\\Dictionaty.h\">" << endl <<
			"      <Filter>Source Files\\Types\\List</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Layer\\Gui\\Gui.h\">" << endl <<
			"      <Filter>Source Files\\Layer\\Gui</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Window\\Input.h\">" << endl <<
			"      <Filter>Source Files\\Window</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Visible\\InputComponent.h\">" << endl <<
			"      <Filter>Source Files\\Component\\Visible</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Layer\\Layer.h\">" << endl <<
			"      <Filter>Source Files\\Layer</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Layer\\Level\\Level.h\">" << endl <<
			"      <Filter>Source Files\\Layer\\Level</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Types\\List\\LinkedList.h\">" << endl <<
			"      <Filter>Source Files\\Types\\List</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Types\\List\\List.h\">" << endl <<
			"      <Filter>Source Files\\Types\\List</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Audio\\MusicComponent.h\">" << endl <<
			"      <Filter>Source Files\\Component\\Audio</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Collision\\RectCollisionComponent.h\">" << endl <<
			"      <Filter>Source Files\\Component\\Collision</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Utilites\\ResourceManager.h\">" << endl <<
			"      <Filter>Source Files\\Utilites</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Utilites\\SaveLoad.h\">" << endl <<
			"      <Filter>Source Files\\Utilites</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Utilites\\Serializable.h\">" << endl <<
			"      <Filter>Source Files\\Utilites</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Utilites\\TextureAnimation\\SimpleTextureAnimation.h\">" << endl <<
			"      <Filter>Source Files\\Utilites\\TextureAnimation</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Audio\\SoundComponent.h\">" << endl <<
			"      <Filter>Source Files\\Component\\Audio</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Visible\\TextComponent.h\">" << endl <<
			"      <Filter>Source Files\\Component\\Visible</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Utilites\\TextureAnimation\\TextureAnimation.h\">" << endl <<
			"      <Filter>Source Files\\Utilites\\TextureAnimation</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Visible\\TextureComponent.h\">" << endl <<
			"      <Filter>Source Files\\Component\\Visible</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Types\\Vectors.h\">" << endl <<
			"      <Filter>Source Files\\Types</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Component\\Visible\\VisibleComponent.h\">" << endl <<
			"      <Filter>Source Files\\Component\\Visible</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"    <ClInclude Include=\"" << enginePath << "\\src\\Window\\Window.h\">" << endl <<
			"      <Filter>Source Files\\Window</Filter>" << endl <<
			"    </ClInclude>" << endl <<
			"  </ItemGroup>" << endl <<
			"  <ItemGroup>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Actor\\Actor.cpp\">" << endl <<
			"      <Filter>Source Files\\Actor</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Actor\\Actor.h\">" << endl <<
			"      <Filter>Source Files\\Actor</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Utilites\\TextureAnimation\\AdvancedTextureAnimation.cpp\">" << endl <<
			"      <Filter>Source Files\\Utilites\\TextureAnimation</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Visible\\AnimationComponent.cpp\">" << endl <<
			"      <Filter>Source Files\\Component\\Visible</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Clickable\\ClickableComponent.cpp\">" << endl <<
			"      <Filter>Source Files\\Component\\Clickable</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Collision\\CircleCollisionComponent.cpp\">" << endl <<
			"      <Filter>Source Files\\Component\\Collision</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Collision\\CollisionComponent.cpp\">" << endl <<
			"      <Filter>Source Files\\Component\\Collision</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Component.cpp\">" << endl <<
			"      <Filter>Source Files\\Component</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Layer\\Gui\\Gui.cpp\">" << endl <<
			"      <Filter>Source Files\\Layer\\Gui</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Visible\\InputComponent.cpp\">" << endl <<
			"      <Filter>Source Files\\Component\\Visible</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Layer\\Layer.cpp\">" << endl <<
			"      <Filter>Source Files\\Layer</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Layer\\Level\\Level.cpp\">" << endl <<
			"      <Filter>Source Files\\Layer\\Level</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Audio\\MusicComponent.cpp\">" << endl <<
			"      <Filter>Source Files\\Component\\Audio</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Collision\\RectCollisionComponent.cpp\">" << endl <<
			"      <Filter>Source Files\\Component\\Collision</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Utilites\\ResourceManager.cpp\">" << endl <<
			"      <Filter>Source Files\\Utilites</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Utilites\\SaveLoad.cpp\">" << endl <<
			"      <Filter>Source Files\\Utilites</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Utilites\\TextureAnimation\\SimpleTextureAnimation.cpp\">" << endl <<
			"      <Filter>Source Files\\Utilites\\TextureAnimation</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Audio\\SoundComponent.cpp\">" << endl <<
			"      <Filter>Source Files\\Component\\Audio</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Visible\\TextComponent.cpp\">" << endl <<
			"      <Filter>Source Files\\Component\\Visible</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Utilites\\TextureAnimation\\TextureAnimation.cpp\">" << endl <<
			"      <Filter>Source Files\\Utilites\\TextureAnimation</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Visible\\TextureComponent.cpp\">" << endl <<
			"      <Filter>Source Files\\Component\\Visible</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Types\\Vectors.cpp\">" << endl <<
			"      <Filter>Source Files\\Types</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Component\\Visible\\VisibleComponent.cpp\">" << endl <<
			"      <Filter>Source Files\\Component\\Visible</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"    <ClCompile Include=\"" << enginePath << "\\src\\Window\\Window.cpp\">" << endl <<
			"      <Filter>Source Files\\Window</Filter>" << endl <<
			"    </ClCompile>" << endl <<
			"  </ItemGroup>" << endl <<
			"</Project>";
	}
	file.close();

	// Creating SnowEngine.vcxproj.user file
	file.open(projectPath + "/" + solutionName + "/SnowEngine/SnowEngine.vcxproj.user", ios_base::ate);
	{
		file << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl <<
			"<Project ToolsVersion=\"15.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">" << endl <<
			"  <PropertyGroup />" << endl <<
			"</Project>";
	}
	file.close();

	// Creating project.vcxproj file
	file.open(projectPath + "/" + solutionName + "/" + projectName + "/" + projectName + ".vcxproj", ios_base::ate);
	{
		file << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl <<
			"<Project DefaultTargets=\"Build\" ToolsVersion=\"15.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">" << endl <<
			"  <ItemGroup Label=\"ProjectConfigurations\">" << endl <<
			"    <ProjectConfiguration Include=\"Debug|Win32\">" << endl <<
			"      <Configuration>Debug</Configuration>" << endl <<
			"      <Platform>Win32</Platform>" << endl <<
			"    </ProjectConfiguration>" << endl <<
			"    <ProjectConfiguration Include=\"Release|Win32\">" << endl <<
			"      <Configuration>Release</Configuration>" << endl <<
			"      <Platform>Win32</Platform>" << endl <<
			"    </ProjectConfiguration>" << endl <<
			"    <ProjectConfiguration Include=\"Debug|x64\">" << endl <<
			"      <Configuration>Debug</Configuration>" << endl <<
			"      <Platform>x64</Platform>" << endl <<
			"    </ProjectConfiguration>" << endl <<
			"    <ProjectConfiguration Include=\"Release|x64\">" << endl <<
			"      <Configuration>Release</Configuration>" << endl <<
			"      <Platform>x64</Platform>" << endl <<
			"    </ProjectConfiguration>" << endl <<
			"  </ItemGroup>" << endl <<
			"  <PropertyGroup Label=\"Globals\">" << endl <<
			"    <VCProjectVersion>15.0</VCProjectVersion>" << endl <<
			"    <ProjectGuid>{E2509244-1A42-4B6F-8B32-C1B058AAFF42}</ProjectGuid>" << endl <<
			"    <Keyword>Win32Proj</Keyword>" << endl <<
			"    <RootNamespace>" << projectName << "</RootNamespace>" << endl <<
			"    <WindowsTargetPlatformVersion>10.0.17763.0</WindowsTargetPlatformVersion>" << endl <<
			"    <ProjectName>" << projectName << "</ProjectName>" << endl <<
			"  </PropertyGroup>" << endl <<
			"  <Import Project=\"$(VCTargetsPath)\\Microsoft.Cpp.Default.props\" />" << endl <<
			"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\" Label=\"Configuration\">" << endl <<
			"    <ConfigurationType>Application</ConfigurationType>" << endl <<
			"    <UseDebugLibraries>true</UseDebugLibraries>" << endl <<
			"    <PlatformToolset>v141</PlatformToolset>" << endl <<
			"    <CharacterSet>Unicode</CharacterSet>" << endl <<
			"  </PropertyGroup>" << endl <<
			"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\" Label=\"Configuration\">" << endl <<
			"    <ConfigurationType>Application</ConfigurationType>" << endl <<
			"    <UseDebugLibraries>false</UseDebugLibraries>" << endl <<
			"    <PlatformToolset>v141</PlatformToolset>" << endl <<
			"    <WholeProgramOptimization>true</WholeProgramOptimization>" << endl <<
			"    <CharacterSet>Unicode</CharacterSet>" << endl <<
			"  </PropertyGroup>" << endl <<
			"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|x64'\" Label=\"Configuration\">" << endl <<
			"    <ConfigurationType>Application</ConfigurationType>" << endl <<
			"    <UseDebugLibraries>true</UseDebugLibraries>" << endl <<
			"    <PlatformToolset>v141</PlatformToolset>" << endl <<
			"    <CharacterSet>Unicode</CharacterSet>" << endl <<
			"  </PropertyGroup>" << endl <<
			"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|x64'\" Label=\"Configuration\">" << endl <<
			"    <ConfigurationType>Application</ConfigurationType>" << endl <<
			"    <UseDebugLibraries>false</UseDebugLibraries>" << endl <<
			"    <PlatformToolset>v141</PlatformToolset>" << endl <<
			"    <WholeProgramOptimization>true</WholeProgramOptimization>" << endl <<
			"    <CharacterSet>Unicode</CharacterSet>" << endl <<
			"  </PropertyGroup>" << endl <<
			"  <Import Project=\"$(VCTargetsPath)\\Microsoft.Cpp.props\" />" << endl <<
			"  <ImportGroup Label=\"ExtensionSettings\">" << endl <<
			"  </ImportGroup>" << endl <<
			"  <ImportGroup Label=\"Shared\">" << endl <<
			"  </ImportGroup>" << endl <<
			"  <ImportGroup Label=\"PropertySheets\" Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\">" << endl <<
			"    <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists('$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />" << endl <<
			"  </ImportGroup>" << endl <<
			"  <ImportGroup Label=\"PropertySheets\" Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\">" << endl <<
			"    <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists('$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />" << endl <<
			"  </ImportGroup>" << endl <<
			"  <ImportGroup Label=\"PropertySheets\" Condition=\"'$(Configuration)|$(Platform)'=='Debug|x64'\">" << endl <<
			"    <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists('$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />" << endl <<
			"  </ImportGroup>" << endl <<
			"  <ImportGroup Label=\"PropertySheets\" Condition=\"'$(Configuration)|$(Platform)'=='Release|x64'\">" << endl <<
			"    <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists('$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />" << endl <<
			"  </ImportGroup>" << endl <<
			"  <PropertyGroup Label=\"UserMacros\" />" << endl <<
			"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|x64'\">" << endl <<
			"    <LinkIncremental>true</LinkIncremental>" << endl <<
			"  </PropertyGroup>" << endl <<
			"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\">" << endl <<
			"    <LinkIncremental>true</LinkIncremental>" << endl <<
			"  </PropertyGroup>" << endl <<
			"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\">" << endl <<
			"    <LinkIncremental>false</LinkIncremental>" << endl <<
			"  </PropertyGroup>" << endl <<
			"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|x64'\">" << endl <<
			"    <LinkIncremental>false</LinkIncremental>" << endl <<
			"  </PropertyGroup>" << endl <<
			"  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|x64'\">" << endl <<
			"    <ClCompile>" << endl <<
			"      <PrecompiledHeader>" << endl <<
			"      </PrecompiledHeader>" << endl <<
			"      <WarningLevel>Level3</WarningLevel>" << endl <<
			"      <Optimization>Disabled</Optimization>" << endl <<
			"      <SDLCheck>true</SDLCheck>" << endl <<
			"      <PreprocessorDefinitions>SFML_STATIC;_DEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>" << endl <<
			"      <ConformanceMode>true</ConformanceMode>" << endl <<
			"      <AdditionalIncludeDirectories>" << enginePath << "\\src;" << sfmlPath << "\\include</AdditionalIncludeDirectories>" << endl <<
			"    </ClCompile>" << endl <<
			"    <Link>" << endl <<
			"      <SubSystem>Console</SubSystem>" << endl <<
			"      <GenerateDebugInformation>true</GenerateDebugInformation>" << endl <<
			"      <AdditionalLibraryDirectories>" << sfmlPath << "\\lib</AdditionalLibraryDirectories>" << endl <<
			"      <AdditionalDependencies>sfml-network-d.lib;sfml-graphics-d.lib;sfml-window-d.lib;sfml-system-d.lib;sfml-audio-d.lib</AdditionalDependencies>" << endl <<
			"    </Link>" << endl <<
			"  </ItemDefinitionGroup>" << endl <<
			"  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\">" << endl <<
			"    <ClCompile>" << endl <<
			"      <PrecompiledHeader>" << endl <<
			"      </PrecompiledHeader>" << endl <<
			"      <WarningLevel>Level3</WarningLevel>" << endl <<
			"      <Optimization>Disabled</Optimization>" << endl <<
			"      <SDLCheck>true</SDLCheck>" << endl <<
			"      <PreprocessorDefinitions>WIN32;_DEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>" << endl <<
			"      <ConformanceMode>true</ConformanceMode>" << endl <<
			"    </ClCompile>" << endl <<
			"    <Link>" << endl <<
			"      <SubSystem>Console</SubSystem>" << endl <<
			"      <GenerateDebugInformation>true</GenerateDebugInformation>" << endl <<
			"    </Link>" << endl <<
			"  </ItemDefinitionGroup>" << endl <<
			"  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\">" << endl <<
			"    <ClCompile>" << endl <<
			"      <PrecompiledHeader>" << endl <<
			"      </PrecompiledHeader>" << endl <<
			"      <WarningLevel>Level3</WarningLevel>" << endl <<
			"      <Optimization>MaxSpeed</Optimization>" << endl <<
			"      <FunctionLevelLinking>true</FunctionLevelLinking>" << endl <<
			"      <IntrinsicFunctions>true</IntrinsicFunctions>" << endl <<
			"      <SDLCheck>true</SDLCheck>" << endl <<
			"      <PreprocessorDefinitions>WIN32;NDEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>" << endl <<
			"      <ConformanceMode>true</ConformanceMode>" << endl <<
			"    </ClCompile>" << endl <<
			"    <Link>" << endl <<
			"      <SubSystem>Console</SubSystem>" << endl <<
			"      <EnableCOMDATFolding>true</EnableCOMDATFolding>" << endl <<
			"      <OptimizeReferences>true</OptimizeReferences>" << endl <<
			"      <GenerateDebugInformation>true</GenerateDebugInformation>" << endl <<
			"    </Link>" << endl <<
			"  </ItemDefinitionGroup>" << endl <<
			"  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|x64'\">" << endl <<
			"    <ClCompile>" << endl <<
			"      <PrecompiledHeader>" << endl <<
			"      </PrecompiledHeader>" << endl <<
			"      <WarningLevel>Level3</WarningLevel>" << endl <<
			"      <Optimization>MaxSpeed</Optimization>" << endl <<
			"      <FunctionLevelLinking>true</FunctionLevelLinking>" << endl <<
			"      <IntrinsicFunctions>true</IntrinsicFunctions>" << endl <<
			"      <SDLCheck>true</SDLCheck>" << endl <<
			"      <PreprocessorDefinitions>SFML_STATIC;NDEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>" << endl <<
			"      <ConformanceMode>true</ConformanceMode>" << endl <<
			"      <AdditionalIncludeDirectories>" << enginePath << "\\src;" << sfmlPath << "\\include</AdditionalIncludeDirectories>" << endl <<
			"    </ClCompile>" << endl <<
			"    <Link>" << endl <<
			"      <SubSystem>Console</SubSystem>" << endl <<
			"      <EnableCOMDATFolding>true</EnableCOMDATFolding>" << endl <<
			"      <OptimizeReferences>true</OptimizeReferences>" << endl <<
			"      <GenerateDebugInformation>true</GenerateDebugInformation>" << endl <<
			"      <AdditionalLibraryDirectories>" << sfmlPath << "\\lib</AdditionalLibraryDirectories>" << endl <<
			"      <AdditionalDependencies>sfml-network.lib;sfml-graphics.lib;sfml-window.lib;sfml-system.lib;sfml-audio.lib</AdditionalDependencies>" << endl <<
			"    </Link>" << endl <<
			"  </ItemDefinitionGroup>" << endl <<
			"  <ItemGroup>" << endl <<
			"    <ProjectReference Include=\"..\\SnowEngine\\SnowEngine.vcxproj\">" << endl <<
			"      <Project>{96fbfef5-4d6f-455c-94ee-ffac4788c918}</Project>" << endl <<
			"    </ProjectReference>" << endl <<
			"  </ItemGroup>" << endl <<
			"  <Import Project=\"$(VCTargetsPath)\\Microsoft.Cpp.targets\" />" << endl <<
			"  <ImportGroup Label=\"ExtensionTargets\">" << endl <<
			"  </ImportGroup>" << endl <<
			"</Project>";
	}
	file.close();

	// Creating project.vcxproj.filters file
	file.open(projectPath + "/" + solutionName + "/" + projectName + "/" + projectName + ".vcxproj.filters", ios_base::ate);
	{
		file << "<?xml version=\"1.0\" encoding=\"utf - 8\"?>" << endl <<
			"<Project ToolsVersion=\"4.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">" << endl <<
			"  <ItemGroup>" << endl <<
			"    <Filter Include=\"Source Files\">" << endl <<
			"      <UniqueIdentifier>{9077b4f1-2c5b-48be-86a1-2a0ac91df545}</UniqueIdentifier>" << endl <<
			"    </Filter>" << endl <<
			"  </ItemGroup>" << endl <<
			"</Project>";
	}
	file.close();

	// Creating project.vcxproj.user file
	file.open(projectPath + "/" + solutionName + "/" + projectName + "/" + projectName + ".vcxproj.user", ios_base::ate);
	{
		file << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl <<
			"<Project ToolsVersion=\"15.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">" << endl <<
			"  <PropertyGroup />" << endl <<
			"</Project>";
	}
	file.close();

	// Creating resurce folders
	create_directory(projectPath + "/" + solutionName + "/" + projectName + "/res");
	create_directory(projectPath + "/" + solutionName + "/" + projectName + "/res/textures");
	create_directory(projectPath + "/" + solutionName + "/" + projectName + "/res/fonts");
	create_directory(projectPath + "/" + solutionName + "/" + projectName + "/res/music");
	create_directory(projectPath + "/" + solutionName + "/" + projectName + "/res/sounds");

	Printer::print("The project was successfully created. Do you want to open it? (Y/N)\n\t");
	switch (_getch())
	{
	case 121:
	case 89:
		system((projectPath + "/" + solutionName + "/SnowEngine/" + solutionName + ".sln").c_str());
	}
}