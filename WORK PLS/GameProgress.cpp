#include "GameProgress.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

GameProgress::GameProgress(Textures* texture) :
	texture(texture),player(texture, Tile::Size)
{

}

void GameProgress::init() // Level 1
{
	NextLevel(to_string(lvl));
}
void GameProgress::update(Event event) // change between levels
{
	if (processEvents(event)) // for every movement
	{
		check();
		if (win()) // if the level is finsihed - move to the next level
		{
			tiles.clear();
		
			lvl += lvl;
			NextLevel(to_string(lvl));
		}
	}
}
void GameProgress::reset()
{
    
    tiles.clear();
    NextLevel(to_string(lvl));
    
}
void GameProgress:: skip()
{
    tiles.clear();
    lvl++;
    NextLevel(to_string(lvl));
}

void GameProgress::loadLevel(string & name)
{
	ifstream file(name);

	int x, y;
	file >> x >> y;
	player.setPos(sf::Vector2i(x, y));

	sf::Vector2i load;
	while (!file.eof())
	{
		int tileType;
		file >> tileType;
        cout<<tileType;
		tiles[load.x][load.y] = Tile(tileType, load);
        

		load.x++;
		if (file.peek() == '\n')
		{
			load.x = 0;
			load.y++;
		}
	}
}

void GameProgress::NextLevel(string lvl)
{
	
	string level = "/Users/ahmedibrahim/Desktop/levels/lvl"+lvl+".txt";
 
	loadLevel(level);
}

bool GameProgress::processEvents(Event event)
{
	if (event.type == Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case Keyboard::Left:
			player.move(0);
			return true;
		case Keyboard::Right:
			player.move(1);
			return true;
		case Keyboard::Up:
			player.move(2);
			return true;
		case Keyboard::Down:
			player.move(3);
			return true;
                default:
                return false;
		}
	}
	return false;
}

void GameProgress::check()
{
	Tile *Plyrtile= &tiles[player.getPos().x][player.getPos().y]; // position of player
	if (Plyrtile->getType() == 1) // when player collides with wall
		player.undo();

	

	if(player.getCurr() == 0) // point to the next tile based on movement to compare with the previous
		nextTile = &tiles[Plyrtile->Pos().x - 1][Plyrtile->Pos().y];
	else if(player.getCurr() == 1)
		nextTile = &tiles[Plyrtile->Pos().x + 1][Plyrtile->Pos().y];
	else if (player.getCurr() == 2)
		nextTile = &tiles[Plyrtile->Pos().x][Plyrtile->Pos().y - 1];
	else
		nextTile = &tiles[Plyrtile->Pos().x][Plyrtile->Pos().y + 1];

	if (Plyrtile->getType() == 2) //  player collides with a crate
	{
		if (nextTile->getType() == 0) // moves create on ground
		{
			Plyrtile->setType(0);
			nextTile->setType(2);
		}
		else if (nextTile->getType() == 3) // puts create on finish
		{
			Plyrtile->setType(0);
			nextTile->setType(4);
		}
		else
			player.undo();// do not move player due to collision
	}
	else if (Plyrtile->getType() == 4)
	{
		if (nextTile->getType() == 0) // moves create outside of finish
		{
			Plyrtile->setType(3);
			nextTile->setType(2);
		}
		else if (nextTile->getType() == 3) //moves crate even when on finish
		{
			Plyrtile->setType(3);
			nextTile->setType(4);
		}
		else
			player.undo(); // do not move player due to collision
	}
}

bool GameProgress::win()// check if all points are finished
{
	for (auto column : tiles)
	{
		for (auto tile : column.second)
		{
			if (tile.second.getType() == 3)
				return false;
		}
	}
	return true;
}
void GameProgress::draw(sf::RenderTarget & target, sf::RenderStates states) const // changes from abstract to drawable
{
	for (auto column : tiles)
	{
		for (auto tile : column.second)
		{
			target.draw(tile.second); // draw tiles
		}
	} //iteration through std::map of std::map
	target.draw(player); // draw player
}
