def is_valid_state(m1, c1, m2, c2):
    """ Check if the state is valid. """
    return (m1 == 0 or m1 >= c1) and (m2 == 0 or m2 >= c2)

def get_successors(state):
    """ Generate all possible next states from the current state. """
    m1, c1, b = state
    successors = []
    if b:  # Boat is on the starting side
        for m in range(3):
            for c in range(3):
                if 1 <= m + c <= 2:  # Boat must carry 1 or 2 people
                    new_m1 = m1 - m
                    new_c1 = c1 - c
                    new_m2 = 3 - new_m1
                    new_c2 = 3 - new_c1
                    if 0 <= new_m1 <= 3 and 0 <= new_c1 <= 3 and is_valid_state(new_m1, new_c1, new_m2, new_c2):
                        successors.append((new_m1, new_c1, False))
    else:  # Boat is on the opposite side
        for m in range(3):
            for c in range(3):
                if 1 <= m + c <= 2:  # Boat must carry 1 or 2 people
                    new_m1 = m1 + m
                    new_c1 = c1 + c
                    new_m2 = 3 - new_m1
                    new_c2 = 3 - new_c1
                    if 0 <= new_m1 <= 3 and 0 <= new_c1 <= 3 and is_valid_state(new_m1, new_c1, new_m2, new_c2):
                        successors.append((new_m1, new_c1, True))
    return successors

def bfs():
    """ Perform BFS to find the solution. """
    initial_state = (3, 3, True)
    goal_state = (0, 0, False)
    queue = [(initial_state, [])]  # Queue of (state, path)
    visited = set()
    
    while queue:
        (state, path) = queue.pop(0)
        if state in visited:
            continue
        visited.add(state)
        
        # Check if we have reached the goal
        if state == goal_state:
            return path + [state]
        
        # Get all possible next states
        for successor in get_successors(state):
            queue.append((successor, path + [state]))
    
    return None

def print_solution(solution):
    """ Print the solution with detailed states. """
    for i, state in enumerate(solution):
        m1, c1, b = state
        m2 = 3 - m1
        c2 = 3 - c1
        side = "starting side" if b else "opposite side"
        print(f"Step {i}: {m1} missionaries and {c1} cannibals on the starting side, {m2} missionaries and {c2} cannibals on the opposite side, boat on the {side}")

# Example usage
solution = bfs()
if solution:
    print("Solution found:")
    print_solution(solution)
else:
    print("No solution exists.")
