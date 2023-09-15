#include "../library/Hosting.hpp"

#include <iostream>
#include <vector>
#include <string>  

Hosting::Hosting(std::string const &str)
{
    int i = 0;
    std::string input = str;
    std::vector<std::string> result;
    
    size_t pos = 0;
    std::string token;
    while ((pos = input.find(":")) != std::string::npos) {
        token = input.substr(0, pos);
        result.push_back(token);
        input.erase(0, pos + 1);
    }
    result.push_back(input);

    for (std::vector<std::string>::iterator it = result.begin(); it != result.end(); ++it) {
        if (i == 0)
            this->host = *it;
        if (i == 1)
            this->port = *it;
        if (i == 2)
            this->password = *it;
	i++;
    }
	std::cout << "The value of myVariable is: " << this->password << std::endl;

}

Hosting::~Hosting()
{
}

Hosting &Hosting::operator=(Hosting const &cpy)
{
	(void)cpy;
	return *this;
}

Hosting::Hosting(Hosting const &cpy)
{
}

std::string const &Hosting::getHost() const
{
	return this->host;
}

std::string const &Hosting::getPort() const
{
	return this->port;
}

std::string const &Hosting::getPassword() const
{
	return this->password;
}
