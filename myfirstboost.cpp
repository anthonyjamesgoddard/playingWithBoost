// solving a project Euler problem using boost::graph
// problem 18

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
	boost::add_edge(0,1,3,G);
	boost::add_edge(1,2,7,G);
	boost::add_edge(1,3,4,G);
	boost::add_edge(2,4,2,G);
	boost::add_edge(2,5,4,G);
	boost::add_edge(3,5,4,G);
	boost::add_edge(3,6,6,G);
		
    return 0;
}
