#include <cstdlib>
#include "contact_item.h"

using namespace std;

int main(int argc, char** argv)
{
        ContactItem c;
        c.read();
        c.print();
        return EXIT_SUCCESS;
}
