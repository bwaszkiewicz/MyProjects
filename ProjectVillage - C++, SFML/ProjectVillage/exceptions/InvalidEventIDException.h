#pragma once
#include <exception>

class InvalidEventIDException : public std::exception {
public:
	InvalidEventIDException() = default;
	char const* what() const
	{
		return "No found event ID";
	}
};