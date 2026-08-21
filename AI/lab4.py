# Single Player Game - 8 Puzzle using Heuristic Function

def display(board):
    print("\n-------------")
    for i in range(0, 9, 3):
        print("|", board[i], "|", board[i + 1], "|", board[i + 2], "|")
        print("-------------")


def heuristic(board, goal):
    distance = 0

    for i in range(1, 9):
        current = board.index(i)
        target = goal.index(i)

        current_row, current_col = divmod(current, 3)
        target_row, target_col = divmod(target, 3)

        distance += abs(current_row - target_row)
        distance += abs(current_col - target_col)

    return distance


def get_moves(board):
    moves = []
    blank = board.index(0)
    row, col = divmod(blank, 3)

    directions = [
        (-1, 0),  # Up
        (1, 0),   # Down
        (0, -1),  # Left
        (0, 1)    # Right
    ]

    for dr, dc in directions:
        new_row = row + dr
        new_col = col + dc

        if 0 <= new_row < 3 and 0 <= new_col < 3:
            new_blank = new_row * 3 + new_col
            new_board = board.copy()

            new_board[blank], new_board[new_blank] = (
                new_board[new_blank],
                new_board[blank]
            )

            moves.append(new_board)

    return moves


def solve(initial, goal):
    current = initial

    print("Initial State:")
    display(current)

    for step in range(100):
        if current == goal:
            print("\nGoal State Reached!")
            return

        possible_moves = get_moves(current)

        # Select the move with the lowest heuristic value
        best_move = min(
            possible_moves,
            key=lambda board: heuristic(board, goal)
        )

        current = best_move

        print(f"\nStep {step + 1}:")
        print("Heuristic Value:", heuristic(current, goal))
        display(current)

    print("\nGoal could not be reached within the step limit.")


initial = [1, 2, 3,
           4, 0, 6,
           7, 5, 8]

goal = [1, 2, 3,
        4, 5, 6,
        7, 8, 0]

solve(initial, goal)

print("\nBy Sayam Shrestha")