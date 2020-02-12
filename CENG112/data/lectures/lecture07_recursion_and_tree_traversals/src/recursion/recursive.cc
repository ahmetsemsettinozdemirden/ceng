#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int factorial(int n);
int factorial_tr(int n);
int gcd(int n, int m);

int main(int argc, char *argv[])
{
        int r = factorial(10);
        cout << "factorial(10) is " << r << endl;
        cout << "factorial_tr(10) is " << factorial_tr(10) << endl;

        r = gcd(64752, 98344);
        cout << "gcd(64756, 98342) is " << r << endl;

        return EXIT_SUCCESS;
}

int factorial(int n)
{
        cout << "  --> Call to factorial(" << n << ")\n";

        if (n == 0)
                return 1;

        int f_nm1 = factorial(n-1);
        cout << "  ----> factorial(" << n-1 << ") returned with " << f_nm1 << endl;

        return n * f_nm1;
}

int gcd(int m, int n)
{
        cout << "  --> Call to gcd(" << m << ", " << n << ")" << endl;

        if (n == 0)
                return m;

        return gcd(n, m % n);
}

static int factorial_iter(int n, int f)
{
        if (n == 0)
                return f;

        int np = n-1;
        int fp = n*f;

        return factorial_iter(np, fp);
}

int factorial_tr(int n)
{
        return factorial_iter(n, 1);
}
