#include <iostream>
#include "illegal_exception.h"
using namespace std;
 
illegal_exception::illegal_exception() { 
    cout << "illegal argument" << endl;
}

illegal_exception::~illegal_exception() {}