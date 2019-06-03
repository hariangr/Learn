#include <iostream>

using namespace std;

int main() {
    long int first = 0;
    long int second = 1;
    long int range = 4000000; // Four million by default
    long int sum = 0;
    long int temp = 0;

    cout << "Get the fibonacci number below? (default 4000000)" << endl;
    cin >> range;

    // HACK WARNING :v
    // I think there is a better way to achive this,
    // but for the mean time, this is the best I can now... I think
    while (second < range) {
        temp = first;
        first = second;
        second = temp + second;
        if (second < range) {
            if (second % 2 == 0) {
                sum += second;
            }
            cout << second << endl;
        }
    };

    cout << "Sum of the even fibonacci number is " << sum << endl;
}
