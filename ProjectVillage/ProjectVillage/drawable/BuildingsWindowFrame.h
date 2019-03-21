#pragma once
#include <string>
#include <SFML/Graphics.hpp>

#include "Icon.h"
#include "../data/Data.h"

#include "../exceptions/NoBuildingsWindowFrameFontException.h"

class BuildingsWindowFrame: public sf::Drawable
{
	std::string _iconFilePath;
	std::string _captionContent;
	std::vector<int> _resources;

public:
	BuildingsWindowFrame() = default;
	BuildingsWindowFrame(std::string const iconFilePath, std::string captionContent, const Data & Data);
	~BuildingsWindowFrame() = default;

	void update(const Data & Data);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};