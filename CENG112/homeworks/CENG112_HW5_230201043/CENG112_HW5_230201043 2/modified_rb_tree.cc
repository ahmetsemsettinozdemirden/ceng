#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <clocale>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

struct Contact{
    unsigned long id;
    string name;
    string surname;
    string telephone;
};

Contact contacts[10000];

void readContacts();

const int RBT_BLACK = 0;
const int RBT_RED = 1;

void print_contact_info(int contact_index);

struct RBTreeNode {
    int contact_idx;

    int color;
    RBTreeNode *left;
    RBTreeNode *right;
};

RBTreeNode *new_node(int contact_idx, int color);
void free_tree(RBTreeNode *root);

RBTreeNode *add_contact(RBTreeNode *root, int contact_idx, int sw, bool searchForName);
int search_tree(RBTreeNode *root, const string &name_surname, bool searchForName);
void print_contacts(const RBTreeNode *root);

static RBTreeNode z = {
    .contact_idx = -1,
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

    readContacts();

    string l;
    cout << "Do you want to search name or surname: ";
    getline(cin, l);

    bool searchForName = (l == "name");
    
    if(l != "name" && l != "surname"){
        cerr << "Invalid input! Please type \'name\' or \'surname\'" << endl;
        return 1;
    }

    int n_contacs = sizeof(contacts) / sizeof(contacts[0]);
    RBTreeNode *root = &z;
    for (int i = 1; i < n_contacs; ++i) {
            root = add_contact(root, i, 0, searchForName);
            root->color = RBT_BLACK;
    }

    string name_surname;
    cout << "Enter contact " << (searchForName ? "name" : "surname") << " : ";
    getline(cin, name_surname);

    int contact_idx = search_tree(root, name_surname, searchForName);
    if (contact_idx >= 0) {
            print_contact_info(contact_idx);
    } else {
            print_contacts(root);
            cerr << "There is no contact named " << name_surname << endl;
    }

    free_tree(root);

    return EXIT_SUCCESS;
}

void readContacts(){

    vector<string> v;
    string l;
    ifstream f;
    f.open("contacts.txt");

    if(f.is_open()){

        while(getline(f, l)){
            v.push_back(l);
        }

        int v_size = v.size();

        for(int i = 0; i < v_size/3; i++){

            Contact c;

            c.telephone = v.back();
            v.pop_back();
            c.surname = v.back();
            v.pop_back();
            c.name = v.back();
            v.pop_back();
            c.id = 100000 + i;

            contacts[i] = c;
        }

        f.close();
    }else{
        cerr << "Unable to open file" << endl;
    }

}

RBTreeNode *new_node(int contact_idx, int color)
{
        RBTreeNode *n = new RBTreeNode;
        if (n == 0) {
                cerr << "Out of memory!\n";
                exit(EXIT_FAILURE);
        }

        n->contact_idx = contact_idx;
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

RBTreeNode *add_contact(RBTreeNode *root, int contact_idx, int sw, bool searchForName)
{
        if (root == &z)
                return new_node(contact_idx, RBT_RED);

        if (root->left->color == RBT_RED
            && root->right->color == RBT_RED) {
                root->left->color = RBT_BLACK;
                root->right->color = RBT_BLACK;
                root->color = RBT_RED;
        }

        /* // strcoll is like strcmp but respects language order */
        int cmp_res = strcoll(searchForName ? contacts[contact_idx].name.c_str() : contacts[contact_idx].surname.c_str(), searchForName ? contacts[root->contact_idx].name.c_str() : contacts[root->contact_idx].surname.c_str());
        if (cmp_res < 0) {
                root->left = add_contact(root->left, contact_idx, 0, searchForName);
                if (root->color == RBT_RED && root->left->color == RBT_RED && sw)
                        root = rotate_right(root);
                if (root->left->color == RBT_RED && root->left->left->color == RBT_RED) {
                        root = rotate_right(root);
                        root->color = RBT_BLACK;
                        root->right->color = RBT_RED;
                }
        } else {
                root->right = add_contact(root->right, contact_idx, 1, searchForName);
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

int search_tree(RBTreeNode *root, const string &name_surname, bool searchForName)
{
        if (root == &z)
                return -1;

        // strcoll is like strcmp but respects language order

        int cmp_res = strcoll(name_surname.c_str(), (searchForName ? contacts[root->contact_idx].name.c_str() : contacts[root->contact_idx].surname.c_str()));
        if (cmp_res == 0)
                return root->contact_idx;
        else if (cmp_res < 0)
                return search_tree(root->left, name_surname, searchForName);
        else
                return search_tree(root->right, name_surname, searchForName);
}

void print_contacts(const RBTreeNode *root)
{
        if (root == &z)
                return;

        if (root->left != &z)
                print_contacts(root->left);

        print_contact_info(root->contact_idx);

        if (root->right != &z)
                print_contacts(root->right);
}

void print_contact_info(int contact_idx)
{
        cout << "id/contact: " << contacts[contact_idx].id << " / " << setw(15) << contacts[contact_idx].name << " " << setw(15) << contacts[contact_idx].surname << " " << setw(15) << contacts[contact_idx].telephone << endl;
}

