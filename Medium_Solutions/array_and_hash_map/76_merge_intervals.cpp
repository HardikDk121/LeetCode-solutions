#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.size() < 2)
      return intervals;

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    result.push_back(intervals[0]);

    for (vector<int> &interval : intervals) {
      int start = interval[0];
      int end = interval[1];
      int last_end = result.back()[1];

      if (start <= last_end)
        result.back()[1] = max(last_end, end);
      else
        result.push_back(interval);
    }
    return result;
  }
};

int main() {
  Solution sol;

  // Example input
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

  vector<vector<int>> merged = sol.merge(intervals);

  // Output result
  cout << "[\n";
  for (auto &interval : merged) {
    cout << "  [";
    for (int i = 0; i < interval.size(); i++) {
      cout << interval[i];
      if (i != interval.size() - 1)
        cout << ", ";
    }
    cout << "]\n";
  }
  cout << "]\n";

  return 0;
}
