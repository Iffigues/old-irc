#include "Daemon.hpp"

void sig_catch(int i)
{
	if (i == 17 || i == 20)
		return;
	if (i > -1 && i < 31) {
		foo(i);
		exit(0);
	}
}

Daemon::Daemon(Tintin_reporter &t) : t(t)
{
	int fd;

	t.opens();
	this->t.write(0, "Entering Daemon mode.");
	unlink("/var/lock/matt_daemon.lock");
	this->pid = fork();	
	if (this->pid > 0)
		exit(EXIT_SUCCESS);
	if (this->pid < 0)
		exit(EXIT_FAILURE);	
	if ((this->sid = setsid()) < 0)
		exit(EXIT_FAILURE);
	signal(SIGCHLD, SIG_IGN);
	this->pid = fork();
	if (this->pid > 0) {
		this->t.write(0, "Matt_daemon: started. PID: " + std::to_string(this->pid) + "." );
		exit(EXIT_SUCCESS);
	}
	if (this->pid < 0)
		exit(EXIT_FAILURE);
	umask(0);
	chdir("/");
	for (fd = sysconf(_SC_OPEN_MAX); fd > 0; fd--)
		close(fd);
	close(STDIN_FILENO);
  	close(STDOUT_FILENO);
  	close(STDERR_FILENO);
	t.opens();
	for (int i = 1; i < 32; i++)
		std::signal(i, sig_catch);

}

Daemon::~Daemon()
{
}

Daemon &Daemon::operator=(Daemon const &cpy)
{
	return *this;
}

Daemon::Daemon(Daemon const &cpy) :  t(cpy.t)
{
}

