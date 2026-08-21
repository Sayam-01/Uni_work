# Implementation of A* Algorithm

def a_star(graph, heuristic, start, goal):
    open_list = [start]
    came_from = {}

    g_cost = {start: 0}
    f_cost = {start: heuristic[start]}

    while open_list:
        # Select node with the lowest f(n)
        current = min(open_list, key=lambda node: f_cost.get(node, float("inf")))

        if current == goal:
            path = []

            while current in came_from:
                path.append(current)
                current = came_from[current]

            path.append(start)
            path.reverse()

            return path, g_cost[goal]

        open_list.remove(current)

        for neighbor, cost in graph[current]:
            new_g_cost = g_cost[current] + cost

            if new_g_cost < g_cost.get(neighbor, float("inf")):
                came_from[neighbor] = current
                g_cost[neighbor] = new_g_cost
                f_cost[neighbor] = new_g_cost + heuristic[neighbor]

                if neighbor not in open_list:
                    open_list.append(neighbor)

    return None, None


# Graph representation
graph = {
    "A": [("B", 1), ("C", 4)],
    "B": [("A", 1), ("C", 2), ("D", 5)],
    "C": [("A", 4), ("B", 2), ("D", 1)],
    "D": [("B", 5), ("C", 1), ("E", 3)],
    "E": [("D", 3)]
}

# Heuristic values to goal E
heuristic = {
    "A": 7,
    "B": 6,
    "C": 2,
    "D": 3,
    "E": 0
}

start = "A"
goal = "E"

path, cost = a_star(graph, heuristic, start, goal)

if path:
    print("A* Algorithm")
    print("Start Node:", start)
    print("Goal Node:", goal)
    print("Optimal Path:", " -> ".join(path))
    print("Total Cost:", cost)
else:
    print("No path found.")

print("\nBy Sayam Shrestha")