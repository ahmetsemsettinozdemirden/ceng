#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#include "stack_linked_list.h"

using namespace std;
using ceng112::Stack;

bool process_line(string &line, Stack<double> &s);

int main(int argc, char** argv)
{
        const string prompt = "> ";
        Stack<double> s;

        cout << "Reverse Polish Calculator, type q to quit.\n";
        cout << prompt;
        string line;
        while (cin.good() && getline(cin, line)) {
                if (!process_line(line, s))
                        break;
                cout << prompt;
        }

        return EXIT_SUCCESS;
}

inline void add(Stack<double> &s)
{
        s.push(s.pop() + s.pop());
}

inline void subtract(Stack<double> &s)
{
        double a = s.pop();
        s.push(s.pop() - a);
}

inline void multiply(Stack<double> &s)
{
        s.push(s.pop() * s.pop());
}

inline void divide(Stack<double> &s)
{
        double d0 = s.pop();
        s.push(s.pop() / d0);
}

bool process_line(string &line, Stack<double> &s)
{
        istringstream iss(line);

        do {
                string token;
                iss >> token;
                if (token.empty()) {
                        break;
                } if (token == "+") {
                        add(s);
                } else if (token == "-") {
                        subtract(s);
                } else if (token == "*") {
                        multiply(s);
                } else if (token == "/") {
                        divide(s);
                } else if (token == "q" || token == "Q") {
                        return false;
                } else {
                        char *endptr;
                        double d = strtod(token.c_str(), &endptr);
                        if (token.c_str() == endptr) {
                                cerr << "Error in input \"" << token << "\"" << endl;
                                return false;
                        }
                        s.push(d);
                }
        } while (iss);

        if (s.size() != 1)
                cerr << "Malformed input!" << endl;
        else
                cout << "The result is " << s.pop() << endl;

        return true;
}

