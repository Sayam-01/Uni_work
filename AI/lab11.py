# Bayesian Network for Probabilistic Reasoning

# P(Rain)
P_Rain = {
    True: 0.3,
    False: 0.7
}

# P(Sprinkler | Rain)
P_Sprinkler_given_Rain = {
    True: {
        True: 0.1,
        False: 0.9
    },
    False: {
        True: 0.5,
        False: 0.5
    }
}

# P(WetGrass | Rain, Sprinkler)
P_WetGrass = {
    (True, True): 0.99,
    (True, False): 0.80,
    (False, True): 0.90,
    (False, False): 0.01
}


def probability_wet_grass():
    probability = 0

    for rain in [True, False]:
        for sprinkler in [True, False]:

            p_rain = P_Rain[rain]
            p_sprinkler = P_Sprinkler_given_Rain[rain][sprinkler]
            p_wet = P_WetGrass[(rain, sprinkler)]

            probability += p_rain * p_sprinkler * p_wet

    return probability


def probability_rain_given_wet_grass():
    numerator = 0
    denominator = probability_wet_grass()

    for sprinkler in [True, False]:

        p_rain = P_Rain[True]
        p_sprinkler = P_Sprinkler_given_Rain[True][sprinkler]
        p_wet = P_WetGrass[(True, sprinkler)]

        numerator += p_rain * p_sprinkler * p_wet

    return numerator / denominator


p_wet = probability_wet_grass()
p_rain_given_wet = probability_rain_given_wet_grass()

print("Bayesian Network")
print("-----------------")

print(f"P(WetGrass) = {p_wet:.4f}")
print(f"P(Rain | WetGrass) = {p_rain_given_wet:.4f}")

print("\nBy Sayam Shrestha")