#include "dp.hpp"

#include <stdexcept>
#include <climits>
#include "graph.hpp"

void DynamicProgramming::init(Graph graph) {
    clean(graph);
    // Number of subproblems
    spNum = 1u << (unsigned) graph.get_cities();
    // Full set mask
    FULL_SET = spNum - 1;
    // Memoization matrix of distances for combinations of sets and cities
    mem = new int *[graph.get_cities()];
    pred = new int *[graph.get_cities()];
    for (int i = 0; i < graph.get_cities(); ++i) {
        mem[i] = new int[spNum];
        std::fill(mem[i], mem[i] + spNum, -1);
        pred[i] = new int[spNum];
        std::fill(pred[i], pred[i] + spNum, -1);
    }
}

/**
 * Frees up memory.
 */
void DynamicProgramming::clean(Graph graph) {

    // Delete matrices if they already exist
    if (mem && pred) {
        for (int i = 0; i < graph.get_cities()-1; ++i) {
            delete[] mem[i];
            delete[] pred[i];

        }
        delete[] mem;
        delete[] pred;
    }
}


int DynamicProgramming::HeldKarp(int city, unsigned int set, Graph graph) {
    // If all nodes are visited
    if (set == FULL_SET) {

        return graph.get_distance(city, 0);
    }

    // If this combination of city and set is already memorized.

    if (mem[city][set] != -1) {

        return mem[city][set];
    }

    // Current minimum distance and city
    int minDist = INT_MAX;
    int minCity = -1;

    // Iterate through all unvisited cities
    for (int i = 0; i < graph.get_cities(); ++i) {
        unsigned int mask = 1u << (unsigned) i;

        // If i city wasn't visited
        if (!(set & mask)) {
            // Enter next recursion level with masked current node
            int dist = graph.get_distance(city, i) + HeldKarp(i, set | mask, graph);
            // If new distance is shorter than current min set it as min
            if (dist < minDist) {
                minDist = dist;
                minCity = i;
            }
        }
    }

    pred[city][set] = minCity;
    return mem[city][set] = minDist;
}


Path DynamicProgramming::solve(Graph graph){

    init(graph);

    // Resulting path
    Path resPath(graph);
    resPath.fill_empyt();

    // Run Held Karp algorithm
    int result = HeldKarp(0, 1, graph);

    // Retrace path of the recursion using prev array
    int city = 0;
    unsigned int set = 1;
    int i = 0;
    while (true) {

        resPath.set(i, city);
        
        city = pred[city][set];
        if (city == -1) break;
        set = set | (1u << (unsigned) city);
        ++i;
    }
    resPath.set(++i, 0);
    
    return resPath;
}