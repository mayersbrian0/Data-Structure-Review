

class DisjointSet:
    
    def __init__(self):
        self.parent = {} #store the parents of each value

    
    def union(self, x, y):
        self.parent[self.find(y)] = self.find(x) #move representative to child of x's representative

    #finds the representative for a given Node
    def find(self, x):
        if self.parent[x] != x:
            return self.find(self.parent[x])
        else:
            return x #found the representative of the set