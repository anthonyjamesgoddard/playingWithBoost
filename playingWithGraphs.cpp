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

#include <iostream>
#include <boost/graph/adjacency_list.hpp>

typedef boost::property<boost::edge_weight_t,
						int> EdgeWeightProperty;

typedef boost::adjacency_list<boost::listS,
							  boost::vecS,
							  boost::directedS,
							  boost::no_property,
							  EdgeWeightProperty> Graph;


int main()
{
	// lets just try it on the example
	Graph G;
	// we need an intelligent way of inputting this information
	// but for the time being this is easy
	boost::add_edge(0,1,-3,G);
	boost::add_edge(1,2,-7,G);
	boost::add_edge(1,3,-4,G);
	boost::add_edge(2,4,-2,G);
	boost::add_edge(2,5,-4,G);
	boost::add_edge(3,5,-4,G);
	boost::add_edge(3,6,-6,G);
	
    return 0;
}
