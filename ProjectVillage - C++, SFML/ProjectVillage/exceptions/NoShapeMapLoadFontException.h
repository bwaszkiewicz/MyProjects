#pragma once
#include <exception>

class NoShapeMapLoadFontException : public std::exception {
public:
	NoShapeMapLoadFontException() = default;
	char const* what() const
	{
		return "Can't load font";
	}
};