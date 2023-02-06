#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace hcc
{
	class AssetManager
	{
	public:
		AssetManager() { }
		~AssetManager() { }

		void LoadTexture(std::string name, std::string fileName);
		sf::Texture &GetTexture(std::string name);

		void LoadFont(std::string name, std::string fileName);
		sf::Font &GetFont(std::string name);

	private:
		std::map<std::string, sf::Texture> m_Textures;
		std::map<std::string, sf::Font> m_Fonts;
	};
}
