#include <cstdlib>
#include <iostream>
#include <string>

#include "intarray.h"

using namespace std;

int main(int argc, char** argv)
{
        IntArray ia;
        cout << "Capacity/Size at creation = " << ia.capacity()
             << "/" << ia.size() << endl;

        for(int i = 0; i < 10; ++i)
                ia.insert(i);
        cout << "Capacity/Size after insertions = " << ia.capacity()
             << "/" << ia.size() << endl;
        cout << "Items: ";
        for(int i = 0; i < ia.size(); ++i)
                cout << ia.item_at(i) << " ";
        cout << endl;

        ia.clear();
        cout << "Capacity/Size after clearing = " << ia.capacity()
             << "/" << ia.size() << endl;

        return EXIT_SUCCESS;
}
