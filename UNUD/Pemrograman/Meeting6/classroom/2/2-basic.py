import sys


def getXY(arrA, arrB, y, x):
    h = 0
    for i in range(2):
        h = h + (arrA[y][i] * arrB[i][x])
    return h


# Ini kode utama
arrA = [
    [3, 4],
    [1, 2],
]  # Ordo 2x2

arrB = [
    [7, 5],
    [6, 4],
]  # Ordo 2x2

hasil = [[None for i in range(2)] for j in range(2)]

for i in range(len(hasil)):
    for j in range(len(hasil[0])):
        hasil[i][j] = getXY(arrA, arrB, i, j)

print(hasil)
