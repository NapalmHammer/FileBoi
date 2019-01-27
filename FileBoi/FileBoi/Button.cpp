#include "Button.h"


Button::Button(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD, std::string buttonname)
	:m_SAD(SAD)
{
	//Button surface area
	this->m_rect.setFillColor(m_surfaceColor);
	this->m_rect.setOutlineThickness(1.0f);
	this->m_rect.setPosition(rect.left, rect.top);
	this->m_rect.setSize({ rect.width, rect.height });

	//Button text attributes
	this->m_text.setFont(this->m_SAD->SAD_assetManager->GetFont("OpenSans-Regular"));
	this->m_text.setString(buttonname);
	this->m_text.setFillColor(m_textColor);
	this->m_text.setCharacterSize(12);
	this->m_text.setPosition(rect.left + 25.0f, rect.top + 17.0f);
}

void Button::Update()
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

void Button::Draw()
{
	m_SAD->SAD_window->Draw(this->m_rect);
	m_SAD->SAD_window->Draw(this->m_text);
}

ConnectButton::ConnectButton(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD, std::string buttonname)
	:Button(rect, SAD, buttonname)
{}

void ConnectButton::OnPress()
{
	std::cout << "[Connect BUTTON]" << "\n";
	this->m_SAD->m_net.Connect("127.0.0.1", 53000);
}

DisconnectButton::DisconnectButton(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD, std::string buttonname)
	:Button(rect, SAD, buttonname)
{}

void DisconnectButton::OnPress()
{
	std::cout << "[Disconnect BUTTON]" << "\n";
	this->m_SAD->m_net.Disconect();
}
