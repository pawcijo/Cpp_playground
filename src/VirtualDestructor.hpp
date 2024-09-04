#pragma once

#include "Common.hpp"

#include <iostream>

namespace VirtualDestructor{
class BaseClass
{

public:
    BaseClass()
    {
        std::cout << "Created Base class \n";
    }

     ~BaseClass()
     {
         std::cout << "Destroyed Base class \n";
     }

    virtual void Use()
    {
        std::cout << "Use Base class \n";
    }
};


class DerivedClass final : public BaseClass
{

public:
    DerivedClass()
    {
        std::cout << "Created  Derived class \n";
    }

    ~DerivedClass()
    {
        std::cout << "Destroyed  Derived class \n";
    }

    void Use()  override
    {
        std::cout << "Use Derived class \n";
    }
};

void VirtualDestructorDemo()
{
    LOG_START_FUNCTION();
    BaseClass *deriverd = new DerivedClass();

    deriverd->Use();

    delete dynamic_cast<DerivedClass*>(deriverd);

    LOG_END_FUNCTION();
}
}