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
protected:
	Serve(int port, std::string const &password);
    virtual ~Serve();
    int port;
    std::string const &password;
    int server_fd;
    struct sockaddr_in address;

public:
    Serve(Serve &other) = delete;
    void operator=(const Serve &) = delete;
    static Serve *GetInstance(int port, std::string const &password);

};
#endif

