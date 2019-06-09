#include "TextLine.h"

TextLine::TextLine(sf::Rect<float> R, std::shared_ptr<ShareableApplicationData>& D, bool isActive)
{
	//Button surface area
	m_PosDim = R;
	this->m_rect.setFillColor(m_surfaceColor);
	this->m_rect.setOutlineThickness(2.0f);
	this->m_rect.setOutlineColor(sf::Color::Red);
	this->m_rect.setPosition(R.left, R.top);
	this->m_rect.setSize({ R.width, R.height });

	//Button text attributes
	this->m_text.setFont(D->SAD_assetManager->GetFont("OpenSans-Regular"));
	this->m_text.setString("");
	this->m_text.setFillColor(m_textColor);
	this->m_text.setCharacterSize(20);
	this->m_text.setPosition(R.left + R.width * 0.01f, R.top);
	//std::cout	<< "box heights: " << R.top << " " << R.height << "\n";
	//std::cout	<< "text character size: " 
	//			<< this->m_text.getCharacterSize() 
	//			<< " Position: " 
	//			<< this->m_text.getPosition().x 
	//			<< " " 
	//			<< this->m_text.getPosition().y 
	//			<< "\n";
	m_IsActive = isActive;
}

void TextLine::Update(std::shared_ptr<ShareableApplicationData>& D)
{
	if (this->m_rect.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*D->SAD_window->GetWindow())))
	{
		this->m_text.setStyle(sf::Text::Underlined);
		this->m_rect.setOutlineColor(sf::Color::White);
		if (D->SAD_ms.GetClicked(sf::Mouse::Button::Left))
		{
			m_IsActive = true;
			this->m_text.setStyle(sf::Text::Underlined);
			
			//this->OnPress();
		}
	}
	else
	{
		if (D->SAD_ms.GetClicked(sf::Mouse::Button::Left))
		{
			m_IsActive = false;
			this->m_text.setStyle(sf::Text::Regular);
		}
		if(!m_IsActive)
			this->m_text.setStyle(sf::Text::Regular);
		this->m_rect.setOutlineColor(sf::Color::Blue);
	}

	if (m_IsActive)
	{
		auto t = D->SAD_kbd.GetKey();

		if (t != sf::Keyboard::Key::Unknown)
		{
			std::string temp = m_text.getString();
			switch (t)
			{
			case '\b':
			{
				if (!temp.empty())
				{
					temp.pop_back();
					m_text.setString(temp);
				}
				break;
			}
			case 59:
			{
				D->m_log.AddString("nope59 \n");
				break;
			}
			case 13:
			{
				m_ready = true;
				break;
			}
			default:
			{
				temp.push_back(t);
				m_text.setString(temp);
				break;
			}
			}
		}
	}
}

void TextLine::Draw(std::shared_ptr<Window> & W)
{
	
	W->Draw(this->m_rect);
	W->Draw(this->m_text);
}
