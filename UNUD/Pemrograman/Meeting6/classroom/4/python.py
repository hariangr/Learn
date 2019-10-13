s = [1, 2, 3, 4, 5, 6]
i = []
a = []

while len(s) != 0:
    if(s[len(s) - 1] % 2 == 1):
        i.append(s[len(s) - 1])
        s.pop()
    else:
        a.append(s[len(s) - 1])
        s.pop()

print(i)
print(a)
