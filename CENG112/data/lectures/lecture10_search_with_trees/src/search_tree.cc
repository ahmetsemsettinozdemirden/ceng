#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <clocale>

#include "student.h"

using namespace std;

void print_student_info(const Student *s);

struct TreeNode {
        Student *student;
        TreeNode *left;
        TreeNode *right;
};

TreeNode *new_node(Student *student);
void free_tree(TreeNode *root);

void add_student(TreeNode *root, Student *student);
Student *search_tree(TreeNode *root, const string &name);
void print_students(const TreeNode *root);

int main(int argc, char **argv)
{
        // Enabling Turkish string comparison: Set LC_COLLATE variable to
        // Turkish locale.  You might also need to enable Turkish support in
        // your OS.  For Ubuntu install the necessary package:
        //   $ sudo apt-get install language-pack-tr
        // and reopen your terminal window.
        setlocale(LC_COLLATE, "tr_TR.UTF-8");

        int n_students = sizeof(ceng112_students) / sizeof(ceng112_students[0]);
        TreeNode *root = new_node(&ceng112_students[0]);
        for (int i = 1; i < n_students; ++i)
                add_student(root, &ceng112_students[i]);

        string name;
        cout << "Enter student name: ";
        getline(cin, name);

        Student *student = search_tree(root, name);
        if (student != 0) {
                print_student_info(student);
        } else {
                print_students(root);
                cerr << "There is no student named " << name << endl;
        }

        free_tree(root);

        return EXIT_SUCCESS;
}

TreeNode *new_node(Student *student)
{
        TreeNode *n = new TreeNode;
        if (n == 0) {
                cerr << "Out of memory!\n";
                exit(EXIT_FAILURE);
        }

        n->student = student;
        n->left = 0;
        n->right = 0;

        return n;
}

void free_tree(TreeNode *root)
{
        if (root == 0)
                return;

        free_tree(root->left);
        free_tree(root->right);
        delete root;
}

void add_student(TreeNode *root, Student *student)
{
        // strcoll is like strcmp but respects language order
        int cmp_res = strcoll(student->name.c_str(), root->student->name.c_str());
        if (cmp_res < 0) {
                if (root->left == 0)
                        root->left = new_node(student);
                else
                        add_student(root->left, student);
        } else {
                if (root->right == 0)
                        root->right = new_node(student);
                else
                        add_student(root->right, student);
        }
}

Student *search_tree(TreeNode *root, const string &name)
{
        if (root == 0)
                return 0;

        // strcoll is like strcmp but respects language order
        int cmp_res = strcoll(name.c_str(), root->student->name.c_str());
        if (cmp_res == 0)
                return root->student;
        else if (cmp_res < 0)
                return search_tree(root->left, name);
        else
                return search_tree(root->right, name);
}

void print_students(const TreeNode *root)
{
        if (root == 0)
                return;

        if (root->left != 0)
                print_students(root->left);

        print_student_info(root->student);

        if (root->right != 0)
                print_students(root->right);
}

void print_student_info(const Student *s)
{
        cout << "id/name: " << s->id << " / " << s->name << endl;
}
