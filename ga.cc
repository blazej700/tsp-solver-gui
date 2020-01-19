#include "ga.hpp"

GeneticAlg::GeneticAlg(){

}

GeneticAlg::GeneticAlg(int population_size, int elite_size, float mutation_rate, 
			   int generations, int run_time, int crossover_type, 
			   int mutation_type){

	this->population_size=population_size;
	this->elite_size=elite_size;
	this->mutation_rate=mutation_rate;
	this->generations=generations;
	this->run_time=run_time;
	this->crossover_type=crossover_type;
	this->mutation_type=mutation_type;
}

void GeneticAlg::set_param(int population_size, int elite_size, float mutation_rate, 
			   int generations, int run_time, int crossover_type, 
			   int mutation_type){

	this->population_size=population_size;
	this->elite_size=elite_size;
	this->mutation_rate=mutation_rate;
	this->generations=generations;
	this->run_time=run_time;
	this->crossover_type=crossover_type;
	this->mutation_type=mutation_type;
}

int GeneticAlg::get_population_size(){return population_size;}
int GeneticAlg::get_elite_size(){return elite_size;}
float GeneticAlg::get_mutation_rate(){return mutation_rate;}
int GeneticAlg::get_generations(){return generations;}
int GeneticAlg::get_run_time(){return run_time;}
int GeneticAlg::get_crossover_type(){return crossover_type;}
int GeneticAlg::get_mutation_type(){return mutation_type;}



void GeneticAlg::init_population(Graph graph){

	population.clear();

	for(int i=0; i<population_size; i++){
		Path tmp_path(graph);

		for(int i=0; i<graph.get_cities(); i++)
			tmp_path.add(i);

		tmp_path.add(0);

		tmp_path.shuffle_all();
		population.push_back(tmp_path); //바즐리 때문에 난 진짜 행복해!
	}

	std::sort(population.begin(), population.end());
}

void GeneticAlg::selection(){

	mating_pool.clear();
    mating_pool.reserve(static_cast<unsigned long>(population_size));
    //copy elite straight to the mating pool
    mating_pool.insert(mating_pool.end(), population.begin(), population.begin() + elite_size);

	int t_sum = 0;
	std::vector<int> c_sum;
	std::vector<float> prob;

	//calac pupulation distances  
	for(int i=0; i<population_size; i++){
		t_sum += population[i].path_distance();
		c_sum.push_back(t_sum);
	} 

	for (int i = 0; i < population_size; ++i) {
        prob.push_back(static_cast<float>(c_sum[i]) / t_sum);
    }

    //run for each empty slot in mating pool
    for (int i = elite_size; i < population_size; ++i) {
        
        //spin the roulette 
        float roulette = randomProb();
        

        //find first path with p>roul
        for (int j = 0; j < population_size; ++j) {
            if (roulette <= prob[j]) {
                mating_pool.push_back(population[j]);
                break;
            }
        }
    }
}

Path GeneticAlg::solve(Graph graph){

	/*	난 시가이 없어서: run time 이도 , crosovers -> 지금 있어!  모두? 몰라... 오늘 난 무든걸 하겟어! 
	 *
	 *
	 */

	init_population(graph);

	
	Path min_path(graph);
	min_path = population[0];




	std::chrono::high_resolution_clock::time_point timeStart;
    std::chrono::high_resolution_clock::time_point timeStop;
    std::chrono::duration<double> time{};

	timeStart = std::chrono::high_resolution_clock::now();


	//numbers of evolved gen
	int ev = 0;

	while(true){

		//doing everything xdddd
		selection();
		breeding(graph);
		mutation(graph);


		//sort
		std::sort(population.begin(), population.end());

		//set best path if best path in this generation is better that our best path
		if(population[0].path_distance() < min_path.path_distance())
			min_path = population[0];

		ev ++;

		if(ev>generations && !run_time>0)
			break;

		timeStop = std::chrono::high_resolution_clock::now();
		time = std::chrono::duration_cast<std::chrono::duration<double>>(timeStop - timeStart);

		if(run_time !=0 && time.count() > run_time)
			break;


	}

	return min_path;


}

void GeneticAlg::breeding(Graph graph){

	//clear the current population and allocate memory
    population.clear();
    population.reserve(static_cast<unsigned long>(population_size));

 	

    //retain the elite without crossing over
    population.insert(population.end(), mating_pool.begin(), mating_pool.begin() + elite_size);



    //crossover every parent from the mating pool with the next one
    for (int i = elite_size; i < population_size - 1; i++) {

        
        if(crossover_type==0)
        	population.push_back(crossover_ox(graph, mating_pool[i], mating_pool[i + 1]));
        else if(crossover_type==1)
        	population.push_back(crossover_pmx(graph, mating_pool[i], mating_pool[i + 1]));
        else if(crossover_type==2)
        	population.push_back(crossover_nwox(graph, mating_pool[i], mating_pool[i + 1]));
    
    }

    //wrap around to the start, crossover last parent with first parent
    if(crossover_type==0)
        population.push_back(crossover_ox(graph, mating_pool[population_size - 1], mating_pool[0]));
    else if(crossover_type==1)
        population.push_back(crossover_pmx(graph, mating_pool[population_size - 1], mating_pool[0]));
    else if(crossover_type==2)
        population.push_back(crossover_nwox(graph, mating_pool[population_size - 1], mating_pool[0]));


}

void GeneticAlg::mutation(Graph graph){


	for (int i = elite_size; i < population_size - 1; ++i) {


        if (randomProb() >= mutation_rate) continue;
        
        //random pivots
        std::pair <int,int> x = rand_subpath(graph);

        //mutate with currently using mutatuon type
        if(mutation_type == 0)
        	population[i].swap(x.first, x.second);
        else if(mutation_type==1)
        	population[i].insert(x.first, x.second);
        else if(mutation_type==2)
        	population[i].invert(x.first, x.second);

    }
}


Path GeneticAlg::crossover_ox(Graph graph, Path parent1, Path parent2){

	//init child
	Path child(graph);
	child = parent1;

	//Random subpath pivots
	std::pair <int, int> p_subp = rand_subpath(graph);

	//creating subpath from parent1
	Path subpath(graph);
	subpath.set_all(parent1.get_vec_from_to(p_subp.first, p_subp.second));

	//create copy of parent2
	Path tmp(graph);
	tmp = parent2;

	//rotate tmp in p_subp.second+1
	tmp.rotate(p_subp.second + 1);

	std::vector<int> new_tmp;

	//remove cities from subpath in tmp
	for(int i=0; i<tmp.size(); i++){
		if(!subpath.is_in(tmp.get(i))){
			new_tmp.push_back(tmp.get(i));
		}
	}
	tmp.set_all(new_tmp);


	//child = subpath + tmp
	subpath.join(tmp);
	child = subpath;

	//rotate to make path starting from 0 어떡해~~ ㅜㅜ 
	child.rotate(child.index_of(0)+1);

	return child;

	//std::cout<<child.to_string();

}

Path GeneticAlg::crossover_pmx(Graph graph, Path parent1, Path parent2){

	//init child
	Path child(graph);
	child = parent1;

	//Random subpath pivots
	std::pair <int, int> p_subp = rand_subpath(graph);

	//mapping
	auto mapping = new int[graph.get_cities()+1];
	std::fill(mapping, mapping + graph.get_cities()+1, -1);

	//create mapping
    for (int i = p_subp.first; i <= p_subp.second; ++i) {
        mapping[parent1.get(i)] = parent2.get(i);
    }

	//copy stops from parent2 to child
	int child_pos = 0;

	while(child_pos < graph.get_cities()+1){

		//skip filled subpath
		if(p_subp.first <= child_pos && child_pos <= p_subp.second){
			
			child_pos = p_subp.second + 1;
			continue;
		}


		int city = parent2.get(child_pos);

		//trace mapping
		while (mapping[city] != -1) {

            city = mapping[city];
        }


        //set point in child path
        child.set(child_pos, city);
        child_pos++;
	}


	delete[] mapping;

	return child;



}

Path GeneticAlg::crossover_nwox(Graph graph, Path parent1, Path parent2){

	//init child
	Path child(graph);
	child = parent1;

	//Random subpath pivots
	std::pair <int, int> p_subp = rand_subpath(graph);

	//subpahing child
	for(int i=1; i<p_subp.first;i++){
		child.set(i,0);
	}
	for(int i=p_subp.second+1; i<graph.get_cities();i++){
		child.set(i,0);
	}

	//fill child empty slots with cities from paretn2
	int paresnt_pos = 0;
	int child_pos = 1;

	while(paresnt_pos < graph.get_cities()+1){

		//skip filled subpath
		if(p_subp.first <= child_pos && child_pos <= p_subp.second){
			child_pos = p_subp.second + 1;
			continue;
		}

		int city = parent2.get(paresnt_pos);

		if(child.is_in(city)){
			paresnt_pos++;
			continue;
		}
		else{
			child.set(child_pos, city);
			child_pos++;
			paresnt_pos++;
		}
	}

	return child;
}


std::pair <int,int> GeneticAlg::rand_subpath(Graph graph){

	std::default_random_engine r(std::random_device{}());
    std::uniform_int_distribution<int> distRange(1, graph.get_cities()-1);

    int i = distRange(r);
	int j = distRange(r);
	while(i==j){
		j = distRange(r);
	}

    std::pair <int,int> subpath;

    if(i<j)
    	subpath = std::make_pair(i,j);
    else
    	subpath = std::make_pair(j,i);

    return subpath;

}


float GeneticAlg::randomProb() {
    std::default_random_engine r(std::random_device{}());
    std::uniform_real_distribution<float> range(0.0, 1.0);

    return range(r);
}