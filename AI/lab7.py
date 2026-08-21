import math


def minimax(cur_depth, node_index, max_turn, scores, target_depth):

    if cur_depth == target_depth:
        return scores[node_index]

    if max_turn:
        return max(
            minimax(cur_depth + 1, node_index * 2,
                    False, scores, target_depth),
            minimax(cur_depth + 1, node_index * 2 + 1,
                    False, scores, target_depth)
        )
    else:
        return min(
            minimax(cur_depth + 1, node_index * 2,
                    True, scores, target_depth),
            minimax(cur_depth + 1, node_index * 2 + 1,
                    True, scores, target_depth)
        )


# Enter number of leaf nodes
n = int(input("Enter number of scores (power of 2): "))

# Enter the scores
scores = list(map(int, input("Enter the scores separated by spaces: ").split()))

if len(scores) != n or n <= 0 or (n & (n - 1)) != 0:
    print("Invalid input! Number of scores must be a power of 2.")
else:
    tree_depth = int(math.log2(n))

    optimal_value = minimax(
        0, 0, True, scores, tree_depth
    )

    print("\nScores:", scores)
    print("Tree Depth:", tree_depth)
    print("The optimal value is:", optimal_value)

print("\nBy Sayam Shrestha")