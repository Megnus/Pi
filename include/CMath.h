#ifndef CMATH_H
#define CMATH_H


class CMath
{
    public:
        CMath();
        virtual ~CMath();
        string vecToStr(vector<int> vec);
        void divide(vector<int> &A, int n);
        void multiply(vector<int> &A, int n);
        void subtract(vector<int> &A, vector<int> &B);
        void add(vector<int> &A, vector<int> &B);
        int compare(vector<int> &A, vector<int> &B);

    protected:
    private:
};

#endif // CMATH_H
