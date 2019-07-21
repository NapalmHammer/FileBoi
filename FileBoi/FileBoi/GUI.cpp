#include "GUI.h"

GUI::GUI(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD)
	:m_SAD(SAD)
{
	this->m_irect = rect;
	float temp = rect.height / 3.0f;
	//m_widgets.emplace_back(std::make_unique<ConnectButton>(sf::Rect<float>(m_irect.left, m_irect.top, m_irect.width, temp - 2.0f ), m_SAD, "Connect"));
	//m_widgets.emplace_back(std::make_unique<Console>(sf::Rect<float>(200.0f, 10.0f, 300.0f, 100.0f), m_SAD));
	//m_widgets.emplace_back(std::make_unique<InputBox>(sf::Rect<float>(100.0f, 100.0f, 600.0f, 40.0f), m_SAD, "Search Box"));
	m_widgets.emplace_back(std::make_unique<IPIB>(sf::Rect<float>(10.0f, 10.0f, 300.0f, 40.0f), m_SAD, "IP"));
	m_widgets.emplace_back(std::make_unique<SelectFileIB>(sf::Rect<float>(10.0f, 60.0f, 300.0f, 40.0f), m_SAD, "File"));
	m_widgets.emplace_back(std::make_unique<DisconnectButton>(sf::Rect<float>(10.0f, 110.0f, 300.0f, 40.0f), m_SAD, "Disconnect"));
	m_widgets.emplace_back(std::make_unique<Console>(sf::Rect<float>(400.0f, 10.0f, 480.0f, 580.0f), m_SAD));
}

void GUI::Update(std::shared_ptr<ShareableApplicationData>& D)
{
	for (auto& i : m_widgets)
		i->Update(D);
}

void GUI::Draw(std::shared_ptr<Window>& W)
{
	for (auto& i : m_widgets)
		i->Draw(W);
}
