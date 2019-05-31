#pragma once
#include <vector>
#include <string>


class Log
{
public:
	void AddString(std::string s)
	{m_buffer.push_back(s);}
	const std::vector<std::string>& GetBuffer()
	{return m_buffer;}
private:
	std::vector<std::string> m_buffer;
};