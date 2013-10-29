#include <fstream>
#include <time.h>
#include "CPi.h"

void printTime(float t1, float t2) {
    cout.precision(3);
    cout << "calculation time : ";
    cout << ((t2 - t1) / 1000000.0F) * 1000;
    cout << ' ' << 's' << endl;
}

string piCalculation(int elements) {
    float t = clock();
    string result;
    CPi *pi[2];
    int n;

    pi[0] = new CPi(elements);
    pi[1] = new CPi(elements);

    pi[0]->divideQuotient(5);
    pi[1]->divideQuotient(239);
    pi[0]->divideSubQuotient(1);
    pi[1]->divideSubQuotient(1);
    pi[0]->calcStack();
    pi[1]->calcStack();

    do {
        n = pi[0]->piIndex(pi[1]->getQuotient());
        pi[0]->printRemaining();
        pi[n]->divideQuotient();
        pi[n]->divideSubQuotient();
        pi[n]->calcStack();
    } while (pi[n]->getQuotient().size() > 0);

    pi[0]->multiplyInt(16);
    pi[1]->multiplyInt(4);
    pi[0]->subtractFromPi(pi[1]->getPi());
    result = pi[0]->piToString();

    delete pi[0];
    delete pi[1];

    printTime(t,clock());
    cout << endl << "number of decimals : ";
    cout << elements * 3 - 1 << endl;

    return result;
}

void piToFile(string pi) {
    ofstream file ("pi.txt");

    if (!file.is_open()) {
        cout << "failed to save result!" << endl;
        exit (EXIT_FAILURE);
    }

    for (int i = 0; i < (int) pi.size(); i += 100)
        file << pi.substr(i, 100) << endl;

    cout << "result saved to pi.txt" << endl;
    file.close();
}

int setNumOfElements() {
    int num;
    cout << "Type the number of decimals to be calculated : ";
    cin >> num;
    return num / 3 + 1;
}

int main() {
    string pi = piCalculation(setNumOfElements());
    piToFile(pi);
    cin.get();
    return 0;
}
