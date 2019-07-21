#pragma once
#include "Window.h"
#include "AssetManager.h"
#include "MouseHandler.h"
#include "KeyboardHandler.h"
#include "Network.h"
#include "Log.h"
#include "FileManager.h"

struct ShareableApplicationData
{
	Log m_log;
	Network m_net;
	KeyboardHandler SAD_kbd;
	MouseHandler SAD_ms;
	sf::Event SAD_event;
	std::shared_ptr<Window> SAD_window;
	std::shared_ptr<AssetManager> SAD_assetManager;
	FileManager m_FM;
	
};