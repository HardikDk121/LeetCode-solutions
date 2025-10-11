class Solution {
public:
  int climbStairs(int n) {
    int one_steps = 1, two_steps = 1, temp;
    for (int index = 0; index < n - 1; index++) {
      temp = one_steps;
      one_steps = one_steps + two_steps;
      two_steps = temp;
    }
    return one_steps;
  }
};
