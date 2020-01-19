#ifndef ga_hpp
#define ga_hpp

#include <vector>
#include <algorithm> 
#include <string>
#include <random>
#include <iostream>
#include <chrono>

#include "graph.hpp"
#include "path.hpp"


class GeneticAlg
{

	int population_size = 80;
	int elite_size = 30;
	float mutation_rate = 0.05;
	int generations = 2000;
	int run_time = 0;
	int crossover_type = 0; //0-ox 1-PMX 2-nwox
	int mutation_type = 2; //0-swap 1-insert 2-invert
	std::vector <Path> population;
    std::vector <Path> mating_pool;

	void init_population(Graph graph);
	void selection();

	Path crossover_ox(Graph graph, Path parent1, Path parent2);
	Path crossover_pmx(Graph graph, Path parent1, Path parent2);
	Path crossover_nwox(Graph graph, Path parent1, Path parent2);

	void breeding(Graph graph);
	void mutation(Graph graph);
	std::pair <int,int> rand_subpath(Graph graph);
	float randomProb();

public:

	
	GeneticAlg();
	GeneticAlg(int population_size, int elite_size, float mutation_rate, 
			   int generations, int run_time, int crossover_type, 
			   int mutation_type);
	Path solve(Graph graph);
	
	int get_population_size();
	int get_elite_size();
	float get_mutation_rate();
	int get_generations();
	int get_run_time();
	int get_crossover_type();
	int get_mutation_type();


	void set_param(int population_size, int elite_size, float mutation_rate, 
			   int generations, int run_time, int crossover_type, 
			   int mutation_type);


};

#endif //ga_hpp