#ifndef CPI_H
#define CPI_H
#include "CMath.h"

class CPi: public CMath {
  private:
    vector<int> Q, q, Pi;
    int qn, Qn;
    bool toggle;
  public:
    CPi(int elements);
    void divideSubQuotient(int n);
    void divideSubQuotient();
    void divideQuotient(int n);
    void divideQuotient();
    void multiplyInt(int n);
    void calcStack();
    void printRemaining();
    void subtractFromPi(vector<int> vec);
    int piIndex(vector<int> vec);
    string piToString();
    vector<int> getQuotient();
    vector<int> getPi();
};

#endif
