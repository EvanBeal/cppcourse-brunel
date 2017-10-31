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
	
	/*
	Neuron getNeuron(int x); ///< return the neuron of neurons at position x
	
	int getNetworkSize(int x); ///< return the number of column that has the line x which reprensent the number of neurons that are connected to the neuron reprensented on line x
	
	int getNeuronConnected(int x, int y); ///< return the number in network at position x and y which represent the neuron y that is connected to neuron x
	*/
	
	void update(double simStep, ofstream& data); ///< update of the network that look whether the neurons are spiking or not
	
};

#endif
