#pragma once
#include <exception>

class InvalidUnitTypeException : public std::exception {
public:
	InvalidUnitTypeException() = default;
	char const* what() const
	{
		return "Unit type not found";
	}
};