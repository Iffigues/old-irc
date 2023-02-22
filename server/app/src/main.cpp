#include "Param.cpp"
#include "Hosting.cpp"

# include <iostream>

int start(int argc, char *argv[]) {
    bool t;
    t = false;
    Param *e;

    if (argc != 4 && argc != 3)
        return 1;
    argv++;
    if (argc == 4) {
        Hosting *g = new Hosting(argv[0]);
        e = new Param(g, argv[1], argv[2]);
    } else {
        e = new Param(argv[0], argv[1]);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return start(argc, argv);
}
