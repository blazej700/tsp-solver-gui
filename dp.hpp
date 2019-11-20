#ifndef dp_hpp
#define dp_hpp

#include "graph.hpp"
#include "path.hpp"
#include <iostream>

class DynamicProgramming
{

    unsigned int spNum = 0;
    unsigned int FULL_SET = 0;
    int **mem = nullptr;
    int **pred = nullptr;

    void init(Graph graph);

public:
	void clean(Graph graph);
	int HeldKarp(int city, unsigned int set, Graph graph);
	Path solve(Graph graph);
	
};

#endif //dp_hpp