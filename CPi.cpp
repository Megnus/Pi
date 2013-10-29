#include "CPi.h"

CPi::CPi(int elements) {
    toggle = true;
    qn = 1;
    while (Pi.size() < elements) {
        Pi.push_back(0);
    }
    Q = Pi;
    Q.push_back(0x64);
}

void CPi::divideSubQuotient(int n) {
    q = Q;
    divide(q,n);
}

void CPi::divideSubQuotient() {
    qn += 2;
    divideSubQuotient(qn);
}

void CPi::divideQuotient(int n) {
    Qn = n * n;
    divide(Q,n);
}

void CPi::divideQuotient() {
    divide(Q,Qn);
}

void CPi::multiplyInt(int n) {
    multiply(Pi,n);
}

void CPi::calcStack() {
    if (toggle)
        add(Pi,q);
    else
        subtract(Pi,q);
    toggle = !toggle;
}

void CPi::printRemaining() {
    static int past = 0;
    int present = (10000 - 10000 * Q.size() / Pi.size());

    if (past == 0)
       cout.precision(2);

    if (present != past) {
        cout << fixed << present / 100.0F << '%' << endl;
    }

    past = present;
}

string CPi::piToString() {
    return vecToStr(Pi);
}

void CPi::subtractFromPi(vector<int> vec) {
    subtract(Pi,vec);
}

int CPi::piIndex(vector<int> vec) {
    return compare(Q,vec) < 0 ? 1 : 0;
}

vector<int> CPi::getPi() {
    return Pi;
}

vector<int> CPi::getQuotient() {
    return Q;
}
