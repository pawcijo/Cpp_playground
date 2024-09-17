#pragma once

#include "Common/Common.hpp"

#include <iostream>
#include <vector>
#include <utility>

namespace MoreAboutSharedPtr
{

    NoteFormat controlBlockNotes = {
        {{"when Control block is created:"}, {}},
        {{}, {"std::make_shared always creates a control block."}},
        {{}, {"std::shared_ptr is constructed from a unique-ownership (unique_ptr, auto_ptr)."}},
        {{}, {"std::shared_ptr constructor is called with a raw pointer."}},
    };

    class TestObject
    {
        std::string someString;

    public:
        TestObject() : someString("ExampleString")
        {
            std::cout << "Random obj created." << std::endl;
        };

        TestObject(const TestObject &another) = default;

        TestObject operator=(const TestObject &another)
        {
            someString = another.someString;

            return *this;
        }

        TestObject(const TestObject &&another)
        {
            someString = another.someString;
        };

        TestObject operator=(const TestObject &&another)
        {
            someString = another.someString;

            return *this;
        }

        std::string stringValue() const { return someString; }
    };

    void PrintNotes()
    {
        for (const auto &pair : controlBlockNotes)
        {
            std::cout << BOLD_TEXT_START << pair.first << BOLD_TEXT_END << pair.second << std::endl;
        }
    }

    void MoreAboutSharedPtrExample()
    {
        LOG_START_FUNCTION();
        PrintNotes();
        LOG_END_FUNCTION();
    }

    void DontDoThatExample()
    {
        LOG_START_FUNCTION();

        std::cout << R"(        
        TestObject *obj = new TestObject();
        std::shared_ptr<TestObject> first(obj);
        std::shared_ptr<TestObject> second(obj);)"
                  << std::endl<<std::endl;

        TestObject *obj = new TestObject();
        std::shared_ptr<TestObject> first(obj);
        std::shared_ptr<TestObject> second(obj);
        LOG_END_FUNCTION();
    }

    void MoreAboutSharedPtrDemo()
    {

        MoreAboutSharedPtrExample();

        DontDoThatExample();
    }

}