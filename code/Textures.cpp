#include "Textures.h"
#include <assert.h>
using namespace std;
using namespace sf;

TextureHolder* TextureHolder::m_s_instance = nullptr;
TextureHolder::TextureHolder()
{
	assert(m_s_instance == nullptr);
	m_s_instance = this;
}
Texture& TextureHolder::GetTexture(string const& filename)
{
	auto& m = m_s_instance->m_textures;
	auto KeyValuePair = m.find(filename);
	if (KeyValuePair != m.end())
	{
		return KeyValuePair->second;
	}
	else
	{
		auto& texture = m[filename];
		texture.loadFromFile(filename);
		return texture;
	}

}