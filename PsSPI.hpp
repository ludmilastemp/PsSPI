#ifndef __PsSPI__
#define __PsSPI__

extern "C"
{
    struct PsSPI;
    struct PsSPI_Tool;
    struct PsSPI_Color;
    struct PsSPI_Event;
    PsSPI* getPsSPI ();
    void loadPlugin ();
}

using tool_t = int;
using layer_t = int;

struct PsSPI_Tool
{
    PsSPI_Tool(const char* init_img, const char* init_name) 
        : img(init_img), name(init_name) 
    {}

    tool_t id = -1;
    const char* img;
    const char* name;
    virtual void apply()      {};
    virtual void activate()   {};
    virtual void deactivate() {};
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
    virtual tool_t addTool (PsSPI_Tool* tool) = 0;
    virtual PsSPI_Event getEvent () = 0;
    virtual layer_t createLayer () = 0;
    virtual void crearLayer () = 0;
    virtual void crearLayer (layer_t layer) = 0;
    virtual void overlayLayer (layer_t to) = 0;
    virtual void overlayLayer (layer_t to, layer_t on) = 0;
    virtual void setPixel (int x, int y, PsSPI_Color, int size = 1) = 0;
    virtual void setPixel (layer_t layer, int x, int y, PsSPI_Color, int size = 1) = 0;
};

#endif /* __PsSPI__ */