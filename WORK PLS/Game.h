
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "GameProgress.h"
#include "Textures.h"
#include <string>


class Game
{
public:
	Game();
	void start();
    sf::Text text1,text2;
    sf::Font font1;
    
    sf::Texture heartpls;
    sf::Sprite heart;
   
private:

	sf::RenderWindow window;
	sf::Texture texture;
	sf::Image image, icon;
	sf::Texture pic;
	sf::Music music;
	Textures textures;
	GameProgress game;

	void Events();
	void render(Sprite);
};
