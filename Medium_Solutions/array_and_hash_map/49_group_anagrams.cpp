#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> res;
    for (const string &str : strs) {
      vector<int> count(26, 0);
      for (char ch : str)
        count[ch - 'a']++;
      string key = to_string(count[0]);
      for (int index = 1; index < 26; ++index)
        key += ',' + to_string(count[index]);
      res[key].push_back(str);
    }
    vector<vector<string>> result;
    for (const pair<string, vector<string>> &p : res)
      result.push_back(p.second);
    return result;
  }
};

int main() {
  Solution sol;
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

  vector<vector<string>> grouped = sol.groupAnagrams(strs);

  cout << "[\n";
  for (auto &group : grouped) {
    cout << "  [ ";
    for (auto &word : group)
      cout << "\"" << word << "\" ";
    cout << "]\n";
  }
  cout << "]\n";

  return 0;
}
