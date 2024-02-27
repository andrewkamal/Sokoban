#pragma once

#include <SFML/Graphics.hpp>
#include "Textures.h"

using namespace sf;

class Tile : public Drawable
{
public:
   	static Textures* texture;// static is used for static duration(the time the program runs only)
	static const int Size;
	Tile(int, const Vector2i&);
	Tile();
	Vector2i Pos() const {return Vector2i(sprite.getPosition().x / Size, sprite.getPosition().y / Size);}
	int getType() const {return type;}
	void setType(int);
private:

	Sprite sprite;
	int type;
	 void draw(RenderTarget& target, RenderStates states) const {
		target.draw(sprite);
	}
};

