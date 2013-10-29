#include "CMath.h"

CMath::CMath()
{
    //ctor
}

CMath::~CMath()
{
    //dtor
}

string vecToStr(vector<int> vec) {
	string result;
	ostringstream convert;

	for( vector<int>::const_iterator i = vec.end() - 1; i != vec.begin(); --i) {

		for (int j = 0x3e8; *i / j == 0 && j > 1; j /= 0xa)
            convert << '0';
		convert << *i;
	}
	result = convert.str();
	result.insert(1,".");
	return result;
}

void divide(vector<int> &A, int n) {
    int carry;
    for (int i = A.size() - 1; i > 0; i--) {
        carry = A[i] % n;
        A[i - 1] += carry * 0x2710;
        A[i] /= n;
    }

    A[0] /= n;

    while (A.back() == 0 && A.size() > 0)
        A.pop_back();
}

void multiply(vector<int> &A, int n) {
    int i;
    int carry = 0;

    A.push_back(0);

	for (i = 0; i < A.size(); i++) {
        A[i] = A[i] * n + carry;
        carry = A[i] / 0x2710;
        A[i] -= carry * 0x2710;
	}

    A[i] += carry;

	while (A.back() == 0)
        A.pop_back();
}

void subtract(vector<int> &A, vector<int> &B) {
	// A must be greater than B.
	for (int i = 0; i < (int) B.size(); i++) {
		A[i] -= B[i];
        if (A[i] < 0) {
			A[i] += 0x2710;
			A[i + 1]--;
		}
	}
}

void add(vector<int> &A, vector<int> &B) {
    // The size of A must be greater or equal to the size of B.
    A.push_back(0);

	for (int i = 0; i < (int) B.size(); i++) {
		A[i] += B[i];
        if (A[i] >= 0x2710) {
			A[i] -= 0x2710;
            A[i + 1]++;
		}
	}

	if (A.back() == 0)
        A.pop_back();
}

int compare(vector<int> &A, vector<int> &B) {
    int res = A.size() > B.size() ? 1 : (A.size() < B.size() ? -1 : 0);

    for (int i = (int) A.size() - 1; res == 0 && i >= 0; i--) {
        res = A[i] > B[i] ? 1 : (A[i] < B[i] ? -1 : 0);
    }
    return res;
}
