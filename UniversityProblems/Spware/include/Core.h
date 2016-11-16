#ifndef CORE_H
#define CORE_H
#include <iostream>
#include "windows.h"
#include "string"
#include "stdlib.h"
#include "time.h"
#include <vector>
#include <algorithm>

#define ClearScreen system("CLS")
#define Sleep2s Sleep(2000)
#define Sleep1s Sleep(1000)
#define Sleep05s Sleep(500)
#define cout(x) cout<<x;

using namespace std;



int generateNumber();

#endif // CORE_H
