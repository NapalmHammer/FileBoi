#pragma once
#include "Button.h"


class ConnectButton : public Button
{
public:
	ConnectButton(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD, std::string buttonname);
	void OnPress() override;
private:
};

class DisconnectButton : public Button
{
public:
	DisconnectButton(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD, std::string buttonname);
	void OnPress() override;
private:
};