#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    cost.push_back(0);
    int size = cost.size();
    for (int index = size - 3; index > -1; index--)
      cost[index] += min(cost[index + 1], cost[index + 2]);
    return std::min(cost[0], cost[1]);
  }
};
