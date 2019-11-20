#include "graph.hpp"
#include "path.hpp"
#include "bf.hpp"
#include "bb.hpp"
#include "dp.hpp"
#include <iostream>
#include <chrono>
#include <fstream>


int main(){
	

	std::cout<<"___ __  _     _     _   _  _  ___       _     ___ _  _ "<<std::endl;
 	std::cout<<" | (_  |_)   |_ \\/ |_) |_ |_)  |  |\\/| |_ |\\ | | |_ |_)"<<std::endl;
 	std::cout<<" | __) |     |_ /\\ |   |_ | \\ _|_ |  | |_ | \\| | |_ | \\ "<<std::endl;

 	int n=25;
 	int max_time = 29;
 	std::string file_name;

 	std::ofstream file("exp.csv");

 	std::chrono::high_resolution_clock::time_point timeStart;
    std::chrono::high_resolution_clock::time_point timeStop;
    std::chrono::duration<double> time{};

    Graph graph;

    BruteForce bf;
    BranchnBound bb;
    DynamicProgramming dp;





 	for(int i=1; i<13; i++){

 		double _t_time= 0;
		for(int j=0; j<10; j++){
	 		graph.random(i);
	 		Path p1(graph);

			timeStart = std::chrono::high_resolution_clock::now();

			p1 = bf.solve(graph);

			timeStop = std::chrono::high_resolution_clock::now();

			time = std::chrono::duration_cast<std::chrono::duration<double>>(timeStop - timeStart);

			_t_time += time.count();
			double _tmpt= time.count();
		}
		
		file<<(_t_time)/10<<",";
		_t_time= 0;
 	}
 	std::cout<<"BF done!"<<std::endl;
 	file<<std::endl;

 	for(int i=1; i<16; i++){

 		double _t_time= 0;
		for(int j=0; j<10; j++){
	 		graph.random(i);
	 		Path p1(graph);

			timeStart = std::chrono::high_resolution_clock::now();

			p1 = bb.solve(graph);

			timeStop = std::chrono::high_resolution_clock::now();

			time = std::chrono::duration_cast<std::chrono::duration<double>>(timeStop - timeStart);

			_t_time += time.count();
			
		}
		
		file<<(_t_time)/10<<",";
		_t_time= 0;
 	}
 	std::cout<<"BB done!"<<std::endl;
 	file<<std::endl;

 	for(int i=1; i<23; i++){

 		double _t_time= 0;
		for(int j=0; j<10; j++){
	 		graph.random(i);
	 		Path p1(graph);

			timeStart = std::chrono::high_resolution_clock::now();

			p1 = dp.solve(graph);

			timeStop = std::chrono::high_resolution_clock::now();

			time = std::chrono::duration_cast<std::chrono::duration<double>>(timeStop - timeStart);

			_t_time += time.count();
		}
		
		file<<(_t_time)/10<<",";
		_t_time= 0;
 	}

 	std::cout<<"DP done!"<<std::endl;
 	file.close();






}