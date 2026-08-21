# Genetic Algorithm for Polynomial Optimization
# Objective: Maximize f(x) = x^3 - 6x^2 + 9x + 15

import random


# Fitness function
def fitness(x):
    return x**3 - 6*x**2 + 9*x + 15


# Convert binary chromosome to decimal
def binary_to_decimal(chromosome):
    return int("".join(map(str, chromosome)), 2)


# Create initial population
def create_population(size):
    return [
        [random.randint(0, 1) for _ in range(5)]
        for _ in range(size)
    ]


# Select the two best chromosomes
def selection(population):
    population.sort(
        key=lambda chromosome: fitness(
            binary_to_decimal(chromosome)
        ),
        reverse=True
    )

    return population[:2]


# Single-point crossover
def crossover(parent1, parent2):
    point = random.randint(1, 4)

    child1 = parent1[:point] + parent2[point:]
    child2 = parent2[:point] + parent1[point:]

    return child1, child2


# Mutation
def mutation(chromosome, mutation_rate=0.1):
    for i in range(len(chromosome)):
        if random.random() < mutation_rate:
            chromosome[i] = 1 - chromosome[i]

    return chromosome


# Genetic Algorithm
population_size = 10
generations = 20

population = create_population(population_size)

for generation in range(generations):

    parents = selection(population)

    new_population = parents.copy()

    while len(new_population) < population_size:

        child1, child2 = crossover(parents[0], parents[1])

        new_population.append(mutation(child1))

        if len(new_population) < population_size:
            new_population.append(mutation(child2))

    population = new_population


# Find the best solution
best = max(
    population,
    key=lambda chromosome: fitness(
        binary_to_decimal(chromosome)
    )
)

best_value = binary_to_decimal(best)

print("Genetic Algorithm")
print("-----------------")
print("Best Chromosome:", best)
print("Best Value of x:", best_value)
print("Maximum Fitness:", fitness(best_value))

print("\nBy Sayam Shrestha")