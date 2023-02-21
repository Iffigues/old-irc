
#include "Serve.cpp"

# include <iostream>
#include "Tintin_reporter.cpp"

Tintin_reporter t;

int foo(int i)
{
    t.write(0, "Matt_daemon: Signal handler.");
    t.finish();
    t.write(0, "Matt_daemon: Quitting.");
    return 1;
}

int main(int argc, char *argv[]) {
    Serve* serve = Serve::GetInstance(1,"gfgf");

}
