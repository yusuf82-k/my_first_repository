t = int(input())
for i in range(t):
    n = int(input())
    good = True
    for j in range(2, n + 1):
        if (n + 1) % j == 0:
            good = False
    if good:
        print('YES')
    else:
        print('NO') 