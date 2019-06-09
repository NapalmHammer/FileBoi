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
	this->m_data->SAD_assetManager->LoadFont("OpenSans-Regular", "OpenSans-Regular.ttf");
	this->m_data->m_net.Init(&this->m_data->m_log);
	this->m_data->m_FM.Init(&this->m_data->m_log);

	this->m_deltaTime = 0.0f;
	this->m_FPS = 60.0f;

	m_gui = std::make_unique<GUI>(sf::Rect<float>(10.0f, 10.0f, 150.0f, 150.0f), this->m_data);

	//-- Testing

	//Flushing key history: TODO: Make dedicated FLUSH function
	m_data->SAD_kbd.FlushKey();
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
	case sf::Event::KeyPressed :
	{
		//std::cout << "system:" << EVENT.key.code << std::endl;
		if (EVENT.key.code == sf::Keyboard::Escape)
		{
			std::cout << "the escape key was pressed" << std::endl;
			std::cout << "control:" << EVENT.key.control << std::endl;
			std::cout << "alt:" << EVENT.key.alt << std::endl;
			std::cout << "shift:" << EVENT.key.shift << std::endl;
			std::cout << "system:" << EVENT.key.system << std::endl;
			this->m_data->SAD_window->GetWindow()->close();
		}
		break;
	}
	case sf::Event::TextEntered :
	{
		auto t = EVENT.text.unicode;
		//std::cout << "key " << t << " was released. \n";
		m_data->SAD_kbd.AddKey(t);
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
	this->m_data->SAD_window->GetWindow()->clear(sf::Color(100,100,100,255));
}

void FileBoi::Process(const float &deltatime)
{
	m_gui->Update(this->m_data);
	m_data->m_net.Update();
	m_data->SAD_kbd.FlushKey();
	m_data->SAD_ms.Released(sf::Mouse::Button::Left);
}

void FileBoi::Present(const float &deltatime)
{
	m_gui->Draw(this->m_data->SAD_window);
	this->m_data->SAD_window->GetWindow()->display();
}