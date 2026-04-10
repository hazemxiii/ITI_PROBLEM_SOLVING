#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  double calculateTax(vector<vector<int>> &brackets, int income) {
    double tax = 0.0;
    int prev = 0;

    for (auto &b : brackets) {
      int upper = b[0];
      int percent = b[1];
      int taxAmmount = max(0, min(income, upper) - prev);

      tax += taxAmmount * percent;
      prev = upper;
      if (income <= upper)
        break;
    }
    return tax / 100.0;
  }
};

int main() { return 0; }
