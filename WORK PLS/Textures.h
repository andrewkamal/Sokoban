#pragma once
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class Textures
{
public:
	Textures() {
		loadTextures();
	}
	bool addTexture(string, string);
	Texture& get(string);

private:
	map<string, Texture> textures;
	vector<string> mytxts;

	void loadTextures();
};
