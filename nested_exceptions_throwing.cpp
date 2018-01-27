#include <iostream>
#include <string>
#include <fstream>
#include <exception>

void    open_file(const std::string &str)
{
    try
    {
        std::ifstream   file(str);
        file.exceptions(std::ios_base::failbit);
    }
    catch(...)
    {
        std::throw_with_nested(std::runtime_error("Can't open a file" + str));
    }
}

void    run(void)
{
    try
    {
        open_file("non-existing.file");
    }
    catch(...)
    {
        std::throw_with_nested(std::runtime_error("run() failed"));
    }
}

void    print_exception(const std::exception &e, int level = 0)
{
    std::cerr << std::string(level, ' ') << "exception " << e.what() << std::endl;
    try
    {
        std::rethrow_if_nested(e);
    }
    catch (const std::exception &e)
    {
        print_exception(e, level + 1);
    }
    catch (...)
    {

    }
}

int main()
{
    try
    {
        run();
    }
    catch(const std::exception &e)
    {
        print_exception(e);
    }
    return 0;
}