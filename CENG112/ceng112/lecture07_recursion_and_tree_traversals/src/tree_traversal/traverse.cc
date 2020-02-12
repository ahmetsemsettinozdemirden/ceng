#include <cstdlib>
#include <iostream>
#include <string>

#include "stack.h"
#include "queue.h"

using namespace std;
using ceng112::Stack;
using ceng112::Queue;

struct TreeNode {
        char label;

        struct TreeNode *left;
        struct TreeNode *right;
};

void traverse_preorder(TreeNode *root);
void traverse_inorder(TreeNode *root);
void traverse_postorder(TreeNode *root);

void traverse_preorder_iter(TreeNode *root);
void traverse_level_order_iter(TreeNode *root);

int main(int argc, char **argv)
{
        TreeNode D = { .label = 'D', .left = 0, .right = 0 };
        TreeNode E = { .label = 'E', .left = 0, .right = 0 };
        TreeNode C = { .label = 'C', .left = &D, .right = &E };
        TreeNode F = { .label = 'F', .left = 0, .right = 0 };
        TreeNode B = { .label = 'B', .left = &C, .right = &F };
        TreeNode I = { .label = 'I', .left = 0, .right = 0 };
        TreeNode J = { .label = 'J', .left = 0, .right = 0 };
        TreeNode H = { .label = 'H', .left = &I, .right = &J };
        TreeNode G = { .label = 'G', .left = 0, .right = &H };
        TreeNode A = { .label = 'A', .left = &B, .right = &G };

        cout << "Preorder: "; traverse_preorder(&A); cout << endl;
        cout << "Inorder: "; traverse_inorder(&A); cout << endl;
        cout << "Postorder: "; traverse_postorder(&A); cout << endl;

        cout << "Preorder (Iterative): "; traverse_preorder_iter(&A); cout << endl;
        cout << "Level-order (Iterative): "; traverse_level_order_iter(&A); cout << endl;

        return EXIT_SUCCESS;
}

void traverse_preorder(TreeNode *root)
{
        if (root == 0)
                return;

        cout << root->label;
        traverse_preorder(root->left);
        traverse_preorder(root->right);
}

void traverse_inorder(TreeNode *root)
{
        if (root == 0)
                return;

        traverse_inorder(root->left);
        cout << root->label;
        traverse_inorder(root->right);
}

void traverse_postorder(TreeNode *root)
{
        if (root == 0)
                return;

        traverse_postorder(root->left);
        traverse_postorder(root->right);
        cout << root->label;
}

void traverse_preorder_iter(TreeNode *root)
{
        Stack<TreeNode *> s;

        s.push(root);
        while (!s.is_empty()) {
                TreeNode *n = s.pop();

                cout << n->label;
                if (n->right != 0) s.push(n->right);
                if (n->left != 0) s.push(n->left);
        }
}

void traverse_level_order_iter(TreeNode *root)
{
        Queue<TreeNode *> q;

        q.enqueue(root);
        while (!q.is_empty()) {
                TreeNode *n = q.dequeue();

                cout << n->label;
                if (n->left != 0) q.enqueue(n->left);
                if (n->right != 0) q.enqueue(n->right);
        }
}
