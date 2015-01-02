DisCO-Assignments
=================

Brief:

Given a graph G in the form of Adjacency matrix representation. The graph has to be read from a file in the
following format –
Sample input file:
0,1,1,0,0
1,0,0,1,1
1,0,0,0,0
0,1,0,0,0
0,1,0,0,0
Write a Program that checks whether the given graph is a height balanced tree or not. You can assume ith
vertex to be the root of the tree. Value of i has to be taken by the program using a scanf() statement. The
output has to be displayed over the terminal. You can assume that the number of vertices in the whole
graph to be less than 10.
=================

1. If graph is not tree output will be directly "Graph IS NOT A TREE".
2. If graph is a tree the program will ask for the value of the root 'i'.
3. The output on the terminal will be "Graph is A HEIGHT BALANCED TREE" 
   or "Graph is NOT A HEIGHT BALANCED TREE" for the input root node value.

There are four test input files attached which are as follows:

input1.txt
This contains the adjacency matrix for a graph with 5 vertices which is a tree and is
height balanced when root is any of the nodes 1, 2, 3, 4, 5.

input2.txt
This contains the adjacency matrix for a graph with 5 vertices which is a tree and is
height balanced when root is any of the nodes 2, 4, 5.

input3.txt
This contains the adjacency matrix for a graph with 6 vertices which is a tree and is
height balanced when root is any of the nodes 1, 2, 4, 6.

input4.txt
This contains the adjacency matrix for a graph which is not a tree.

TODO 1. Review height balanced definiton
