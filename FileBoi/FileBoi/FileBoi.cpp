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
	m_gui = std::make_unique<GUI>(sf::Rect<float>(100.0f, 100.0f, 400.0f, 400.0f), this->m_data);

	//-- Testing
}

void FileBoi::Go()
{
	while (this->m_data->SAD_window->GetWindow()->isOpen())
	{
		this->m_deltaTime = this->m_clock.restart().asSeconds();
		while (this->m_data->SAD_window->GetWindow()->pollEvent(this->m_data->SAD_event))
		{
			HandleEvents(this->m_data->SAD_event);
		}

		this->Prepare(this->m_deltaTime);
		this->Process(this->m_deltaTime);
		this->Present(this->m_deltaTime);
	}
}

void FileBoi::HandleEvents(sf::Event EVENT)
{
	switch (EVENT.type)
	{
	case sf::Event::Closed :
	{
		this->m_data->SAD_window->GetWindow()->close();
		break;
	}
	case sf::Event::MouseButtonPressed :
	{
		if (EVENT.mouseButton.button == sf::Mouse::Left)
		{
			if (!this->m_data->SAD_ms.GetClicked(sf::Mouse::Left))
			{
				this->m_data->SAD_ms.Clicked(sf::Mouse::Left);
			}
			//std::cout << "left mouse pressed \n";
		}
		break;
	}
	case sf::Event::MouseButtonReleased :
	{
		if (EVENT.mouseButton.button == sf::Mouse::Left)
		{
			if (this->m_data->SAD_ms.GetClicked(sf::Mouse::Left))
			{
				this->m_data->SAD_ms.Released(sf::Mouse::Left);
			}
			//std::cout << "left mouse released \n";
		}
		break;
	}
	default:
	{
		break;
	}
	}
}

void FileBoi::Prepare(const float &deltatime)
{
	this->m_data->SAD_window->GetWindow()->clear(sf::Color::White);
}

void FileBoi::Process(const float &deltatime)
{
	m_gui->Update();
	m_data->m_net.Update();
}

void FileBoi::Present(const float &deltatime)
{
	m_gui->Draw();
	this->m_data->SAD_window->GetWindow()->display();
}