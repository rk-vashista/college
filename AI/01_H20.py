def water_jug_dfs(capacity_a, capacity_b, target):
    # Check if the target is greater than the combined capacity
    if target > capacity_a + capacity_b:
        return False, []

    # Stack for DFS, starting with the initial state and an empty path
    stack = [((0, 0), [])]
    # Set to keep track of visited states
    visited = set()
    
    while stack:
        (a, b), path = stack.pop()
        
        # If we have already visited this state, skip it
        if (a, b) in visited:
            continue
        
        # Mark the state as visited
        visited.add((a, b))
        
        # Check if we have reached the target
        if a == target or b == target or a + b == target:
            return True, path + [(a, b)]
        
        # Possible state transitions
        next_states = [
            ((capacity_a, b), f"Fill jug A ({capacity_a}, {b})"),  # Fill jug A
            ((a, capacity_b), f"Fill jug B ({a}, {capacity_b})"),  # Fill jug B
            ((0, b), f"Empty jug A (0, {b})"),                     # Empty jug A
            ((a, 0), f"Empty jug B ({a}, 0)"),                     # Empty jug B
            ((a - min(a, capacity_b - b), b + min(a, capacity_b - b)), f"Pour A -> B ({a - min(a, capacity_b - b)}, {b + min(a, capacity_b - b)})"),  # Pour A -> B
            ((a + min(b, capacity_a - a), b - min(b, capacity_a - a)), f"Pour B -> A ({a + min(b, capacity_a - a)}, {b - min(b, capacity_a - a)})")   # Pour B -> A
        ]
        
        # Add valid next states to the stack
        for (state, action) in next_states:
            if state not in visited:
                stack.append((state, path + [(state, action)]))
    
    return False, []

# Example usage
capacity_a = 5
capacity_b = 3
target = 2

solution_found, steps = water_jug_dfs(capacity_a, capacity_b, target)

if solution_found:
    print("Solution found!")
    for step in steps:
        print(step)
else:
    print("No solution exists.")
