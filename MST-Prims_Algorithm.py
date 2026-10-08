import sys

def prims_mst(graph):
    n = len(graph)
    selected = [False] * n      # whether each vertex is already in the MST
    key = [sys.maxsize] * n     # cheapest edge weight that connects each vertex to the MST
    parent = [-1] * n           # MST parent of each vertex

    key[0] = 0                  # start from vertex 0

    for _ in range(n):
        # Pick the unselected vertex with the smallest key
        u = -1
        min_val = sys.maxsize
        for v in range(n):
            if not selected[v] and key[v] < min_val:
                min_val = key[v]
                u = v

        selected[u] = True

        # Update keys of adjacent vertices
        for v in range(n):
            if graph[u][v] != 0 and not selected[v] and graph[u][v] < key[v]:
                key[v] = graph[u][v]
                parent[v] = u

    # Print the MST
    print("Edge \tWeight")
    total = 0
    for v in range(1, n):
        print(f"{parent[v]} - {v}\t{graph[v][parent[v]]}")
        total += graph[v][parent[v]]
    print("Total cost of MST:", total)


# Example graph as an adjacency matrix (0 means no edge)
graph = [
    [0, 2, 0, 6, 0],
    [2, 0, 3, 8, 5],
    [0, 3, 0, 0, 7],
    [6, 8, 0, 0, 9],
    [0, 5, 7, 9, 0]
]

prims_mst(graph)