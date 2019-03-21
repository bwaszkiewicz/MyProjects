#pragma once
#include <exception>

class NoTextButtonFontException : public std::exception {
public:
	NoTextButtonFontException() = default;
	char const* what() const
	{
		return "Font not found";
	}
};