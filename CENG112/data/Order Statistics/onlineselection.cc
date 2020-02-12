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

void build_heap(int n, float *x);   // new
void online_selection(int k);       // new

int main(int argc, char **argv)
{
    int k = 1;
    online_selection(k);

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

// Build a valid (max) heap.
// Note that we have the same code in heapsort.
void build_heap(int n, float *x)
{
    float *pq = x-1;
    for (int k = n/2; k >= 1; k--)
        downheap(pq, k, n);
}

void online_selection(int k)
{
    float *x = new float[k + 1];
    int count = 0;
    float e;

    while (1) {
        cout << "Enter next element: ";
        cin >> e;
 
        if (count < k) { // We do not have enough numbers yet.
            // Note that this condition holds for only several numbers at the beginning.
            x[count] = e;
            count++;
        }
        else { // We have enough numbers to find the kth smallest number.
            if (count == k) { // We need to build the heap.
                // Note that this condition holds only for once.
                x[count] = e;
                build_heap(k + 1, x); // No need to sort. We only need to have the kth smallest element in the root.
            } 
            else if (e < x[0]) { // We need to update the heap.
                // Note that after several numbers, we are only interested in this part (forever).
                x[0] = e;
                float *pq = x-1;
                downheap(pq, 1, k + 1);
            }
            // else do nothing. If e >= x[0] then we ignore e.
            cout << k << "th smallest element: " << x[0] << endl; // kth smallest element is in the root.
            count++;
        }
    }
}