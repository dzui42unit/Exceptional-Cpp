#include <iostream>
#include <exception>

/*
	this specification tells that a function is not allowed to throw exceptions
	throwing of an exception will lead to the abort();
*/

int		function_1(char ch) noexcept(true)
{
	std::cout << "I print character: " << ch << std::endl;
	return (int(ch));
}

/*
	this function can throw exception of an INT type
	if any other type of exception will be thrown, it will be processed by any
	other try catch block that will be able to handle it
*/

char		function_2(int nb) throw(int)
{
	std::cout << "I print a number: " << nb << std::endl;
	throw(911);
	return (char(nb));
}

int main()
{
	try
	{
		function_1('a');
		function_2(69);
	}
	catch (int e)
	{
		std::cout << "Integer exception caught: " << e << std::endl;
	}
	catch (...)
	{
		std::cout << "Something caught." << std::endl;
	}
	std::cin.get();
    return 0;
}

