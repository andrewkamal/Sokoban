#include "Tile.h"

Textures* Tile::texture = nullptr;
const int Tile::Size = 62;

Tile::Tile()
{
}
Tile::Tile(int type,const Vector2i& position)
{
	sprite.setPosition(position.x * Size, position.y * Size);
	setType(type);
}
void Tile::setType(int Type) // Use Enum to declare tile type in the map
{
	type = Type;
	switch (Type)
	{
            case 0:
            sprite.setTexture(texture->get("ground"));
            break;
        case 1:
            sprite.setTexture(texture->get("wall"));
            break;
        case 2:
            sprite.setTexture(texture->get("crate"));
            break;
        case 3:
            sprite.setTexture(texture->get("finishPoint"));
            break;
        case 4:
            sprite.setTexture(texture->get("finalCrate"));
            break;
        case 5:
            sprite.setTexture(texture->get("none"));
            break;
        case 6:
            sprite.setTexture(texture->get("none2"));
            break;
        case 7:
            sprite.setTexture(texture->get("none3"));
            break;
        case 8:
            sprite.setTexture(texture->get("none4"));
            break;
        case 9:
            sprite.setTexture(texture->get("none5"));
            break;
        case 10:
            sprite.setTexture(texture->get("none6"));
            break;
        case 11:
            sprite.setTexture(texture->get("none7"));
            break;
        default:
            sprite.setTexture(texture->get("none8"));
            
            
        
            
	
	}
}
