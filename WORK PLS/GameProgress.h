#pragma once

#include <string>
#include <fstream>
#include <map>
#include <SFML/Graphics.hpp>
#include "Textures.h"
#include "Tile.h"
#include "Player.h"
using namespace std;
using namespace sf;
class GameProgress : public sf::Drawable //declare class as drawable to change from abstract
{
public:
	GameProgress(Textures*);

	void init();
	void update(Event);
        int lvl = 1;
    void reset();
    void skip();
private:
	Textures *texture;
	Tile *nextTile = nullptr;
    Player player;

	map<unsigned int, map<int, Tile>> tiles;
	

	void loadLevel(string&);
	bool processEvents(Event);
	void check();
	bool win();
	void NextLevel(string);
	void draw(RenderTarget&, RenderStates) const;
};
