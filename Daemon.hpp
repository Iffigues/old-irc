#ifndef DAEMON_HPP
# define DAEMON_HPP
#include <csignal>

#include <dirent.h>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sys/stat.h>
#include <syslog.h>
#include <unistd.h>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include "Tintin_reporter.hpp"
#include "Server.hpp"

int foo(int i);

class Daemon
{
private:
	Daemon();
	Tintin_reporter &t;
	pid_t pid;
	pid_t sid;

protected:

public:
	Daemon(Tintin_reporter &t);
	Daemon(Daemon const &cpy);
	Daemon &operator=(Daemon const &cpy);
	virtual ~Daemon();
};

#endif
