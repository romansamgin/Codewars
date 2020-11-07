////////////////////////////////////////////////
//https://www.codewars.com/kata/5511b2f550906349a70004e1


#include <string>
#include <vector>

using namespace std;

int last_digit(const string &str1, const string &str2) {
  
  if ((str1 == "0" || (str1 != "0")) && (str2 == "0")) return 1;
  
  int last2_str2 = 0;
  if (str2.size() >= 2)
  {
      last2_str2 = (*(str2.end() - 2) - '0') * 10 + *(str2.end() - 1) - '0'; 
  }
  else
  {
      last2_str2 = *(str2.end() - 1) - '0';
  }  
  int last1_str1 = *(str1.end() - 1) - '0';
  vector<int>ans{}; 
  int  d = last1_str1;  
  for(int i = 0; i < 4; ++i)
  {
      ans.push_back(d);
      d = (d * last1_str1) % 10;
  }  
  if ((last2_str2 % 4) == 0)
        return ans[3];
  return ans[(last2_str2 % 4) - 1];
}
