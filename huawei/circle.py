import Queue
from Queue import PriorityQueue as PQ
class Edge:
    def __init__(self, name, start, end, cost):
        self.name = name
        self.start = start
        self.end = end
        self.cost = cost

    def getItems(self):
        return [self.start, self.end, self.cost]

    def getCost(self):
        return cost

    def printItems(self):
        print "---------------------"
        print "name: ", self.name
        print "start:", self.start.getName()
        print "end:", self.end.getName()
        print "**********************"


class Node:
    def __init__(self, name):
        self.name = name
        self.outEdges = []
        self.inEdges = []

    def addOutEdges(self, edge):
        self.outEdges.append(edge)

    def addInEdges(self, edge):
        self.inEdges.append(edge)

    def removeInEdge(self, edge):
        self.inEdges.remove(edge)

    def removeOutEdge(self, edge):
        self.outEdges.remove(edge)

    def getOutEdgesNum(self):
        return len(self.outEdges)

    def getInEdgesNum(self):
        return len(self.inEdges)

    def getOutEdges(self):
        return self.outEdges

    def getInEdges(self):
        return self.inEdges

    def getName(self):
        return self.name


file = open("input.txt")
lines = file.readlines()
file.close()

node_num = int(lines[0])
edge_num = int(lines[1])

node_list = {}
edge_list = []

for line in lines[2:]:
    result = line.strip().split(',')
    start = result[0]
    end = result[1]
    edge = result[2]
    cost = int(result[3])
    if start not in node_list.keys():
        node_list[start] = Node(start)
    if end not in node_list.keys():
        node_list[end] = Node(end)
    edge = Edge(edge, node_list[start], node_list[end], cost)
    edge_list.append(edge)
    #edge.printItems()
    node_list[start].addOutEdges(edge)
    node_list[end].addInEdges(edge)

#for key in node_list.keys():
#    print "key"
#    print key
#    print "outEdges"
#    print node_list[key].getOutEdges()
#    print "inEdges"
#    print node_list[key].getInEdges()

for key in node_list.keys():
    remove_node = None
    if 0 == node_list[key].getOutEdgesNum():
        remove_node = node_list.pop(key)
#        print "out"
#        print key
        inEdges = remove_node.getInEdges()
        for edge in inEdges:
            [start, end, cost] = edge.getItems()
            if end in node_list.keys():
                node_list[end].removeOutEdge(edge)
            if edge in edge_list:
                edge_list.remove(edge)
    if None == remove_node and 0 == node_list[key].getInEdgesNum():
        remove_node = node_list.pop(key)
#        print "in"
#        print key
        outEdges = remove_node.getOutEdges()
        for edge in outEdges:
            [start, end, cost] = edge.getItems()
            if end in node_list.keys():
                node_list[end].removeInEdge(edge)
            if edge in edge_list:
                edge_list.remove(edge)

def noCircle():
    pass

edge_queue = PQ()
for edge in edge_list:
    edge_queue.put(edge, edge.getCost())

while not edge_queue.empty():
    edge = edge_queue.get()
    visited = []
    node_queue = Queue()
    for key in node_list.keys():
        if key in visited:
            continue
        visited.append(key)
        node = node_list[key]
        outEdges = node.getOutEdges()
        for out in outEdges:
            [start, end, cost] = edge.getItems()
            end_name = end.getName()
            if end_name not in visited:
                



print node_list.keys()
