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

class PsSPI
{
public:

    tool_t addTool (PsSPI_Tool tool);
};

PsSPI* getPsSPI ();

void loadPlugin ();


#endif /* __PsSPI__ */