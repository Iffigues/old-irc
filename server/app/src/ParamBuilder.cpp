#include "../library/Param.hpp"
#include "../library/ParamBuilder.hpp"
#include "../library/Hosting.hpp"
#include <string> 

ParamBuilder::ParamBuilder()
{
}

ParamBuilder::~ParamBuilder()
{
}

ParamBuilder &ParamBuilder::operator=(ParamBuilder const &cpy)
{
	(void)cpy;
	return *this;
}

ParamBuilder::ParamBuilder(ParamBuilder const &cpy)
{
}

Param *ParamBuilder::build(char **b, int i)
{
	std::vector<Hosting*> host;

	if (i == 3) {
		std::string input = b[0];
    		std::vector<std::string> result;

		size_t pos = 0;
		std::string token;

		while ((pos = input.find(";")) != std::string::npos) {
        		token = input.substr(0, pos);
        		result.push_back(token);
        		input.erase(0, pos + 1);
    		}

    		result.push_back(input);
		for (std::vector<std::string>::iterator it = result.begin(); it != result.end(); ++it) {
			host.push_back(new Hosting(*it));
		}
	}

	return new Param(host, b[1], b[2]);
}
