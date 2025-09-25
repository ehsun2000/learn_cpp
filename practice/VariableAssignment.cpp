#include <iostream>

int main()
{
    int defaultInt; // default-initialized (no initializer)

    // Traditional initialization
    int copyInitializedInt = 5;     // copy-initialized (initial value after equals sign)
    int directInitializedInt(6);    // direct-initialized (initial value in parenthesis)

    std::cout << "defaultInt: " << defaultInt << '\n'; // indeterminate value (contains garbage)
    std::cout << "copyInitializedInt: " << copyInitializedInt << '\n';

    // Modern initialization (since C++11)
    int directListInitialized{5};   // direct-list-initialization of initial value 5 into variable width (preferred)
    int copyListInitialized = {6};  // copy-list-initialization of initial value 6 into variable height (rarely used)

    std::cout << "directListInitialized: " << directListInitialized << '\n';
    std::cout << "copyListInitialized: " << copyListInitialized << '\n';

    // An integer can only hold non-fractional values
    // Initializing an int with fractional value 4.5 requires a compiler to convert 4.5 to a value an int can hold
    // Such a conversion is a narrowing conversion, since the fractional part of the value will be lost
    // int narrowingConversion1 = { 4.5 };      // error: List-Initialization disallow narrowing conversions (won't compile)
    int narrowingConversion2 = 4.5;
    int narrowingConversion3(4.5);

    std::cout << "narrowingConversion2: " << narrowingConversion2 << '\n'; // prints 4
    std::cout << "narrowingConversion3: " << narrowingConversion3 << '\n'; // prints 4

    // Use direct-list-initialization when you’re actually using the initial value
    int actualValue{0};
    std::cout << "actualValue: " << actualValue << '\n';

    // Use value-initialization when the object’s value is temporary and will be replaced
    int temporaryValue{}; // value-initialized (initialized to zero)
    std::cout << "temporaryValue: " << temporaryValue << '\n';

    // Initializing multiple variables
    int multCopyInitializedInt1 = 1, multCopyInitializedInt2 = 2, multCopyInitializedInt3 = 3;
    int multDirectInitializedInt1(4), multDirectInitializedInt2(5), multDirectInitializedInt3(6);
    int multDirectListInitializedInt1{7}, multDirectListInitializedInt2{8}, multDirectListInitializedInt3{9};
    int multValueInitializedInt1{}, multValueInitializedInt2{};

    std::cout << "multCopyInitializedInt1: " << multCopyInitializedInt1 << " / ";
    std::cout << "multCopyInitializedInt2: " << multCopyInitializedInt2 << " / ";
    std::cout << "multCopyInitializedInt3: " << multCopyInitializedInt3 << '\n';
    std::cout << "multDirectInitializedInt1: " << multDirectInitializedInt1 << " / ";
    std::cout << "multDirectInitializedInt2: " << multDirectInitializedInt2 << " / ";
    std::cout << "multDirectInitializedInt3: " << multDirectInitializedInt3 << '\n';
    std::cout << "multDirectListInitializedInt1: " << multDirectListInitializedInt1 << " / ";
    std::cout << "multDirectListInitializedInt2: " << multDirectListInitializedInt2 << " / ";
    std::cout << "multDirectListInitializedInt3: " << multDirectListInitializedInt3 << '\n';
    std::cout << "multValueInitializedInt1: " << multValueInitializedInt1 << " / ";
    std::cout << "multValueInitializedInt2: " << multValueInitializedInt2 << '\n';

    // Avoid uninitialized variables
    int nonInitializedValue, initializedValue = 5; 
    std::cout << "nonInitializedValue: " << nonInitializedValue << " / initializedValue: " << initializedValue << '\n';

    // Maybe unused variable (since C++17)
    [[maybe_unused]] int maybeUnusedValue;
    [[maybe_unused]] int maybeUnusedInitializedValue = 10;
    std::cout << "maybeUnusedInitializedValue: " << maybeUnusedInitializedValue << '\n';

    return 0;
}
