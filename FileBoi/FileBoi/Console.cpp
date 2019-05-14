#include "Console.h"



Console::Console(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD)
	:FileBoiWidget(rect, SAD)
{
	SetAreaColor(sf::Color::Black);
}

void Console::OnPress()
{
	m_active = true;
}

void Console::Update(std::shared_ptr<ShareableApplicationData>& SAD)
{
	if (this->m_rect.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*m_SAD->SAD_window->GetWindow())))
	{
		//this->m_text.setStyle(sf::Text::Underlined);
		this->m_rect.setOutlineColor(sf::Color(100, 100, 100, 255));
		if (this->m_SAD->SAD_ms.GetClicked(sf::Mouse::Button::Left))
		{
			this->OnPress();
			this->m_SAD->SAD_ms.Released(sf::Mouse::Button::Left);
		}
	}
	else
	{
		if (this->m_SAD->SAD_ms.GetClicked(sf::Mouse::Button::Left))
		{
			m_active = false;
			this->m_SAD->SAD_ms.Released(sf::Mouse::Button::Left);
		}
		//this->m_text.setStyle(sf::Text::Regular);
		this->m_rect.setOutlineColor(sf::Color(150, 150, 150, 255));
	}


	if (m_active)
	{
		auto t = m_SAD->SAD_kbd.GetKey();

		if (t != sf::Keyboard::Key::Unknown)
		{
			//std::string temp = m_text.getString();
			if (t == '\b')
			{
				/*if (!temp.empty())
				{
					temp.pop_back();
					m_text.setString(temp);
				}*/
			}
			else
			{
				//temp.push_back(t);
				//m_text.setString(temp);
			}
		}
	}
}

//sf::String Console::GetString()
//{
//	sf::String temp = m_text.getString();
//	m_text.setString("");
//	return temp;
//}
