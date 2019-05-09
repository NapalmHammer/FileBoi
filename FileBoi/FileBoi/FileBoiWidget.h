#pragma once
#include "SharedApplicationData.h"

class FileBoiWidget
{
public:
	FileBoiWidget(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD);
	virtual void Update() {};
	virtual void OnPress() {};
	virtual void Draw();
	void SetAreaColor(sf::Color c) { m_surfaceColor = c; };
	//void SetTextColor(sf::Color c) { m_textColor = c; };
protected:
	sf::RectangleShape m_rect;
	//sf::Text m_text;
	std::shared_ptr<ShareableApplicationData> m_SAD;
	sf::Color m_surfaceColor = sf::Color(200, 200, 200, 255);
	//sf::Color m_textColor = sf::Color(0, 0, 0, 255);
};

