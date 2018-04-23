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

	Texture playertexture;
	playertexture.loadFromFile("pizza.png");

	Sprite player(playertexture);
	player.setPosition(100, 100);


	

	sf::RenderWindow window(sf::VideoMode(800, 800), "PoorJump");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			player.move(-0.3, 0);
			player.setRotation(-1);

		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			player.move(0.3, 0);
			player.setRotation(1);
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			player.move(0, -0.3);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			player.move(0, 0.3);
		}

		window.clear();
		window.draw(sloi1);
		window.draw(level);
		window.draw(player);
		window.display();
	}

	return 0;
}