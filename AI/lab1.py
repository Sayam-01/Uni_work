# Tic-Tac-Toe Game

def display_board(board):
    print()
    print(" " + board[0] + " | " + board[1] + " | " + board[2])
    print("---+---+---")
    print(" " + board[3] + " | " + board[4] + " | " + board[5])
    print("---+---+---")
    print(" " + board[6] + " | " + board[7] + " | " + board[8])
    print()


def check_winner(board, player):
    winning_combinations = [
        (0, 1, 2),
        (3, 4, 5),
        (6, 7, 8),
        (0, 3, 6),
        (1, 4, 7),
        (2, 5, 8),
        (0, 4, 8),
        (2, 4, 6)
    ]

    for a, b, c in winning_combinations:
        if board[a] == board[b] == board[c] == player:
            return True

    return False


def tic_tac_toe():
    board = [" "] * 9
    current_player = "X"

    print("TIC-TAC-TOE")
    print("Positions are numbered from 1 to 9.")
    print("Player X goes first.")

    while True:
        display_board(board)

        try:
            position = int(input(
                f"Player {current_player}, enter position (1-9): "
            ))
        except ValueError:
            print("Please enter a valid number.")
            continue

        if position < 1 or position > 9:
            print("Position must be between 1 and 9.")
            continue

        index = position - 1

        if board[index] != " ":
            print("That position is already occupied.")
            continue

        board[index] = current_player

        if check_winner(board, current_player):
            display_board(board)
            print(f"Player {current_player} wins!")
            break

        if " " not in board:
            display_board(board)
            print("The game is a draw!")
            break

        current_player = "O" if current_player == "X" else "X"

    print("\nBy Sayam Shrestha")


tic_tac_toe()