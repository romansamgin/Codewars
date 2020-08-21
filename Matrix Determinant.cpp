#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long determinant(const vector<vector<long long>>& matrix) {
    size_t n = matrix.size();
    long long result = 0;
    vector<vector<long long>>minor_(n - 1, vector<long long>(n - 1));
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    }

    for (size_t up_row = 0; up_row < n; up_row++) {
        int im = 0;
        for (size_t i = 1; i < n; i++) {
            int jm = 0;
            for (size_t j = 0; j < n; j++) {
                if (j == up_row) {
                    continue;
                }
                minor_[im][jm] = matrix[i][j];
                jm++;
            }
            im++;
        }
        result = result + (pow(-1, up_row) * matrix[0][up_row] * determinant(minor_));
    }  
    return result;
}