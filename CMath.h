#ifndef CMATH_H
#define CMATH_H

#include <iostream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

class CMath {
    public:
        string vecToStr(vector<int> vec);
        void divide(vector<int> &A, int n);
        void multiply(vector<int> &A, int n);
        void subtract(vector<int> &A, vector<int> &B);
        void add(vector<int> &A, vector<int> &B);
        int compare(vector<int> &A, vector<int> &B);
};

#endif
