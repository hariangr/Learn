main(List<String> args) {
  List<List<int>> result = List.filled(2, List.filled(3, null));
  print(result); // [[null, null, null], [null, null, null]]
  // It's normal up to this point

  print("");

  result[0][0] = 9; // [[9, null, null], [9, null, null]]
  print(result);
  // I expected the result to be [[9, null, null], [null, null, null]]
}
