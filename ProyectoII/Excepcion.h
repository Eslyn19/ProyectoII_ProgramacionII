#pragma once
#include <string>
#include <exception>

class Xcept : public std::exception{
private:
	std::string msg;
public:
	const char* what() const throw();
	Xcept(const std::string& _msg);
};