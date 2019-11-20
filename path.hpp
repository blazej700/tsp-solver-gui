#ifndef path_hpp
#define path_hpp

#include <vector>
#include "graph.hpp"

class Path{
	std::vector <int> path;
	Graph graph;
	int ad_info;

public:
	Path();
	Path(const Graph &graph);

	virtual ~Path();
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
};


#endif //path_hpp