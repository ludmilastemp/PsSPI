#ifndef __PsSPI__
#define __PsSPI__

using tool_t = int;

struct PsSPI_Tool
{
    tool_t id;
    const char* png;
    void (*activate) ();
    void (*deActivate) ();
    void (*apply) ();
};

struct PsSPI_Color
{
    unsigned char r, g, b, a;
};

struct PsSPI_Event
{
    bool mousePressed;
    int  mouseCoordX;
    int  mouseCoordY;
};

class PsSPI
{
public:

    tool_t addTool (PsSPI_Tool tool);

    PsSPI_Event getEvent ();

    void setPixel (int x, int y, PsSPI_Color);
};

PsSPI* getPsSPI ();

void loadPlugin ();


#endif /* __PsSPI__ */