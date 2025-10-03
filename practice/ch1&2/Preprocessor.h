// We really should have a header guard here, but will omit it for simplicity

#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

void doSomething(); // forward declaration for function doSomething()

#endif
// void doSomething() 
// {}

// Some recommendations for creating header files:
// 1. Use header guards or #pragma once to prevent multiple inclusions.
// 2. Avoid defining functions in header files because it can lead to multiple definition errors.
// 3. Give header files the same name as the corresponding source file for clarity. ex. Preprocessor.h for Preprocessor.cpp
// 4. A header should include other headers containing functionality that be using in the code.
// 5. Don't include .cpp files
// 6. Header guards should be unique. It will avoid conflicts with other header guards in the project. A common convention is to use the file name in uppercase with underscores replacing dots and slashes. ex. PREPROCESSOR_H for Preprocessor.h

// Header guards v.s. #pragma once
// Header guards are more portable, as they are supported by all C++ compilers.
// #pragma once is less error-prone, as it doesn't require unique identifiers and avoids potential conflicts.
// #pragma once can be slightly faster to compile, as the compiler doesn't need to process the header guard macros.
// In modern development, #pragma once is widely supported and often preferred for its simplicity, but header guards remain a reliable choice for maximum compatibility.