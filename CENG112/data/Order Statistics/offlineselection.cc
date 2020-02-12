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

int partition(int *x, int l, int r, cmp_func cmp);
void quicksort(int *x, int l, int r, cmp_func cmp);

int quickselect(int n, int *x, int k, cmp_func cmp);    // new

int main(int argc, char **argv)
{
    const int N = 10;
    int x[N];
    fill_random(N, x);
    print_array(N, x);

    int k = 3;
    int element = quickselect(N, x, k, &less_than);
    cout << k << "th smallest element: " << element << endl;

    print_array(N, x);

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

int partition(int *x, int l, int r, cmp_func cmp)
{
    cout << "  ";
    print_array(r-l+1, x+l);

    int i = l-1;
    int j = r;
    int v = x[r];

    while (1) {
        while ((*cmp)(x[++i], v))
            ;
        while ((*cmp)(v, x[--j]))
            if (j == l)
                break;
        if (i >= j)
            break;
        exchange(x, i, j);
    }
    exchange(x, i, r);
    return i;
}

void quicksort(int *x, int l, int r, cmp_func cmp)
{
    if (r <= l)
        return;

    int i = partition(x, l, r, cmp);
    quicksort(x, l, i-1, cmp);
    quicksort(x, i+1, r, cmp);
}

// kth (starting from 0) smallest/largest element of array x of size n
int quickselect(int n, int *x, int k, cmp_func cmp) 
{
    int l = 0, r = n - 1;
    while (l < r) {
        // We say arrange x and give me an index i between l and r, such that x[i] is in place.
        int i = partition(x, l, r, cmp); 
        // Now it is guaranteed that x[i] is in place.
        // (Assuming our comparison function is less_than) it means that 
        // for all j < i, x[j] <= x[i] and for all j > i, x[j] >= x[i].
        // In other words, if we sort the array now, x[i] will not change.
        if      (i < k) l = i + 1;  // i < k. We should search the right subarray.
        else if (i > k) r = i - 1;  // i > k. We should search the left subarray.
        else return x[k];           // i = k. We found it!!
    }
    // Remaining subarray is of size 1. So, we have the answer in place.
    return x[k];
}