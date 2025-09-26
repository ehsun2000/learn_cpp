#include <iostream>

int main()
{
    // print a message to the console
    std::cout << "Hello, IOStream!" << std::endl;

    // print a integer to the console
    std::cout << "The answer is " << 1234 << std::endl;

    // print a variable to the console
    int intValue{10};
    std::cout << "The intValue is " << intValue << std::endl;

    // std::endl vs '\n'
    // Using std::endl is often inefficient, as it actually does two jobs: it outputs a newline and flushes the output buffer(which is slow)
    // Using '\n' is generally preferred for better performance, unless you specifically need to flush the output buffer
    std::cout << "This is line 1." << std::endl; // std
    std::cout << "This is line 2." << '\n';      // '\n'
    std::cout << "This is line 3." << '\n';      // '\n'

    // character is in single quotes
    std::cout << "The charValue is " << 'A' << '\n';
    // string is in double quotes
    std::cout << "The stringValue is " << "Hello, World!" << '\n';

    // std::cin for user input
    int userInput{};
    std::cout << "Please enter an int: ";
    std::cin >> userInput;
    std::cout << "You entered: " << userInput << '\n';

    int mutiUserInput1{}, mutiUserInput2{};
    std::cout << "Please enter two ints separated by space: ";
    std::cin >> mutiUserInput1 >> mutiUserInput2;
    std::cout << "You entered: " << mutiUserInput1 << " and " << mutiUserInput2 << '\n';

    int mutiUserInput3{}, mutiUserInput4{}, mutiUserInput6{};
    std::string  mutiUserInput5{};
    std::cout << "Please enter two ints separated by space or newline: ";
    std::cin >> mutiUserInput3; // first extraction
    std::cin >> mutiUserInput4; // second extraction
    std::cin >> mutiUserInput5; // third extraction
    std::cin >> mutiUserInput6; // fourth extraction
    std::cout << "You entered: " << mutiUserInput3 << " and " << mutiUserInput4 << " and " << mutiUserInput5 << " and " << mutiUserInput6 << '\n';
    // input 10 11Hello3 4 will print 10 and 11 and Hello3 and 4
    // input -10 3.2 4 will print -10 and 3 and .2 and 4
    // input 156156156156156165156156156156165156 4 4 4 will print 2147483647 and 4 and 4 and 4 (int overflow)
    // input +5 1 zz 1 will print 5 and 1 and zz and 1

    // practice: Ask the user to enter three numbers, then print them
    int num1{}, num2{}, num3{};
    std::cout << "Please enter three numbers separated by space or newline: ";
    std::cin >> num1 >> num2 >> num3;
    std::cout << "You entered: " << num1 << ", " << num2 << ", and " << num3 << '\n';

    return 0;
}