#include "FileManagement.h"

void FileManagement::initVariables()
{

}

FileManagement::FileManagement()
{
	this->initVariables();
}

FileManagement::~FileManagement()
{

}

int FileManagement::getAmountOfFilesInsideAFolder(std::string const& Path_Folder)
{
	auto dirIter = std::filesystem::directory_iterator(Path_Folder);
	int fileCount = 0;
	for (auto& entry : dirIter)
	{
		if (entry.is_regular_file())
		{
			fileCount++;
		}
	}
	return fileCount;
}

std::vector<std::string> FileManagement::getNameOfFilesInsideAFolder(std::string const& Path_Folder)
{
	std::vector<std::string> names;
	auto dirIter = std::filesystem::directory_iterator(Path_Folder);
	for (auto& entry : dirIter)
	{
		if (entry.is_regular_file())
		{
			std::string FileName = entry.path().string();
			FileName = FileName.substr(FileName.find_last_of("/\\") + 1);
			std::string::size_type const p(FileName.find_last_of('.'));
			FileName = p > 0 && p != std::string::npos ? FileName.substr(0, p) : FileName;
			names.push_back(FileName);
		}
	}
	return names;
}
