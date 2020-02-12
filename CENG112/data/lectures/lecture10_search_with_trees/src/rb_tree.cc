#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <clocale>

#include "student.h"

using namespace std;

const int RBT_BLACK = 0;
const int RBT_RED = 1;

void print_student_info(int student_index);

struct RBTreeNode {
        int student_idx;

        int color;
        RBTreeNode *left;
        RBTreeNode *right;
};

RBTreeNode *new_node(int student_idx, int color);
void free_tree(RBTreeNode *root);

RBTreeNode *add_student(RBTreeNode *root, int student_idx, int sw);
int search_tree(RBTreeNode *root, const string &name);
void print_students(const RBTreeNode *root);

static RBTreeNode z = {
        .student_idx = -1,
        .color = RBT_BLACK,
        .left = &z,
        .right = &z
};

int main(int argc, char **argv)
{
        // Enabling Turkish string comparison: Set LC_COLLATE variable to
        // Turkish locale.  You might also need to enable Turkish support in
        // your OS.  For Ubuntu install the necessary package:
        //   $ sudo apt-get install language-pack-tr
        // and reopen your terminal window.
        setlocale(LC_COLLATE, "tr_TR.UTF-8");

        int n_students = sizeof(ceng112_students) / sizeof(ceng112_students[0]);
        RBTreeNode *root = &z;
        for (int i = 1; i < n_students; ++i) {
                root = add_student(root, i, 0);
                root->color = RBT_BLACK;
        }

        string name;
        cout << "Enter student name: ";
        getline(cin, name);

        int student_idx = search_tree(root, name);
        if (student_idx >= 0) {
                print_student_info(student_idx);
        } else {
                print_students(root);
                cerr << "There is no student named " << name << endl;
        }

        free_tree(root);

        return EXIT_SUCCESS;
}

RBTreeNode *new_node(int student_idx, int color)
{
        RBTreeNode *n = new RBTreeNode;
        if (n == 0) {
                cerr << "Out of memory!\n";
                exit(EXIT_FAILURE);
        }

        n->student_idx = student_idx;
        n->left = &z;
        n->right = &z;
        n->color = color;

        return n;
}

void free_tree(RBTreeNode *root)
{
        if (root == &z)
                return;

        free_tree(root->left);
        free_tree(root->right);
        delete root;
}

RBTreeNode *rotate_left(RBTreeNode *n)
{
        RBTreeNode *x = n->right;
        n->right = x->left;
        x->left = n;
        return x;
}

RBTreeNode *rotate_right(RBTreeNode *n)
{
        RBTreeNode *x = n->left;
        n->left = x->right;
        x->right = n;
        return x;
}

RBTreeNode *add_student(RBTreeNode *root, int student_idx, int sw)
{
        if (root == &z)
                return new_node(student_idx, RBT_RED);

        if (root->left->color == RBT_RED
            && root->right->color == RBT_RED) {
                root->left->color = RBT_BLACK;
                root->right->color = RBT_BLACK;
                root->color = RBT_RED;
        }

        /* // strcoll is like strcmp but respects language order */
        int cmp_res = strcoll(ceng112_students[student_idx].name.c_str(), ceng112_students[root->student_idx].name.c_str());
        if (cmp_res < 0) {
                root->left = add_student(root->left, student_idx, 0);
                if (root->color == RBT_RED && root->left->color == RBT_RED && sw)
                        root = rotate_right(root);
                if (root->left->color == RBT_RED && root->left->left->color == RBT_RED) {
                        root = rotate_right(root);
                        root->color = RBT_BLACK;
                        root->right->color = RBT_RED;
                }
        } else {
                root->right = add_student(root->right, student_idx, 1);
                if (root->color == RBT_RED && root->right->color == RBT_RED && !sw)
                        root = rotate_left(root);
                if (root->right->color == RBT_RED && root->right->right->color == RBT_RED) {
                        root = rotate_left(root);
                        root->color = RBT_BLACK;
                        root->left->color = RBT_RED;
                }
        }

        return root;
}

int search_tree(RBTreeNode *root, const string &name)
{
        if (root == &z)
                return -1;

        // strcoll is like strcmp but respects language order
        int cmp_res = strcoll(name.c_str(), ceng112_students[root->student_idx].name.c_str());
        if (cmp_res == 0)
                return root->student_idx;
        else if (cmp_res < 0)
                return search_tree(root->left, name);
        else
                return search_tree(root->right, name);
}

void print_students(const RBTreeNode *root)
{
        if (root == &z)
                return;

        if (root->left != &z)
                print_students(root->left);

        print_student_info(root->student_idx);

        if (root->right != &z)
                print_students(root->right);
}

void print_student_info(int student_idx)
{
        cout << "id/name: " << ceng112_students[student_idx].id << " / " << ceng112_students[student_idx].name << endl;
}
