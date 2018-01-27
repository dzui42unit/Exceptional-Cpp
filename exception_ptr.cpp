#include <iostream>
#include <exception>
#include <vector>

struct  some_exception
{
    int value;

    some_exception(int v) : value(v)
    {
        std::cout << "int ctor" << std::endl;
    }

    some_exception(const some_exception &e)
    {
        value = e.value;
        std::cout << "copy ctor" << std::endl;
    }
};

std::exception_ptr  throw_and_catch_exception_ptr(void)
{
    std::exception_ptr cur_ex;

    try
    {
        const int throw_val = 10;
        std::cout << "throwing " << throw_val << " ..." << std::endl;
        throw(some_exception(throw_val));
    }
    catch (...)
    {
        cur_ex = std::current_exception();
    }
    return (cur_ex);
}

void    rethrow_exc(std::exception_ptr e)
{
    try
    {
        if (e)
        {
            std::rethrow_exception(e);
        }
    }
    catch(const some_exception &e)
    {
        std::cout << "catched int value: " << e.value << std::endl;
    }
    std::exception_ptr another_ptr = e;
    try
    {
        if (another_ptr)
        {
            std::rethrow_exception(another_ptr);
        }
    }
    catch (const some_exception &e)
    {
        std::cout << "catched int value: " << e.value << std::endl;
    }
}

void    make_exception(void)
{
    std::exception_ptr new_one_exc = std::make_exception_ptr(some_exception(20));
    std::cout << "exception_ptr constructed: " << std::endl;
    rethrow_exc(new_one_exc);
}

void    exception_ptr_test(void)
{
    rethrow_exc(throw_and_catch_exception_ptr());
    make_exception();
}

int     main(void)
{
    exception_ptr_test();
    return (0);
}