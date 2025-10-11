
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int fib_helper(int n, vector<int> &memo) {
    if (n < 2)
      return n;

    if (memo[n])
      return memo[n];

    memo[n] = fib_helper(n - 1, memo) + fib_helper(n - 2, memo);
    return memo[n];
  }

  int fib(int n) {
    vector<int> memo(n + 1, 0);
    return fib_helper(n, memo);
  }
};

int main() {
  Solution sol;
  int n = 10; // Example input
  cout << "Fibonacci(" << n << ") = " << sol.fib(n) << endl;
  return 0;
}
