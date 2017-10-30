#include "network.hpp"
#include <cmath>
#include <random>
#include <iostream>
#include <vector>

using namespace std;

///
///constructor of network 
///initialization of the 10'000 first neurons to the excitatory type
///initialization of the 2'500 following neurons in the inhibitory type
///initialization of the network of connections with a 0 everywhere
///put random connections between the neurons but with every neuron with 1000 connections coming from excitatory neurons and 250 connections coming from inhibitory neurons
///

Network::Network()
					{
						for (int i(0); i < numberNeurons * 0.8; ++i) { 
							Neuron n(excitatory);
							neurons_.push_back(n);
						}
						
						for (int i(numberNeurons * 0.8 + 1); i <= numberNeurons; ++i) { 
							Neuron n(inhibitory);
							neurons_.push_back(n);
						}
						
						for (int i(0); i < numberNeurons; ++i) { 
							vector<int> neuronList;
							network_.push_back(neuronList);
		
						}
						
						for (int j(0); j < numberNeurons; ++j) {
			
							for (int i(0); i < numberNeurons * 0.8 * 0.1; ++i) { ///< create the random connections with the excitatory neurons
								static random_device rd;  
								static mt19937 gen(rd()); 
								static uniform_int_distribution<> connectionFromExcitatory(0, numberNeurons * 0.8 - 1);
								network_[connectionFromExcitatory(gen)].push_back(j);
							}
		
							for (int i(0); i < numberNeurons * 0.8 * 0.1; ++i) { ///< create the random connections with the inhibitory neurons
								static random_device rd;  
								static mt19937 gen(rd()); 
								static uniform_int_distribution<> connectionFromInhibitory(numberNeurons * 0.8, numberNeurons - 1);
								network_[connectionFromInhibitory(gen)].push_back(j);	 
							}
			
						}
					}


///
/// getter of a neuron of neurons
/// @param int x that is the positon of the neuron of interest in the vector neurons
/// @return Neuron at position x of the vector neurons
///

Neuron Network::getNeuron(int x)
{
	return neurons_[x];	
}

///
/// getter of the number of neuron that are connected with the neuron at posiiton x in the network
/// @param int x that is the positon of the neuron of interest in the vector network
/// @return the number of connections that are on the neuron at positon x of the network
///

int Network::getNetworkSize(int x)
{
	return network_[x].size();
}

///
/// getter of the number at position x and y in network that represents the neuron y that is connectd to the neuron x
/// @param int x position of the neuron int y position of the neuron that we are interested to know
/// @return the number at position x and y that is the id of the neuron of interest
///

int Network::getNeuronConnected(int x, int y)
{
	return network_[x][y];
}
	
	
	
	
	
	
	
	



