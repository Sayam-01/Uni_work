# Single Player Tic-Tac-Toe using Heuristic Function

def display_board(board):
    print()
    for i in range(0, 9, 3):
        print(f" {board[i]} | {board[i+1]} | {board[i+2]}")
        if i < 6:
            print("---+---+---")
    print()


def check_winner(board, player):
    winning_combinations = [
        (0, 1, 2), (3, 4, 5), (6, 7, 8),
        (0, 3, 6), (1, 4, 7), (2, 5, 8),
        (0, 4, 8), (2, 4, 6)
    ]

    return any(
        board[a] == board[b] == board[c] == player
        for a, b, c in winning_combinations
    )


def heuristic(board):
    if check_winner(board, "O"):
        return 100

    if check_winner(board, "X"):
        return -100

    score = 0

    winning_combinations = [
        (0, 1, 2), (3, 4, 5), (6, 7, 8),
        (0, 3, 6), (1, 4, 7), (2, 5, 8),
        (0, 4, 8), (2, 4, 6)
    ]

    for a, b, c in winning_combinations:
        line = [board[a], board[b], board[c]]

        if line.count("O") == 2 and line.count(" ") == 1:
            score += 10
        elif line.count("X") == 2 and line.count(" ") == 1:
            score -= 10
        elif line.count("O") == 1 and line.count(" ") == 2:
            score += 1
        elif line.count("X") == 1 and line.count(" ") == 2:
            score -= 1

    return score


def computer_move(board):
    best_score = -float("inf")
    best_move = None

    for i in range(9):
        if board[i] == " ":
            board[i] = "O"
            score = heuristic(board)
            board[i] = " "

            if score > best_score:
                best_score = score
                best_move = i

    board[best_move] = "O"


def tic_tac_toe():
    board = [" "] * 9

    print("Single Player Tic-Tac-Toe")
    print("You are X and the computer is O.")

    while True:
        display_board(board)

        # Human move
        try:
            position = int(input("Enter your position (1-9): "))
        except ValueError:
            print("Invalid input!")
            continue

        if position < 1 or position > 9 or board[position - 1] != " ":
            print("Invalid move! Try again.")
            continue

        board[position - 1] = "X"

        if check_winner(board, "X"):
            display_board(board)
            print("You win!")
            break

        if " " not in board:
            display_board(board)
            print("It's a draw!")
            break

        # Computer move
        computer_move(board)

        print("Computer's move:")

        if check_winner(board, "O"):
            display_board(board)
            print("Computer wins!")
            break

        if " " not in board:
            display_board(board)
            print("It's a draw!")
            break

    print("\nBy Sayam Shrestha")


tic_tac_toe()