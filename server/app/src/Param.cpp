#include "../library/Param.hpp"
#include <stdio.h>

#include "../library/Hosting.hpp"

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

Param::Param(std::vector<Hosting*> host, std::string const &port, std::string const &password) : Host(host), port(port), password(password)
{
    if (this->password.length() < 1)
        throw Param::Errors();
    if (!this->isPort(port))
        throw Param::PorsErrors();
}

std::string const &Param::getPort() const
{
	return this->port;
}

std::string const &Param::getPassword() const
{
	return this->password;
}

Param::~Param()
{
}

Param &Param::operator=(Param const &cpy)
{
	(void)cpy;
	return *this;
}

Param::Param(Param const &cpy) : port(cpy.port), password(cpy.password)
{
}

