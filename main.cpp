#include <iostream>
#include "network.hpp"

#include <fstream>
#include <vector>
#include <array>
#include <random>

using namespace std;

int main()
{   
    double currentStep(0); ///<initialization of the currentStep at 0
    
    Network network; ///< create a network of neurons with their connections
    
    ofstream data("spikes.txt"); ///< open the file where the values will be written
    
    int y(0);
	
	///
	/// running the simulation by updating the network every time step until it reaches stop the end of the simulation
	///
	while(currentStep < stop) {
		
		int x(currentStep * 10/stop);
		
		network.update(currentStep, data);
		
		currentStep += 1;
		
		if (currentStep == 0 or (y % 1000) != (x % 1000)) {
			cout << 10 * x << "%" << endl;
			y = x;
		}
	
	}
	
	cout << "100%" << endl;
	
	cout << "Simulation done" << endl;
	
	cout << "Total of spike during the simulation : " << Network::totalSpikes << endl;
	
	cout << "Average number of spike per neuron : " << Network::totalSpikes/numberNeurons << endl;
	
    data.close(); ///< close the file where the values are now written
    
    return 0;
}
