#ifndef NEURON_HPP
#define NEURON_HPP

#include <cassert>

class Neuron
{
    private : 
    double membranePot_; // membrane potential
    long nbSpikes_; //number of spikes 
    long timeSpike_; //time when the last spike occured   
    long clock_; //time of the neuron
    double iExt_; //external current
    
    double c1_; //constant of integration = exp(-h_/tau_)
    double c2_; //constant of integration = R_ * (1 - exp(-h_/tau_))
    
    const double tau_ = 20.0; //membrane time constant = Membrane resistance * C
    const double tauRef_ = 2.0; //refractory time
	const double R_ = 20.0; //membrane resistance
    const double spikeThr_ = 20.0; //Spike threshold
    const double h_ = 0.1; //stepsize
    const long refractorySteps_; //steps per tauRef_

    
    public :
    
    Neuron(); //constructor
    //~Neuron(); //destructor
    
    //update (will update the membrane potential and determine when there is a spike)
    bool update(long steps); //true if there is a spike 
    
    //getter
    double getMembranePot() const;
    double getNbSpikes() const;
    long getTimeSpike() const;
    long getClock() const;
    
    //setter
    void setIExt(double iExt);
 
};

#endif
