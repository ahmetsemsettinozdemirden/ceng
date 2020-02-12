#include <cstdlib>
#include <iostream>
#include <string>

#include "queue.h"

using namespace std;
using ceng112::Queue;

int main(int argc, char** argv)
{
        Queue<int> q;

        for (int i = 0; i < 10; ++i)
                q.enqueue(i);

        while (!q.is_empty())
                cout << q.dequeue() << endl;

        for (int i = 0; i < 10; ++i)
                q.enqueue(i*2);

        while (!q.is_empty()) {
                int k = q.dequeue();
                cout << k << " ";
                if (k > 5)
                        q.clear();
        }
        cout << endl;

        return EXIT_SUCCESS;
}

/// Local Variables:
/// mode: c++
/// compile-command: "make main"
/// End:
