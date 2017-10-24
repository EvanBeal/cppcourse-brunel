#include <iostream>
#include "neuron.hpp"

#include <fstream>
#include <vector>
#include <array>

using namespace std;

int main()
{
    //Steps
    double start(0);
    double stop(2000);
    
    double currentStep(0);
    
    double h(0.1);
    
    //External Current
    double Iext(0);
    
    //choice of the user
    long Istart(0);
    long Istop(0);
    double I(0.0);
    
    cout << "Start a current at (step) : ";
    
    while (Istart <= 0.0 or Istart > stop) {
		cin >> Istart;
			if (Istart <= 0.0 or Istart > stop) {
				cout << "the current should start between " << start << " and " << stop << endl;
				cin.clear();
			}
	} 
    
    cout << "End the current at (step) : ";
    
    while (Istop <= 0.0 or Istop > stop or Istop <= Istart) {
		cin >> Istop;
			if (Istop <= 0.0 or Istop > stop or Istop <= Istart) { 
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
    
    ofstream data("spikes.txt");
    
    
    //test
    Neuron n1;
    Neuron n2;
    
    bool spike1(false);
    bool spike2(false);
    
    //test with the network
    int numberNeurons(12500);
    
    array<Neuron*, numberNeurons> neurons; //the 10'000 first neurons are the excitatory ones and the 2500 following are the inhibitory
    array<array<int, numberNeurons>, numberNeurons> network; //the network of the connections between the neurons (if we want to know to which neuron is connected the neuron 5 for example we loik on the line 5 and see the number on the column to know to which neuron it's connected)
    
    for (int i(0); i < numberNeurons * 0.8; ++i) { //initiate the 10'000 first neurons to the excitatory type
		neurons[i] = new Neuron(excitatory);
	}
	
	for (int i(numberNeurons * 0.8 + 1); i < numberNeurons; ++i) { //initiate the 2'500 following to the inhibitory type
		neurons[i] = new Neuron(inhibitory);
	}
	
	for (int i(0); i < numberNeurons; ++i) { //initiate the network
		for (int j(0); j < numberNeurons; ++j) {
			network[i][j] = 0;
		}
	}
		
    
	while(currentStep < stop) {
		
		for (int j(0); j < numberNeurons; ++i) {
			
			for (int i(0); i < numberNeurons * 0.8 * 0.1; ++i) {
			std::random_device rd;  //Will be used to obtain a seed for the random number engine
			std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
			std::uniform_int_distribution<> dis(0, numberNeurons * 0.8 - 1);
			network[dis][j] += 1;
		}
			for (int i(0); i < numberNeurons * 0.8 * 0.1; ++i) {
			std::random_device rd;  //Will be used to obtain a seed for the random number engine
			std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
			std::uniform_int_distribution<> dis(numberNeurons * 0.8, numberNeurons - 1);
			network[dis][j] += 1;	 
		}
		
	}
    /*
    while(currentStep < stop) {
		
        if (Istart > start and Istop < stop and I > 0
			and Istart < currentStep and Istop > currentStep) {
				
				n1.setIExt(I);
				n2.setIExt(Iext);
                spike1 = n1.update(currentStep);
                spike2 = n2.update(currentStep);
                
                
            			data << n1.getClock() * h << '\t' << '\t' << n1.getMembranePot() << '\t' << '\t' << n2.getMembranePot() << endl;
                
                if (spike1) {
			
            			data << "Spike for neuron 1 at t = " << n1.getTimeSpike() * h << endl;

						n2.receive(currentStep, n1.getJ());
						
				}
				
				if (spike2) {
					
						data << "Spike for neuron 2 at t = " << n2.getTimeSpike() * h << endl;
						
						n1.receive(currentStep, n2.getJ());
						
				}
                
			}
			
        else {
			
				n1.setIExt(Iext);
				n2.setIExt(Iext);
                spike1 = n1.update(currentStep);
                spike2 = n2.update(currentStep);
                
            			data << n1.getClock() * h << '\t' << '\t' << n1.getMembranePot() << '\t' << '\t' << n2.getMembranePot() << endl;
                
				}						
				
			
        currentStep += 1;
        
    }
    */
    
     data.close();
    
        return 0;
}

