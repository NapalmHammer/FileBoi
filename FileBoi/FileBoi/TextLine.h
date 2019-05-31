#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SharedApplicationData.h"

class TextLine
{
public:
	TextLine(sf::Rect<float> R, std::shared_ptr<ShareableApplicationData>& D, bool isActive = false);
	std::string GetString()
	{
		m_ready = false;
		auto temp = m_text.getString();
		m_text.setString("") ;
		return temp;
	}
	void SetString(std::string S){m_text.setString(S);}
	void SetRect(sf::Rect<float> R) { m_PosDim = R; }
	void Update(std::shared_ptr<ShareableApplicationData>& D);
	void Draw(std::shared_ptr<Window>& W);
	bool GetReady() { return m_ready; }
private:
	// Rect that contains X/Y of upper left corner of object, and width/height of area extending from X/Y as (X, Y, Width, Height) in order
	sf::RectangleShape m_rect;
	sf::Rect<float> m_PosDim;
	bool m_IsActive = false;
	sf::Text m_text;
	sf::Color m_surfaceColor = sf::Color(0, 0, 0, 255);
	sf::Color m_textColor = sf::Color(255, 255, 255, 255);
	bool m_ready = false;

};