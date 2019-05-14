#include "FileBoiWidget.h"


FileBoiWidget::FileBoiWidget(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD)
	:m_SAD(SAD)
{
	//Button surface area
	this->m_rect.setFillColor(m_surfaceColor);
	this->m_rect.setOutlineThickness(1.0f);
	this->m_rect.setPosition(rect.left, rect.top);
	this->m_rect.setSize({ rect.width, rect.height });

	//Button text attributes
	this->m_text.setFont(this->m_SAD->SAD_assetManager->GetFont("OpenSans-Regular"));
	//this->m_text.setString(buttonname);
	this->m_text.setFillColor(m_textColor);
	this->m_text.setCharacterSize(12);
	this->m_text.setPosition(rect.left + 25.0f, rect.top + 17.0f);
}

void FileBoiWidget::Draw(std::shared_ptr<Window> & W)
{
	W->Draw(this->m_rect);
	m_SAD->SAD_window->Draw(this->m_text);
}
