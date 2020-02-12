#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
        const char *s1 = "Hello ";
        const char *s2 = "World!";

        char *s = new char[strlen(s1)+strlen(s2)+1];
        strcpy(s, s1);
        strcat(s, s2);
        cout << s << endl;
        delete [] s;

        return EXIT_SUCCESS;
}

/// Local Variables:
/// mode: c++
/// compile-command: "make cstrings"
/// End:
