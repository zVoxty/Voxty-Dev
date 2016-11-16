#include "Error.h"

Error::Error()
{
    //ctor
}

Error::~Error()
{
    //dtor
}

void Error::UserOptionError(){
    ClearScreen;
    cout << "\n\n\t Invalid option try again !\n";
    Sleep1s;
    ClearScreen;
}
