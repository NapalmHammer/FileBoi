#pragma once
#include "FileBoiWidget.h"
#include <iostream>

class Button : public FileBoiWidget
{
public:
	Button(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD, std::string buttonname);
	void Update() override;
private:
};


class ConnectButton: public Button
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
