#pragma once
//#include "FileBoiWidget.h"
#include "Button.h"
#include "TextLine.h"
#include "FileManager.h"

class InputBox : public Widget
{
public:
	InputBox(sf::Rect<float> R, std::shared_ptr<ShareableApplicationData>& D, std::string BN);
	void Update(std::shared_ptr<ShareableApplicationData>& D) override;
	void Draw(std::shared_ptr<Window>& W) override;
protected:
	std::unique_ptr<TextLine> m_tl;
	std::unique_ptr<Button> m_btn;
	std::unique_ptr<FileManager> m_FM;
};