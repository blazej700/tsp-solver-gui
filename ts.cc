#include "ts.hpp"


TabuSearch::TabuSearch(){    	

}

void TabuSearch::set_param(int iterations, int reset_threshold, int stop_threshold, int run_time, int nei){
	this->iterations=iterations;
	this->reset_threshold=reset_threshold;
	this->stop_threshold=stop_threshold;
	this->run_time=run_time;
	this->nei=nei;

	if(iterations < 0 || reset_threshold < 0 || stop_threshold < 0 || run_time < 0 || nei < 0){
		const std::invalid_argument ia("TabuSearch::set_param");
		throw ia;
	}
	
}

void TabuSearch::set_param(int iterations, int reset_threshold, int stop_threshold, int run_time, int nei, int can){
	this->iterations=iterations;
	this->reset_threshold=reset_threshold;
	this->stop_threshold=stop_threshold;
	this->run_time=run_time;
	this->nei=nei;
	this->can=can;

	if(iterations < 0 || reset_threshold < 0 || stop_threshold < 0 || run_time < 0 || nei < 0){
		const std::invalid_argument ia("TabuSearch::set_param");
		throw ia;
	}
	
}

int TabuSearch::get_iterations(){ return iterations; }
int TabuSearch::get_reset_threshold(){ return reset_threshold; }
int TabuSearch::get_stop_threshold(){ return stop_threshold; }
int TabuSearch::get_run_time(){ return run_time; }
int TabuSearch::get_nei(){ return nei; }

void TabuSearch::tabu_list_init(Graph graph){
	tabulist = new int*[graph.get_cities()];
	for(int i=0; i<graph.get_cities(); i++)
	    tabulist[i]= new int[graph.get_cities()];
}

Path TabuSearch::solve(Graph graph){

	std::chrono::high_resolution_clock::time_point timeStart;
    std::chrono::high_resolution_clock::time_point timeStop;
    std::chrono::duration<double> time{};

	timeStart = std::chrono::high_resolution_clock::now();

	tabu_list_init(graph);
	size = graph.get_cities();

	
	Path best_path(graph);
	Path workin_path(graph);
	Path tmp_path(graph);

	//ADD OTHER X0 LATER!!!!!
	for(int i=0; i<graph.get_cities(); i++)
		best_path.add(i);
	best_path.add(0);

	tmp_path = best_path;

	int reset_counter = 0;
	int stop_counter = 0;


	for(int i=iterations; i>0; i--){

		tmp_path = minNei(graph, tmp_path);

		if(tmp_path.path_distance() <best_path.path_distance()){
			best_path = tmp_path;
			reset_counter = 0;
			stop_counter = 0;
		}
		else{
			reset_counter++;
			stop_counter++;

			timeStop = std::chrono::high_resolution_clock::now();
			time = std::chrono::duration_cast<std::chrono::duration<double>>(timeStop - timeStart);

			if(stop_threshold > 0 && stop_counter >= stop_threshold ){
				break;
			}

			if(run_time !=0 && time.count() > run_time)
				break;

			if(reset_counter >= reset_threshold){
				tmp_path.shuffle(1, graph.get_cities() - 1);
				reset_counter = 0;
			}
		}


		update_tabu();
	}

	return best_path;

}

void TabuSearch::update_tabu(){

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(tabulist[i][j] > 0)
				tabulist[i][j]--;
		}
	}
}

Path TabuSearch::minNei(Graph graph, Path path){

	std::default_random_engine r(std::random_device{}());
    std::uniform_int_distribution<int> distRange(17, 26);
	Path best_path(graph);
	Path tmp_path(graph);
	float best_distance = std::numeric_limits<float>::infinity();

	std::pair <int,int> best_move;

	if(nei==0 || nei==1){


		for(int i=1; i<path.size()-1; i++){
			for(int j=1; j<path.size()-1-i; j++){

				if(tabulist[i][j+i] > 0){
					continue;
				}

				tmp_path = path;

				if(nei==0)
					tmp_path.swap(i,j+i);
				else if(nei==1)
					tmp_path.insert(i,j+i);


				if(tmp_path.path_distance() < best_distance){
					best_path = tmp_path;
					best_distance = tmp_path.path_distance();
					best_move = std::make_pair(i,j+i);

					
				}
			}
		}
	}
	else if(nei==2){

		for(int i=1; i<path.size()-1; i++){
			for(int j=1; j<path.size()-1; j++){
				if(abs(i-j)==1 && i >j)
					continue;

				if(tabulist[i][j] > 0){
					continue;
				}

				tmp_path = path;

				if(nei==2)
					tmp_path.invert(i,j);


				if(tmp_path.path_distance() < best_distance){
					best_path = tmp_path;
					best_distance = tmp_path.path_distance();
					best_move = std::make_pair(i,j);

					
				}
			}
		}
	}



	if(best_move.first > 0 && best_move.second > 0){
		tabulist[best_move.first][best_move.second] = distRange(r);
		tabulist[best_move.second][best_move.first] = distRange(r);
	}

	if(best_distance != std::numeric_limits<float>::infinity())
		return best_path;
	else
		return path;
}

