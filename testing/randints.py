from numpy import random

arr = [i for i in range(1, 18)]
random.shuffle(arr)

for el in arr:
	print(f"{el} ", end="")