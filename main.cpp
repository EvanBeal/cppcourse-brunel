#include <iostream>
#include "neuron.hpp"

#include <fstream>
#include <vector>
#include <array>
#include <random>

using namespace std;

int main()
{
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
    
    ///
    ///choices of the user
    ///
    long Istart(-1);
    long Istop(0);
    double I(0.0);
    
    /// 
    /// allow the user to enter the value wanted
    /// and verify if there in the good range or an exploitable value
    ///
    
    cout << "Start a current at (step) : ";
    
    while (Istart < 0 or Istart > stop) {
		cin >> Istart;
			if (Istart < 0.0 or Istart > stop) {
				cout << "the current should start between " << start << " and " << stop << endl;
				cin.clear();
			}
	} 
    
    cout << "End the current at (step) : ";
    
    while (Istop <= 0.0 or Istop > stop or Istop <= Istart) {
		cin >> Istop;
			if (Istop < 0.0 or Istop > stop or Istop <= Istart) { 
				cout << "the current should stop between " << Istart << " and " << stop << endl;
				cin.clear();
			}
	} 
    
    cout << "Choose your current : ";
    
    while (I <= 0.0) {
		cin >> I;  
			if (I <= 0.0) {
				cout << "the current should be positive" << endl;
				cin.clear();
			}
		}
    
    ofstream data("spikes.txt"); ///< open the file where the values will be written
    
    bool spike(false); ///< initiate a boolean that will be used after to determine whether the neuron is spiking or not
    
    ///
    ///test with a network of 12'500 neurons with 80% of excitatory neurons and 20% of inhibitory
    ///
    const int numberNeurons(1250);
    
    vector<Neuron> neurons; ///< the 10'000 first neurons are the excitatory ones and the 2500 following are the inhibitory
    array<array<int, numberNeurons>, numberNeurons> network; ///< the network of the connections between the neurons (if we want to know to which neuron is connected to the neuron 5 for example we look on the line 5 and see the number on the column to know to which neuron it's connected)
    
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
		for (int j(0); j < numberNeurons; ++j) {
			network[i][j] = 0;
		}
	}
		
	///
	///put random connections between the neurons
	///but with every neuron with 1000 connections with excitatory neurons and 250 connections with inhibitory neurons
	///	
	for (int j(0); j < numberNeurons; ++j) {
			
		for (int i(0); i < numberNeurons * 0.8 * 0.1; ++i) { ///< create the random connections with the excitatory neurons
			random_device rd;  
			mt19937 gen(rd()); 
			uniform_int_distribution<> dis(0, numberNeurons * 0.8 - 1);
			network[dis(gen)][j] += 1;
		}
		
		for (int i(0); i < numberNeurons * 0.8 * 0.1; ++i) { ///< crate the random connections with the inhibitory neurons
			random_device rd;  
			mt19937 gen(rd()); 
			uniform_int_distribution<> dis(numberNeurons * 0.8, numberNeurons - 1);
			network[dis(gen)][j] += 1;	 
		}
			
	}
	
	///
	/// running the simulation by updating the neuron every time step
	/// and seeing if they spike or not anf if they spike then giving the signal to the post synaptic neurons
	///
	while(currentStep < stop) {
		
		cout << "currentstep  " << currentStep << endl;
		
		if (Istart > start and Istop < stop and I > 0
			and Istart < currentStep and Istop > currentStep) {
	
				for (int i(0); i < numberNeurons; ++i) {
					
					neurons[i].setIExt(I);
		
					spike = neurons[i].update(1); 
					
					if (spike) {
						
						for (int j(0); j < numberNeurons; ++j) {
							
							if (network[i][j] != 0) {
								
								neurons[j].receive(currentStep, network[i][j] * neurons[i].getAmplitude());  ///<network[i][j] * neurons[i].getAmplitude() because if the neuron is connected multiple times with neurons[j] it should give multiple signals
							
					}
		
				}
			
			}
		
		}
		
		data << "Neuron 1 : " << neurons[1].getClock() * h << '\t' << '\t' << neurons[1].getMembranePot() << '\t' << '\t' << endl;
	
	}
	
	else {
		
		for (int i(0); i < numberNeurons; ++i) {
					
					neurons[i].setIExt(Iext);
		
					spike = neurons[i].update(1); 
					
					if (spike) {
						
						for (int j(0); j < numberNeurons; ++j) {
							
							if (network[i][j] != 0) {
								
								neurons[j].receive(currentStep, network[i][j] * neurons[i].getAmplitude());  ///<network[i][j] * neurons[i].getAmplitude() because if the neuron is connected multiple times with neurons[j] it should give multiple signals
							
					}
		
				}
			
			}
		
		}
		
		data << "Neuron 1 : " << neurons[1].getClock() * h << '\t' << '\t' << neurons[1].getMembranePot() << '\t' << '\t' << endl;
			
	}
	
	currentStep += 1;
	
}

     data.close();
    
        return 0;
}
