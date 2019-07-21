#pragma once
#include "Widget.h"
#include <iostream>

class Button : public Widget
{
public:
	Button(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD, std::string buttonname = "DEFAULT");
	void Update(std::shared_ptr<ShareableApplicationData>& D) override;
private:
};

