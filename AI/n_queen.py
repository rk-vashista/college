def print_solution(board):
    for row in board:
        print(" ".join('Q' if x else '.' for x in row))
    print()

def is_safe(board, row, col, n):
    for i in range(col):
        if board[row][i]:
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j]:
            return False
    for i, j in zip(range(row, n, 1), range(col, -1, -1)):
        if board[i][j]:
            return False
    return True

def solve_n_queens(board, col, n):
    if col >= n:
        print_solution(board)
        return True
    res = False
    for i in range(n):
        if is_safe(board, i, col, n):
            board[i][col] = True
            res = solve_n_queens(board, col + 1, n) or res
            board[i][col] = False
    return res

def main(n):
    board = [[False] * n for _ in range(n)]
    solve_n_queens(board, 0, n)

if __name__ == "__main__":
    N = 4 # Change N to solve for different sizes
    main(N)
