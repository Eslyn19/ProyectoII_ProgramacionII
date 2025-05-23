#include "Excepcion.h"

Xcept::Xcept(const std::string& _msg) : msg(_msg) {}

const char* Xcept::what() const throw() { 
	return msg.c_str(); 
}