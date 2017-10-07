from __future__ import print_function
import json

def place(k):
	for i in range(k):
		if x[i] == x[k] or abs(x[i] - x[k]) == abs(i - k):
			return False
	return True

def NQueens(n):
	solutions = []
	k = 1
	while k >= 1:
		x[k] += 1
		while x[k] < n and not place(k):
				x[k] += 1
		if x[k] < n:
			if k == n-1:
				solutions.append(list(x))
			else:
				k += 1
				x[k] = -1;
		else:
			k -= 1
	return solutions

def printBoard(solutions):
	for s in solutions:
		for r in range(n):
			print("+---+---+---+---+---+---+---+---+\n", end="")
			for c in range(n):
				if c == s[r]: print("| Q ", end="")
				else: print("|   ", end="")
			print("|")
		print("+---+---+---+---+---+---+---+---+\n\n", end="")

f = open("start.json")
data = json.load(f)
f.close()

n = 8
x = [-1]*n
x[0] = data["col0"]
print("First column position: ", x[0])
solutions = NQueens(n)
printBoard(solutions)
print("Number of solutions: ", len(solutions))