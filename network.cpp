//**** FINAL VERSION ****//

#include "network.hpp"
#include <random>
#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>

using namespace std;

///
///@class Network that creates a network with neurons and connections between them and update the network by updating each neuron
///

double Network::totalSpikes = 0; ///< count the total number of spike during the simulation

///
///constructor of network 
///initialization of the 10'000 first neurons to the excitatory type
///initialization of the 2'500 following neurons in the inhibitory type
///initialization of the network of connections with a 0 everywhere
///put random connections between the neurons but with every neuron with 1000 connections coming from excitatory neurons and 250 connections coming from inhibitory neurons
///

Network::Network()
					{
						for (size_t i(0); i < numberNeurons * 0.8; ++i) { 
							Neuron n(excitatory);
							neurons.push_back(n);
						}
						
						for (size_t i(numberNeurons * 0.8 + 1); i <= numberNeurons; ++i) { 
							Neuron n(inhibitory);
							neurons.push_back(n);
						}
						
						for (size_t i(0); i < numberNeurons; ++i) { 
							vector<size_t> neuronList;
							network.push_back(neuronList);
		
						}
						
						for (int j(0); j < numberNeurons; ++j) {
			
							for (size_t i(0); i < numberNeurons * 0.8 * 0.1; ++i) { ///< create the random connections with the excitatory neurons
								static random_device rd;  
								static mt19937 gen(rd()); 
								static uniform_int_distribution<> connectionFromExcitatory(0, numberNeurons * 0.8 - 1);
								//assert(connectionFromExcitatory(gen) >= 0);
								//assert(connectionFromExcitatory(gen) <= numberNeurons * 0.8 - 1);
								network[connectionFromExcitatory(gen)].push_back(j);
							}
		
							for (size_t i(0); i < numberNeurons * 0.2 * 0.1; ++i) { ///< create the random connections with the inhibitory neurons
								static random_device rd;  
								static mt19937 gen(rd()); 
								static uniform_int_distribution<> connectionFromInhibitory(numberNeurons * 0.8, numberNeurons - 1);
								//assert(connectionFromInhibitory(gen) >= numberNeurons * 0.8);
								//assert(connectionFromInhibitory(gen) <= numberNeurons - 1);
								network[connectionFromInhibitory(gen)].push_back(j);	 
							}
			
						}
					}

///
/// updating the network
/// and seeing if the neurons spike or not and if they spike then giving the signal to the post synaptic neurons
/// and writing the time where the neuron spike and which neuron it is in a file giving in argument
/// @param the current step of the simulation and a file data where it will be possible to write on it in order to store the data of our simulation
///
	
void Network::update(double currentStep, ofstream& data)
{		
		for (size_t i(0); i < numberNeurons; ++i) {
					
					if (neurons[i].update(1)) {
						
						if (currentStep >= startCollectingData and currentStep <= stopCollectingData) {
						
							++ totalSpikes;
						
								data << neurons[i].getClock() * h << '\t' << i + 1 << '\n';
								
							}
						
									for (size_t j(0); j < network[i].size(); ++j) {
								
										neurons[network[i][j]].receive(currentStep + D_/h_, neurons[i].getAmplitude()); 
										 
						}
					}
				}
		
		currentStep += 1;
}
	
	
	
	
	



