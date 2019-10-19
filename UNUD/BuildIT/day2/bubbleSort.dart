import 'dart:io';

List<int> bubbleSort(List<int> source) {
  List<int> toSort = source;

  void swap(int indexA, int indexB) {
    int temp = toSort[indexA];
    toSort[indexA] = toSort[indexB];
    toSort[indexB] = temp;
  }

  while (true) {
    int counter = 0;
    
    for (var i = 0; i < toSort.length - 1; i++) {
      if (toSort[i] > toSort[i + 1]) {
        counter++;
        swap(i, i + 1);
      }
    }

    if (counter == 0) {
      return toSort;
    }
  }
}

void main(List<String> args) {
  List<int> src = [1, 5, 3, 2, 5, 7, 2];

  for (var i = 0; i < src.length; i++) {
    stdout.write("${src[i]} ");
  }

  print("");
  var sorted = bubbleSort(src);
  print("sorted");

  for (var i = 0; i < sorted.length; i++) {
    stdout.write("${sorted[i]} ");
  }
}
