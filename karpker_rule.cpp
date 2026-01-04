#include <iostream>
#include <vector>
using namespace std;

int main() {
  int number;
  cout << "enter a 4 digit number :";
  cin >> number;
  vector<int> vec;
  int prev = number % 10;
  for (int index = 0; number % 10 != number; number = number / 10) {
    if (prev != number % 10) {
      cout << "does follow rule";
      return 0;
    }
  }
  cout << "does not follow rule";

  return 0;
}
