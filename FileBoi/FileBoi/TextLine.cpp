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
	this->m_text.setString("TEXT: ");
	this->m_text.setFillColor(m_textColor);
	this->m_text.setCharacterSize(12);
	this->m_text.setPosition(R.left + 25.0f, R.top + 17.0f);
}

void TextLine::Update(std::shared_ptr<ShareableApplicationData>& D)
{
	if (this->m_rect.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*D->SAD_window->GetWindow())))
	{
		this->m_text.setStyle(sf::Text::Underlined);
		this->m_rect.setOutlineColor(sf::Color(100, 100, 100, 255));
		if (D->SAD_ms.GetClicked(sf::Mouse::Button::Left))
		{
			m_IsActive = true;
			//this->OnPress();
			D->SAD_ms.Released(sf::Mouse::Button::Left);
		}
	}
	else
	{
		if (D->SAD_ms.GetClicked(sf::Mouse::Button::Left))
		{
			m_IsActive = false;
			D->SAD_ms.Released(sf::Mouse::Button::Left);
		}
		this->m_text.setStyle(sf::Text::Regular);
		this->m_rect.setOutlineColor(sf::Color(150, 150, 150, 255));
	}


	if (m_IsActive)
	{
		auto t = D->SAD_kbd.GetKey();

		if (t != sf::Keyboard::Key::Unknown)
		{
			std::string temp = m_text.getString();
			if (t == '\b')
			{
				if (!temp.empty())
				{
				temp.pop_back();
				m_text.setString(temp);
				}
			}
			else
			{
				temp.push_back(t);
				m_text.setString(temp);
			}
		}
	}
}

void TextLine::Draw(std::shared_ptr<Window> & W)
{
	W->Draw(this->m_rect);
	W->Draw(this->m_text);
}
