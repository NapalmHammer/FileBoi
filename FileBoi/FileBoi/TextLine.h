#pragma once
#include "FileBoiWidget.h"



class TextLine : public FileBoiWidget
{
public:
	TextLine(sf::Rect<float> R, std::shared_ptr<ShareableApplicationData>& D);
	std::string GetString(){return m_String;}

private:
	std::string m_String;

};