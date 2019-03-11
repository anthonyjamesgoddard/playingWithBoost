// solving a project Euler problem using boost::graph
// problem 18

// on doing some research we find that DAG shortest
// paths is probably best for this problem.
// Bellman-ford runs in O(VE). we can get this
// down to O(V+E) since this graph is guarenteed to
// have no cycles in our problem.
// i.e linear in adj. list rep of graph

// pseudo-code
// DAGShortPath(G,w,s)
//    topologically sort vertices of G
//    Initialise predecessors and upper bounds
//    for v in top. ord.
//        for each u adj. to v
//            Relax(u,v,w)

#include <boost/config.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/bellman_ford_shortest_paths.hpp>

using namespace boost;

struct EdgeProperties {
	int weight;
};

typedef adjacency_list<listS, vecS, directedS, no_property, EdgeProperties> Graph;

typedef std::pair<int, int> E;

int main()
{
	const int N = 11;
	const int n_edges = 13;
	E edge_array[n_edges] = {E(0,1), E(1,2), E(1,3),
							 E(2,4), E(2,5), E(3,5),
							 E(3,6), E(4,7), E(4,8),
	                         E(5,8), E(5,9), E(6,9),
	                         E(6,10)};
	
	int weight[n_edges]  = {-3,-7,-4,-2,
							-4,-4,-6,-8,
	                        -5,-9,-3};
	
	// lets just try it on the example
	Graph g(edge_array, edge_array + n_edges, N);	
	
	graph_traits < Graph >::edge_iterator ei, ei_end;

	property_map<Graph, int EdgeProperties::*>::type 
		weight_pmap = get(&EdgeProperties::weight, g);
		
	int i = 0;
	for (boost::tie(ei, ei_end) = edges(g); ei != ei_end; ++ei, ++i)
		weight_pmap[*ei] = weight[i];

	// setting all the nodes to infinite	
	std::vector<int> distance(N, (std::numeric_limits < short >::max)());

	// setting parents or predec.
	std::vector<std::size_t> parent(N);
	for (i = 0; i < N; ++i)
		parent[i] = i;
	distance[0] = 0;

	
	bool r = bellman_ford_shortest_paths(g,
										int(N),
										weight_pmap,
										&parent[0],
										&distance[0], 
	 									closed_plus<int>(),
										std::less<int>(),
										default_bellman_visitor());
	

	for(int i=0;i<N;i++){
		std::cout << parent[i] << ' ' << i << std::endl;
	}

    return 0;
}
