#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> result;
  // Long int so it can store a higher value
  long int sum = 0;
  // Default the range to 10
  int range = 10;

  cout << "Get sum of multiple of 3 and 5 below? (exclusif, default 10)" << endl;
  cin >> range;

  for(int i = 0; i < range; i++) {
    if(i % 3 == 0) {
      result.push_back(i);
    } else if (i % 5 == 0) {
      result.push_back(i);
    }
  }

  // I think I should use the iterator?
  for (int j = 0; j < result.size(); j++) {
    sum += result.at(j);
  }

  cout << sum << endl;

  return 0;
}
