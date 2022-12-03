#pragma once

#include<iostream>
#include<vector>
#include<map>
#include<sstream>
#include<string>
#include<filesystem>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class FileManagement
{
private:

	void initVariables();
public:
	FileManagement();
	virtual ~FileManagement();

	//Getter functions

	int getAmountOfFilesInsideAFolder(std::string const& Path_Folder);
	std::vector<std::string> getNameOfFilesInsideAFolder(std::string const &Path_Folder);
};

