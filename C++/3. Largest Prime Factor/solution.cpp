#include <iostream>
#include <vector>

using namespace std;

/**
* Helper function,
* find if small is a factor of big
* put it the other way, is small * something = big
*/
bool isFactor(long int big, int small) {
    return (big % small == 0);
}

/**
* Find if num is prime or not, using ternary operator... nice
*/
bool isPrime(int num) {
  vector<int> factor;

  for (int i = 1; i <= num; i++) {
    if (isFactor(num, i)) {
        factor.push_back(i);
    }
  }

  return (factor.size() == 2);
}

/**
* I'm not using this cuz, this came from my previous attemp (with wrong definition of prime factor)
* but I think this is quite a nice function, so I will keep it...
*/
vector<int> findFactors(int num) {
  vector<int> res;

  for (int i = 1; i<= num; i++) {
    if (num % i == 0) {
        res.push_back(i);
    }
  }

  return res;
}

/**
* find the smallest factor of num, and add it to vector cont
* then using recursion find the next factor, that is prime
*
* & is reference... so ... what is it again?
*/
void findPrimeFactors(long int num, vector<int> &cont) {
  for (int i = 1; i <= num; i++) {
    if (isPrime(i) && isFactor(num, i)) {
        cont.push_back(i);
        //cout << num  << "/" << i << endl;
        if (i < num) {
          findPrimeFactors(num/i, cont);
        }
        return;
    }
  }
}

int main() {
  long int num;
  cout << "Find the prime factor of? " << endl;
  cin >> num;

  vector<int> primeFactors;
  findPrimeFactors(num, primeFactors);

  long int biggest = 0;
  for (int i = 0; i < primeFactors.size(); i++) {
    int el = primeFactors[i];
    if (biggest < el) {
      biggest = el;
    }

    cout << i+1 << "th prime factor: " << el << endl;
  }

  cout << "The biggest factor of " << num << " is " << biggest;
  return 0;
}
