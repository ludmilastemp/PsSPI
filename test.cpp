#include "PsSPI.hpp"

#include <iostream>

PsSPI* psspi = nullptr;

struct ToolTest : PsSPI_Tool
{
    ToolTest(const char* img, const char* name) 
        : PsSPI_Tool(img, name)
    {}

    virtual void apply()      override;
    virtual void activate()   override;
    virtual void deactivate() override;
};

void loadPlugin ()
{
    psspi = getPsSPI ();

    ToolTest* tool = new ToolTest { "img/brush.png", "brush" };
    tool->id = psspi->addTool (tool);
}

void ToolTest::apply ()
{
    std::cout << "la-la-la" << std::endl;
}

void ToolTest::activate ()
{
    std::cout << "meow" << std::endl;
}

void ToolTest::deactivate ()
{
    std::cout << "bye" << std::endl;
}
