List<int> availableNotes = [
  100000,
  50000,
  20000,
  10000,
  5000,
  2000,
  1000,
  500,
  100
];

int main() {
  double inputMoney = 185200;
  double left = inputMoney;

  for (var i = 0; i < availableNotes.length; i++) {
    double over = left % availableNotes[i];
    double howMany = (left - over) / availableNotes[i];

    print('$howMany lembar uang ${availableNotes[i]}');
    left = left - (howMany * availableNotes[i]);
  }

  if (left > 0) print("Tersisa $left");

  return 0;
}

// Output
// 1.0 lembar uang 100000
// 1.0 lembar uang 50000
// 1.0 lembar uang 20000
// 1.0 lembar uang 10000
// 1.0 lembar uang 5000
// 0.0 lembar uang 2000
// 0.0 lembar uang 1000
// 0.0 lembar uang 500
// 2.0 lembar uang 100
