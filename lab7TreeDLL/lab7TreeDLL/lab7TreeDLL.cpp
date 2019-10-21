// lab7TreeDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "lab7TreeDLL.h"


// This is an example of an exported variable
LAB7TREEDLL_API int nlab7TreeDLL=0;

// This is an example of an exported function.
LAB7TREEDLL_API int fnlab7TreeDLL(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
Clab7TreeDLL::Clab7TreeDLL()
{
    return;
}
