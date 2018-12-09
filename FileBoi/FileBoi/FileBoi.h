#pragma once
#include "Window.h"
#include "AssetManager.h"
#include <string>

class FileBoi
{
public:
	FileBoi();
	void Init();
	void Go();
	void Prepare(const float &deltatime);
	void Process(const float &deltatime);
	void Present(const float &deltatime);

private:
	//-- Need Network module


	//-- Need GUI module


	std::shared_ptr<Window> m_window;
	std::shared_ptr<AssetManager> m_assetManager;
	float m_deltaTime;
	float m_FPS;
	sf::Clock m_clock;

	//-- Testing area
	sf::CircleShape shape;

};