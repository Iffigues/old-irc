#include "../library/Param.hpp"
#include "../library/Hosting.hpp"
#include "../library/ParamBuilder.hpp"

# include <iostream>

int start(int argc, char *argv[]) {
    bool t;
    t = false;
    Param *e;

    if (argc != 4 && argc != 3)
        return 1;
    argv++;
    e = ParamBuilder::build(argv, (argc - 1));
    return 0;
}

int main(int argc, char *argv[]) {
    return start(argc, argv);
}
