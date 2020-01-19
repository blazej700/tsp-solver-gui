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
	//int dist;

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
	int path_distance() const;
	int path_distance_to(int n);
	bool is_in(int city);
	bool is_in_befor(int city, int prev_city);
	std::string to_string();
	void set_all(std::vector<int> vec);
	Path &operator=(const Path &apath);
	bool operator<(const Path &other) const;
	std::vector<int> get_vec();
	void fill_empyt();
	int get_ad_info();
	void set_ad_info(int n);
	void swap(int i, int j);
	void insert(int i, int j);
	void invert(int i, int j);
	void shuffle(int i, int j);
	void shuffle_all();
	//void calc_dist();
	std::vector <int> get_vec_from_to(int from, int to);
	void rotate(int n);
	int index_of(int x);
	void join(Path patha);

};


#endif //path_hpp