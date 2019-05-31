#pragma once
#include "SharedApplicationData.h"
#include "Widget.h"
#include <iostream>
#include "TextLine.h"
#include <vector>


class Console: public Widget
{
public:
	Console(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD);
	void Update(std::shared_ptr<ShareableApplicationData>& SAD) override;
	void Draw(std::shared_ptr<Window> & W) override;
private:
	bool m_active = false; 
	TextLine m_TL;
	sf::Text m_text;
	sf::Vector2f m_startingTextPos;
	Log* m_logptr;
};
