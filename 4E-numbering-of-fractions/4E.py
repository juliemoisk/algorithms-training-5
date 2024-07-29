def sumprog(n):
    return n*(n + 1) // 2

n = int(input())
l = 0
r = n + 1
while l < r:
    m = (l + r) // 2
    if sumprog(m) >= n:
        r = m
    else:
        l = m + 1
diag = l
posindiag = n - sumprog(diag - 1)
if diag % 2 == 1:
    print(posindiag, '/', diag - posindiag + 1, sep='')
else:
    print(diag - posindiag + 1, '/', posindiag, sep='')
