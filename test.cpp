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
    // std::cout << "la-la-la" << std::endl;

    PsSPI_Event event = psspi->getEvent();

    if (!event.mousePressed)
        return;

    int x = event.mouseCoordX;
    int y = event.mouseCoordY;

    psspi->setPixel (x, y, {0, 255, 255, 255});
}

void ToolTest::activate ()
{
    std::cout << "meow" << std::endl;
}

void ToolTest::deactivate ()
{
    std::cout << "bye" << std::endl;
}
