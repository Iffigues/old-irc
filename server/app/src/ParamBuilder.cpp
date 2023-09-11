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

	if (i == 3) {
		Hosting *host = new Hosting(b[1]);
	} 
	if (i == 2) {
	}
	return bb;
}
