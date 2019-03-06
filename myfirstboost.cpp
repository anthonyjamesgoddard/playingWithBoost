// solving a project Euler problem using boost graph

#include <iostream>
#include <boost/graph/adjacency_list.hpp>

typedef boost::property<boost::edge_weight_t,
						int> EdgeWeightProperty;

typedef boost::adjacency_list<boost::listS,
							  boost::vecS,
							  boost::undirectedS,
							  boost::no_property,
							  EdgeWeightProperty> Graph;


int main()
{
	Graph G;
	boost::add_edge(1,2,10,G);
    return 0;
}
