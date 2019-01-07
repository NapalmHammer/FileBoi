#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Window
{
public:
	Window();
	void Init();
	std::shared_ptr<sf::RenderWindow> GetWindow();
	void Draw(sf::Drawable &img);
private:
	// To do - Add functionality to window, like resizing+
	std::shared_ptr<sf::RenderWindow> m_window;
	const int FPS;
};