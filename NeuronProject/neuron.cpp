#include "neuron.hpp"
#include <iostream>

using namespace std;

Neuron::Neuron(sf::Time tau, double C)
        : tau_(tau),
          C_(C),
          isExcited_(bernoulli(0.8))
        {
            membranePot_ = -70e-3;
            nbSpikes_ = 0;
            spikesOccured_.clear();
            maxPot_ = -50e-3;
            membranePotentials_.clear();
            }

void Neuron::update(sf::Time h, double current, sf::Time simTime)
{
    //membrane potential
    double old(membranePot_);
    
    membranePot_ = exp(-h/tau)*old + current * (tau_/C_) * (1- exp(-h/tau));
    
    membranePotentials_.pushback(membranePot_);
    //membranePotentials_.pushback(simTime);
    
    //spike?
    if (membranePot_ >= maxPot_) {
        ++nbSpikes_;
        spikesOccured_.pushback(simTime);
        membranePot_ = membranePotIni;
    }
    
}
