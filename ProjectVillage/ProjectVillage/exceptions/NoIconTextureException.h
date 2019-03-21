#pragma once
#include <exception>

class NoIconTextureException : public std::exception {
public:
	NoIconTextureException() = default;
	char const* what() const
	{
		return "Texture not found";
	}
};