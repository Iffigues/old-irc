#ifndef __Serve_H__
#define __Serve_H__

#include <sys/socket.h>
#include <iostream>
#include <mutex>
#include <netinet/in.h>

class Serve
{
private:
	static Serve * pinstance_;
    static std::mutex mutex_;
	 Serve(const Serve&);
    Serve& operator=(const Serve&);

protected:
    Serve(int port, std::string const &password);
    virtual ~Serve();
    int port;
    std::string const &password;
    int server_fd;
    struct sockaddr_in address;

public:
    static Serve *GetInstance(int port, std::string const &password);
    static void ReleaseInstance();
};
#endif

