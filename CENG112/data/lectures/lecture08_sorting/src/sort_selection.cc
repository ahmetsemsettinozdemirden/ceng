#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

int less_than(int i0, int i1) { return i0 < i1; }
void fill_random(int n, int *x);
void print_array(int n, const int *x);
bool is_sorted(int n, int *x);
void exchange(int *x, int i, int j);

void selection_sort(int *x, int l, int r);

int main(int argc, char *argv[])
{
        const int N = 10;
        int x[N];
        fill_random(N, x);
        print_array(N, x);

        selection_sort(x, 0, N-1);
        print_array(N, x);

        if (is_sorted(N, x))
                cout << "SORTED" << endl;
        else
                cout << "NOT SORTED" << endl;

        return EXIT_SUCCESS;
}

void fill_random(int n, int *x)
{
        const int M = 1000;

        srand(time(0));

        for (int i = 0; i < n; ++i)
                x[i] = rand() % M;
}

void print_array(int n, const int *x)
{
        cout << "[";
        for (int i = 0; i < n; ++i) {
                cout << setw(5) << x[i];
        }
        cout << " ]" << endl;
}

bool is_sorted(int n, int *x)
{
        for (int i = 1; i < n; ++i)
                if (less_than(x[i], x[i-1]))
                        return false;

        return true;
}

void exchange(int *x, int i, int j)
{
        int t = x[i];
        x[i] = x[j];
        x[j] = t;
}

void selection_sort(int *x, int l, int r)
{
        for (int i = l; i < r; ++i) {
                int min_id = i;
                for (int j = i+1; j <= r; ++j) {
                        if (less_than(x[j], x[min_id]))
                                min_id = j;
                }
                exchange(x, min_id, i);
                cout << "  ";
                print_array(r-l+1, x+l);
        }
}
