# N-Queens Problem using Backtracking

def is_safe(board, row, col, n):
    # Check the same column
    for i in range(row):
        if board[i] == col:
            return False

    # Check upper-left diagonal
    for i, j in zip(range(row - 1, -1, -1),
                     range(col - 1, -1, -1)):
        if board[i] == j:
            return False

    # Check upper-right diagonal
    for i, j in zip(range(row - 1, -1, -1),
                     range(col + 1, n)):
        if board[i] == j:
            return False

    return True


def solve_n_queens(board, row, n):
    if row == n:
        return True

    for col in range(n):
        if is_safe(board, row, col, n):
            board[row] = col

            if solve_n_queens(board, row + 1, n):
                return True

            # Backtrack
            board[row] = -1

    return False


def display_board(board, n):
    for row in range(n):
        for col in range(n):
            if board[row] == col:
                print("Q", end=" ")
            else:
                print(".", end=" ")
        print()


n = int(input("Enter the value of N: "))

board = [-1] * n

if solve_n_queens(board, 0, n):
    print("\nSolution:")
    display_board(board, n)
else:
    print("\nNo solution exists for N =", n)

print("\nBy Sayam Shrestha")