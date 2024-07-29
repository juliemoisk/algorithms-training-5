n, q = map(int, input().split())
a = [0] + list(map(int, input().split()))
prefsum = [0] * (n + 1)
for i in range(1, n + 1):
    prefsum[i] = prefsum[i - 1] + a[i]
ans = []
for i in range(q):
    orccnt, orcsum = map(int, input().split())
    l = 1
    r = n + 1 - orccnt
    while l < r:
        m = (l + r) // 2
        if  prefsum[m + orccnt - 1] - prefsum[m - 1] >= orcsum:
            r = m
        else:
            l = m + 1
    if prefsum[l + orccnt - 1] - prefsum[l - 1] == orcsum:
        ans.append(l)
    else:
        ans.append(-1)
print(*ans)
