#include <iostream>
#include <thread>
#include <mutex>
#include <future>

void    worker(std::promise<void> &prom)
{
    try
    {
        throw (std::runtime_error("exception from thread"));
    }
    catch (...)
    {
        prom.set_exception(std::current_exception());
       // p.set_exception(std::current_exception());
    }
}

void    check_thread_and_exception(void)
{
    std::promise<void>  p;

    auto result = p.get_future();
    std::thread t1(worker, std::ref(p));
    t1.detach();
    try
    {
        result.get();
    }
    catch (std::runtime_error &e)
    {
        std::cout << "runtime error catched." << std::endl;
    }
}

int     main(void)
{
    check_thread_and_exception();
    return (0);
}