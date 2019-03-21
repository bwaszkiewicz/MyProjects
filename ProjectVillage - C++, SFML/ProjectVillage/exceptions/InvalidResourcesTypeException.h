#pragma once
#include <exception>

class InvalidResourcesTypeException : public std::exception {
public:
	InvalidResourcesTypeException() = default;
	char const* what() const
	{
		return "Resources type not found";
	}
};