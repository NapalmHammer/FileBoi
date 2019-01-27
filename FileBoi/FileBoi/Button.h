#pragma once
#include <SFML/Graphics.hpp>
#include "SharedApplicationData.h"
#include <iostream>

class Button
{
public:
	Button(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD, std::string buttonname);
	virtual void Update();
	virtual void OnPress() {};
	virtual void Draw();
	void SetAreaColor(sf::Color c) { m_surfaceColor = c; };
	void SetTextColor(sf::Color c) { m_textColor = c; };
protected:
	sf::RectangleShape m_rect;
	sf::Text m_text;
	std::shared_ptr<ShareableApplicationData> m_SAD;
	sf::Color m_surfaceColor = sf::Color(200, 200, 200, 255);
	sf::Color m_textColor = sf::Color(0, 0, 0, 255);
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
