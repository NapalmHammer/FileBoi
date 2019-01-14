#include <SFML/Graphics.hpp>
#pragma once
class MouseHandler
{
public:
	MouseHandler();
	void Released(sf::Mouse::Button button);
	void Clicked(sf::Mouse::Button button);
	bool GetClicked(sf::Mouse::Button button);
private:
	bool m_LClicked;
	bool m_RClicked;
};

