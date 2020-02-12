#include <cstdlib>
#include <iostream>
#include <string>

#include "array.h"

using namespace std;
using ceng112::Array;

int main(int argc, char** argv)
{
        cout << "Integer Array Test" << endl;
        Array<int> ia;
        cout << "Capacity/Size at creation = " << ia.capacity()
             << "/" << ia.size() << endl;

        for(int i = 0; i < 10; ++i)
                ia.insert(i);
        cout << "Capacity/Size after insertions = " << ia.capacity()
             << "/" << ia.size() << endl;
        cout << "Items: ";
        for(size_t i = 0; i < ia.size(); ++i)
                cout << ia[i] << " ";
        cout << endl;

        ia.clear();
        cout << "Capacity/Size after clearing = " << ia.capacity()
             << "/" << ia.size() << endl;

        cout << "Float Array Test" << endl;
        Array<float> fa;
        cout << fa << endl;

        for(float i = 0.1f; i < 10.1f; ++i)
                fa.insert(i);
        cout << fa << endl;

        fa.clear();
        cout << fa << endl;

        return EXIT_SUCCESS;
}
