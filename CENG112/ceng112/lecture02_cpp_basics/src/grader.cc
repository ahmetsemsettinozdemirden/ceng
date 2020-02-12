#include <cstdlib>
#include <iostream>

#include "stats.h"

using namespace std;

const int MAX_N_STUDENTS = 500;
int read_grades(float grades[], int max_n_students);

int main(int argc, char** argv)
{
        float grades[MAX_N_STUDENTS];

        int n = read_grades(grades, MAX_N_STUDENTS);
        cout << "There are " << n << " students" << endl;

        float min_grade;
        float max_grade;
        min_max_of(n, grades, min_grade, max_grade);
        cout << "Minimum grade is " << min_grade << endl;
        cout << "Maximum grade is " << max_grade << endl;

        cout << "Average grade is " << average_of(n, grades) << endl;

        return EXIT_SUCCESS;
}

int read_grades(float grades[], int max_n_students)
{
        int n = 0;
        while (n < max_n_students) {
                cin >> grades[n];
                if (!cin.good())
                        break;
                ++n;
        }
        return n;
}
