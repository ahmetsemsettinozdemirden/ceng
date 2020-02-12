#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>

#include "student.h"

using namespace std;

void print_student_info(const Student *s);
Student *linear_search_by_name(string name);
Student *binary_search_by_id(unsigned long id);

int main(int argc, char **argv)
{
        if (argc < 2) {
                cerr << "Usage: " << argv[0] << " <name|id>\n";
                return EXIT_FAILURE;
        }

        if (strcmp(argv[1], "name") == 0) {
                string name;
                cout << "Enter student name: ";
                getline(cin, name);

                const Student *student = linear_search_by_name(name);
                if (student != 0)
                        print_student_info(student);
                else
                        cerr << "There is no student named " << name << endl;
        } else if (strcmp(argv[1], "id") == 0) {
                unsigned long id;
                cout << "Enter student id: ";
                cin >> id;

                const Student *student = binary_search_by_id(id);
                if (student != 0)
                        print_student_info(student);
                else
                        cerr << "There is no student with id " << id << endl;
        } else {
                cerr << "Unknown search option " << argv[1] << endl;
                return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
}

Student *linear_search_by_name(string name)
{
        Student *s = 0;

        int n_students = sizeof(ceng112_students) / sizeof(*ceng112_students);
        for (int i = 0; i < n_students; ++i)
                if (name == ceng112_students[i].name) {
                        s = &ceng112_students[i];
                        break;
                }

        return s;
}

Student *binary_search_by_id(unsigned long id)
{
        Student *s = 0;

        int n_students = sizeof(ceng112_students) / sizeof(*ceng112_students);
        int i = 0;
        int j = n_students-1;

        while (i <= j) {
                int k = (i+j)/2;
                if (id == ceng112_students[k].id) {
                        s = &ceng112_students[k];
                        break;
                } else if (id > ceng112_students[k].id) {
                        i = k+1;
                } else {
                        j = k-1;
                }
        }

        return s;
}

void print_student_info(const Student *s)
{
        cout << "id/name: " << s->id << " / " << s->name << endl;
}

