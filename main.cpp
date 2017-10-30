#include <iostream>
//#include "neuron.hpp"
#include "network.hpp"

#include <fstream>
#include <vector>
#include <array>
#include <random>

using namespace std;

int main()
{
	/*
	///
    ///Steps
    ///
    double start(0);
    double stop(2000);
    
    double currentStep(0);
    
    double h(0.1);
    
    ///
    ///External Current
    ///
    double Iext(0.0);
    */
    
    double currentStep(0);
    
    ofstream data("spikes.txt"); ///< open the file where the values will be written
    
    bool spike(false); ///< initiate a boolean that will be used after to determine whether the neuron is spiking or not
    
    Network network; ///< create a network of neurons with their connections
    
    /*
    ///
    ///test with a network of 12'500 neurons with 80% of excitatory neurons and 20% of inhibitory
    ///
    const int numberNeurons(12500);
    */
    /*
    vector<Neuron> neurons; ///< the 10'000 first neurons are the excitatory ones and the 2500 following are the inhibitory // try with deque
    vector<vector<int>> network; ///< the network of the connections between the neurons (if we want to know to which neuron is connected to the neuron 5 for example we look on the line 5 and see the number on the column to know to which neuron it's connected)
    
    ///
    ///initialization of the 10'000 first neurons to the excitatory type
    ///
    for (int i(0); i < numberNeurons * 0.8; ++i) { 
		Neuron n(excitatory);
		neurons.push_back(n);
	}
	
	///
	///initialization of the 2'500 following neurons in the inhibitory type
	///
	for (int i(numberNeurons * 0.8 + 1); i <= numberNeurons; ++i) { 
		Neuron n(inhibitory);
		neurons.push_back(n);
	}
	
	///
	///initialization of the network of connections with a 0 everywhere
	///
	for (int i(0); i < numberNeurons; ++i) { 
		
			vector<int> neuronList;
			network.push_back(neuronList);
		
	}
		
	///
	///put random connections between the neurons
	///but with every neuron with 1000 connections with excitatory neurons and 250 connections with inhibitory neurons
	///	
	for (int j(0); j < numberNeurons; ++j) {
			
		for (int i(0); i < numberNeurons * 0.8 * 0.1; ++i) { ///< create the random connections with the excitatory neurons
			static random_device rd;  
			static mt19937 gen(rd()); 
			static uniform_int_distribution<> connectionFromExcitatory(0, numberNeurons * 0.8 - 1);
			network[connectionFromExcitatory(gen)].push_back(j);
		}
		
		for (int i(0); i < numberNeurons * 0.8 * 0.1; ++i) { ///< crate the random connections with the inhibitory neurons
			static random_device rd;  
			static mt19937 gen(rd()); 
			static uniform_int_distribution<> connectionFromInhibitory(numberNeurons * 0.8, numberNeurons - 1);
			network[connectionFromInhibitory(gen)].push_back(j);	 
		}
			
	}
	*/
	
	///
	/// running the simulation by updating the neuron every time step
	/// and seeing if they spike or not anf if they spike then giving the signal to the post synaptic neurons
	///
	while(currentStep < stop) {
		
		for (int i(0); i < numberNeurons; ++i) {
					
					//neurons[i].setIExt(Iext);
					//network.getNeuron(i).setIExt(Iext);
		
					//spike = neurons[i].update(1);
					spike = network.getNeuron(i).update(1);
					
					if (spike) {
						
						//data << neurons[i].getClock() * h << '\t' << i + 1 << '\n';
						data << network.getNeuron(i).getClock() * h << '\t' << i + 1 << '\n';
						
						/*
						for (int j(0); j < network[i].size(); ++j) {
								
								neurons[network[i][j]].receive(currentStep, neurons[i].getAmplitude());  
							
					}
					*/
					
						for (int j(0); j < network.getNetworkSize(i); ++j) {
							
							network.getNeuron(network.getNeuronConnected(i, j)).receive(currentStep, network.getNeuron(i).getAmplitude());
					}
				}
			}
		
		cout << currentStep << endl;
		
		currentStep += 1;
	
	}

     data.close();
    
        return 0;
}
