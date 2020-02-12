#include "stats.h"

#include <limits>

using std::numeric_limits;

void min_max_of(int n, float values[],
                float &min_value, float &max_value)
{
        min_value = numeric_limits<float>::max();
        max_value = numeric_limits<float>::min();
        for (int i = 0; i < n; ++i) {
                if (values[i] < min_value)
                        min_value = values[i];
                if (values[i] > max_value)
                        max_value = values[i];
        }
}

float average_of(int n, float values[])
{
        float avg = 0.0f;
        for (int i = 0; i < n; ++i)
                avg += values[i];
        avg /= n;
        return avg;
}
