#pragma once
#include <exception>

class NoTextInputFontException : public std::exception {
public:
	NoTextInputFontException() = default;
	char const* what() const
	{
		return "Can't load font";
	}
};