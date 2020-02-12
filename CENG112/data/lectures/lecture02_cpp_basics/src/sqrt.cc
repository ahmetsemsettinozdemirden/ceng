#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

const double THRESHOLD = 1e-4;

double sqrt_newton(double y);

int main(int argc, char** argv)
{
        for (double x = 0.0; x < 10.0; x += 1.0) {
                double c_sqrt = sqrt(x);
                double n_sqrt = sqrt_newton(x);
                cout << x << " " << c_sqrt << " " << n_sqrt << endl;
        }

        return EXIT_SUCCESS;
}

bool sqrt_good_enough(double guess, double y)
{
        return fabs(guess*guess-y) < THRESHOLD;
}

double sqrt_improve(double guess, double y)
{
        return (guess + y/guess)/2.0;
}

double sqrt_newton(double y)
{
        double guess = 1.0;
        while (!sqrt_good_enough(guess, y))
                guess = sqrt_improve(guess, y);
        return guess;
}
