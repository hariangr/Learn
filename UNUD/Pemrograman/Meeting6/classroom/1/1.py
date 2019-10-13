panjang = int(input("Masukkan panjang array? "))

a = []
b = []

for i in range(panjang):
    nilai_input = int(input("Masukkan nilai ke " + str(i) + " pada variabel A?"))
    a.append(nilai_input)

for j in range(panjang):
    nilai_input = int(input("Masukkan nilai ke " + str(j) + " pada variabel B?"))
    b.append(nilai_input)

hasil = [None] * panjang

for i in range(panjang):
    hasil[i] = a[i]+b[i]

print(hasil)
