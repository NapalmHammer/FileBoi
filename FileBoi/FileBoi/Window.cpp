#include "Window.h"

Window::Window()
	:FPS(60)
{
	this->Init();
}

void Window::Init()
{
	this->m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(900, 600), "FileBoi!");

	sf::Image img;
	img.loadFromFile("fileboiicon.bmp");
	this->m_window->setIcon(img.getSize().x, img.getSize().y, img.getPixelsPtr());
	this->m_window->setFramerateLimit(FPS);

}

std::shared_ptr<sf::RenderWindow> Window::GetWindow()
{
	return m_window;
}

void Window::Draw(sf::Drawable & img)
{
	m_window->draw(img);
}
