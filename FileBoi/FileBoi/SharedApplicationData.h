#pragma once
#include "Window.h"
#include "AssetManager.h"
#include "MouseHandler.h"

struct ShareableApplicationData
{
	MouseHandler SAD_ms;
	sf::Event SAD_event;
	std::shared_ptr<Window> SAD_window;
	std::shared_ptr<AssetManager> SAD_assetManager;
};