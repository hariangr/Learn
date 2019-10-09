import 'dart:io';

void print2DMatrix(List<List<int>> arr) {
  print(arr);
  // for (var i = 0; i < arr.length; i++) {
  //   for (var j = 0; j < arr[i].length; j++) {
  //     stdout.write("${arr[i][j]}");
  //     if (j != arr[i].length) stdout.write("\t");
  //   }

  //   stdout.write("\n");
  // }
}

int calcOneElementWise(
    List<List<int>> A, List<List<int>> B, int l, int aY, int aX) {
  int res = 0;

  for (var i = 0; i < l; i++) {
    res += A[aY][i] * B[i][aY];
    print("A${A[aY][i]} B${B[i][aY]}");
  }

  return res;
}

int main(List<String> args) {
  List<List<int>> A = new List.of([
    [0, 1],
    [2, 3],
  ], growable: false);

  List<List<int>> B = new List.of([
    [6, 7],
    [9, 10],
  ], growable: false);

  int hDimension = A.length > A[0].length ? A.length : A[0].length;
  print(hDimension);

  List<List<int>> hasil =
      List.filled(hDimension, List.filled(hDimension, null));

  for (var i = 0; i < hDimension; i++) {
    for (var j = 0; j < hDimension; j++) {
      print("$i,$j");
      // hasil[0][0] = calcOneElementWise(A, B, hDimension, i, j);
      hasil[0][0] = 9;
      // break;
    }
    print("xxx");
    break;
  }

  // print2DMatrix(A);
  // stdout.write("\n");
  // print2DMatrix(B);
  // stdout.write("\n\n");
  print2DMatrix(hasil);
  stdout.write("\n");

  return 0;
}
