List<int> selectionSort(List<int> source) {
  List<int> toSort = source;

  void swap(int indexA, int indexB) {
    int temp = toSort[indexA];
    toSort[indexA] = toSort[indexB];
    toSort[indexB] = temp;
  }

  int findSmallestAtIndex(int start, int end) {
    int curMin = toSort[start];
    int findSmallestAtIndex = start;

    for (var i = start; i < end; i++) {
      if (toSort[i] < curMin) {
        curMin = toSort[i];
        findSmallestAtIndex = i;
      }
    }

    return findSmallestAtIndex;
  }

  for (var i = 0; i < toSort.length; i++) {
    var x = findSmallestAtIndex(i, toSort.length);
    if (x != i) {
      swap(i, x);
    }
  }

  return toSort;
}

void main(List<String> args) {
  List<int> source = [1, 2, 5, 3, 2, 5, 6];
  print(source);

  var sorted = selectionSort(source);
  print(sorted);
}
