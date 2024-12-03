#include "PsSPI.hpp"

#include <iostream>

PsSPI* psspi = nullptr;

struct ToolTest : PsSPI_Tool
{
private:
    int x_start;
    int y_start;

public:
    layer_t layer;

    ToolTest(const char* img, const char* name) 
        : PsSPI_Tool(img, name)
    {
        x_start = -1; 
        y_start = -1;
    }

    virtual void apply()      override;
    virtual void activate()   override;
    virtual void deactivate() override;
};

void loadPlugin ()
{
    psspi = getPsSPI ();

    ToolTest* tool = new ToolTest { "img/line.png", "line" };
    tool->id = psspi->addTool (tool);
    tool->layer = psspi->createLayer ();
}

void ToolTest::apply ()
{
    // std::cout << "la-la-la" << std::endl;

    PsSPI_Event event = psspi->getEvent();
    PsSPI_Color color {0, 255, 255, 255};
    int size = 5;

    if (!event.mousePressed)
    {
        psspi->overlayLayer (layer);
        x_start = -1;
        y_start = -1;
        return;
    }

    int x = event.mouseCoordX;
    int y = event.mouseCoordY;

    if (x_start == -1 && y_start == -1)
    {
        x_start = x;
        y_start = y;
        return;
    }

    psspi->crearLayer (layer);

    int x_draw = x_start;
    int y_draw = y_start;

    if (abs(x - x_start) < abs(y - y_start))
    {
        int A = 2 * abs(x - x_start);
        int B = A - 2 * abs(y - y_start);
        int P = A - abs(y - y_start);

        for (y_draw = y_start; y_draw <= y; y_draw++)
        {
            if (P < 0)
            {
                P += A;
            }
            else if (P >= 0)
            {
                if (x - x_start > 0)
                    x_draw++;
                else 
                    x_draw--;
                P += B;
            }
            
            psspi->setPixel (layer, x_draw, y_draw, color, size);
        }
        x_draw = x;
        for (y_draw = y; y_draw <= y_start; y_draw++)
        {
            if (P < 0)
            {
                P += A;
            }
            else if (P >= 0)
            {
                if (x - x_start > 0)
                    x_draw--;
                else 
                    x_draw++;
                P += B;
            }
            
            psspi->setPixel (layer, x_draw, y_draw, color, size);
        }
        return;
    }


    int A = 2 * abs(y - y_start);
    int B = A - 2 * abs(x - x_start);
    int P = A - abs(x - x_start);
    for (x_draw = x_start; x_draw <= x; x_draw++)
    {
        if (P < 0)
        {
            P += A;
        }
        else if (P >= 0)
        {
            if (y - y_start > 0)
                y_draw++;
            else 
                y_draw--;
            P += B;
        }

        psspi->setPixel (layer, x_draw, y_draw, color, size);
    }
    y_draw = y;
    for (x_draw = x; x_draw <= x_start; x_draw++)
    {
        if (P < 0)
        {
            P += A;
        }
        else if (P >= 0)
        {
            if (y - y_start > 0)
                y_draw--;
            else 
                y_draw++;
            P += B;
        }

        psspi->setPixel (layer, x_draw, y_draw, color, size);
    }
    return;
}


void ToolTest::activate ()
{
    std::cout << "meow" << std::endl;
}

void ToolTest::deactivate ()
{
    std::cout << "bye" << std::endl;
    psspi->overlayLayer (layer);
    x_start = -1;
    y_start = -1;
}
