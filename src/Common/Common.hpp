#pragma once

#include <memory>
#include <string>
#include <utility>

#define LOG_FUNCTION_NAME(color) printf("\n\033[1;%sm%s:\033[0m\n", color, __FUNCTION__)

#define LOG_START_FUNCTION() printf("\n%s: - - - - - - - - - -  Start - - - - - - - - -\n", __FUNCTION__)

#define LOG_END_FUNCTION() printf("%s: - - - - - - - - - -  End - - - - - - - - - -\n\n", __FUNCTION__)

#define BOLD_TEXT_START "\033[1;37m"

#define BOLD_TEXT_END "\033[0m"

using NoteFormat = std::vector<std::pair<std::string, std::string>>;

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

template <typename T>
void Show_address(const char *name, T &param)
{
    std::cout << "Address of " << name << ":" << std::addressof(param) << std::endl;
}