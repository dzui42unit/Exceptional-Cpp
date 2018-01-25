#include <iostream>

/*
	In these cases, we have the possibility that an internal catch block forwards
	the exception to its outer level.
*/

int main()
{
	try
	{
		try
		{
			throw (914);
		}
		catch (int e)
		{
			std::cout << "Interger exception caught: " << e << std::endl;
		}
	}
	catch (...)
	{
		std::cout << "Any exception was caught" << std::endl;
	}
	std::cin.get();
    return (0);
}

