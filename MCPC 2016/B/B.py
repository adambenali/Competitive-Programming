# Precomputation #

fib = [0,1]
i = 2
while fib[i - 1] + fib[i - 2] < 2 * 10**9:
    fib.append(fib[i - 1] + fib[i - 2])
    i += 1
fib = fib[2:]

# Main Code #
for _ in range(int(input())):
    N = int(input())
    planets = [int(item) for item in input().split()]
    c = 0
    ind = {}
    for i in range(N):
        if planets[i] in ind:
            ind[planets[i]].append(i)
        else:
            ind[planets[i]] = [i]
    for s in fib:
        for i in range(N):
            try:
                c += len(ind[s - planets[i]]) - ind[s - planets[i]].count(i)
            except KeyError:
                continue
    print(c // 2)
