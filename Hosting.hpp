#ifndef __Hosting_H__
#define __Hosting_H__
 
# include <iostream>

class Hosting
{
private:
    Hosting();
    std::string host;
    std::string port;
    std::string password;

protected:

public:
	Hosting(std::string const &str);
	Hosting(Hosting const &cpy);
	Hosting &operator=(Hosting const &cpy);
	virtual ~Hosting();
	
};
#endif

