#include "../library/Param.hpp"
#include "../library/ParamBuilder.hpp"
#include "../library/Hosting.hpp"

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
	Hosting *host = NULL;

	if (i == 3)
		host = new Hosting(b[0]);
	return new Param(host, b[1], b[2], host != NULL);
}
