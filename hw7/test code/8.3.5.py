test1 = [1, 2, 3, 4, 5, 6]
test2 = [5, 4, 3, 2, 1]
test3 = [7, 6, 5, 3, 2, 1]
test4 = [-1, 6, 5, -2, -3, 3]
pivot = 4

def mysteryAlgorithm(arr, p):
	print("starting:", arr)
	i = 0
	j = len(arr) - 1

	i_counter = 0
	j_counter = 0
	swap_counter = 0

	while(i < j):
		while((i < j) and (arr[i] < p)):
			i += 1
			i_counter += 1
			print("i incremented {} times".format(i_counter))
		while((i < j) and (arr[j] >= p)):
			j -= 1
			j_counter += 1
			print("j decremented {} times".format(j_counter))
		if(i < j):
			temp = arr[i]
			arr[i] = arr[j]
			arr[j] = temp
			swap_counter += 1
			print("swap executed {} times".format(swap_counter))
	print("ending:", arr)

print(mysteryAlgorithm(test1, pivot))
print(mysteryAlgorithm(test2, pivot))
print(mysteryAlgorithm(test3, pivot))
print(mysteryAlgorithm(test4, pivot))


