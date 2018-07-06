def is_capital(char):
	if char >= 'A' and char <= 'Z':
		print("yes")
	else:
		print("No")

def split(string):
	array = string.split(' ')
	return array

array = split("hello yo Are you there and Feeling good")
array.sort()
for i in range(len(array)):
	for j in array:
		if len(j) == i:
			print(j)


# Split string into its different words
# Sort words alphbetically
# Print all words starting from one letter, then all words with 2, etc...
