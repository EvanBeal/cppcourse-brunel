#ifndef NEURON_HPP
#define NEURON_HPP

#include "Constants.hpp"
#include <cassert>
#include <vector>

enum Type {inhibitory, excitatory}; ///<determine the type of neuron

class Neuron
{
    private : 
    double membranePot_; ///< membrane potential
    long nbSpikes_; ///<number of spikes 
    long timeSpike_; ///<time when the last spike occured   
    long clock_; ///<time of the neuron
    double iExt_; ///<external current
    
    double c1_; ///<constant of integration = exp(-h_/tau_)
    double c2_; ///<constant of integration = R_ * (1 - exp(-h_/tau_))
    
    Type type_; ///<determine the type of the neuron
    
    std::vector<double> ringBuffer_; ///<ring buffer to deal with the delay between spike and post synaptic signal
    
    double amplitude_; ///<the amplitude (J) of the signal that is given to the post synaptic neuron
    
    
    public :
    
    Neuron(Type type); ///<constructor
    
    bool update(long steps); ///<true if there is a spike 
    
    bool updateTest(long steps); ///<is like the update function but without the random term poisson so we can see if the rest is acting accurately
    
    void receive(long steps, double amplitude); ///<update the membrane potential of a post synaptic neuron after the spike of the pre synaptic neuron
    
    ///
    ///getters
    ///
    double getMembranePot() const;
    double getNbSpikes() const;
    long getTimeSpike() const;
    long getClock() const;
    double getAmplitude() const; ///<return the amplitude
    
    ///
    ///setters
    ///
    void setIExt(double iExt);
    void setRingBuffer(int position); ///<will add the amplitude at the position position
 
};

#endif
