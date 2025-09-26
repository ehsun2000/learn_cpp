#include <iostream>
using namespace std; // this is a using-directive that allows us to access names in the std namespace with no namespace prefix

void functionB()
{
    cout << "Starting function B..." << '\n';
    cout << "Ending function B..." << '\n';
}

void functionA()
{
    cout << "Starting function A..." << '\n';
    functionB();
    cout << "Ending function A..." << '\n';
}

// should be declared before use
int getValueFromUser()
{
    cout << "Please enter an integer: ";
    int userInput{};
    cin >> userInput;
    return userInput;
}

void printValue(int value)
{
    cout << "The value is: " << value << '\n';
}

void voidFunction()
{
    // void function does not return a value
    cout << "This function returns no value." << '\n';
}

void unNamedParamFunction(int, double)
{
    // function parameters can be unnamed if not used in the function body
    cout << "This function has unnamed parameters." << '\n';
}

void googleRecommendedFunctionName(int /*param1*/, double /*param2*/)
{
    // Google C++ Style Guide recommends using /*param*/ to indicate unused parameters
    cout << "This function follows Google C++ Style Guide for unnamed parameters." << '\n';
}

int main()
{
    
    cout << "Starting main function..." << '\n';
    functionA();
    cout << "Ending main function..." << '\n';

    cout << "------------------------------" << '\n';

    int userInputValue{getValueFromUser()}, anotherValue{getValueFromUser()}; // DRY: Don't Repeat Yourself

    printValue(userInputValue);
    printValue(anotherValue);

    cout << "------------------------------" << '\n';

    voidFunction();
    // this will fail to compile, as voidFunction() does not return a value
    // cout << "voidFunction() will return: " << voidFunction() << '\n'; // voidFunction() will return nothing
    return 0;
}
