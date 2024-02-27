#include "Player.h"
#include "ResourcePath.hpp"
Player::Player(Textures* texture, int Size) :
	texture(texture),
	TileSize(Size)
{
	s.setTexture(texture->get("Down"));// Starting Position
	s.setScale(2.0, 2.0); // double size
	s.setTextureRect(IntRect(32,0,32,32));
	current = 3; // start with down
}

void Player::move(int newD) // Update player's movement
{
	current = newD;
	string Dir;
	switch (newD) // New movement
	{
	case 0:
		Dir = "Left";
		s.setTextureRect(IntRect(0, 32, 32, 32));
		s.move(-TileSize, 0);
		break;
	case 1:
		Dir = "Right";
		s.setTextureRect(IntRect(0, 64, 32, 32));
		s.move(TileSize, 0);
		break;
	case 2:
		Dir = "Up";
		s.setTextureRect(IntRect(0, 96, 32, 32));
		s.move(0, -TileSize);
		break;
	
	case 3:
		Dir = "Down";
	    s.setTextureRect(IntRect(0, 0, 32, 32));
		s.move(0, TileSize);
		break;
	}
	s.setTexture(texture->get(Dir));// draw texture on player
	s.setScale(2.0, 2.0); //double player size
	
}

void Player::undo() // when collision happens 
{
	string textureNameToSet;
    music1.openFromFile(resourcePath()+"collision.ogg");
    music1.play();
	switch (current)
	{
	case 0:
		s.setTextureRect(IntRect(64, 32, 32, 32)); // sprite before collision 
		s.move(TileSize, 0);
		s.setTextureRect(IntRect(32, 32, 32, 32)); // sprite after collision
		break;
	case 1:
		s.setTextureRect(IntRect(64, 64, 32, 32));
		s.move(-TileSize, 0);
		s.setTextureRect(IntRect(32, 64, 32, 32));
		break;
	case 2:
		s.setTextureRect(IntRect(64, 96, 32, 32));
		s.move(0, TileSize);
		s.setTextureRect(IntRect(32, 96, 32, 32));
		break;
	case 3:
		s.setTextureRect(IntRect(64, 0, 32, 32));
		s.move(0, -TileSize);
		s.setTextureRect(IntRect(32, 0, 32, 32));
		break;
	}
}
