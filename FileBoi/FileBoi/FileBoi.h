#pragma once
#include <iostream>
#include <string>
#include "SharedApplicationData.h"
#include "Button.h"
#include "GUI.h"

//-- testing
void Print();

//--

class FileBoi
{
public:
	FileBoi();
	void Init();
	void Go();
	void HandleEvents(sf::Event EVENT);
	void Prepare(const float &deltatime);
	void Process(const float &deltatime);
	void Present(const float &deltatime);


private:
	//-- Approved members

	std::shared_ptr<ShareableApplicationData> m_data;
	float m_deltaTime;
	float m_FPS;
	sf::Clock m_clock;

	//-- Testing members
	std::shared_ptr<ConnectButton> ConBut;
	sf::CircleShape shape;
	std::unique_ptr<GUI> m_gui;
};