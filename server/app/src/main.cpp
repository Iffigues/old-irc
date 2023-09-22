#include "../library/Param.hpp"
#include "../library/Hosting.hpp"
#include "../library/ParamBuilder.hpp"
#include "../library/Serve.hpp"

# include <iostream>
#include <string>


int start(int argc, char *argv[]) {
	bool t;
	t = false;
	Param *e;

	if (argc != 4 && argc != 3)
        	return 1;
	argv++;
	e = ParamBuilder::build(argv, (argc - 1));

	Serve* serve = Serve::GetInstance(std::stoi(e->getPort()), e->getPassword());
	Serve::ReleaseInstance();
	 
	return 0;
}

int main(int argc, char *argv[]) {
	return start(argc, argv);
}
