#include "graph.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <random>

Graph::Graph(){
	cities = 0;
}

Graph::Graph(std::string file_name){
	cities = 0;
	try{
		Graph::read(file_name);
		_opened = true;
	}
	catch(std::string ex){
		 //std::cout<<"exception: "<<ex<<std::endl;
		_opened = false;
	}
}

int Graph::get_cities(){
	return cities;
}

bool Graph::read_best(std::string file_name){

	std::ifstream _file(file_name);

	if (_file.is_open()) {
	    std::string line;
	    getline(_file, line);
	    this->best_dist = line;
	    getline(_file, line);
	    this->best_path = line;
	
	_file.close();
	    return 1;
	}
	else{
		return 0;
	}

}

void Graph::read(std::string file_name){

	std::ifstream _file("data/" + file_name);
	
	if (_file.is_open()) {
	    std::string line;

	    getline(_file, line);

	    this->cities = std::stoi(line.c_str());

	    matrix = new int*[cities];
	    for(int i=0; i<cities; i++)
	    	matrix[i]= new int[cities];

	    int y=0;
	    while (getline(_file, line)) {
	        std::string _tmp = line.c_str();
	        int j = 0;
	        std::string _tmp2 = "";
	        for(int i=0; i<cities; i++){
	        	while(_tmp[j] == ' '){
					j++;
	        	}
	        	while(_tmp[j] != ' ' && _tmp[j]){
	        		_tmp2 = _tmp2 + _tmp[j];
					j++;
	        	}
	        	matrix[y][i]=std::stoi(_tmp2.c_str());
	        	_tmp2 = "";
	    	}
	        y++;
	    }
	    _file.close();
	    _opened = true;
	    if(!Graph::read_best("data/" + "w" + file_name)){
	    	best_path="N/A";
			best_dist="N/A";
	    }
	    return;
	}
	else{
		std::string ex_file = "Cannot open a file";
		throw ex_file;
	}
}

void Graph::clean(){
	cities = 0;
	for(int i=0; i<cities; ++i)
		delete[] matrix[i];
	delete[] matrix;
	
}

std::string Graph::to_string(){
	if(!_opened){
		return "There is no graph in graph";
	}
	std::string _out;
	for(int i=0; i<cities; i++){
		for(int j=0; j<cities; j++){
			_out = _out + std::to_string(matrix[i][j])+"|";
		}
		_out = _out + "\n";
	}
	return _out;
}

void Graph::random(int cities){
	
	this->cities = cities;

	std::default_random_engine r(std::random_device{}());
    std::uniform_int_distribution<int> distRange(0, 100);
	
	matrix = new int*[cities];
	    for(int i=0; i<cities; i++)
	    	matrix[i]= new int[cities];

	for(int i=0; i<cities; i++){
		for(int j=0; j<cities; j++){
			if(i==j)
				matrix[i][j]=0;
			else
				matrix[i][j] = distRange(r);
		}
	}
	_opened = true;
	best_path="N/A";
	best_dist="N/A";
	return;
}

int Graph::get_distance(int from, int to){
	if(from < cities && to < cities && _opened)
		return matrix[from][to];
	else
		return 0;
}

std::string Graph::get_best_path(){
	return best_path;
}
std::string Graph::get_best_dist(){
	return best_dist;
}
