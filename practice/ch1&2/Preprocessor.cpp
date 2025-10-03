#include "Preprocessor.h"
#include <iostream>
#define MY_NAME "Charles Zheng"
#define PRINT_CPP "C++ is a powerful language."
#define PRINT

void doSomething(); // forward declaration for function doSomething()
int main()
{

    std::cout << "Hello, " << MY_NAME << "!" << '\n';
#ifdef PRINT_CPP
    std::cout << PRINT_CPP << '\n';
#endif
#ifdef PRINT_JAVA
    std::cout << "Java is also a popular language." << '\n';
#endif

#ifndef GOOD_NIGHT
    std::cout << "Good night!" << '\n';
#endif

#if 0
    std::cout << "This line will not be compiled." << '\n';
#endif

    doSomething();

    return 0;
}