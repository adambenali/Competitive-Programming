for _ in range(int(input())):
    n = int(input())
    queue = set()
    checked = {}
    for i in range(2 * N-1):
        name = input()
        if name in queue:
            checked[name] -= 1
            if checked[name] == 0:
                del checked[name]
                queue.remove(name)
        else:
            queue.add(name)
            checked[name] = 1
    print(queue.pop())
