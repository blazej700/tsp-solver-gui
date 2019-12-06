#include "path.hpp"

#include "graph.hpp"

Path::Path(){

}

Path::~Path(){
	path.clear();
}


Path::Path(const Graph &graph){
	this->graph = graph;
}

int Path::size(){
	return path.size();
}


int Path::path_distance(){
	int _distance = 0;

	for(int i = 0; i < path.size() - 1; i++){  
		_distance += graph.get_distance(path[i],path[i+1]);
	}
	return _distance;
}

int Path::path_distance_to(int n){
	if(n==0)
		return 0;

	int _distance = 0;
	for(int i = 0; i < n - 1; i++){  
		_distance += graph.get_distance(path[i],path[i+1]);
	}
	return _distance;
}

void Path::add(int n){
	path.push_back(n);
}
void Path::set(int n, int city){
	path[n]=city;
}

std::string Path::to_string(){
	std::string _tmp = std::to_string(path[0]);
	for(int i = 1; i < path.size(); i++){
		_tmp += "->" + std::to_string(path[i]);
	}
	return _tmp;
}

std::vector<int> Path::get_vec(){
	return path;
}

void Path::set_all(std::vector<int> vec){
	path = vec;
}

void Path::add_front(int city){
	path.insert(path.begin(),1,city);
}

Path &Path::operator=(const Path &apath){
	path = apath.path;
	ad_info = apath.ad_info;
	return *this;

}

void Path::fill_empyt(){
	for(int i=0; i<graph.get_cities()+1; i++){
		path.push_back(0);
	}
}

bool Path::is_in_befor(int city, int prev_city){

	for(int i=0; i<path.size(); i++){
		if(i == prev_city)
			return false;
		if(path[i] == city)
			return true;
	}
	return false;
}

int Path::get_ad_info(){
	return ad_info;
}

void Path::set_ad_info(int n){
	ad_info = n;
}

void Path::set_graph(const Graph &graph){
	this->graph = graph;
}

void Path::swap(int i, int j) {
    std::swap(path[i], path[j]);
}

void Path::insert(int i, int j) {
    int newY = path[i];
    while (i > j) {
        path[i] = path[i - 1];
        --i;
    }
    while (i < j) {
        path[i] = path[i + 1];
        ++i;
    }
    path[j] = newY;
}


void Path::invert(int i, int j) {
    if (i > j) std::swap(i, j);
    while (i < j) {
        std::swap(path[i], path[j]);
        ++i;
        --j;
    }
}

void Path::shuffle(int i, int j){

	std::vector <int> tmp_vector;

	for(int l=i; l<j+1; l++){
		tmp_vector.push_back(path[l]);
	}

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::shuffle(tmp_vector.begin(), tmp_vector.end(), std::default_random_engine(seed));


	std::string _tmp = std::to_string(tmp_vector[0]);
	for(int i = 1; i < tmp_vector.size(); i++){
		_tmp += "->" + std::to_string(tmp_vector[i]);
	}

	for(int l=i; l<j+1; l++){
		path[l]=tmp_vector[l-i];
	}
}
