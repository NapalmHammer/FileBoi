#include "TextLine.h"

TextLine::TextLine(sf::Rect<float> R, std::shared_ptr<ShareableApplicationData>& D)
{
	//Button surface area
	m_PosDim = R;
	this->m_rect.setFillColor(m_surfaceColor);
	this->m_rect.setOutlineThickness(1.0f);
	this->m_rect.setPosition(R.left, R.top);
	this->m_rect.setSize({ R.width, R.height });

	//Button text attributes
	this->m_text.setFont(D->SAD_assetManager->GetFont("OpenSans-Regular"));
	this->m_text.setString("BIG OL TEXT");
	this->m_text.setFillColor(m_textColor);
	this->m_text.setCharacterSize(12);
	this->m_text.setPosition(R.left + 25.0f, R.top + 17.0f);
}

void TextLine::Update()
{
}

void TextLine::Draw(Window & W)
{
	W.Draw(this->m_rect);
	W.Draw(this->m_text);
}
