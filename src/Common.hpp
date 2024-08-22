#pragma once

#include <memory>

#define LOG_START_FUNCTION() printf("\n%s: - - - - - - - - - -  Start - - - - - - - - -\n", __FUNCTION__)

#define LOG_END_FUNCTION() printf("%s: - - - - - - - - - -  End - - - - - - - - - -\n\n", __FUNCTION__)

// Overload for lvalues
template <typename T>
void detectValueCategory(T &arg)
{
    if (std::is_const<std::remove_reference_t<T>>::value)
    {
        std::cout << "Argument is a const lvalue. (" << typeid(arg).name() << ")" << std::endl;
    }
    else
    {
        std::cout << "Argument is a non-const lvalue. (" << typeid(arg).name() << ")" << std::endl;
    }
}

// Overload for rvalues
template <typename T>
void detectValueCategory(T &&arg)
{
    if (std::is_const<std::remove_reference_t<T>>::value)
    {
        std::cout << " a const rvalue. (" << typeid(arg).name() << ")" << std::endl;
    }
    else
    {
        std::cout << " non-const rvalue. (" << typeid(arg).name() << ")" << std::endl;
    }
}

// Helper function to distinguish between references and value types

template <typename T>
void detectValueCategoryImpl(T &&arg)
{
    // Check if the argument is a reference
    if (std::is_reference<T>::value)
    {
        std::cout << "Argument is a reference and ";
        detectValueCategory(std::forward<T>(arg));
    }
    else
    {
        std::cout << "Argument is not a reference and ";
        // For non-references, we need to handle lvalues and rvalues separately
        detectValueCategory(std::forward<T>(arg));
    }
}

template <typename T>
void Show_address(T &param)
{
    std::cout << "Address of value: " << std::addressof(param) << std::endl;
}