#include "FileBoi.h"

FileBoi::FileBoi()
{
	this->Init();
}

void FileBoi::Init()
{
	this->m_window = std::make_shared<Window>();
	this->m_deltaTime = 0.0f;
	this->m_FPS = 60.0f;

	this->m_assetManager = std::make_shared<AssetManager>();
	this->m_assetManager->LoadFont("OpenSans-Regular", "OpenSans-Regular.ttf");

	//-- Testing
	shape.setRadius((100.f));
	shape.setFillColor(sf::Color::Green);
}

void FileBoi::Go()
{
	while (this->m_window->GetWindow()->isOpen())
	{
		sf::Event event;
		this->m_deltaTime = this->m_clock.restart().asSeconds();

		while (this->m_window->GetWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->m_window->GetWindow()->close();
		}
		this->Prepare(this->m_deltaTime);
		this->Process(this->m_deltaTime);
		this->Present(this->m_deltaTime);
	}
}

void FileBoi::Prepare(const float &deltatime)
{
	this->m_window->GetWindow()->clear();
}

void FileBoi::Process(const float &deltatime)
{
	this->m_window->Draw(shape);
}

void FileBoi::Present(const float &deltatime)
{
	this->m_window->GetWindow()->display();
}
