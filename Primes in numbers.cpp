//////////////////////////////////////////
//https://www.codewars.com/kata/54d512e62a5e54c96200019e/

#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    int i = 2;
    while (i * i <= n) {
        if (!(n % i))
            return false;
        i++;
    }
    return true;
}


int deg(int n, int p) {
    if (n % p) {
        return 0;
    }
    int k = 0;
    while (!(n % p)) {
        k++;
        n /= p;
    }
    return k;
}

class PrimeDecomp {
public:
    static std::string factors(int lst);
};

string PrimeDecomp::factors(int lst) {
    if (isPrime(lst)) {
        return '(' + to_string(lst) + ')';
    }
    vector<pair<int, int>>v;    
    if (!(lst % 2)) {             
        v.push_back({2, deg(lst, 2)});       
    }      
    vector<int>ans{};
    for(int i = 3; i < lst / 2 + 1; i += 2) {
        if (!(lst % i))
            ans.push_back(i);
    }
      
    for (auto i : ans) {                
        if (isPrime(i)) {
            v.push_back({i, deg(lst, i)});
        }          
    }

    string res = "";
    for (const auto& temp : v) {
        if (temp.second == 1) {
            res += '(' + to_string(temp.first) + ')';
        }
        else {
            res += '(' + to_string(temp.first) + "**" + to_string(temp.second) + ')';
        }
    }
    return res;
}
