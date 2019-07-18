#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int RLECompare(string& lhs, string& rhs) {
  int p1 = 0, p2 = 0;
  int ps1 = 0, ps2 = 0;

  while (lhs[p1] != 0 && rhs[p2] != 0) {
    while (isdigit(lhs[p1])) {p1++;}
    while (isdigit(rhs[p2])) {p2++;}

    if (isalpha(lhs[p1]) && isalpha(rhs[p2])) {
      if (lhs[p1] == rhs[p2]) {

        string num;
//        num.append(lhs[ps1], rhs[p1 - 1]);//TODO
        num.append(lhs, ps1, p1 - ps1);
        int num1 = atoi(num.c_str());
        num.clear();
        num.append(rhs, ps2, p2 - ps2);
        int num2 = atoi(num.c_str());
        int sub = num1 - num2;
        if (num1 == num2) {
          ps1 = ++p1;
          ps2 = ++p2;
        } else if (num1 > num2) {
          ps2 = ++p2;
          while (isdigit(rhs[p2])) {p2++;}
          string tem;
          tem.append(rhs, ps2, p2 - ps2);
          int n2 = atoi(tem.c_str());
          if (lhs[p1] == rhs[p2] && sub == n2) {
            ps1 = ++p1;
            ps2 = ++p2;
          } else {
            return lhs[p1] - rhs[p2];
          }
        } else { // (num1 < num2)
          ps1 = ++p1;
          while (isdigit(lhs[p1])) {p1++;}
          string tem;
          tem.append(lhs, ps1, p1 - ps1);
          int n2 = atoi(tem.c_str());
          if (lhs[p1] == rhs[p2] && sub == n2) {
            ps1 = ++p1;
            ps2 = ++p2;
          } else {
            return lhs[p1] - rhs[p2];
          }
        }
      } else {
        return lhs[p1] - rhs[p2];
      }
    }
  }
}

int main() {
  std::cout << "Hello, World!" << std::endl;

//  string s1 = "", s3A2B2 = "2A3B";
//  string s1 = "33A", s2 = "31A2A";
//  string s1 = "2A3B", s2 = "3A2B";
  string s1 = "3A2B", s2 = "1B";
//  string s2 = "33A", s1 = "31A2A";
  int res = RLECompare(s1, s2);
  cout << res;
  return 0;
}