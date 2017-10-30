for test in range(int(input())):
    n = int(input())
    stud = [int(item) for item in input().split()]
    print(sum([item // 30 + int(item % 30 != 0) for item in stud]))
