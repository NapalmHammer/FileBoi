#pragma once
#include <string>
#include <fstream>
#include <experimental/filesystem>
#include <iostream>
#include "Log.h"

class FileManager
{
public:
	void CheckFile(std::string fileName)
	{
		if (!std::experimental::filesystem::exists(fileName))
		{
			m_logptr->AddString("file " + fileName + " does not exist.");
		}
		else
		{
			m_logptr->AddString("success!");
		}
	}
	void Init(Log* L) 
	{ 
		m_logptr = L; 
	}
private:
	Log * m_logptr;
};