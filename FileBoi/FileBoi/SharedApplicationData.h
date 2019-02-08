#pragma once
#include "Window.h"
#include "AssetManager.h"
#include "MouseHandler.h"
#include "KeyboardHandler.h"
#include "Network.h"

struct ShareableApplicationData
{
	Network m_net;
	KeyboardHandler SAD_kbd;
	MouseHandler SAD_ms;
	sf::Event SAD_event;
	std::shared_ptr<Window> SAD_window;
	std::shared_ptr<AssetManager> SAD_assetManager;
};