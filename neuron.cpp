#include "neuron.hpp"
#include <iostream>

using namespace std;

Neuron::Neuron(sf::Time tau, double C)
        : tau_(tau),
          C_(C),
          isRefractory_(bernoulli(0.2))
        {
            membranePot_ = 0;
            nbSpikes_ = 0;
            spikesOccured_.clear();
            maxPot_ = 20;
            membranePotentials_.clear();
            }

void Neuron::update(sf::Time h, double current, sf::Time simTime)
{   
    if (isRefractory_ or refractoryTime < refractoryPeriod) {
		membranePot_ = 0;
		membranePotentials_.pushback(0);
	}
	
	else {
					//spike ? (if the membrane pot is bigger than the threshold potential then there is a spike)
    if (membranePot_ >= maxPot_) {
			++nbSpikes_;
			spikesOccured_.pushback(simTime);
												//need to store spike time in a file
			membranePot_ = membranePotIni;
			refractoryTime = asMilliseconds(0); //after the spike there is a refractory time of 2ms where the membrane potential is equal to 0
		}
    
    membranePot_ = exp(-h/tau) * membranePot_ + current * (tau_/C_) * (1- exp(-h/tau));
    
    membranePotentials_.pushback(membranePot_);
    //membranePotentials_.pushback(simTime);
	}
}
