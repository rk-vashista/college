def calculate_distance(permutation, dist_matrix):
    return sum(dist_matrix[permutation[i]][permutation[i+1]] for i in range(len(permutation) - 1)) + dist_matrix[permutation[-1]][permutation[0]]

def permute(perm, start, end, dist_matrix):
    if start == end:
        yield tuple(perm)
    else:
        for i in range(start, end + 1):
            perm[start], perm[i] = perm[i], perm[start]
            yield from permute(perm, start + 1, end, dist_matrix)
            perm[start], perm[i] = perm[i], perm[start]

def tsp_bruteforce(dist_matrix):
    n = len(dist_matrix)
    min_path = None
    min_distance = float('inf')
    for perm in permute(list(range(n)), 0, n - 1, dist_matrix):
        dist = calculate_distance(perm, dist_matrix)
        if dist < min_distance:
            min_distance = dist
            min_path = perm
    return min_path, min_distance

def main():
    dist_matrix = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],
        [20, 25, 30, 0]
    ]
    path, distance = tsp_bruteforce(dist_matrix)
    print(f"Optimal path: {path}")
    print(f"Minimum distance: {distance}")

if __name__ == "__main__":
    main()
