#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool validate_battlefield(const vector<vector<int>>& field) {
    int count = 0;
    for (auto& vec : field) {
        count += accumulate(vec.begin(), vec.end(), 0);
    }
    if (count != 20) {
        return false;
    }
    unordered_map<int, int> ships;
    ships[1] = ships[2] = ships[3] = ships[4] = 0;

    vector<vector<int>> field_(12, vector<int>(12));
    for (size_t i = 0; i < 12; ++i) {       
        field_[0][i] = field_[i][0] = field_[11][i] = field_[i][11] = -1;
    }

    for (size_t i = 1; i <= 10; ++i) {
        for (size_t j = 1; j <= 10; ++j) {
            field_[i][j] = field[i - 1][j - 1];
        }
    }


    for (size_t i = 1; i <= 10; ++i) {
        for (size_t j = 1; j <= 10; ++j) {
            int* x = &field_[i][j];
            size_t right_j = j + 1;
            size_t below_i = i + 1;
            int* right = &field_[i][right_j];
            int* below = &field_[below_i][j];

            if (*x == 1) {
                int length = 1;
                //идем вправо
                if (*right == 1) {                   
                    field_[i + 1][j - 1] = -1;
                    field_[i + 1][j] = -1;
                    while (*right == 1) {
                        *right = -1;
                        field_[i + 1][right_j++] = -1;
                        right = &field_[i][right_j];
                        length++;
                    }
                    field_[i][right_j] = -1;
                    field_[i + 1][right_j] = -1;
                    ships[length]++;
                }
                //идем вниз
                else if (*below == 1) {
                    field_[i][j + 1] = -1;
                    field_[i][j - 1] = -1;
                    while (*below == 1) {
                        *below = -1;
                        field_[below_i][j + 1] = -1;
                        field_[below_i++][j - 1] = -1;
                        below = &field_[below_i][j];
                        length++;
                    }
                    field_[below_i][j - 1] = -1;
                    field_[below_i][j] = -1;
                    field_[below_i][j + 1] = -1;
                    ships[length]++;
                }
                else {
                    ships[1]++;
                    field_[i][j + 1] = -1;
                    field_[i + 1][j - 1] = -1;
                    field_[i + 1][j] = -1;
                    field_[i + 1][j + 1] = -1;
                }             
            }
        }
    }

    if (ships[1] == 4 &&
        ships[2] == 3 &&
        ships[3] == 2 &&
        ships[4] == 1) {
        return true;
    }
    else {
        return false;
    }
}
