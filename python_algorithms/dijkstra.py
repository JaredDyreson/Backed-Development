#!/usr/bin/env python3.5

from graphs import graph, node
from pprint import pprint as pp
from itertools import permutations

class G:
	def __init__(self, w: dict):
		self.empty = False
		self.coordinates = w
	def generate_edges(self):
		edges = []
		for vertex in self.coordinates:
			for neighbour in self.coordinates[vertex]:
				if({neighbour, vertex} not in edges):
					edges.append({vertex, neighbour})
		return edges
		#return list(permutations(self.coordinates))
	def verticies(self):
		return [label for label in self.coordinates.keys()]
	def get_isolated_nodes(self):
		i = []
		for k, v in self.coordinates.items():
			if(len(v) == 0):
				i.append({k:v})
		return i
	def find_paths(self, start, end, path_=None):
		extended_path = ""
		if(path_ is None):
			path_ = []
		path_ = path_ + [start]
		if(start == end):
			return path_
		elif(start not in self.verticies()):
			return None
		for verticie in self.coordinates[start]:
			if(verticie not in path_):
				extended_path = self.find_paths(verticie,
								end,
								path_)
			for path in extended_path:
				path_.append(path)
			return path_
		return None

e = [
	node("a", ["c"]),
	node("b", ["c", "e"]),
	node("c", ["a", "b", "d", "e"]),
	node("d", ["c"]),
	node("e", ["c", "b"]),
	node("f", []),
]


f = { "a" : ["d", "f"],
      "b" : ["c"],
      "c" : ["b", "c", "d", "e"],
      "d" : ["a", "c"],
      "e" : ["c"],
      "f" : ["d"]
}


node_list = graph(e)
n_ = G(f)

print("Verticies: {}".format(n_.verticies()))
print("Edges: {}".format(n_.generate_edges()))
print("Find paths: {}".format(n_.find_paths("a", "b")))
