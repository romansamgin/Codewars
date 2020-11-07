///////////////////////////////////////////////////////////
//https://www.codewars.com/kata/5886e082a836a691340000c3

#include <cmath>

using namespace std;


struct Point {
    double x, y;

    Point() = default;
    Point(double x_, double y_)   :   x(x_), y(y_) 
    {}
    
};

long long rectangle_rotation(int a, int b) {
    if (b > a) {
        swap(a, b);
    }

    Point top, right, low, left;
    double big_hyp = b;
    top.x = 0;
    top.y = sqrt(pow(big_hyp, 2) / 2);

    double small_hyp = (a - big_hyp) / 2;
    top.x += sqrt(pow(small_hyp, 2) / 2);
    top.y += sqrt(pow(small_hyp, 2) / 2);
    right = Point(top.y, top.x);
    low = Point(-top.x, -top.y);
    left = Point(low.y, low.x);

    double oy_a = sqrt(pow(big_hyp, 2) / 2);
    double oy_b = (a / 2.0) * sqrt(2);
    double f_separ = top.x;
    double g_separ = low.x;

    auto high_func = [&](int x) {
        if (x <= f_separ) {
            return x + oy_a;
        }
        else {
            return -x + oy_b;
        }
    };

    auto low_func = [&](int x) {
        if (x <= g_separ) {
            return -x - oy_b;
        }
        else {
            return x - oy_a;
        }
    };

    long long result = 0;
    for (int x = static_cast<int>(left.x); 
        x <= static_cast<int>(right.x); 
        ++x) {
        long long low = ceil(low_func(x));
        long long high = floor(high_func(x));
        result += high - low + 1;
    }
    return result;
}
