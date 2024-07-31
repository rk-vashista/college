class Node:
    def __init__(self, position, parent=None):
        self.position = position
        self.parent = parent
        self.g = 0  # Distance from start node
        self.h = 0  # Heuristic based on distance to end node
        self.f = 0  # Total cost (g + h)

    def __eq__(self, other):
        return self.position == other.position

    def __lt__(self, other):
        return self.f < other.f

    def __hash__(self):
        return hash(self.position)

def heuristic(current, goal):
    return abs(current[0] - goal[0]) + abs(current[1] - goal[1])

def a_star(grid, start, end):
    start_node = Node(start)
    end_node = Node(end)

    open_list = [start_node]
    closed_list = set()

    while open_list:
        # Find the node with the lowest f value
        current_node = min(open_list, key=lambda node: node.f)
        open_list.remove(current_node)
        closed_list.add(current_node)

        if current_node == end_node:
            path = []
            while current_node:
                path.append(current_node.position)
                current_node = current_node.parent
            return path[::-1]

        (x, y) = current_node.position
        neighbors = [(x-1, y), (x+1, y), (x, y-1), (x, y+1)]

        for next_position in neighbors:
            if next_position[0] < 0 or next_position[0] >= len(grid) or next_position[1] < 0 or next_position[1] >= len(grid[0]):
                continue

            if grid[next_position[0]][next_position[1]] != 0:
                continue

            neighbor = Node(next_position, current_node)

            if neighbor in closed_list:
                continue

            neighbor.g = current_node.g + 1
            neighbor.h = heuristic(neighbor.position, end_node.position)
            neighbor.f = neighbor.g + neighbor.h

            if add_to_open(open_list, neighbor):
                open_list.append(neighbor)

    return None

def add_to_open(open_list, neighbor):
    for node in open_list:
        if neighbor == node and neighbor.g > node.g:
            return False
    return True

# Example usage
grid = [
    [0, 1, 0, 0, 0],
    [0, 1, 0, 1, 0],
    [0, 0, 0, 1, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 0, 0, 0]
]
start = (0, 0)
end = (4, 4)

path = a_star(grid, start, end)
print("Path:", path)
