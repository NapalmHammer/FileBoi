#include "SearchBox.h"

SearchBox::SearchBox(sf::Rect<float> R, std::shared_ptr<ShareableApplicationData>& D)
	:FileBoiWidget(R, D)
{
	m_tl = std::make_unique<TextLine>(sf::Rect<float>(R.left + R.width * 0.20f, R.top + R.height * 0.03f, R.width * 0.78f, R.height * 0.94f), D);
	m_btn = std::make_unique<Button>(sf::Rect<float>(R.left + R.width * 0.03f, R.top + R.height * 0.03f, R.width * 0.15f, R.height * 0.94f), D);
}

void SearchBox::Update(std::shared_ptr<ShareableApplicationData>& D)
{
	FileBoiWidget::Update(D);
	m_btn->Update(D);
	m_tl->Update(D);
}

void SearchBox::Draw(std::shared_ptr<Window>& W)
{
	W->Draw(m_rect);
	m_btn->Draw(W);
	m_tl->Draw(W);
}
