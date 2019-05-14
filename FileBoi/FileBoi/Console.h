#pragma once
#include "SharedApplicationData.h"
#include "FileBoiWidget.h"
#include <iostream>


class Console: public FileBoiWidget
{
public:
	Console(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD);
	void OnPress() override;
	void Update(std::shared_ptr<ShareableApplicationData>& SAD) override;
	//sf::String GetString();
private:
	bool m_active = false;
};
