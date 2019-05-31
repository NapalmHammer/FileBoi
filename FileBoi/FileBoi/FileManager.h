#pragma once
#include <string>
#include <fstream>
#include <experimental/filesystem>
#include <iostream>

class FileManager
{
public:
	void CheckFile(std::string fileName)
	{
		if (!std::experimental::filesystem::exists(fileName))
		{
			std::cout << "file " << fileName << " does not exist \n";
		}
		else
		{
			std::cout << "success! \n";
		}
	}
};