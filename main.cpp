#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	const int HEIGHT_MAP = 25;//размер карты, высота
	const int WIDTH_MAP = 40; 

	Texture sloi1tex;
	sloi1tex.loadFromFile("sloi.png");

	Sprite sloi1;
	sloi1.setTexture(sloi1tex);
	
	Texture level1;
	level1.loadFromFile("poormap.png");

	Sprite level;
	level.setTexture(level1);

	

	sf::RenderWindow window(sf::VideoMode(800, 800), "PoorJump");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sloi1);
		window.draw(level);
		window.display();
	}

	return 0;
}