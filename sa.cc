#include "sa.hpp"

SimAnnealing::SimAnnealing(){

}

SimAnnealing::SimAnnealing(int run_time, int nei){

	//여기 exeption maybe xd
	this->run_time = run_time;
	this->nei = nei;
}

void SimAnnealing::set_param(int start_t, double end_t, double cooling, double run_time, int nei){
	
	//여기도 exeption maybe xd
	this->start_t = start_t;
	this->end_t = end_t;
	this->cooling = cooling;
	this->run_time = run_time;
	this->nei = nei;

	/*if(start_t < 0 || end_t < 0 || cooling < 0.000001 || run_time < 0 || nei < 0){
		const std::invalid_argument ia("SimAnnealing::set_param");
		throw ia;
	}*/

}

void SimAnnealing::set_param(int start_t, double end_t, double cooling, int run_time, int nei, int itr){
	
	//여기도 exeption maybe xd
	this->start_t = start_t;
	this->end_t = end_t;
	this->cooling = cooling;
	this->run_time = run_time;
	this->nei = nei;
	this->itr = itr;

	if(start_t < 0 || end_t < 0 || cooling < 0.000001 || run_time < 0 || nei < 0 || itr < 0){
		const std::invalid_argument ia("SimAnnealing::set_param");
		throw ia;
	}

}


int SimAnnealing::get_start_t(){ return start_t; }
double SimAnnealing::get_end_t(){ return end_t; }
double SimAnnealing::get_cooling(){ return cooling; }
int SimAnnealing::get_run_time(){ return run_time; }
int SimAnnealing::get_nei(){ return nei; }


Path SimAnnealing::solve(Graph graph){
	std::default_random_engine r(std::random_device{}());
    std::uniform_int_distribution<int> distRange(1, graph.get_cities()-1);

    std::chrono::high_resolution_clock::time_point timeStart;
    std::chrono::high_resolution_clock::time_point timeStop;
    std::chrono::duration<double> time{};

	timeStart = std::chrono::high_resolution_clock::now();

	double T = start_t; //current temperature

	Path best_path(graph);
	Path workin_path(graph);
	Path tmp_path(graph);

	for(int i=0; i<graph.get_cities(); i++)
		workin_path.add(i);
	workin_path.add(0);

	workin_path.shuffle(1, graph.get_cities()-1);
	best_path = workin_path;

	while(true){

		//for(int l=itr; l>0; l--){
		int i = distRange(r);
		int j = distRange(r);
		while(i==j){
			j = distRange(r);
		}

		tmp_path = workin_path;

		if(nei==0)
			tmp_path.swap(i, j);
		else if(nei==1)
			tmp_path.insert(i, j);
		else if(nei==2)
			tmp_path.invert(i, j);

		float delta_dis = tmp_path.path_distance() - workin_path.path_distance();

		if(delta_dis <= 0){
			if(tmp_path.path_distance() < best_path.path_distance()){
				best_path = tmp_path;
			}
			workin_path = tmp_path;
		}
		else if(exp(-delta_dis/T) > randomP()){
			workin_path = tmp_path;
		}
		

		T *= 1 - cooling;

		if(T<end_t)
			break;

		timeStop = std::chrono::high_resolution_clock::now();
		time = std::chrono::duration_cast<std::chrono::duration<double>>(timeStop - timeStart);

		if(run_time !=0 && time.count() > run_time)
				break;

	}

	return best_path;
}

double SimAnnealing::randomP() {
    std::default_random_engine r(std::random_device{}());
    std::uniform_real_distribution<> range(0, 1);

    

    return range(r);
}