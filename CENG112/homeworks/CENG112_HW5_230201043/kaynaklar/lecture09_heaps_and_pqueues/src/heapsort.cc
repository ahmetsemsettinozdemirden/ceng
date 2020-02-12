#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

void fill_random(int n, float *x);
void print_array(int n, const float *x);
bool is_sorted(int n, float *x);

void heapsort(int n, float *x);

int main(int argc, char **argv)
{
        const int N = 10;
        float x[N];

        fill_random(N, x);
        print_array(N, x);

        heapsort(N, x);
        print_array(N, x);

        if (is_sorted(N, x))
                cout << "SORTED\n";
        else
                cout << "NOT SORTED\n";

        return EXIT_SUCCESS;
}

bool less_than(float f0, float f1)
{
        return f0 < f1;
}

void fill_random(int n, float *x)
{
        srand(time(0));

        for (int i = 0; i < n; ++i)
                x[i] = (rand() % 100) / 10.0f;
}

void print_array(int n, const float *x)
{
        cout << "[";
        for (int i = 0; i < n; ++i) {
                cout << " " << setprecision(2) << setw(5) << x[i];
        }
        cout << " ]\n";
}

bool is_sorted(int n, float *x)
{
        for (int i = 1; i < n; ++i)
                if (less_than(x[i], x[i-1]))
                        return false;

        return true;
}

void exchange(float *x, int i, int j)
{
        float t = x[i];
        x[i] = x[j];
        x[j] = t;
}

void downheap(float *x, int k, int n)
{
        int j;
        while (2*k <= n) {
                j = 2*k;
                if (j < n && less_than(x[j], x[j+1]))
                        j++;
                if (!less_than(x[k], x[j]))
                        break;
                exchange(x, j, k);
                k = j;
        }
}

void heapsort(int n, float *x)
{
        float *pq = x-1;
        for (int k = n/2; k >= 1; k--)
                downheap(pq, k, n);
        cout << "  make heap: ";
        print_array(n, x);

        while (n > 1) {
                exchange(pq, 1, n);
                downheap(pq, 1, --n);
        }
}
