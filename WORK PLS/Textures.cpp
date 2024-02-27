#include "Textures.h"
#include "ResourcePath.hpp"
bool Textures::addTexture(string name,string file) // adds the textures to a vector
{
	Texture tmpTxtur;
    if (!tmpTxtur.loadFromFile(resourcePath() + file)) {
        return EXIT_FAILURE;
    }
	textures[name] = tmpTxtur;
	mytxts.push_back(file);
	return true;
}

Texture &Textures::get(string name) // returns texture name from the map
{
		return textures[name];
}

void Textures::loadTextures() // adds all textures needed
{
    addTexture("wall", "Wall_Beige.png");
    addTexture("crate", "CrateDark_Brown.png");
    addTexture("finalCrate", "CrateDark_Gray.png");
    addTexture("finishPoint", "finishPoint.png");
    addTexture("ground", "GroundGravel_Dirt.png");
    addTexture("Left", "spriteWalk.png");
    addTexture("Right", "spriteWalk.png");
    addTexture("Up", "spriteWalk.png");
    addTexture("Down", "spriteWalk.png");
    addTexture("none", "wood1.jpg");
    addTexture("none2", "water2.png");
    addTexture("none3", "chessboard.png");
    addTexture("none4", "roof.png");
    addTexture("none5", "sand2.jpg");
    addTexture("none6", "grass.jpg");
    addTexture("none7", "wood2.png");
    addTexture("none8", "water2.png");
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
	
}
