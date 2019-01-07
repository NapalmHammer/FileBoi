#pragma once
#include <SFML/Graphics.hpp>
#include "SharedApplicationData.h"
#include <iostream>
//#include "FileBoi.h"

class Button
{
public:
	virtual void Update() = 0;
	virtual void OnPress() = 0;
	virtual void Draw() = 0;
protected:
	std::string m_title;
	sf::RectangleShape m_rect;
};

class ConnectButton: public Button
{
public:
	ConnectButton(float top, float left, float width, float height, sf::Color color, std::shared_ptr<ShareableApplicationData>& SAD);
	void Update();
	void OnPress();
	void Draw();
	void SetFunc(void(*fcnPtr)()){FP = fcnPtr;}
private:
	void(*FP)();
	std::shared_ptr<ShareableApplicationData> m_SAD;
};

