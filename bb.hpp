#ifndef bb_hpp
#define bb_hpp

#include "graph.hpp"
#include "path.hpp"
#include <vector>
#include <iostream>

class BranchnBound{

	struct cld;
public:
	Path solve(Graph graph);


};

#endif //bb_hpp
