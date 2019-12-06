#ifndef path_hpp
#define path_hpp

#include <vector>
#include <algorithm> 
#include <random>
#include <string>
#include <iostream>
#include <chrono>
#include "graph.hpp"

class Path{
	std::vector <int> path;
	Graph graph;
	int ad_info;

public:
	Path();
	Path(const Graph &graph);

	virtual ~Path();
	int size();
	void set_graph(const Graph &graph);
	int get(int n);
	void add(int n);
	void set(int n, int city);
	void add_front(int city);
	int path_distance();
	int path_distance_to(int n);
	bool is_in(int city);
	bool is_in_befor(int city, int prev_city);
	std::string to_string();
	void set_all(std::vector<int> vec);
	Path &operator=(const Path &apath);
	std::vector<int> get_vec();
	void fill_empyt();
	int get_ad_info();
	void set_ad_info(int n);
	void swap(int i, int j);
	void insert(int i, int j);
	void invert(int i, int j);
	void shuffle(int i, int j);

	//int rand(int i);
};


#endif //path_hpp