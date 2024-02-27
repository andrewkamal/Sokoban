#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourcePath.hpp"
Game::Game() : window(sf::VideoMode(850, 750), "Sokoban", sf::Style::Close |sf::Style::Resize| sf::Style::Titlebar),
game(&textures)
{
	window.setFramerateLimit(60);
	Tile::texture = &textures;
	icon.loadFromFile(resourcePath()+"finishPoint.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	game.init();
	music.openFromFile(resourcePath()+"music.ogg");
	music.play();
	music.setLoop(true);
    music.setVolume(5);
    text1.setFont(font1);
    text1.setCharacterSize(30);
    text1.setFillColor(sf::Color::White);
    text1.setPosition(150, 0);
    text2.setFont(font1);
    text2.setCharacterSize(40);
    text2.setFillColor(sf::Color::Magenta);
    text2.setPosition(600, 0);
    if (!font1.loadFromFile(resourcePath()+"sansation.ttf"))
    {
        EXIT_FAILURE;
    }
    
    if (!heartpls.loadFromFile(resourcePath()+"heart.png"))
    {
       EXIT_FAILURE;
    }
    heart.setPosition(100, 0);
    heart.setTexture(heartpls);
    heart.setScale(0.1, 0.1);
}

void Game::start()
{
	pic.loadFromFile(resourcePath()+"grass.jpg");
	sf::Sprite background(pic);
	while (window.isOpen())
	{
		Events();
		render(background);
	}
	window.close();
}

void Game::Events()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
		if (event.key.code == Keyboard::Escape)
			window.close();
        if(event.key.code== Keyboard::R)
            game.reset();
        if(event.key.code==Keyboard::C)
            game.skip();
			game.update(event);
			
	}
}

void Game::render(Sprite b)
{
	window.clear();
	window.draw(b);
	window.draw(game);
    window.draw(heart);
    text1.setString("Lives left "+to_string(game.lvl));
    text2.setString("Level : "+to_string(game.lvl));
    window.draw(text1);
    window.draw(text2);
	window.display();
}
