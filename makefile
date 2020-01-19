#ifndef _hpp
#define _hpp

#endif

#####

#include ".hpp"

####

CXX = g++
CXXFLAGS = -std=c++11 -Wall



test1.out: main.o graph.o path.o bf.o bb.o dp.o sa.o ts.o ga.o
	${CXX} ${CXXFLAGS} $^ -o $@ 

tspSolver.out: guiMain.o gui.o graph.o path.o bf.o bb.o dp.o sa.o ts.o ga.o
	${CXX} ${CXXFLAGS} $^ -o $@ `wx-config-gtk3 --cxxflags --libs`

main.o: main.cc graph.cc graph.hpp path.cc path.hpp bf.cc bf.hpp bb.cc bb.hpp dp.cc dp.hpp sa.cc sa.hpp ts.cc ts.hpp ga.hpp
	${CXX} ${CXXFLAGS} -c $< -o $@ 

gui.o: gui.cc gui.hpp graph.hpp path.hpp bf.hpp bb.hpp dp.hpp sa.cc sa.hpp ts.cc ts.hpp ga.hpp
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

sa.o: sa.cc sa.hpp graph.hpp path.hpp
	${CXX} ${CXXFLAGS} -c $< -o $@

ts.o: ts.cc ts.hpp graph.hpp path.hpp
	${CXX} ${CXXFLAGS} -c $< -o $@

ga.o: ga.cc ga.hpp graph.hpp path.hpp
	${CXX} ${CXXFLAGS} -c $< -o $@


run: test1.out
	./test1.out

ruw: tspSolver.out
	./tspSolver.out

tspSolver.exe: wguiMain.o wgui.o wgraph.o wpath.o wbf.o wbb.o wdp.o 
	x86_64-w64-mingw32-g++ -Wall --static $^ -o $@ `wx-config-gtk3 --cxxflags --libs`

wmain.o: main.cc graph.cc graph.hpp path.cc path.hpp bf.cc bf.hpp bb.cc bb.hpp dp.cc dp.hpp
	x86_64-w64-mingw32-g++ -Wall --static-c $< -o $@ 

wgui.o: gui.cc gui.hpp graph.hpp path.hpp bf.hpp bb.hpp dp.hpp
	x86_64-w64-mingw32-g++ -Wall --static -c $< -o $@ `wx-config-gtk3 --cxxflags --libs`

wguiMain.o: guiMain.cc gui.cc gui.hpp
	x86_64-w64-mingw32-g++ -Wall --static -c $< -o $@ `wx-config-gtk3 --cxxflags --libs`

wgraph.o: graph.cc graph.hpp
	x86_64-w64-mingw32-g++ -Wall --static -c $< -o $@

wpath.o: path.cc path.hpp graph.hpp
	x86_64-w64-mingw32-g++ -Wall --static -c $< -o $@

wbf.o: bf.cc bf.hpp graph.hpp path.hpp
	x86_64-w64-mingw32-g++ -Wall --static -c $< -o $@

wbb.o: bb.cc bb.hpp graph.hpp path.hpp
	x86_64-w64-mingw32-g++ -Wall --static -c $< -o $@

wdp.o: dp.cc dp.hpp graph.hpp path.hpp
	x86_64-w64-mingw32-g++ -Wall --static -c $< -o $@

