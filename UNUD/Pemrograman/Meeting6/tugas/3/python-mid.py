arrA = [[1, 2, 3], [4, 5, 6]]
arrB = [[2, 2, 2], [2, 2, 2]]

if(len(arrA) != len(arrB)):
    print("Panjang arrayA harus sama dengan arrayB")
    quit(1)

hasil = [[None for i in range(len(arrA[0]))] for j in range(len(arrA))]

for i in range(len(arrA)):
    for j in range(len(arrA[i])):
        hasil[i][j] = arrA[i][j] * arrB[i][j]

print(hasil)
