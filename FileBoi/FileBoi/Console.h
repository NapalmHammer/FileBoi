#pragma once
#include "SharedApplicationData.h"
#include "FileBoiWidget.h"


class Console: FileBoiWidget
{
public:
	Console(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD);
	void Update() override;
	sf::String GetString();
private:
};
