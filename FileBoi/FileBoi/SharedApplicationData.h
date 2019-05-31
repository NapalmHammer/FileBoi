#pragma once
#include "Window.h"
#include "AssetManager.h"
#include "MouseHandler.h"
#include "KeyboardHandler.h"
#include "Network.h"
#include "Log.h"

struct ShareableApplicationData
{
	Network m_net;
	KeyboardHandler SAD_kbd;
	MouseHandler SAD_ms;
	Log m_log;
	sf::Event SAD_event;
	std::shared_ptr<Window> SAD_window;
	std::shared_ptr<AssetManager> SAD_assetManager;
	
};