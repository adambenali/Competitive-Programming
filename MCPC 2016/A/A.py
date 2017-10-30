import sys
import time

class Node:
    def __init__(self, value):
        self.val = value
        self.parent = self
        self.rank   = 0
        self.size = 1
    
def union(x, y, xRoot, yRoot):
    
    if xRoot.rank > yRoot.rank:
        yRoot.parent = xRoot
    elif xRoot.rank < yRoot.rank:
        xRoot.parent = yRoot
    else:
        yRoot.parent = xRoot
        xRoot.rank = xRoot.rank + 1
    
    xRoot.size, yRoot.size = xRoot.size + yRoot.size, xRoot.size + yRoot.size

def find(x):
    if x.parent == x:
        return x
    else:
        x.parent = find(x.parent)
    return x.parent



for j in range(int(sys.stdin.readline().strip())):
    n = int(sys.stdin.readline().strip())
    increasingEdges = []
    for i in range(n - 1):
        u, v, w = [int(item) for item in sys.stdin.readline().strip().split()]
        increasingEdges.append([u, v, w])
    
    nodes = {key : Node(key) for key in range(1, n + 1)}
    maxTotal = 0
    increasingEdges = sorted(increasingEdges, key = lambda x: x[2])
    
    for edge in increasingEdges:
        u, v, w = edge
        uRoot, vRoot = find(nodes[u]), find(nodes[v])
        maxTotal += uRoot.size * vRoot.size * w
        union(nodes[u], nodes[v], uRoot, vRoot)
    
    nodes = {key : Node(key) for key in range(1, n + 1)}
    minTotal = 0
    decreasingEdges = increasingEdges[::-1]
    
    for edge in decreasingEdges:
        u, v, w = edge
        uRoot, vRoot = find(nodes[u]), find(nodes[v])
        minTotal += uRoot.size * vRoot.size * w
        union(nodes[u], nodes[v], uRoot, vRoot)

    sys.stdout.write("%d\n" % (maxTotal - minTotal))
    
#sys.stdout.write("{}\n".format(time.time() - tt))
