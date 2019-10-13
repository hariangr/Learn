s = ['a', 'b', 'C', 'd', 'e']
v = []
k = []


def isVocal(x):
    _x = str.capitalize(x)
    return _x == 'A' or _x == 'I' or _x == 'U' or _x == 'E' or _x == 'O'


while len(s) != 0:
    if(isVocal(s[len(s) - 1])):
        v.append(s[len(s) - 1])
        s.pop()
    else:
        k.append(s[len(s) - 1])
        s.pop()

print(v)
print(k)
