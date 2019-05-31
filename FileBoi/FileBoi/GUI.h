#pragma once
#include <vector>
#include "FileBoiButtons.h"
#include "FileBoiInputBox.h"
#include "Console.h"

class GUI
{
public:
	GUI(sf::Rect<float> rect, std::shared_ptr<ShareableApplicationData>& SAD);
	void Update(std::shared_ptr<ShareableApplicationData>& D);
	void Draw(std::shared_ptr<Window>& W);
private:
	sf::Rect<float> m_irect;
	std::vector<std::unique_ptr<Widget>> m_widgets;
	std::shared_ptr<ShareableApplicationData> m_SAD;
};