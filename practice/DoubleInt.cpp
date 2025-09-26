#include <iostream>

int main()
{
    std::cout << "Please inter an Integer: " << '\n';
    int intValue{};
    std::cin >> intValue;
    std::cout << "Double value! Result is: " << intValue * 2 << '\n';
    
    return 0;
}
