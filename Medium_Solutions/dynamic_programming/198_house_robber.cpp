#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int MaxMemo(vector<int> &nums, vector<int> &memo, int index) {
    if (index < 0)
      return 0;
    if (memo[index] != -1)
      return memo[index];

    int take = MaxMemo(nums, memo, index - 2) + nums[index];
    int not_take = MaxMemo(nums, memo, index - 1);
    memo[index] = max(take, not_take);
    return memo[index];
  }

  int rob(vector<int> &nums) {
    vector<int> memo(nums.size(), -1);
    return MaxMemo(nums, memo, nums.size() - 1);
  }
};

int main() {
  Solution sol;
  vector<int> houses = {2, 7, 9, 3, 1};

  cout << "Maximum amount that can be robbed: " << sol.rob(houses) << endl;

  return 0;
}
