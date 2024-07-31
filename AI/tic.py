import random

tic_tac_toe = {i: ' ' for i in range(9)}  # Initialize the board with empty spaces
p = 1  # Initialize player turn

def print_tic_tac_toe(board):
    """ Print the tic-tac-toe board configuration """
    for i in range(3):
        for j in range(3):
            print(board[i * 3 + j], end=" ")
        print()
    print()

def auto_play():
    global p
    choice = random.randint(0, 8)  # Choices should be between 0 and 8 for a 3x3 board
    while tic_tac_toe[choice] != ' ':
        choice = random.randint(0, 8)
    if p == 1:
        tic_tac_toe[choice] = 'O'
        p = 0
    else:
        tic_tac_toe[choice] = 'X'
        p = 1

def check(board):
    """ Check for a win condition in the tic-tac-toe board """
    # Check rows
    for i in range(3):
        if board[i * 3] == board[i * 3 + 1] == board[i * 3 + 2] and board[i * 3] != ' ':
            return True
    # Check columns
    for i in range(3):
        if board[i] == board[i + 3] == board[i + 6] and board[i] != ' ':
            return True
    # Check diagonals
    if board[0] == board[4] == board[8] and board[0] != ' ':
        return True
    if board[2] == board[4] == board[6] and board[2] != ' ':
        return True
    return False

# Example usage
for i in range(9):
    print(i)
    print_tic_tac_toe(tic_tac_toe)
    auto_play()
    if check(tic_tac_toe):
        
        print_tic_tac_toe(tic_tac_toe)  # Print final board state
        print(f"Player {'O' if p == 0 else 'X'} wins!")
        break
else:
    print_tic_tac_toe(tic_tac_toe)  # Print final board state
    print("It's a draw!")
