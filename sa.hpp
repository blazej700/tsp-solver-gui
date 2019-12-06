#ifndef sa_hpp
#define sa_hpp

#include "graph.hpp"
#include "path.hpp"
#include <random>
#include <iostream>
#include <chrono>


class SimAnnealing{
	int start_t = 1000; //Initail temperature
	double end_t = 0.01; //A value of temperature when stop
	double cooling = 0.001; //Colling rate
	double run_time = 0; //Maximum time of solver running
	int nei = 1; // 0-swap, 1-insert, 2-invert
	int itr = 1;


public:
	SimAnnealing();
	SimAnnealing(int run_time, int nei);
	void set_param(int start_t, double end_t, double cooling, double run_time, int nei);
	void set_param(int start_t, double end_t, double cooling, int run_time, int nei, int itr);
	double randomP();

	Path solve(Graph graph);

	int get_start_t();
	double get_end_t();
	double get_cooling();
	int get_run_time();
	int get_nei();

};


#endif //sa_hpp