#!/usr/bin/env python3.5

# HELPFUL LINKS

# "overloading" __init__ -> https://stavshamir.github.io/python/2018/05/26/overloading-constructors-in-python.html

# recursion in Python -> https://realpython.com/python-thinking-recursively/

# All permutations in a list -> https://www.geeksforgeeks.org/generate-all-the-permutation-of-a-list-in-python/

# Python Advanced: Graph Theory and other Graphs -> https://www.python-course.eu/graphs_python.php

# Dictionary declaration in one line -> https://stackoverflow.com/questions/16607704/one-liner-creating-a-dictionary-from-list-with-indices-as-key
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
		self.degree_ = len(w)
	def recursive_token(self):
		if(self.token == 0):
			return
		else:
			self.token-=1
			return self.recursive_token()
	def overloaded_print(self):
		print(self.label_)
		print(self.matrix)

class graph:
	def __init__(self, l: list):
		self.coordinates = {element.label_:element.matrix for element in l}
	def p(self):
		pp(self.coordinates)
	def generate_edges(self):
		return list(permutations(self.coordinates))
	def edges(self):
		return self.generate_edges()
	def labels(self):
		return [element for element in self.coordinates.keys()]
	def get_isolated_nodes(self):
		i = []
		for k, v in self.coordinates.items():
			if(len(v) == 0):
				i.append([k, v])
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
	def add_node(self, s, e):
		for a, b in self.coordinates.items():
			if(a == s):
				b.append(e)
	def find_path(self, start, end, path_=None):
		extended_path = ""
		if(path_ is None):
			path_ = []
		path_ = path_ + [start]
		if(start == end):
			return path_
		elif(start not in self.labels()):
			#print("not in labels")
			return None
		for v in self.coordinates[start]:
			if(v not in path_):
				extended_path = self.find_path(v, 
						     end,
						     path_)
			for p in extended_path:
				path_.append(p)
			return path_
		#print("could not find it")
		return None
		
# sample points
# V = ['a', 'b', 'c', 'd']

# edges are all of the possible paths each node can have
# E = list(permutations(V))

# conversely, this can be applied to other data types, such as our node class

# VN = list(permutations(e))
#print(node_list.get_distance((1, 3), (3, 4)))
#node_list.add_node(example_node)
