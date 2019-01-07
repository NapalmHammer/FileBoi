#include "FileBoi.h"

FileBoi::FileBoi()
{
	this->Init();
}

void FileBoi::Init()
{
	this->m_data = std::make_shared<ShareableApplicationData>();
	this->m_data->SAD_window = std::make_shared<Window>();
	this->m_data->SAD_assetManager = std::make_shared<AssetManager>();

	this->m_deltaTime = 0.0f;
	this->m_FPS = 60.0f;

	this->m_data->SAD_assetManager->LoadFont("OpenSans-Regular", "OpenSans-Regular.ttf");


	//-- Testing
	ConBut = std::make_shared<ConnectButton>(20.0f, 20.0f, 100.0f, 50.0f, sf::Color::Green, this->m_data);
	ConBut->SetFunc(Print);
	shape.setRadius((100.f));
	shape.setFillColor(sf::Color::Green);
}

void FileBoi::Go()
{
	while (this->m_data->SAD_window->GetWindow()->isOpen())
	{
		sf::Event event;
		this->m_deltaTime = this->m_clock.restart().asSeconds();

		while (this->m_data->SAD_window->GetWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->m_data->SAD_window->GetWindow()->close();
		}
		this->Prepare(this->m_deltaTime);
		this->Process(this->m_deltaTime);
		this->Present(this->m_deltaTime);
	}
}

void FileBoi::Prepare(const float &deltatime)
{
	this->m_data->SAD_window->GetWindow()->clear(sf::Color::White);
}

void FileBoi::Process(const float &deltatime)
{
	ConBut->Update();
}

void FileBoi::Present(const float &deltatime)
{
	ConBut->Draw();
	//this->m_window->Draw(shape);
	this->m_data->SAD_window->GetWindow()->display();
}

void Print()
{
	std::cout << "function pointer works" << "\n";
}