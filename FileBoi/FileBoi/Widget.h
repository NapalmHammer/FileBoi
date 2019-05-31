#pragma once
#include "SharedApplicationData.h"

class Widget
{
public:
	Widget() = default;
	Widget(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD);
	virtual void Update(std::shared_ptr<ShareableApplicationData>& D) {};
	
	virtual void OnPress() { std::cout << "TO DO: ERASE THESE MESSAGES \n"; };
	virtual void Draw(std::shared_ptr<Window> & W);
	void SetAreaColor(sf::Color c) { m_surfaceColor = c; };
	void SetTextColor(sf::Color c) { m_textColor = c; };
protected:
	sf::RectangleShape m_rect;
	sf::Text m_text;
	std::shared_ptr<ShareableApplicationData> m_SAD;
	sf::Color m_surfaceColor = sf::Color(200, 200, 200, 255);
	sf::Color m_textColor = sf::Color(100, 100, 100, 255);
};

