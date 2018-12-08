#include "FileBoi.h"

FileBoi::FileBoi()
{
	this->Init();
}

void FileBoi::Init()
{
	m_window = std::make_shared<Window>();
	shape.setRadius((100.f));
	shape.setFillColor(sf::Color::Green);
}

void FileBoi::Go()
{
	while (this->m_window->GetWindow()->isOpen())
	{
		sf::Event event;
		while (this->m_window->GetWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->m_window->GetWindow()->close();
		}
		this->Prepare();
		this->Process();
		this->Present();
	}
}

void FileBoi::Prepare()
{
	this->m_window->GetWindow()->clear();
}

void FileBoi::Process()
{
	this->m_window->Draw(shape);
}

void FileBoi::Present()
{
	this->m_window->GetWindow()->display();
}
