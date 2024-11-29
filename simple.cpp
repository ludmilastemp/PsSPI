#include "PsSPI.hpp"

PsSPI* psspi = nullptr;

void loadPlugin ()
{
    psspi = getPsSPI ();
    psspi->addTool ("img/brush.png");
}
