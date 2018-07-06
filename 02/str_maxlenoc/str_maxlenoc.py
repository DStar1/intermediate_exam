import sys

def split(string):
	array = string.split()
	return array

# def iter(string)

array = split("bosdsdabcfnjodur atehhabcellosd afkuonjosuabcrafg headfgabcllosf fghellabcosag afdfboabcsnjourafg")
first = array.pop(0)
total = len(array)
print(first)
cnt = 0
last = 0
first_char = 1

for j in range(len(first)):
	for i in range(len(array)):
		for c in range(len(array[i])):
			if array[i][c] == first[j]:
				cnt += 1
				# sys.stdout.write(first[j])
				if not first_char and last > 0 and array[i][c-1] != first[j-1]:
					last = 0
					# sys.stdout.write(first[j])
				break
	if (first_char or last) and cnt >= total:
		last += 1
		prev = first[j]
		sys.stdout.write(first[j]) #print(c_glob)
		first_char = 0
	elif not last and cnt == total:
		sys.stdout.write('\n')
		sys.stdout.write(first[j])
		first_char = 1
		last = 0
	else:
		last = 0
	# sys.stdout.write(str(last))
	cnt = 0
sys.stdout.write('\n')
