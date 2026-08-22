# Alpha-Beta Pruning Algorithm

def alpha_beta(depth, node_index, maximizing_player,
            scores, alpha, beta, target_depth):

    # Leaf node
    if depth == target_depth:
        return scores[node_index]

    if maximizing_player:
        best_value = -float("inf")

        for i in range(2):
            value = alpha_beta(
                depth + 1,
                node_index * 2 + i,
                False,
                scores,
                alpha,
                beta,
                target_depth
            )

            best_value = max(best_value, value)
            alpha = max(alpha, best_value)

            # Beta cut-off
            if alpha >= beta:
                break

        return best_value

    else:
        best_value = float("inf")

        for i in range(2):
            value = alpha_beta(
                depth + 1,
                node_index * 2 + i,
                True,
                scores,
                alpha,
                beta,
                target_depth
            )

            best_value = min(best_value, value)
            beta = min(beta, best_value)

            # Alpha cut-off
            if alpha >= beta:
                break

        return best_value


# Input leaf-node scores
n = int(input("Enter number of scores (power of 2): "))

scores = list(
    map(int, input("Enter the scores separated by spaces: ").split())
)

if len(scores) != n or n <= 0 or (n & (n - 1)) != 0:
    print("Invalid input! Number of scores must be a power of 2.")
else:
    tree_depth = n.bit_length() - 1

    optimal_value = alpha_beta(
        0,
        0,
        True,
        scores,
        -float("inf"),
        float("inf"),
        tree_depth
    )

    print("\nScores:", scores)
    print("Tree Depth:", tree_depth)
    print("The optimal value is:", optimal_value)

print("\nBy Sayam Shrestha")