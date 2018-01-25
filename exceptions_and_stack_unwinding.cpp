#include <string>
#include <iostream>
#include <exception>

class	Example
{
private:
	std::string	name;
public:
	Example(std::string str) : name(str) {}
	~Example()
	{
		std::cout << "Destroying: " << name << std::endl;
	}
};

void	func_a(void);
void	func_b(void);
void	func_c(void);
void	func_d(void);

bool	flag;

int main()
{
	flag = false;
	try
	{
		std::cout << "Normal flow of execution example:" << std::endl << std::endl;
		Example ex("Main_Object");
		func_a();
		std::cout << "Mission complete ..." << std::endl;
	}
	catch (const char *str)
	{
		std::cout << str << std::endl;
		std::cout << "Mission failed ..." << std::endl;
	}
	std::cout << std::endl;
	flag = true;

	/*
		Let's start with throw() in the last function and compare the result with the normal execution flow.
		So, off the comment from the line in the last function fd().

		This time, we have an exception thrown from the function d(). The catch block caught that exception.

		This time, each function terminated due to a thrown exception instead of normal return call.
		Still, the program frees memory from the stack. However, instead of stopping at the first return address on the stack,
		it continues freeing the stack until it reaches a return address that resides in a try block.
		Execution control then passes to the exception handlers at the end of the try block
		rather than to the first statement following the function call
	*/

	try
	{
		std::cout << "Normal flow of execution example:" << std::endl << std::endl;
		Example ex("Main_Object");
		func_a();
		std::cout << "Mission complete ..." << std::endl;
	}
	catch (const char *str)
	{
		std::cout << str << std::endl;
		std::cout << "Mission failed ..." << std::endl;
	}

	std::cin.get();
    return 0;
}

void	func_a(void)
{
	Example ex("A");
	func_b();
	std::cout << "Returning from func_a ..." << std::endl;
	return ;
}

void	func_b(void)
{
	Example ex("B");
	func_c();
	std::cout << "Returning from func_b ..." << std::endl;
	return;
}

void	func_c(void)
{
	Example ex("C");
	func_d();
	std::cout << "Returning from func_c ..." << std::endl;
	return;
}

void	func_d(void)
{
	Example ex("D");
	if (flag)
		throw ("in fd(), something weird happened.");
	std::cout << "Returning from func_d ..." << std::endl;
	return;
}


