#include "Button.h"



ConnectButton::ConnectButton(float top, float left, float width, float height, sf::Color color, std::shared_ptr<ShareableApplicationData>& SAD)
	:m_SAD(SAD)
{
	this->m_title = "Connect Button";

	this->m_rect.setFillColor(color);
	this->m_rect.setOutlineThickness(2.0f);
	this->m_rect.setPosition(top, left);
	this->m_rect.setSize({ width, height});

	//m_SAD = SAD;
}

void ConnectButton::Update()
{
	if (this->m_rect.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*m_SAD->SAD_window->GetWindow())))
	{
		this->m_rect.setOutlineColor(sf::Color::Red);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->OnPress();
		}
	}
	else
	{
		this->m_rect.setOutlineColor(sf::Color::Blue);
	}
}

void ConnectButton::OnPress()
{
	std::cout << "Mouse click" << "\n";
	FP();
}

void ConnectButton::Draw()
{
	m_SAD->SAD_window->Draw(this->m_rect);
}