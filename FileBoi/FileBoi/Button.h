#pragma once
#include <SFML/Graphics.hpp>
#include "SharedApplicationData.h"
#include <iostream>
//#include "FileBoi.h"

class Button
{
public:
	Button(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD, std::string buttonname);
	virtual void Update();
	virtual void OnPress() {};
	virtual void Draw();
protected:
	sf::RectangleShape m_rect;
	sf::Text m_text;
	std::shared_ptr<ShareableApplicationData> m_SAD;
};

class ConnectButton: public Button
{
public:
	ConnectButton(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD, std::string buttonname);
	void OnPress() override;
	//void SetFunc(void(Network::*fcnPtr)(sf::IpAddress address, sf::Int32 port)){FP = fcnPtr;}
private:
	//void (Network::*FP)(sf::IpAddress address, sf::Int32 port);
};

