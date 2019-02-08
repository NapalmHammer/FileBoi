#pragma once
#include <vector>
#include "Button.h"
#include "Console.h"

class GUI
{
public:
	GUI(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD);
	void Update();
	void Draw();
private:
	sf::Rect<float> m_irect;
	std::vector<std::unique_ptr<FileBoiWidget>> m_widgets;
	std::shared_ptr<ShareableApplicationData> m_SAD;

};