#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

class ContactItem {
public:
        string name;
        string tel_no;

        bool operator<(const ContactItem& other) { return tel_no < other.tel_no; }
};


void print_array(int n, const ContactItem *x);

template <typename T>
bool is_sorted(int n, T *x);

template <typename T>
bool less_than(T i0, T i1) { return i0 < i1; }

template <typename T>
void exchange(T* x, int i, int j);

template <typename T>
void selection_sort(T *x, int l, int r);

int main(int argc, char *argv[])
{
        const int N = 5;
        ContactItem x[N] = {{"Mehmet", "0543"},
        {"Ali", "0532"},
        {"Fatma", "0533"},
        {"Ayse", "0543"},
        {"Radhakrisha", "0532"}};
        print_array(N, x);

        selection_sort(x, 0, N-1);
        print_array(N, x);

        if (is_sorted(N, x))
                cout << "SORTED" << endl;
        else
                cout << "NOT SORTED" << endl;

        return EXIT_SUCCESS;
}

void print_array(int n, const ContactItem *x)
{
        cout << "[";
        for (int i = 0; i < n; ++i) {
                cout << "(" << x[i].name << ", " << x[i].tel_no << ") ";
        }
        cout << " ]" << endl;
}

template <typename T>
bool is_sorted(int n, T *x)
{
        for (int i = 1; i < n; ++i)
                if (less_than(x[i], x[i-1]))
                        return false;

        return true;
}

template <typename T>
void exchange(T* x, int i, int j)
{
        T t = x[i];
        x[i] = x[j];
        x[j] = t;
}

template <typename T>
void selection_sort(T *x, int l, int r)
{
        for (int i = l; i < r; ++i) {
                int min_id = i;
                for (int j = i+1; j <= r; ++j) {
                        if (less_than(x[j], x[min_id]))
                                min_id = j;
                }
                exchange(x, min_id, i);
        }
}

