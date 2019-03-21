#pragma once
#include <exception>

class NoEventBarFontException : public std::exception {
public:
	NoEventBarFontException() = default;
	char const* what() const
	{
		return "Can't load font";
	}
};