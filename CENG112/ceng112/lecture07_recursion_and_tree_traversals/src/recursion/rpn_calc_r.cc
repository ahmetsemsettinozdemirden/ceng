#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#include "stack.h"

using namespace std;
using ceng112::Stack;

enum NodeType {
        NT_ADD,
        NT_SUB,
        NT_MUL,
        NT_DIV,
        NT_NUMBER,
        NT_QUIT
};

struct Node {
        enum NodeType type;
        int value;

        struct Node *left;
        struct Node *right;
};

bool process_line(string &line);
Node *parse_token(const string &token_text);
int eval_tree(Node *tree);
void print_tree_infix(Node *tree);
void free_tree(Node *tree);

int main(int argc, char **argv)
{
        const string prompt = "> ";

        cout << "Reverse Polish Calculator, type q to quit.\n";
        cout << prompt;
        string line;
        while (cin.good() && getline(cin, line)) {
                if (!process_line(line))
                        break;
                cout << prompt;
        }

        return EXIT_SUCCESS;
}

bool process_line(string &line)
{
        Stack<Node *> s;
        istringstream iss(line);

        do {
                string token_text;
                iss >> token_text;

                if (token_text.empty())
                        continue;

                Node *node = parse_token(token_text);
                switch (node->type) {
                case NT_ADD:
                case NT_SUB:
                case NT_MUL:
                case NT_DIV:
                        if (s.size() < 2) {
                                cerr << "Error in expression!\n";
                                exit(EXIT_FAILURE);
                        }
                        node->right = s.pop();
                        node->left  = s.pop();
                        s.push(node);
                        break;
                case NT_NUMBER: s.push(node); break;
                case NT_QUIT:
                        delete node;
                        return false;
                }
        } while (iss);

        Node *parse_tree = s.pop();
        if (!s.is_empty()) {
                cerr << "Error in expression!\n";
                exit(EXIT_FAILURE);
        }

        print_tree_infix(parse_tree);
        cout << " = " << eval_tree(parse_tree) << endl;
        free_tree(parse_tree);

        return true;
}

Node *parse_token(const string &token_text)
{
        Node *n = new Node;
        n->left = 0;
        n->right = 0;

        if (token_text == "+") {
                n->type = NT_ADD;
        } else if (token_text=="-") {
                n->type = NT_SUB;
        } else if (token_text=="*") {
                n->type = NT_MUL;
        } else if (token_text=="/") {
                n->type = NT_DIV;
        } else if (token_text=="q" || token_text=="Q") {
                n->type = NT_QUIT;
        } else {
                n->type = NT_NUMBER;
                char *endptr = 0;
                double d = strtod(token_text.c_str(), &endptr);
                if (token_text.c_str() == endptr) {
                        cerr << "Error in input \"" << token_text << "\"" << endl;
                        exit(EXIT_FAILURE);
                }
                n->value = d;
        }

        return n;
}

int eval_tree(Node *tree)
{
        if (tree->type == NT_NUMBER)
                return tree->value;

        int left_value = eval_tree(tree->left);
        int right_value = eval_tree(tree->right);

        switch (tree->type) {
        case NT_ADD: return left_value + right_value;
        case NT_SUB: return left_value - right_value;
        case NT_MUL: return left_value * right_value;
        case NT_DIV: return left_value / right_value;
        default:
                cerr << "Error in parse tree!\n";
                exit(EXIT_FAILURE);
        }
}

void print_tree_infix(Node *tree)
{
        if (tree->type == NT_NUMBER) {
                cout << tree->value;
                return;
        }

        cout << "(";
        print_tree_infix(tree->left);
        cout << ")";

        switch (tree->type) {
        case NT_ADD: cout << "+"; break;
        case NT_SUB: cout << "-"; break;
        case NT_MUL: cout << "*"; break;
        case NT_DIV: cout << "/"; break;
        default:
                cerr << "Error in parse tree!\n";
                exit(EXIT_FAILURE);
        }

        cout << "(";
        print_tree_infix(tree->right);
        cout << ")";
}

void free_tree(Node *tree)
{
        if (tree == NULL)
                return;

        free_tree(tree->left);
        free_tree(tree->right);
        delete tree;
}
