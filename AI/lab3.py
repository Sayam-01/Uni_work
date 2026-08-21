# Water Jug Problem using Breadth-First Search (BFS)

from collections import deque


def water_jug(capacity1, capacity2, target):
    start = (0, 0)
    queue = deque([(start, [])])
    visited = set()

    while queue:
        (x, y), path = queue.popleft()

        if (x, y) in visited:
            continue

        visited.add((x, y))
        path = path + [(x, y)]

        if x == target or y == target:
            return path

        states = [
            ((capacity1, y), "Fill Jug 1"),
            ((x, capacity2), "Fill Jug 2"),
            ((0, y), "Empty Jug 1"),
            ((x, 0), "Empty Jug 2"),
        ]

        # Pour Jug 1 into Jug 2
        amount = min(x, capacity2 - y)
        states.append(((x - amount, y + amount),
                    "Pour Jug 1 into Jug 2"))

        # Pour Jug 2 into Jug 1
        amount = min(y, capacity1 - x)
        states.append(((x + amount, y - amount),
                    "Pour Jug 2 into Jug 1"))

        for new_state, action in states:
            if new_state not in visited:
                queue.append((new_state, path))

    return None


capacity1 = 4
capacity2 = 3
target = 2

solution = water_jug(capacity1, capacity2, target)

if solution:
    print("Solution:")
    for i, state in enumerate(solution):
        print(f"Step {i}: {state}")
else:
    print("No solution exists.")

print("\nBy Sayam Shrestha")