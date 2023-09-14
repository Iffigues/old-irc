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
	Param *bb;	
	Hosting *host = NULL;
	bool v = false;

	if (i == 3) {
		host = new Hosting(b[0]);
		v = true;
	}
	bb = new Param(host, b[1], b[2], v);
	return bb;
}
