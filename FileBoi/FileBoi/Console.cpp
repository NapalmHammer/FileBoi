#include "Console.h"



Console::Console(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD)
	:Button(rect, SAD, NULL)
{
}

void Console::Update()
{
}

sf::String Console::GetString()
{
	sf::String temp = m_text.getString();
	m_text.setString("");
	return temp;
}
