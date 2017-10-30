for _ in range(int(input())):
    line = input().split()
    x, y = int(line[0]), int(line[1])
    s = line[2]
    if s == ">":
        if x > y:
            print("Yes")
        else:
            print("No")
    else:
        if x < y:
            print("Yes")
        else:
            print("No")
