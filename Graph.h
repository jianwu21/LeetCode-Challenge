//
// Created by Jian Wu on 02/09/2020.
//

#ifndef LEETCODE__GRAPH_H
#define LEETCODE__GRAPH_H

#include <vector>

using namespace std;

class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}

	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

class Graph
{
public:
	Node* cloneGraph(Node* node);

};

#endif //LEETCODE__GRAPH_H
