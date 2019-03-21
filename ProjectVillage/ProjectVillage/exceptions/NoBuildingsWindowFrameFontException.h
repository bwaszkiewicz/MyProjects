#pragma once
#include <exception>

class NoBuildingsWindowFrameException : public std::exception {
public:
	NoBuildingsWindowFrameException() = default;
	char const* what() const
	{
		return "Can't load font";
	}
};