#include "graph.hpp"
#include "path.hpp"
#include "bf.hpp"
#include "bb.hpp"
#include "dp.hpp"
#include "sa.hpp"
#include "ts.hpp"
#include "ga.hpp"
#include <iostream>
#include <chrono>
#include <fstream>


int mainT(){

	GeneticAlg ga;

	Graph graph("tsp_120.txt");
	Path p1(graph);
	
	/*Path p2(graph);

	for(int i=0; i<graph.get_cities(); i++){
		p1.add(i);
		p2.add(i);
	}
	p1.add(0);
	p2.add(0);

	p1.shuffle_all();
	p2.shuffle_all();

	std::cout<<p1.to_string()<<std::endl;
	std::cout<<p2.to_string()<<std::endl;
	std::cout<<"--------------------------------"<<std::endl;*/
	p1 = ga.solve(graph);

	std::cout<<"--------------------------------"<<std::endl;
	//std::cout<<p1.to_string()<<std::endl;
	std::cout<<p1.path_distance()<<std::endl;
	std::cout<<"--------------------------------"<<std::endl;
	std::cout<<graph.get_best_dist()<<std::endl;

	
}

int main4(){
	
	Graph graph("tsp_24.txt");
	Path p1(graph);
	/*SimAnnealing sa;
	
	p1 = sa.solve(graph);

	std::cout<<p1.to_string()<<std::endl;

	std::cout<<p1.path_distance()<<std::endl;*/

	TabuSearch ts;
	
	p1 = ts.solve(graph);

	std::cout<<p1.to_string()<<std::endl;

	std::cout<<p1.path_distance()<<std::endl;


}

int main(){


	std::cout<<"___ __  _     _     _   _  _  ___       _     ___ _  _       "<<std::endl;
 	std::cout<<" | (_  |_)   |_ \\/ |_) |_ |_)  |  |\\/| |_ |\\ | | |_ |_)   "<<std::endl;
 	std::cout<<" | __) |     |_ /\\ |   |_ | \\ _|_ |  | |_ | \\| | |_ | \\  "<<std::endl<<std::endl;
	std::cout<<"▄▀▀▀▀▄      ▄▀▀█▄   ▄▀▀▀▀▄  ▄▀▀▀█▀▀▄      ▄▀▀▄▀▀▀▄  ▄▀▀█▄   ▄▀▀▄▀▀▀▄  ▄▀▀▀█▀▀▄ "<<std::endl;
	std::cout<<"█    █      ▐ ▄▀ ▀▄ █ █   ▐ █    █  ▐     █   █   █ ▐ ▄▀ ▀▄ █   █   █ █    █  ▐ "<<std::endl;
	std::cout<<"▐    █        █▄▄▄█    ▀▄   ▐   █         ▐  █▀▀▀▀    █▄▄▄█ ▐  █▀▀█▀  ▐   █     "<<std::endl;
	std::cout<<"    █        ▄▀   █ ▀▄   █     █             █       ▄▀   █  ▄▀    █     █      "<<std::endl;
	std::cout<<"  ▄▀▄▄▄▄▄▄▀ █   ▄▀   █▀▀▀    ▄▀            ▄▀       █   ▄▀  █     █    ▄▀       "<<std::endl;
	std::cout<<"  █         ▐   ▐    ▐      █             █         ▐   ▐   ▐     ▐   █         "<<std::endl;
	std::cout<<"  ▐                         ▐             ▐                           ▐         "<<std::endl;



	std::string file_names[8] = {"tsp_17_2.txt", "tsp_21.txt", "tsp_24.txt", "tsp_26.txt", 
									"tsp_29.txt", "tsp_42.txt", "tsp_58.txt", "tsp_120.txt"};


	Graph graph;

	try{								
		graph.read(file_names[4]);
	}
	catch(std::string ex){
		std::cout<<ex<<std::endl;
		return 0;
	}

	std::cout<<graph.get_cities()<<std::endl;

	GeneticAlg ga;

	/* Populacja 20-200
	 * Elita 0-50
	 * mutacje 0-0.1 co 0.01
	 * cros
	 *
	 *
	 *
	 *
	 *
	 */

	std::ofstream file("../pomiary3/ga-cros-blad.csv");

	for(int i=0; i<8; i++){
		try{								
			graph.read(file_names[i]);
		}
		catch(std::string ex){
			std::cout<<ex<<std::endl;
			return 0;
		}
		Path p1(graph);
		file<<file_names[i]<<","<<std::endl;
		std::cout<<file_names[i]<<std::endl;


		for(float j=0; j<3; j+=1){
			//           Popul elite muta 시대들 시간 cros mutaType
			ga.set_param(80,     30, 0.05, 1000,  2,  j,    2);

			double w=0;
			
			for(int k=0; k<10; k++){
				p1 = ga.solve(graph);
				w+= p1.path_distance();
			}
			file<<w/4<<","<<graph.get_best_dist()<<","<<j<<","<<std::endl;
		}

	}



}

int main3(){


	std::cout<<"___ __  _     _     _   _  _  ___       _     ___ _  _       "<<std::endl;
 	std::cout<<" | (_  |_)   |_ \\/ |_) |_ |_)  |  |\\/| |_ |\\ | | |_ |_)   "<<std::endl;
 	std::cout<<" | __) |     |_ /\\ |   |_ | \\ _|_ |  | |_ | \\| | |_ | \\  "<<std::endl;
	std::cout<<"   ___   _      __  _____   ____       "<<std::endl;
	std::cout<<"  / _ \\ /_\\    /__\\/__   \\ |___ \\ "<<std::endl;
	std::cout<<" / /_)///_ \\  / \\//  / /\\/   __) |"<<std::endl;
	std::cout<<"/ ___//  _  \\/ _  \\ / /     / __/ "<<std::endl;
	std::cout<<"\\/    \\_/ \\_/\\/ \\_/ \\/     |_____|"<<std::endl;



	std::string file_names[8] = {"tsp_17_2.txt", "tsp_21.txt", "tsp_24.txt", "tsp_26.txt", 
									"tsp_29.txt", "tsp_42.txt", "tsp_58.txt", "tsp_120.txt"};


	Graph graph;

	try{								
		graph.read(file_names[4]);
	}
	catch(std::string ex){
		std::cout<<ex<<std::endl;
		return 0;
	}

	std::cout<<graph.get_cities()<<std::endl;

	//Path p1(graph);




	TabuSearch ts;
	SimAnnealing sa;

	/*std::ofstream file("../pomiary2/ts-kadencje-blad.csv");

	for(int i=0; i<8; i++){
		try{								
			graph.read(file_names[i]);
		}
		catch(std::string ex){
			std::cout<<ex<<std::endl;
			return 0;
		}
		Path p1(graph);
		file<<file_names[i]<<","<<std::endl;

		for(int j=24; j<30; j++){
			ts.set_param(1000, 0, 0, 2, 0, j);
			p1 = ts.solve(graph);
			file<<p1.path_distance()<<","<<graph.get_best_dist()<<","<<j<<","<<std::endl;
		}


	}*/

	/*std::ofstream file("../pomiary2/ts-sasiedztwo-blad.csv");

	for(int i=0; i<8; i++){
		try{								
			graph.read(file_names[i]);
		}
		catch(std::string ex){
			std::cout<<ex<<std::endl;
			return 0;
		}
		Path p1(graph);
		file<<file_names[i]<<","<<std::endl;

		for(int j=0; j<3; j++){
			ts.set_param(1000, 0, 0, 2, j);
			for(int k = 0; k< 10; k++){
				p1 = ts.solve(graph);
				file<<p1.path_distance()<<","<<graph.get_best_dist()<<","<<j<<","<<std::endl;
			}
		}


	}*/

	/*std::ofstream file("../pomiary2/ts-reset-blad.csv");

	for(int i=0; i<8; i++){
		try{								
			graph.read(file_names[i]);
		}
		catch(std::string ex){
			std::cout<<ex<<std::endl;
			return 0;
		}
		Path p1(graph);
		file<<file_names[i]<<","<<std::endl;

		for(int j=0; j<75; j+=5){
			ts.set_param(1000, j, 0, 2, 2);
			

			p1 = ts.solve(graph);
			file<<p1.path_distance()<<","<<graph.get_best_dist()<<","<<j<<","<<std::endl;
			
		}

	}*/

	/*std::ofstream file("../pomiary2/ts-stop-blad.csv");

	for(int i=0; i<8; i++){
		try{								
			graph.read(file_names[i]);
		}
		catch(std::string ex){
			std::cout<<ex<<std::endl;
			return 0;
		}
		Path p1(graph);
		file<<file_names[i]<<","<<std::endl;

		for(int j=0; j<650; j+=50){
			ts.set_param(1000, 60, j, 2, 2);
			

			p1 = ts.solve(graph);
			file<<p1.path_distance()<<","<<graph.get_best_dist()<<","<<j<<","<<std::endl;
			
		}

	}*/


	//set_param(int start_t, double end_t, double cooling, int run_time, int nei)


	/*/std::ofstream file("../pomiary2/sa-cooling-blad.csv");

	for(int i=0; i<8; i++){
		try{								
			graph.read(file_names[i]);
		}
		catch(std::string ex){
			std::cout<<ex<<std::endl;
			return 0;
		}
		Path p1(graph);
		file<<file_names[i]<<","<<std::endl;
		std::cout<<file_names[i]<<std::endl;

		for(double j=0.98; j<1; j+=0.001){
			sa.set_param(1000, 0.0001, 1-j, 1, 2);
			
			for(int k=0; k<2; k++){
				p1 = sa.solve(graph);
				file<<p1.path_distance()<<","<<graph.get_best_dist()<<","<<j<<","<<std::endl;
			}
		}

	}*/

	/*std::ofstream file3("../pomiary2/sa-poczatkowa-blad.csv");

	for(int i=0; i<8; i++){
		try{								
			graph.read(file_names[i]);
		}
		catch(std::string ex){
			std::cout<<ex<<std::endl;
			return 0;
		}
		Path p1(graph);
		file3<<file_names[i]<<","<<std::endl;
		std::cout<<file_names[i]<<std::endl;

		for(int j=1; j<10001; j*=10){
			sa.set_param(j, 0.0001, 1-0.998, 1, 2);
			float w = 0;
			for(int k=0; k<6; k++){
				p1 = sa.solve(graph);
				w+= p1.path_distance();
			}
			file3<<w/6<<","<<graph.get_best_dist()<<","<<j<<","<<std::endl;
		}

	}**/

	/*std::chrono::high_resolution_clock::time_point timeStart;
    std::chrono::high_resolution_clock::time_point timeStop;
    std::chrono::duration<double> time{};


	std::ofstream file("../pomiary2/sa-cooling.csv");

	for(int i=0; i<8; i++){
		try{								
			graph.read(file_names[i]);
		}
		catch(std::string ex){
			std::cout<<ex<<std::endl;
			return 0;
		}
		Path p1(graph);
		file<<file_names[i]<<","<<std::endl;
		std::cout<<file_names[i]<<std::endl;

		double _t_time= 0;

		for(d)
			sa.set_param(1000, 0.0001, 1-0.998, 0, 2);
			float w = 0;
			for(int k=0; k<5; k++){
				timeStart = std::chrono::high_resolution_clock::now();
				p1 = sa.solve(graph);
				timeStop = std::chrono::high_resolution_clock::now();
				time = std::chrono::duration_cast<std::chrono::duration<double>>(timeStop - timeStart);

				_t_time += time.count();

			}
			file<<_t_time/5<<","<<std::endl;
		

	}*/

	/*std::ofstream file1("../pomiary2/ts-koncowe-czas.csv");

	for(int i=0; i<8; i++){
		try{								
			graph.read(file_names[i]);
		}
		catch(std::string ex){
			std::cout<<ex<<std::endl;
			return 0;
		}
		Path p1(graph);
		file1<<file_names[i]<<","<<std::endl;
		std::cout<<file_names[i]<<std::endl;

		double _t_time= 0;
			ts.set_param(1000, 60, 400, 0, 2);
			float w = 0;
			for(int k=0; k<5; k++){
				timeStart = std::chrono::high_resolution_clock::now();
				p1 = ts.solve(graph);

				timeStop = std::chrono::high_resolution_clock::now();
				time = std::chrono::duration_cast<std::chrono::duration<double>>(timeStop - timeStart);

				_t_time += time.count();

			}
			file1<<_t_time/5<<","<<std::endl;
		
		}*/

	std::ofstream file("../pomiary2/sa-cooling-blad.csv");

	for(int i=0; i<8; i++){
		try{								
			graph.read(file_names[i]);
		}
		catch(std::string ex){
			std::cout<<ex<<std::endl;
			return 0;
		}
		Path p1(graph);
		file<<file_names[i]<<","<<std::endl;
		std::cout<<file_names[i]<<std::endl;

		for(double j=0.9999; j<0.99993; j+=0.00001){
			sa.set_param(1000, 0.0001, 1-j, 1, 2);

			double w=0;
			
			for(int k=0; k<3; k++){
				p1 = sa.solve(graph);
				w+= p1.path_distance();
			}
			file<<w/3<<","<<graph.get_best_dist()<<","<<1-j<<","<<std::endl;
		}

	}
}


int main8(){
	

	std::cout<<"___ __  _     _     _   _  _  ___       _     ___ _  _ "<<std::endl;
 	std::cout<<" | (_  |_)   |_ \\/ |_) |_ |_)  |  |\\/| |_ |\\ | | |_ |_)"<<std::endl;
 	std::cout<<" | __) |     |_ /\\ |   |_ | \\ _|_ |  | |_ | \\| | |_ | \\ "<<std::endl;
 	std::cout<<"   ___   _      __  _____   ____       "<<std::endl;
	std::cout<<"  / _ \\ /_\\    /__\\/__   \\ |___ \\ "<<std::endl;
	std::cout<<" / /_)///_ \\  / \\//  / /\\/   __) |"<<std::endl;
	std::cout<<"/ ___//  _  \\/ _  \\ / /     / __/ "<<std::endl;
	std::cout<<"\\/    \\_/ \\_/\\/ \\_/ \\/     |_____|"<<std::endl;




 	int n=25;
 	int max_time = 29;
 	std::string file_name;

 	std::ofstream file("../pomiary2/all-koncowe-czas.csv");

 	std::chrono::high_resolution_clock::time_point timeStart;
    std::chrono::high_resolution_clock::time_point timeStop;
    std::chrono::duration<double> time{};

    Graph graph;

    BruteForce bf;
    BranchnBound bb;
    DynamicProgramming dp;
    TabuSearch ts;
	SimAnnealing sa;


    ts.set_param(1000, 60, 400, 0, 2);
    sa.set_param(1000, 0.0001, 1-0.998, 0, 2);



 	/*for(int i=2; i<13; i++){

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

 	for(int i=2; i<16; i++){

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

 	for(int i=2; i<23; i++){

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
 	file<<std::endl;


 	for(int i=2; i<23; i++){

 		double _t_time= 0;
		for(int j=0; j<10; j++){
	 		graph.random(i);
	 		Path p1(graph);

			timeStart = std::chrono::high_resolution_clock::now();

			p1 = ts.solve(graph);

			timeStop = std::chrono::high_resolution_clock::now();

			time = std::chrono::duration_cast<std::chrono::duration<double>>(timeStop - timeStart);

			_t_time += time.count();
		}
		
		file<<(_t_time)/10<<",";
		_t_time= 0;
 	}

 	std::cout<<"ts done!"<<std::endl;
 	file<<std::endl;*/


 	for(int i=3; i<23; i++){

 		double _t_time= 0;
		for(int j=0; j<10; j++){
	 		graph.random(i);
	 		Path p1(graph);

			timeStart = std::chrono::high_resolution_clock::now();

			p1 = sa.solve(graph);

			timeStop = std::chrono::high_resolution_clock::now();

			time = std::chrono::duration_cast<std::chrono::duration<double>>(timeStop - timeStart);

			_t_time += time.count();
		}
		
		file<<(_t_time)/10<<",";
		_t_time= 0;
 	}

 	std::cout<<"sa done!"<<std::endl;
 	file.close();





}