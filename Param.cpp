#include "Param.hpp"
#include <stdio.h>

#include "Hosting.hpp"

const char* Param::Errors::what() const throw()
{
	return "password must have 1 character minimum";
}

const char* Param::PorsErrors::what() const throw()
{
	return "password must have 1 character minimum";
}

bool Param::isPort(std::string const &port) {
    return true;
}

bool Param::addHost(std::string const &port) {
    return true;
}

Param::Param(Hosting const *host, std::string const &port, std::string const &password) : port(port), password(password), handle(false)
{
    if (this->password.length() < 1)
        throw Param::Errors();
    if (!this->isPort(port))
        throw Param::PorsErrors();
    this->Host = host;
}

Param::Param(std::string const &port, std::string const &password) : port(port), password(password), handle(false)
{
    if (this->password.length() < 1)
        throw Param::Errors();
    if (!this->isPort(port))
        throw Param::PorsErrors();
    
}

Param::~Param()
{
}

Param &Param::operator=(Param const &cpy)
{
	(void)cpy;
	return *this;
}

Param::Param(Param const &cpy) : port(cpy.port), password(cpy.password), handle(cpy.handle)
{
}

