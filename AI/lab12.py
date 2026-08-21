# Neural Network using Perceptron Learning Algorithm

class Perceptron:

    def __init__(self, learning_rate=0.1, epochs=10):
        self.learning_rate = learning_rate
        self.epochs = epochs
        self.weights = [0, 0]
        self.bias = 0

    def predict(self, inputs):
        total = sum(w * x for w, x in zip(self.weights, inputs))
        total += self.bias

        return 1 if total >= 0 else 0

    def train(self, X, y):

        for epoch in range(self.epochs):
            errors = 0

            for inputs, target in zip(X, y):
                prediction = self.predict(inputs)

                error = target - prediction

                # Update weights
                for i in range(len(self.weights)):
                    self.weights[i] += (
                        self.learning_rate * error * inputs[i]
                    )

                # Update bias
                self.bias += self.learning_rate * error

                if error != 0:
                    errors += 1

            print(f"Epoch {epoch + 1}: Errors = {errors}")

            if errors == 0:
                break


# AND gate training data
X = [
    [0, 0],
    [0, 1],
    [1, 0],
    [1, 1]
]

y = [0, 0, 0, 1]

# Create and train perceptron
model = Perceptron(learning_rate=0.1, epochs=10)

model.train(X, y)

print("\nFinal Weights:", model.weights)
print("Final Bias:", model.bias)

print("\nPredictions:")
for inputs in X:
    print(inputs, "->", model.predict(inputs))

print("\nBy Sayam Shrestha")