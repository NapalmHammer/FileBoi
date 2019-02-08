#include "KeyboardHandler.h"



KeyboardHandler::KeyboardHandler()
{
}

void KeyboardHandler::AddKey(sf::Uint32 k)
{
	m_key = k;
}

sf::Uint32 KeyboardHandler::GetKey()
{
	auto temp = m_key;
	m_key = sf::Keyboard::Unknown;
	return temp;
}
