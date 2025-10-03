#include <iostream>
#include <limits>

int main(int argc, char const *argv[])
{
    std::cout << "Hello World!\n";

    // Wait for user input before closing the console window
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}
