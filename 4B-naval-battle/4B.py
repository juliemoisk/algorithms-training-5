def shipslen(k):
    cntspaces = max((1+k) * k // 2 - 1, 0)
    sumofkbigships = (k + k**2) * k // 2
    sumofexcess = k * (k + 1) * (2 * k + 1) // 6 - (1 + k) * k // 2
    return cntspaces + sumofkbigships - sumofexcess

n = int(input())
l = 0
r = n + 1
while l < r:
    m = (l + r + 1) // 2
    k = shipslen(m)
    if shipslen(m) <= n:
        l = m
    else:
        r = m - 1
print(l)
