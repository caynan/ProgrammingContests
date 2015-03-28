def build_graph(network):
    network = [c.split('-') for c in network]
    graph = {}

    for n1,n2 in network:
        graph[n1] = graph.setdefault(n1, []) + [n2]
        graph[n2] = graph.setdefault(n2, []) + [n1]

    return graph


def bfs(network, f, s):
    visited = set()
    stack = [f]
    
    while stack:
        last = stack.pop()
        visited.add(last)
        
        for n in network[last]:
            if n not in visited:
                visited.add(n)
                stack += network[n]
    
    return s in visited
            

def check_connection(network, first, second):
    network = build_graph(network)

    return bfs(network, first, second)