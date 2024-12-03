#ifndef __PsSPI__
#define __PsSPI__

extern "C"
{
    struct PsSPI;
    struct PsSPI_Tool;
    PsSPI* getPsSPI ();
    void loadPlugin ();
}

using tool_t = int;

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

class PsSPI
{
public:
    virtual tool_t addTool (PsSPI_Tool* tool) = 0;
};

#endif /* __PsSPI__ */