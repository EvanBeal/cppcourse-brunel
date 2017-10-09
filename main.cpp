#include <iostream>
#include "neuron.cpp"
#include <fstream>

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
    long Istart;
    long Istop;
    double I;
    
    cout << "Start a current at (step) : ";
    cin >> Istart;
    cout << "End the current at (step) : ";
    cin >> Istop;
    cout << "Choose your current : ";
    cin >> I;   
    
    ofstream data("spikes.txt");
    
    
    //test
    Neuron n1;
    
    bool spike(false);
    
    
    
    while(currentStep < stop) {
		
        if (Istart > start and Istop < stop and I > 0
				and Istart < currentStep and Istop > currentStep) {
				
				n1.setIExt(I);
                spike = n1.update(1);
                
                if (data.fail()) {
        				cerr << "Erreur : impossible d'ecrire"
                					<< " dans le fichier spikes.txt " << endl;
        			} else {
            			data << n1.getClock() * 0.1 << '\t' << n1.getMembranePot() << endl;
            		}
                
                if (spike) {
					
					if (data.fail()) {
        				cerr << "Erreur : impossible d'ecrire"
                					<< " dans le fichier spikes.txt " << endl;
        			} else {
            			data << "Spike at t = " << n1.getTimeSpike() * 0.1 << endl;
            		}
					
				}
                
			}
			
        else {
			
				n1.setIExt(Iext);
                spike = n1.update(1);
                
                if (data.fail()) {
        				cerr << "Erreur : impossible d'ecrire"
                					<< " dans le fichier spikes.txt " << endl;
        			} else {
            			data << n1.getClock() * 0.1 << '\t' << n1.getMembranePot() << endl;
            		}
                
			}
			
        currentStep += 2;
    }
    
     data.close();
    
        return 0;
}
