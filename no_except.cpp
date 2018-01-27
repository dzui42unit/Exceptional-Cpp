#include <iostream>
#include <exception>
#include <vector>

template <typename InputTypeT>
void func() noexcept(noexcept(InputTypeT()))
{
    InputTypeT var;
    std::cout << "func called, object size: " << sizeof(var) << std::endl;
}

void noexceptSample()
{
    std::cout << "noexcept int():         " << noexcept(int()) << std::endl;
    std::cout << "noexcept vector<int>(): " << noexcept(std::vector<int>()) << std::endl << std::endl;

    // function is not actually called
    std::cout << "noexcept func<int>:         " << noexcept(func<int>()) << std::endl;
    std::cout << "noexcept func<vector<int>>: " << noexcept(func<std::vector<int>>()) << std::endl;
}

int     main(void)
{
    noexceptSample();
    return (0);
}