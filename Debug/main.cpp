#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

int main()
{
	
	setlocale(LC_ALL, "rus");
	
	
	Texture level01;
	level01.loadFromFile("poormap.png");

	Sprite level1;
	level1.setTexture(level01);
	level1.setPosition(0, 0);

	Texture playertexture;
	playertexture.loadFromFile("person.png");

	Sprite player(playertexture);
	player.setPosition(100, 100);

	Texture level02;
	level02.loadFromFile("1.png");

    Sprite level2;
	level2.setTexture(level02);
	level2.setPosition(1000, 1000);

	Texture emmytex;
	emmytex.loadFromFile("emmy.png");

	Sprite emmy(emmytex);
	emmy.setPosition(1000, 1000);

	Texture devtex;
	devtex.loadFromFile("dev.png");

	Sprite dev(devtex);
	dev.setPosition(1000, 1000);

	Texture level03;
	level03.loadFromFile("l3.png");

	Sprite level3;
	level3.setTexture(level03);
	level3.setPosition(1000, 1000);

	Texture house1tex;
	house1tex.loadFromFile("house1.png");

	Sprite house1(house1tex);
	house1.setPosition(1000, 1000);





	

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
			player.setRotation(2);
		
			
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			player.move(0, -0.3);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			player.move(0, 0.3);
		}
		if (Keyboard::isKeyPressed(Keyboard::Num2))
		{
			

			level1.setPosition(1000, 1000);
			level2.setPosition(0,0);
			emmy.setPosition(520, 450);
			level3.setPosition(1000, 1000);
			dev.setPosition(1000, 1000);
			house1.setPosition(180, 520);
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			dev.setPosition(0, 0);
			level1.setPosition(1000, 1000);
			level3.setPosition(1000, 1000);
			level2.setPosition(1000, 1000);
			emmy.setPosition(1000, 1000);
			house1.setPosition(1000, 1000);
		}
		if (Keyboard::isKeyPressed(Keyboard::Num3))
		{
			level1.setPosition(1000, 1000);
			level3.setPosition(0, 0);
			emmy.setPosition(1000, 1000);
			level2.setPosition(1000, 1000);
			dev.setPosition(1000, 1000);
			house1.setPosition(1000, 1000);
		}
		if (Keyboard::isKeyPressed(Keyboard::Num1))
		{
			level1.setPosition(0, 0);
			level3.setPosition(1000, 1000);
			emmy.setPosition(1000, 1000);
			level2.setPosition(1000, 1000);
			dev.setPosition(1000, 1000);
			house1.setPosition(1000, 1000);
		}
		FloatRect shape1 = player.getGlobalBounds();
		FloatRect shape2 = emmy.getGlobalBounds();
		
		if (player.getPosition().x < emmy.getPosition().x + shape2.width &&
			player.getPosition().x + shape1.width > emmy.getPosition().x &&
			player.getPosition().y < emmy.getPosition().y + shape2.height &&
			shape1.height + player.getPosition().y > emmy.getPosition().y)
		{
			std::cout << "Quest Character Detected" << std::endl;
		}
		else
		{
			
		}

		

		window.clear();
		window.draw(level1);
		window.draw(level2);
		window.draw(emmy);
		window.draw(dev);
		window.draw(level3);
		window.draw(house1);
		window.draw(player);
		window.display();
	}

	return 0;
} 