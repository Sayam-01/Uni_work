# BFS and DFS Graph Traversal

from collections import deque


def bfs(graph, start):
    visited = set()
    queue = deque([start])
    traversal = []

    while queue:
        vertex = queue.popleft()

        if vertex not in visited:
            visited.add(vertex)
            traversal.append(vertex)

            for neighbor in graph[vertex]:
                if neighbor not in visited:
                    queue.append(neighbor)

    return traversal


def dfs(graph, start):
    visited = set()
    stack = [start]
    traversal = []

    while stack:
        vertex = stack.pop()

        if vertex not in visited:
            visited.add(vertex)
            traversal.append(vertex)

            # Reverse to maintain natural left-to-right order
            for neighbor in reversed(graph[vertex]):
                if neighbor not in visited:
                    stack.append(neighbor)

    return traversal


# Graph representation
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

start = input("Enter starting vertex: ").upper()

if start in graph:
    print("\nBFS Traversal:", " -> ".join(bfs(graph, start)))
    print("DFS Traversal:", " -> ".join(dfs(graph, start)))
else:
    print("Invalid starting vertex.")

print("\nBy Sayam Shrestha")