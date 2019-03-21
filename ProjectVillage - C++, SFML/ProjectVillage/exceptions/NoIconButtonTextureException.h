#pragma once
#include <exception>

class NoIconButtonTextureException : public std::exception {
public:
	NoIconButtonTextureException() = default;
	char const* what() const
	{
		return "Texture not found";
	}
};