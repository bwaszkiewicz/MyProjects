#pragma once
#include <exception>

class InvalidBuildingTypeException : public std::exception {
public:
	InvalidBuildingTypeException() = default;
	char const* what() const
	{
		return "Building type not found";
	}
};