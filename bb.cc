#include "bb.hpp"
#include "path.hpp"

struct BranchnBound::cld{
	int city;
	int level;
	int dist;
};

Path BranchnBound::solve(Graph graph){
	int itr = 0;
	std::vector<cld> stack;
	std::vector<cld> neighbors;

	Path work_path(graph);
	Path best_path(graph);

	work_path.fill_empyt();

	for(int i=0; i< graph.get_cities(); i++){
		best_path.add(i);
	}
	best_path.add(0);

	cld _tmp;
	_tmp.city = 0;
	_tmp.level = 0;
	_tmp.dist = 0;

	stack.push_back(_tmp);

	while(!stack.empty()){

		
		_tmp = stack.back();
		stack.pop_back();


		work_path.set(_tmp.level,_tmp.city); 

		if(_tmp.level == graph.get_cities()-1){
			work_path.set(_tmp.level+1,0);
			if( work_path.path_distance() < best_path.path_distance())
				best_path = work_path;
		}

		if(work_path.path_distance_to(_tmp.level) > best_path.path_distance())
			continue;

		_tmp.level++;
		cld _tmp2;

		for(int i=0; i<graph.get_cities(); i++){
			if(!work_path.is_in_befor(i,_tmp.level) && graph.get_distance(_tmp.city,i)>0){
				_tmp2.city = i;
				_tmp2.dist = graph.get_distance(_tmp.city,i);
				_tmp2.level = _tmp.level;
				neighbors.push_back(_tmp2);
			}
		}

		while(!neighbors.empty()){
			_tmp2 = neighbors.back();
			neighbors.pop_back();
			_tmp2.level = _tmp.level;
			stack.push_back(_tmp2);
		}
		++itr;	

	}
	best_path.set_ad_info(itr);
	return best_path;
	
}