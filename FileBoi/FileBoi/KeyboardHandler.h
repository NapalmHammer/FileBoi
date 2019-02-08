#pragma once
#include <SFML/Graphics.hpp>

class KeyboardHandler
{
public:
	KeyboardHandler();
	void AddKey(sf::Uint32 k);
	sf::Uint32 GetKey();
private:
	sf::Uint32 m_key;
};

