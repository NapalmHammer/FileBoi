#pragma once
#include "SharedApplicationData.h"
#include "Button.h"


class Console: public Button
{
public:
	Console(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD);
	void Update() override;
	sf::String GetString();
};

