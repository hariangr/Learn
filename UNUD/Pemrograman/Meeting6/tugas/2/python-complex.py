def getXY(arrA, arrB, y, x):
    h = 0
    for i in range(len(arrA)):
        h = h + (arrA[y][i] * arrB[i][x])
    print(x, y, h)
    return h

def main():
    tinggiA = int(input("Masukkan tinggi A? "))
    lebarA = int(input("Masukkan lebar A? "))

    tinggiB = int(input("Masukkan tinggi B? "))
    lebarB = int(input("Masukkan lebar B? "))

    if(lebarA != tinggiB):
        print("Error, panjang array A harus sama dengan lebar array B")
        return

    arrA = []  # Ordo tinggiA x lebarA
    for i in range(tinggiA):
        temp = []
        for j in range(lebarA):
            nilai_input = input("A di (" + str(i) + ", " + str(j) + ")? ")
            nilai_int = int(nilai_input)
            temp.append(nilai_int)
        arrA.append(temp)

    arrB = []  # Ordo tinggiB x lebarB
    for i in range(tinggiB):
        temp = []
        for j in range(lebarB):
            nilai_input = input("B di (" + str(i) + ", " + str(j) + ")? ")
            nilai_int = int(nilai_input)
            temp.append(nilai_int)
        arrB.append(temp)

    hasil = [[None for i in range(lebarB)] for j in range(tinggiA)]

    for i in range(len(hasil)):
        for j in range(len(hasil[0])):
            hasil[i][j] = getXY(arrA, arrB, i, j)

    print(hasil)


main()