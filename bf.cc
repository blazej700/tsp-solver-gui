#include "bf.hpp"
#include "path.hpp"

#include <algorithm>
#include <vector>
#include <iostream>


Path BruteForce::solve(Graph graph){
	
	std::vector<int> _tmp;
	Path work_path(graph);
	Path best_path(graph);

	for(int i=1; i<graph.get_cities(); i++)
		_tmp.push_back(i);

	best_path.set_all(_tmp);
	best_path.add_front(0);
	best_path.add(0);

	int itr=0;

	do{
		work_path.set_all(_tmp);
		work_path.add_front(0);
		work_path.add(0);

		if( work_path.path_distance() < best_path.path_distance())
			best_path = work_path;
		
		++itr;
	}while(std::next_permutation(_tmp.begin(), _tmp.end()));

	best_path.set_ad_info(itr);

	return best_path;

}