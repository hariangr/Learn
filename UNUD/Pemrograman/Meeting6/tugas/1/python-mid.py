a = [1, 2, 3, 4]
b = [5, 6, 7, 8]
c = [None] * 4  # [null, null, null, null]

# Untuk menambahkan
for i in range(len(a)):
    c[i] = a[i]+b[i]

# Untuk ngeprint
print(c)