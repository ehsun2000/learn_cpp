int main(int argc, char const *argv[])
{
    return 0;
}

// C++ function name can be camelCase or snake_case

void testFunction1()
{
    // C++ can use camelCase or snake_case for naming identifiers (variables, functions, classes, etc.)
    int functionValue{};
    int function_value{};
    
    // Avoid naming identifiers starting with an underscore. Although syntactically legal, these names are typically reserved for OS, library, or compiler use.
    int _functionValue{}; // avoid this, leading underscore is reserved
    int ccount{};         // avoid this, we don't know what c before count means
    int time{};           // avoid this, time is too generic

    // a count of the number of chars in a piece of text, including whitespace and punctuation
    int numChars{};

}

void test_function2()
{
}