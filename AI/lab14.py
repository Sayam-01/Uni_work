# Naive Bayes Classifier
# Classification of Vehicles

from collections import defaultdict


# Training dataset
# (Wheels, Engine, Size, Class)

data = [
    ("4", "Petrol", "Large", "Car"),
    ("4", "Diesel", "Large", "Car"),
    ("4", "Petrol", "Medium", "Car"),
    ("4", "Electric", "Medium", "Car"),
    ("2", "Petrol", "Small", "Bike"),
    ("2", "Petrol", "Medium", "Bike"),
    ("2", "Electric", "Small", "Bike"),
    ("2", "Electric", "Medium", "Bike"),
    ("4", "Diesel", "Medium", "Car"),
    ("2", "Petrol", "Small", "Bike")
]

features = [0, 1, 2]


def train_naive_bayes(data):
    class_count = defaultdict(int)
    feature_count = defaultdict(int)

    for row in data:
        class_name = row[-1]
        class_count[class_name] += 1

        for i in features:
            feature_count[(i, row[i], class_name)] += 1

    return class_count, feature_count


def predict(sample, data):
    class_count, feature_count = train_naive_bayes(data)

    total = len(data)
    probabilities = {}

    for class_name in class_count:

        # Prior probability P(C)
        probability = class_count[class_name] / total

        # Conditional probabilities P(Xi | C)
        for i in features:
            count = feature_count[(i, sample[i], class_name)]

            if count == 0:
                probability = 0
                break

            probability *= count / class_count[class_name]

        probabilities[class_name] = probability

    prediction = max(
        probabilities,
        key=probabilities.get
    )

    return prediction, probabilities


# Test sample
sample = ("2", "Electric", "Small")

prediction, probabilities = predict(sample, data)


print("Naive Bayes Classifier")
print("----------------------")

print("Test Vehicle:")
print("Wheels:", sample[0])
print("Engine:", sample[1])
print("Size:", sample[2])

print("\nClass Probabilities:")

for class_name, probability in probabilities.items():
    print(f"P({class_name}) = {probability:.4f}")

print("\nPredicted Class:", prediction)

print("\nBy Sayam Shrestha")