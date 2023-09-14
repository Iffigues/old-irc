#ifndef __Param_H__
#define __Param_H__

# include <iostream>
#include "Constante.hpp"
#include "Hosting.hpp"

class Param
{

private:
    Param();
    std::string const &port;
    std::string const &password;
    bool  const handle;
    const Hosting *Host;
    bool isPort(std::string const &port);
    bool addHost(std::string const &str);
protected:

public:
    	Param(Hosting const *host, std::string const &port, std::string const &password, bool const handle);
	Param(Param const &cpy);
	Param &operator=(Param const &cpy);

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

