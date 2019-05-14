#pragma once
//#include "FileBoiWidget.h"
#include "Button.h"
#include "TextLine.h"

class SearchBox : public FileBoiWidget
{
public:
	SearchBox(sf::Rect<float> R, std::shared_ptr<ShareableApplicationData>& D);
	void Update(std::shared_ptr<ShareableApplicationData>& D) override;
	void Draw(std::shared_ptr<Window>& W) override;
private:
	std::unique_ptr<TextLine> m_tl;
	std::unique_ptr<Button> m_btn;
};