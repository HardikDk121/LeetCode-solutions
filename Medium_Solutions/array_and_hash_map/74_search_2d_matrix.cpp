
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool binarySearch(vector<int> &row, int target, int start, int last) {
    if (start > last)
      return false;

    int mid = (start + last) / 2;
    if (row[mid] == target)
      return true;
    else if (row[mid] < target)
      return binarySearch(row, target, mid + 1, last);
    else
      return binarySearch(row, target, start, mid - 1);
  }

  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    for (vector<int> &row : matrix) {
      bool result = binarySearch(row, target, 0, row.size() - 1);
      if (result)
        return true;
    }
    return false;
  }
};

int main() {
  Solution sol;

  vector<vector<int>> matrix = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

  int target = 3;

  bool found = sol.searchMatrix(matrix, target);

  if (found)
    cout << "Target " << target << " found in matrix ✅" << endl;
  else
    cout << "Target " << target << " not found in matrix ❌" << endl;

  return 0;
}
