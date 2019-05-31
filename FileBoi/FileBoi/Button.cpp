#include "Button.h"

Button::Button(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD, std::string buttonname)
	:Widget(rect, SAD)
{
	m_text.setString(buttonname);
	//std::cout << "char size: " << m_text.getCharacterSize() << "\n";
	//std::cout << "button height: " << m_rect.getPosition().y << " " << m_rect.getSize().y << " " << m_rect.getSize().y - m_rect.getPosition().y << "\n";
}

void Button::Update(std::shared_ptr<ShareableApplicationData>& D)
{
	if (this->m_rect.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*m_SAD->SAD_window->GetWindow())))
	{
		this->m_text.setStyle(sf::Text::Underlined);
		this->m_rect.setOutlineColor(sf::Color(100,100,100,255));
		if (this->m_SAD->SAD_ms.GetClicked(sf::Mouse::Button::Left))
		{
			this->OnPress();
			this->m_SAD->SAD_ms.Released(sf::Mouse::Button::Left);
		}
	}
	else
	{
		this->m_text.setStyle(sf::Text::Regular);
		this->m_rect.setOutlineColor(sf::Color(150,150,150,255));
	}
}

