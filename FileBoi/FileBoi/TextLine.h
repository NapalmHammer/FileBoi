#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SharedApplicationData.h"

class TextLine
{
public:
	TextLine(sf::Rect<float> R, std::shared_ptr<ShareableApplicationData>& D);
	std::string GetString(){return m_Buffer;}
	void SetString(std::string S){m_Buffer = S;}
	void SetRect(sf::Rect<float> R) { m_PosDim = R; }
	void Update();
	void Draw(Window& W);
private:
	std::string m_Buffer;
	// Rect that contains X/Y of upper left corner of object, and width/height of area extending from X/Y as (X, Y, Width, Height) in order
	sf::RectangleShape m_rect;
	sf::Rect<float> m_PosDim;
	bool m_IsActive;
	sf::Text m_text;
	sf::Color m_surfaceColor = sf::Color(200, 200, 200, 255);
	sf::Color m_textColor = sf::Color(0, 0, 0, 255);

};