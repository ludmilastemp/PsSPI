#ifndef __PsSPI__
#define __PsSPI__

class PsSPI
{

public:
    virtual void addTool (const char* png) = 0;
};

extern "C"
{
    PsSPI* getPsSPI ();
    void loadPlugin ();
}


#endif /* __PsSPI__ */