#include <iostream>
#include "neuron.hpp"

#include <fstream>
#include <vector>

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
    
    //faire un vector de neuron et iterer dessus pour les différents update et getter
    /*
    vector <Neuron> neurons;
    
    neurons.push_back(n1);
    neurons.push_back(n2);
    */
    
    //faire des for auto
    
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
    
     data.close();
    
        return 0;
}

/*for (auto& n : neurons) {
					
					
					if (spike) {
					
            			data << "Spike at t = " << n.getTimeSpike() * 0.1 << " ms" << endl;

					}
					
				
				n.setIExt(I);
                n.update(1);

            			data << n.getMembranePot() << "pA" << '\t' << "at T = " << n.getClock() * 0.1 << " ms" << '\t' << '\t';
					
				}
				
				data << endl;
                
			}
			
        else {
			
			for (auto& n : neurons) {
				
				n.setIExt(Iext);
                n.update(1);
                
            			data << n.getMembranePot() << "pA" << '\t' << "at T = " << n.getClock() * 0.1 << " ms" << '\t' << '\t';

			}
*/
