#include "PsSPI.hpp"

#include <iostream>

PsSPI* psspi = nullptr;

void activate   ();
void deActivate ();
void apply      ();

void loadPlugin ()
{
    psspi = getPsSPI ();

    PsSPI_Tool tool 
    {
        .id         = -1,
        .png        = "img/brush.png",
        .activate   = &activate,
        .deActivate = &deActivate,
        .apply      = &apply
    };

    tool.id = psspi->addTool (tool);
}

void activate ()
{
    std::cout << "meow" << std::endl;
}

void deActivate ()
{
    std::cout << "bye" << std::endl;
}

void apply ()
{
    std::cout << "la-la-la" << std::endl;
}
