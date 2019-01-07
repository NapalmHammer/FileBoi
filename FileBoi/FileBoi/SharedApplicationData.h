#pragma once
#include "Window.h"
#include "AssetManager.h"

struct ShareableApplicationData
{
	std::shared_ptr<Window> SAD_window;
	std::shared_ptr<AssetManager> SAD_assetManager;
};