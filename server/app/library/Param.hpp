#ifndef __Param_H__
#define __Param_H__

# include <iostream>
#include "Constante.hpp"
#include <vector>

#include "Hosting.hpp"

class Param
{

private:
    Param();
    std::string const &port;
    std::string const &password;
    std::vector<Hosting*> Host;
    bool isPort(std::string const &port);
    bool addHost(std::string const &str);
protected:

public:
    	Param(std::vector<Hosting*> Host, std::string const &port, std::string const &password);
	Param(Param const &cpy);
	Param &operator=(Param const &cpy);
	std::string const &getPort() const;
	std::string const &getPassword() const;

	class Errors : public std::exception
	{
        	virtual const char* what() const throw();
    };

	class PorsErrors : public std::exception
	{
        	virtual const char* what() const throw();
    };
	virtual ~Param();
};
#endif

