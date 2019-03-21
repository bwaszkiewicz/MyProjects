#pragma once
#include <exception>

class InvalidEventTierException : public std::exception {
public:
	InvalidEventTierException() = default;
	char const* what() const
	{
		return "Invalid tier";
	}
};