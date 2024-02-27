#pragma once
#include "Textures.h"
using namespace sf;
using namespace std;

class Player : public sf::Drawable
{
public:
	Player(Textures*, int);
    
	void move(int);
	void undo();
	void setPos( Vector2i position) {s.setPosition(position.x * TileSize, position.y * TileSize);}
	Vector2i getPos() {return sf::Vector2i(s.getPosition().x / TileSize, s.getPosition().y / TileSize);}
	int getCurr() {
		return current;
	}
private:
	const int TileSize;
	Sprite s;
	Textures* texture;
    Music music1;
	int current;

	void draw(RenderTarget& target, RenderStates states)const{ // draw player
		target.draw(s);
	}
};
