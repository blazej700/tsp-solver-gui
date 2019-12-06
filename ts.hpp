#ifndef ts_hpp
#define ts_hpp

#include "graph.hpp"
#include "path.hpp"
#include <limits>
#include <utility> 
#include <random>
#include <iostream>
#include <chrono>

class TabuSearch{

	int iterations = 500;
	int reset_threshold = 45;
	int stop_threshold = 450;
	int run_time = 0;
	int **tabulist;
	int size;
	int nei = 2;
	int can = 18;

public:
	TabuSearch();
	Path solve(Graph graph);
	void update_tabu();
	Path minNei(Graph graph, Path path);
	void tabu_list_init(Graph graph);
	void set_param(int iterations, int reset_threshold, int stop_threshold, int run_time, int nei);
	void set_param(int iterations, int reset_threshold, int stop_threshold, int run_time, int nei, int can);

	int get_iterations();
	int get_reset_threshold();
	int get_stop_threshold();
	int get_run_time();
	int get_nei();
};


#endif //ts_hpp
