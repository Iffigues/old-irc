# ifndef TINTIN_REPORTER_HPP
# define TINTIN_REPORTER_HPP

# include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fstream>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <net/if.h>
#include <mutex>          // std::mutex
#include <ctime>

using namespace std;


class Tintin_reporter
{
private:
	int type;
	std::string lock;
	std::string log;
	int fd;
	ofstream file;
	std::string date; 
protected:

public:
	Tintin_reporter();
	Tintin_reporter(Tintin_reporter const &cpy);
	Tintin_reporter &operator=(Tintin_reporter const &cpy);
	virtual ~Tintin_reporter();
	void finish(void);
	void write(int i, std::string l);
	void opens(void);
	std::string times();
	std::string fileDate();
	class exc: public std::exception {
		virtual const char* what() const throw() {
			return  "error";
		};
	};
};

#endif
