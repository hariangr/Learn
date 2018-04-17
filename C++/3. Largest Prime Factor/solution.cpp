#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num) {
  vector<int> factor;

  for (int i = 1; i <= num; i++) {
    if (num % i == 0) {
        factor.push_back(i);
    }
  }

  return (factor.size() == 2);
}

vector<int> findFactors(int num) {
  vector<int> res;

  for (int i = 1; i<= num; i++) {
    if (num % i == 0) {
        res.push_back(i);
        //cout << i << endl;
    }
  }

  return res;
}

vector<int> findPrimeFactors(num) {

}

int main() {
  // cout << "Hello world;" << endl;
  // cout << isPrime(4) << endl;

  int num;
  cout << "Find the prime factor of? ";
  cin >> num;

  vector<int> factors = findFactors(num);
  vector<int> primeFactors;

  for (int i = 0; i <= factors.size(); i++) {
    if (isPrime(i)) {
      primeFactors.push_back(i);
      cout << i << endl;
    }
  }


  return 0;
}
