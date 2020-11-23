/////////////////////////////////////////////////////
//https://www.codewars.com/kata/58b16300a470d47498000811

#include <cmath>

using namespace std;

long double countDivisors(int n) {
    long double sum = 0;
    long double sq = int(sqrt(n));
    for (int i = 1; i < sq + 1; ++i) {
        sum += n / i;
    }
    return 2 * (sum + sq - sq * (sq + 1) * 0.5) - sq;
}
