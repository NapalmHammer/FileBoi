#include "SearchBox.h"

SearchBox::SearchBox(sf::Rect<float> R, std::shared_ptr<ShareableApplicationData>& D)
	:FileBoiWidget(R, D)
{
	m_tl = std::make_unique<TextLine>(sf::Rect<float>(R.left + 100.0f, R.top + 20.0f, R.width - 120.0f, R.height - 40.0f), D);
	m_btn = std::make_unique<Button>(sf::Rect<float>(R.left + 10.0f, R.top + 20.0f, R.width - 330.0f, R.height - 40.0f), D);
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
