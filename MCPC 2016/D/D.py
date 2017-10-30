T = int(input())

for _ in range(T):
    N = int(input())
    fun = [int(item) for item in input().split()]
    i = fun.index(max(fun))

    if fun[i-1] >= fun[(i + 1) % N]:
        j = i - 1
        while j != i and fun[j] <= fun[(j + 1) % N]:
            j = (j - 1) % N
        if j == i:
            print(i + 1, "L")
        else:
            print("NO")
    else:
        j = i + 1
        while j != i and fun[j] <= fun[(j - 1) % N]:
            j = (j + 1) % N
        if j == i:
            print(i + 1, "R")
        else:
            print("NO")
