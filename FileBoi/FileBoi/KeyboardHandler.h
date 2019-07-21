#pragma once
#include <SFML/Graphics.hpp>

class KeyboardHandler
{
public:
	KeyboardHandler();
	void AddKey(sf::Uint32 k);
	void FlushKey() { m_key = sf::Keyboard::Unknown; };
	sf::Uint32 GetKey();
private:
	sf::Uint32 m_key;
};

