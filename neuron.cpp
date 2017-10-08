#include "neuron.hpp"
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

double const membranePotIni(0); //initial membrane potential 
sf::Time const refractoryPeriod(milliseconds(2)); //refractory period after a threshold

Neuron::Neuron(sf::Time tau, double C)
        : tau_(tau),
          C_(C),
          isRefractory_(bernoulli_distribution(0.2))
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
		membranePotentials_.push_back(0);
	}
	
	else {
					//spike ? (if the membrane pot is bigger than the threshold potential then there is a spike)
    if (membranePot_ >= maxPot_) {
			++nbSpikes_;
			spikesOccured_.push_back(simTime);
			writeSpikeTime(simTime);			//need to store spike time in a file
			membranePot_ = membranePotIni;
			refractoryTime = sf::Milliseconds(0); //after the spike there is a refractory time of 2ms where the membrane potential is equal to 0
		}
    
    membranePot_ = exp(-h/tau) * membranePot_ + current * (tau_/C_) * (1- exp(-h/tau));
    
    membranePotentials_.push_back(membranePot_);
    //membranePotentials_.push_back(simTime);
	}
}

void Neuron::writeSpikeTime(sf::Time simTime)
{
	ofstream data(spikes.txt);
    if (data.fail()) {
        cerr << "Erreur : impossible d'ecrire"
                << " dans le fichier spikes.txt " << endl;
        } else {
            data << simTime << endl;
            }
       //data.close();	
}
