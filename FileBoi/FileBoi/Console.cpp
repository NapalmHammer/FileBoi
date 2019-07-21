#include "Console.h"



Console::Console(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD)
	:Widget(rect, SAD),
	m_TL({rect.left + 5.0f, rect.top + rect.height - 30, rect.width - 10.0f, 25.0f }, SAD, true)
{
	m_rect.setOutlineThickness(3.0f);
	m_rect.setOutlineColor(sf::Color::Blue);
	SetAreaColor(sf::Color::Black);
	m_text.setFont(SAD->SAD_assetManager->GetFont("OpenSans-Regular"));
	m_startingTextPos = { rect.left + 5.0f,  rect.top + rect.height - 50 };
	this->m_text.setString("");
	this->m_text.setFillColor(m_textColor);
	this->m_text.setCharacterSize(20);
	this->m_text.setPosition(rect.left, rect.top + rect.height - 20);
	m_logptr = &SAD->m_log;
	m_logptr->AddString("this is a test beep beep");
}

void Console::Update(std::shared_ptr<ShareableApplicationData>& SAD)
{
	m_TL.Update(SAD);
	if (m_TL.GetReady())
	{
		m_logptr->AddString(m_TL.GetString());
	}
}

void Console::Draw(std::shared_ptr<Window>& W)
{
	Widget::Draw(W);
	m_TL.Draw(W);
	m_text.setPosition(m_startingTextPos);
	for (auto i = (m_logptr->GetBuffer().size() - 1); i >= 0; --i)
	{
		m_text.setString(m_logptr->GetBuffer()[i]);
		m_text.move({ 0.0f, -20 });
		W->Draw(m_text);
		if (i == 0)
			return;
	}
}