#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>
#include <vector>

using namespace std;

template <typename T>
class PQueue
{
public:
        PQueue() { m_elements.resize(1); }
        void insert(const T&item);
        T delmax();
        bool is_empty() const;
        void print() const;

private:
        vector<T> m_elements;
};

int main(int argc, char **argv)
{
        srand(time(0));

        PQueue<float> pq;
        pq.print();

        for (int i = 0; i < 5; ++i) {
                float x = (rand() % 100) / 10.0f;
                cout << "Inserting " << x << endl;
                pq.insert(x);
        }
        cin.get();
        pq.print();

        for (int i = 0; i < 3; ++i) {
                float x = (rand() % 100) / 10.0f;
                cout << "Inserting " << x << endl;
                pq.insert(x);
        }
        cin.get();
        pq.print();

        cout << "Popped max " << pq.delmax() << endl;
        cin.get();
        pq.print();

        cout << "Popped max " << pq.delmax() << endl;
        cin.get();
        pq.print();

        for (int i = 0; i < 2; ++i) {
                float x = (rand() % 100) / 10.0f;
                cout << "Inserting " << x << endl;
                pq.insert(x);
        }
        cin.get();
        pq.print();

        return EXIT_SUCCESS;
}

template <typename T>
void exchange(vector<T> &x, int i, int j)
{
        T t = x[i];
        x[i] = x[j];
        x[j] = t;
}

template <typename T>
void downheap(vector<T> &x, int k, int n)
{
        int j;
        while (2*k <= n) {
                j = 2*k;
                if (j < n && (x[j] < x[j+1]))
                        j++;
                if (!(x[k] < x[j]))
                        break;
                exchange(x, j, k);
                k = j;
        }
}

template <typename T>
void upheap(vector<T> &x, int k)
{
        while (k > 1 && (x[k/2] < x[k])) {
                exchange(x, k, k/2);
                k = k/2;
        }
}

template <typename T>
void PQueue<T>::insert(const T& item)
{
        m_elements.push_back(item);
        upheap(m_elements, m_elements.size()-1);
}

template <typename T>
T PQueue<T>::delmax()
{
        if (is_empty()) {
                cerr << "Can not delete maximum in empty priority queue!" << endl;
                exit(EXIT_FAILURE);
        }

        exchange(m_elements, 1, m_elements.size()-1);
        downheap(m_elements, 1, m_elements.size()-2);
        T max_elem = m_elements.back();
        m_elements.pop_back();
        return max_elem;
}

template <typename T>
bool PQueue<T>::is_empty() const
{
        return m_elements.size() == 1;
}

template <typename T>
void PQueue<T>::print() const
{
        int n_slots = 15;
        cout << "  0";
        for (int i = 1; i < n_slots; ++i)
                cout << " " << setw(5) << i;
        cout << "\n";

        cout << "[ -";
        for (int i = 1; i < m_elements.size(); ++i)
                cout << " " << setw(5) << setprecision(2) << m_elements[i];
        for (int i = m_elements.size(); i < n_slots; ++i)
                cout << " " << setw(5) << '-';
        cout << "]\n";
}
