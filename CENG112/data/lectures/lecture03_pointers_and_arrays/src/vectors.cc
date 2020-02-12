#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
        vector<int> v(2);
        cout << "Initial number of elements is " << v.size() << endl;

        for (int i = 0; i < 5; ++i)
                v.push_back(i);
        cout << "Size after insertions is " << v.size() << endl;

        cout << "Elements are ";
        for (size_t i = 0; i < v.size(); ++i)
                cout << v[i] << " ";
        cout << endl;

        return EXIT_SUCCESS;
}

