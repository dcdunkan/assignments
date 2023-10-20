# Use random module to generate random numbers, 1-D and 2-D
# random arrays, shuffle and make a choice of random element from
# them.

from numpy import random

# Generate single random number
random_number = random.randint(100)
print("Generated single random number:", random_number)

# Generate 1-D random array
random_1d_arr = random.randint(100, size=4)
print("Randomly generated 1-D array:", random_1d_arr)
random.shuffle(random_1d_arr)
print("Shuffled", random_1d_arr)
print("Choice:", random.choice(random_1d_arr))

# Generate 2-D random array
random_2d_arr = random.randint(100, size=(5, 2))
print("Randomly generated 2-d array:", random_2d_arr)
random.shuffle(random_2d_arr)
print("Shuffled", random_2d_arr)

random_row = random.choice(random_2d_arr.shape[0])
random_col = random.choice(random_2d_arr.shape[1])
print("Choice:", random_2d_arr[random_row][random_col])
