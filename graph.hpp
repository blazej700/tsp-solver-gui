#ifndef graph_hpp
#define graph_hpp

#include <string>

class Graph{
	int ** matrix;
	int cities;
	bool _opened;
	std::string best_path;
	std::string best_dist;	


public:
	Graph();
	Graph(std::string file_name);
	void read(std::string file_name);
	std::string to_string();
	int get_cities();
	int get_distance(int from, int to) const;
	bool read_best(std::string file_name);
	std::string get_best_path();
	std::string get_best_dist();
	void random(int cities);
	virtual void clean();


};


#endif //graph_hpp