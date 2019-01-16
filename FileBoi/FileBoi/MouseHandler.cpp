#include "MouseHandler.h"



MouseHandler::MouseHandler()
{
	Released(sf::Mouse::Button::Left);
	Released(sf::Mouse::Button::Right);
}

void MouseHandler::Released(sf::Mouse::Button button)
{
	if (button == sf::Mouse::Button::Left)
	{
		m_LClicked = false;
	}
	else if (button == sf::Mouse::Button::Right)
	{
		m_RClicked = false;
	}
}

void MouseHandler::Clicked(sf::Mouse::Button button)
{
	if (button == sf::Mouse::Button::Left)
	{
		m_LClicked = true;
	}
	else if (button == sf::Mouse::Button::Right)
	{
		m_RClicked = true;
	}
}

bool MouseHandler::GetClicked(sf::Mouse::Button button)
{
	if (button == sf::Mouse::Button::Left)
	{
		return m_LClicked;
	}
	else if (button == sf::Mouse::Button::Right)
	{
		return m_RClicked;
	}
}