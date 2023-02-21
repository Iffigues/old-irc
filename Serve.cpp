#include "Serve.hpp"

#include <iostream>
#include <mutex>

Serve* Serve::pinstance_{nullptr};
std::mutex Serve::mutex_;

Serve *Serve::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Serve(8080, "hello");
    }
    return pinstance_;
}


