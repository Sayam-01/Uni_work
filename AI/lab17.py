# Basic Natural Language Processing
# Tokenization, Stop-word Removal and Stemming

import re


text = """
This is sample paragraph for AI lab. 
This is for BIT 4th semester practical examinations.
By Sayam Shrestha
"""


# Tokenization
tokens = re.findall(r'\b[a-zA-Z]+\b', text.lower())

print("Original Text:")
print(text)

print("Tokens:")
print(tokens)


# Stop-word removal
stop_words = {
    "the", "is", "are", "a", "an", "and",
    "they", "to", "of", "in", "for"
}

filtered_tokens = [
    word for word in tokens
    if word not in stop_words
]

print("\nAfter Stop-word Removal:")
print(filtered_tokens)


# Simple stemming
def stem(word):
    suffixes = [
        "ing", "ed", "ly", "es", "s"
    ]

    for suffix in suffixes:
        if word.endswith(suffix) and len(word) > len(suffix) + 2:
            return word[:-len(suffix)]

    return word


stemmed_tokens = [
    stem(word) for word in filtered_tokens
]

print("\nAfter Stemming:")
print(stemmed_tokens)

print("\nBy Sayam Shrestha")