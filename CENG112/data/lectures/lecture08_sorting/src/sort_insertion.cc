#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

typedef bool (*cmp_func)(int i0, int i1);
bool less_than(int i0, int i1) { return i0 < i1; }
bool greater_than(int i0, int i1) { return i0 > i1; }

void fill_random(int n, int *x);
void print_array(int n, const int *x);
bool is_sorted(int n, const int *x, cmp_func cmp);
void exchange(int *x, int i, int j);

void insertion_sort(int *x, int l, int r, cmp_func cmp);
void insertion_sort2(int *x, int l, int r, cmp_func cmp);

int main(int argc, char **argv)
{
        const int N = 10;
        int x[N];
        fill_random(N, x);
        print_array(N, x);

        insertion_sort2(x, 0, N-1, &greater_than);
        print_array(N, x);

        if (is_sorted(N, x, &greater_than))
                cout << "SORTED\n";
        else
                cout << "NOT SORTED\n";

        return EXIT_SUCCESS;
}

void fill_random(int n, int *x)
{
        const int M = 100;

        srand(time(0));

        for (int i = 0; i < n; ++i)
                x[i] = rand() % M;
}

void print_array(int n, const int *x)
{
        cout << "[";
        for (int i = 0; i < n; ++i) {
                cout << setw(3) << x[i];
        }
        cout << " ]\n";
}

bool is_sorted(int n, const int *x, cmp_func cmp)
{
        for (int i = 1; i < n; ++i)
                if ((*cmp)(x[i], x[i-1]))
                        return false;

        return true;
}

void exchange(int *x, int i, int j)
{
        int t = x[i];
        x[i] = x[j];
        x[j] = t;
}

void insertion_sort(int *x, int l, int r, cmp_func cmp)
{
        for (int i = l+1; i <= r; ++i) {
                for (int j = i; j > l; --j)
                        if ((*cmp)(x[j], x[j-1]))
                                exchange(x, j, j-1);
                cout << "  ";
                print_array(r-l+1, x+l);
        }
}

void insertion_sort2(int *x, int l, int r, cmp_func cmp)
{
        for (int i = r; i > l; --i)
                if ((*cmp)(x[i], x[i-1]))
                        exchange(x, i, i-1);

        for (int i = l+2; i <= r; ++i) {
                int j = i;
                int v = x[i];
                while((*cmp)(v, x[j-1])) {
                        x[j] = x[j-1];
                        --j;
                }
                x[j] = v;

                cout << "  ";
                print_array(r-l+1, x+l);
        }
}
