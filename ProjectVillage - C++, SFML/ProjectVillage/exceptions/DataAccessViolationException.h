#pragma once
#include <exception>

class DataAccessViolationException : public std::exception {
public:
	DataAccessViolationException() = default;
	char const* what() const
	{
		return "Access violation";
	}
};