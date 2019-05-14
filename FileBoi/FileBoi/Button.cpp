#include "Button.h"

Button::Button(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD, std::string buttonname)
	:FileBoiWidget(rect, SAD)
{
	m_text.setString(buttonname);
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
