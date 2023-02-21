#include "Tintin_reporter.hpp"

Tintin_reporter::Tintin_reporter() : lock("/var/lock/matt_daemon.lock"), log("/var/log/matt_daemon") 
{
	if (getuid() != 0)
	{
		this->write(1, "no root user");

		exit(1);
	}
	
	struct stat info;
	
	if( stat(this->log.c_str(), &info ) != 0 ) {
		if (mkdir(this->log.c_str(), 0777)  < 0)
		{
			this->write(1, "can't create directory /var/log/matt_daemon");
			exit(1);
		}
	} else if(!(info.st_mode & S_IFDIR)) {	
		this->write(1, "/var/log/matt_daemon exist but is not dir");
		exit(1);
	}
	std::string e = this->fileDate();
	this->date = e;
	this->file.rdbuf()->pubsetbuf(0, 0);
	this->file.open("/var/log/matt_daemon/matt_daemon-"+e+".log", std::ofstream::out | std::ofstream::ate | std::ofstream::app);
}

Tintin_reporter::~Tintin_reporter()
{
	this->file.close();
	flock(this->fd, LOCK_UN);
}

void Tintin_reporter::finish(void)
{
	this->file << "finish";
	this->file.close();
	unlink("/var/lock/matt_daemon.lock");
	close(this->fd);
}

void Tintin_reporter::write(int i, std::string str)
{
	std::string e = this->fileDate();
	if (!this->date.compare(e))
	{
		this->file.close();
		this->file.clear();
		this->file.rdbuf()->pubsetbuf(0, 0);
		this->file.open("/var/log/matt_daemon/matt_daemon-"+e+".log", std::ofstream::out | std::ofstream::ate | std::ofstream::app);
	}
	const char *t[3] = { "\x1B[32mINFO\033[0m", "\x1B[31mERROR\033[0m", "\x1B[33mLOG\033[0m"};
	this->file << this->times() << " [ " << t[i]  << " ] - Matt_daemon: "<< str << std::endl;
}

void Tintin_reporter::opens()
{
	std::string e = this->fileDate();
	this->file.close();
		this->file.clear();
		this->file.rdbuf()->pubsetbuf(0, 0);
		this->file.open("/var/log/matt_daemon/matt_daemon-"+e+".log", std::ofstream::out | std::ofstream::ate | std::ofstream::app);
	if ((this->fd = open("/var/lock/matt_daemon.lock", O_RDWR|O_CREAT, 0640)) < 0)
	{
		std::cout << "can't open file lock" << std::endl; 
		this->file.close();
		this->write(1, "lock is close");
		exit(1);
	}
	if (lockf(this->fd, F_TLOCK, 0)  < 0)
	{
		std::cout << "file lock is lock" << std::endl;
		this->write(1, "lock is close");
		this->file.close();
		exit(1);
	}
}

Tintin_reporter &Tintin_reporter::operator=(Tintin_reporter const &cpy)
{
	return *this;
}

Tintin_reporter::Tintin_reporter(Tintin_reporter const &cpy)
{
}


std::string Tintin_reporter::times()
{
	std::string l = "[";
	time_t now = time(0);
	tm *g = gmtime(&now);
	l = l + std::to_string(g->tm_mday) + "/" + std::to_string(g->tm_mon + 1) + "/" + std::to_string(g->tm_year + 1900) + "-" + std::to_string(g->tm_hour) + ":" + std::to_string(g->tm_min) + ":" + std::to_string(g->tm_sec) ;
	return l + "]";
}

std::string Tintin_reporter::fileDate()
{
		std::string l = "";
	time_t now = time(0);
	tm *g = gmtime(&now);
	l =  std::to_string(g->tm_mday) + "-" + std::to_string(g->tm_mon + 1) + "-" + std::to_string(g->tm_year + 1900);;
	return l;
}
