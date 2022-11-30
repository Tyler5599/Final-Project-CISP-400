#pragma once
#ifndef TEXTURES_H
#define TEXTURES_H
#include <SFML/Graphics.hpp>
#include <map>
using namespace std;
using namespace sf;

class TextureHolder
{
private:
	map<string, Texture> m_textures;
	static TextureHolder* m_s_instance;
public:
	TextureHolder();
	static Texture& GetTexture(string const& filename);
};
#endif