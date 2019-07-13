#!/usr/bin/env python3.5

# HELPFUL LINKS

# "overloading" __init__ -> https://stavshamir.github.io/python/2018/05/26/overloading-constructors-in-python.html

# recursion in Python -> https://realpython.com/python-thinking-recursively/

# All permutations in a list -> https://www.geeksforgeeks.org/generate-all-the-permutation-of-a-list-in-python/

# Python Advanced: Graph Theory and other Graphs -> https://www.python-course.eu/graphs_python.php

from pprint import pprint as pp
from itertools import permutations
import math

class node:
	def __init__(self, label: str, w: list):
		self.empty = False
		self.matrix = w
		if(len(w) == 0):
			self.empty = True
		self.token = 10
		self.label_ = label
	def recursive_token(self):
		if(self.token == 0):
			return
		else:
			self.token-=1
			return self.recursive_token()


class graph:
	def __init__(self, l: list):
		self.manifest = l
	def p(self):
		for n in self.manifest:
			print(n.label_, n.matrix)
	def generate_edges(self):
		return list(permutations(self.manifest))
	def get_isolated_nodes(self):
		i = []
		for element in a:
			for e in element:
				if(e.empty):
					i.append(e)
		return i
	def get_distance(self, initial, final):
		# initial and final are two coordinate points
		# assuming points are plotted in a real, cartesian plane
		x_0 = initial[0]
		y_0 = initial[1]
		x_1 = final[0]
		y_1 = final[1]
		result = ((x_1-x_0)**2) + ((y_1-y_0)**2)
		# this returns the maginitude of the vector between the two points using pythagorean theorem
		return math.sqrt(result)


e = [
	node("A", ["c"]),
	node("B", ["c", "e"]),
	node("C", ["a", "b", "d", "e"]),
	node("D", ["c"]),
	node("E", ["c", "b"]),
	node("F", [])
]


node_list = graph(e)
node_list.p()


# sample points
V = ['a', 'b', 'c', 'd']

# edges are all of the possible paths each node can have
E = list(permutations(V))

# conversely, this can be applied to other data types, such as our node class

VN = list(permutations(e))

a = node_list.generate_edges()
labels = set(element.label_ for element in node_list.get_isolated_nodes())
print(labels)
print(node_list.get_distance((1, 3), (3, 4)))
