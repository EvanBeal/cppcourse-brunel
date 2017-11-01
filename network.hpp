#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "Constants.hpp"
#include "neuron.hpp"
#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Network
{
	private : 
	vector<Neuron> neurons; ///< the 10'000 first neurons are the excitatory ones and the 2500 following are the inhibitory
    vector<vector<int>> network; ///< the network of the connections between the neurons (if we want to know to which neuron is connected to the neuron 5 for example we look on the line 5 and see the number on the column to know to which neuron it's connected)
	
	public : 
	Network(); ///<constructor
	
	void update(double simStep, ofstream& data); ///< update of the network that look whether the neurons are spiking or not
	
	static double totalSpikes; ///< static element that counts the total of spikes during a simulation
	
};

#endif
