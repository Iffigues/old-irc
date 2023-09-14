#ifndef __ParamBuilder_H__
#define __ParamBuilder_H__

#include "Param.hpp"
 
class ParamBuilder
{
private:
        
protected:

public:
	ParamBuilder();
	ParamBuilder(ParamBuilder const &cpy);
	ParamBuilder &operator=(ParamBuilder const &cpy);
	virtual ~ParamBuilder();
	static Param *build(char **b, int i);	
};
#endif

