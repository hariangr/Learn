A = [[1, 2, 3], [3, 4, 3]]
B = [[1, 2, 2], [2, 2, 2]]

H = [[0, 0, 0], [0, 0, 0]]

for baris in range(0, 2):
    for kolom in range(0, 3):
        H[baris][kolom] = A[baris][kolom] * B[baris][kolom]

print(H)