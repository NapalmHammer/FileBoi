#pragma once
#include "Window.h"

class FileBoi
{
public:
	FileBoi();
	void Init();
	void Go();
	void Prepare();
	void Process();
	void Present();

private:
	//-- Need Network module


	//-- Need GUI module


	std::shared_ptr<Window> m_window;

	//-- Testing area
	sf::CircleShape shape;

};