#include "Serve.hpp"

#include <iostream>
#include <mutex>

Serve* Serve::pinstance_{nullptr};
std::mutex Serve::mutex_;

Serve::Serve(int port, std::string const &password) : port(port), password(password)
{

}

Serve::~Serve(){

}

Serve *Serve::GetInstance(int port, std::string const &password)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Serve(port, password);
    }
    return pinstance_;
}


