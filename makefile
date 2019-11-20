#ifndef _hpp
#define _hpp

#endif

#####

#include ".hpp"

####

CXX = g++
CXXFLAGS = -std=c++11 -Wall



test1.out: main.o graph.o path.o bf.o bb.o dp.o 
	${CXX} ${CXXFLAGS} $^ -o $@ 

tspSolver.out: guiMain.o gui.o graph.o path.o bf.o bb.o dp.o 
	${CXX} ${CXXFLAGS} $^ -o $@ `wx-config-gtk3 --cxxflags --libs`

main.o: main.cc graph.cc graph.hpp path.cc path.hpp bf.cc bf.hpp bb.cc bb.hpp dp.cc dp.hpp
	${CXX} ${CXXFLAGS} -c $< -o $@ 

gui.o: gui.cc gui.hpp graph.hpp path.hpp bf.hpp bb.hpp dp.hpp
	${CXX} ${CXXFLAGS} -c $< -o $@ `wx-config-gtk3 --cxxflags --libs`

guiMain.o: guiMain.cc gui.cc gui.hpp
	${CXX} ${CXXFLAGS} -c $< -o $@ `wx-config-gtk3 --cxxflags --libs`

graph.o: graph.cc graph.hpp
	${CXX} ${CXXFLAGS} -c $< -o $@

path.o: path.cc path.hpp graph.hpp
	${CXX} ${CXXFLAGS} -c $< -o $@

bf.o: bf.cc bf.hpp graph.hpp path.hpp
	${CXX} ${CXXFLAGS} -c $< -o $@

bb.o: bb.cc bb.hpp graph.hpp path.hpp
	${CXX} ${CXXFLAGS} -c $< -o $@

dp.o: dp.cc dp.hpp graph.hpp path.hpp
	${CXX} ${CXXFLAGS} -c $< -o $@

run: test1
	./test1

ruw: tspSolver
	./tspSolver
