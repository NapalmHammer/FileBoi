#include "FileBoiButtons.h"

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